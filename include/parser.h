//
// Created by axelc on 07/12/2022.
//

#ifndef YOPE_PARSER_H
#define YOPE_PARSER_H

#include "token.h"
#include "node.h"
#include <vector>
#include <memory>

class Parser {
public:
    std::vector<std::shared_ptr<IToken>> m_tokens;
    uintptr_t m_index = 0;

    explicit Parser(std::vector<std::shared_ptr<IToken>> tokens);
    std::vector<std::shared_ptr<INode>> parse();
private:
    std::shared_ptr<IToken> current();
    void advance();

    std::shared_ptr<INode> parse_current();
};


#endif //YOPE_PARSER_H
