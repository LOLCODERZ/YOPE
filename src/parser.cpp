//
// Created by axelc on 07/12/2022.
//

#include "parser.h"

std::shared_ptr<IToken> Parser::current() {
    if (this->m_index < this->m_tokens.size()) {
        return this->m_tokens[this->m_index];
    } else {
        return std::nullptr_t();
    }
}

void Parser::advance() {
    this->m_index += 1;
}

std::vector<std::shared_ptr<INode>> Parser::parse() {
    std::vector<std::shared_ptr<INode>> ast;

    auto current = this->current();
    while (current != std::nullptr_t()) {
        ast.push_back(this->parse_current());
        this->advance();
        current = this->current();
    }

    return ast;
}

std::shared_ptr<INode> Parser::parse_current() {
    auto current = this->current(); // Expected not null!

    switch (current->m_type) {
        case TOKEN_KEYWORD: {
            auto keyword = std::dynamic_pointer_cast<TokenKeyword>(current);
            switch (keyword->m_keyword) {
                case TOKEN_KEYWORD_HAI: {
                    // After 1.2 (version?)
                    this->advance();
                    current = this->current();
                    if (current->m_type != TOKEN_NUMBER) throw std::runtime_error("Unexpected token");
                    auto num_tok = std::dynamic_pointer_cast<TokenNumber>(current);
                    this->advance(); // Version Ignored
                    return this->parse_current();
                }
                case TOKEN_KEYWORD_CAN: {
                    // Imports
                    // HAS STDIO?
                    this->advance();
                    current = this->current();
                    if (current->m_type != TOKEN_KEYWORD) throw std::runtime_error("Unexpected token");
                    auto keyword_tok = std::dynamic_pointer_cast<TokenKeyword>(current);
                    if (keyword_tok->m_keyword != TOKEN_KEYWORD_HAS) throw std::runtime_error("Unexpected keyword");
                    this->advance();
                    current = this->current();
                    if (current->m_type != TOKEN_IDENTIFIER) throw std::runtime_error("Unexpected token");
                    auto id_tok = std::dynamic_pointer_cast<TokenIdentifier>(current);
                    this->advance();
                    current = this->current();
                    if (current->m_type != TOKEN_SYMBOL) throw std::runtime_error("Unexpected token");
                    auto sym_tok = std::dynamic_pointer_cast<TokenSymbol>(current);
                    if (sym_tok->m_symbol != TOKEN_QUESTION_MARK) throw std::runtime_error("Unexpected symbol");
                    return std::make_shared<IncludeNode>(id_tok->m_value);
                }
                case TOKEN_KEYWORD_VISIBLE: {
                    // Function Call Print
                    // String
                    this->advance();
                    current = this->current();
                    if (current->m_type != TOKEN_STRING) throw std::runtime_error("Unexpected token");
                    auto str_tok = std::dynamic_pointer_cast<TokenString>(current);
                    return std::make_shared<VisibleNode>(str_tok->m_string);
                }
                case TOKEN_KEYWORD_KTHXBYE: {
                    // Interrupt
                    return std::make_shared<InterruptNode>();
                }
                default:
                    throw std::runtime_error("Unexpected Keyword!");
            }
        }
        default:
            throw std::runtime_error("Unexpected token!");
    }
}

Parser::Parser(std::vector<std::shared_ptr<IToken>> tokens) : m_tokens(tokens) {

}
