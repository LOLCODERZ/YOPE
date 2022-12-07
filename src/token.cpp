#include "token.h"

// IToken
IToken::IToken(TokenType type): m_type(type) {}

//Token Identifier
TokenIdentifier::TokenIdentifier(std::string &value): IToken(TokenType::TOKEN_IDENTIFIER), m_value(value) {}

std::string TokenIdentifier::to_string(){
    auto str = std::string();

    str.append
}