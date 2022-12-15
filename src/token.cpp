#include "token.h"

// IToken
IToken::IToken(TokenType type) : m_type(type) {}

//Token Identifier
TokenIdentifier::TokenIdentifier(std::string &value) : IToken(TokenType::TOKEN_IDENTIFIER), m_value(value) {}

std::string TokenIdentifier::to_string() {
    auto str = std::string();

    str.append("Identifier{");
    str.append(this->m_value);
    str.append("}");

    return str;
}

//Token Symbol
TokenSymbol::TokenSymbol(TokenSymbolT symbol) : IToken(TokenType::TOKEN_SYMBOL), m_symbol(symbol) {}

std::string TokenSymbol::to_string() {
    auto str = std::string();
    str.append("Symbol{");
    switch (m_symbol) {
        case TokenSymbolT::TOKEN_COMMA:
            str.append("[,]");
            break;
        case TokenSymbolT::TOKEN_QUESTION_MARK:
            str.append("[?]");
            break;
        case TokenSymbolT::TOKEN_SINGLE_APOSTROPHE:
            str.append("[']");
            break;
        case TokenSymbolT::TOKEN_DOUBLE_APOSTROPHE:
            str.append("[\"]");
            break;
        default:
            str.append("[Unknown symbol]");
            break;
    }
    str.append("}");

    return str;
}

//Token String
TokenString::TokenString(std::string &string) : IToken(TokenType::TOKEN_STRING), m_string(string) {}

std::string TokenString::to_string() {
    auto str = std::string();

    str.append("String{");
    str.append(this->m_string);
    str.append("}");

    return str;
}

//Token Number
TokenNumber::TokenNumber(std::string &number) : IToken(TokenType::TOKEN_NUMBER), m_number(number) {}

std::string TokenNumber::to_string() {
    auto str = std::string();

    str.append("Number{");
    str.append(this->m_number);
    str.append("}");

    return str;
}

//Token Keyword
TokenKeyword::TokenKeyword(TokenKeywordT keyword) : IToken(TokenType::TOKEN_KEYWORD), m_keyword(keyword) {}

std::string TokenKeyword::to_string() {
    auto str = std::string();

    str.append("Keyword{");
    switch (m_keyword) {
        case TOKEN_KEYWORD_HAI:
            str.append("HAI");
            break;
        case TOKEN_KEYWORD_KTHX:
            str.append("KTHX");
            break;
        case TOKEN_KEYWORD_KTHXBYE:
            str.append("KTHXBYE");
            break;
        case TOKEN_KEYWORD_I:
            str.append("I");
            break;
        case TOKEN_KEYWORD_ME:
            str.append("ME");
            break;
        case TOKEN_KEYWORD_HAS:
            str.append("HAS");
            break;
        case TOKEN_KEYWORD_A:
            str.append("A");
            break;
        case TOKEN_KEYWORD_AN:
            str.append("AN");
            break;
        case TOKEN_KEYWORD_ITZ:
            str.append("ITZ");
            break;
        case TOKEN_KEYWORD_IZ:
            str.append("IZ");
            break;
        case TOKEN_KEYWORD_LIEK:
            str.append("LIEK");
            break;
        case TOKEN_KEYWORD_CAN:
            str.append("CAN");
            break;
        case TOKEN_KEYWORD_MKAY:
            str.append("MKAY");
            break;
        case TOKEN_KEYWORD_NOW:
            str.append("NOW");
            break;
        case TOKEN_KEYWORD_NOOB:
            str.append("NOOB");
            break;
        case TOKEN_KEYWORD_TROOF:
            str.append("TROOF");
            break;
        case TOKEN_KEYWORD_WIN:
            str.append("WIN");
            break;
        case TOKEN_KEYWORD_FAIL:
            str.append("FAIL");
            break;
        case TOKEN_KEYWORD_NUMBR:
            str.append("NUMBR");
            break;
        case TOKEN_KEYWORD_NUMBAR:
            str.append("NUMBAR");
            break;
        case TOKEN_KEYWORD_YARN:
            str.append("YARN");
            break;
        case TOKEN_KEYWORD_GIMMEH:
            str.append("GIMMEH");
            break;
        case TOKEN_KEYWORD_VISIBLE:
            str.append("VISIBLE");
            break;
        case TOKEN_KEYWORD_BOTH:
            str.append("BOTH");
            break;
        case TOKEN_KEYWORD_SAEM:
            str.append("SAEM");
            break;
        case TOKEN_KEYWORD_MAEK:
            str.append("MAEK");
            break;
        case TOKEN_KEYWORD_DIFFRINT:
            str.append("DIFFRINT");
            break;
        case TOKEN_KEYWORD_BIGGR:
            str.append("BIGGR");
            break;
        case TOKEN_KEYWORD_SMALLR:
            str.append("SMALLR");
            break;
        case TOKEN_KEYWORD_SUM:
            str.append("SUM");
            break;
        case TOKEN_KEYWORD_DIFF:
            str.append("DIFF");
            break;
        case TOKEN_KEYWORD_PRODUKT:
            str.append("PRODUKT");
            break;
        case TOKEN_KEYWORD_QUOSHUNT:
            str.append("QUOSHUNT");
            break;
        case TOKEN_KEYWORD_MOD:
            str.append("MOD");
            break;
        case TOKEN_KEYWORD_SMOOSH:
            str.append("SMOOSH");
            break;
        case TOKEN_KEYWORD_SRS:
            str.append("SRS");
            break;
        case TOKEN_KEYWORD_O:
            str.append("O");
            break;
        case TOKEN_KEYWORD_RLY:
            str.append("RLY");
            break;
        case TOKEN_KEYWORD_YA:
            str.append("YA");
            break;
        case TOKEN_KEYWORD_NO:
            str.append("NO");
            break;
        case TOKEN_KEYWORD_WAI:
            str.append("WAI");
            break;
        case TOKEN_KEYWORD_OIC:
            str.append("OIC");
            break;
        case TOKEN_KEYWORD_WTF:
            str.append("WTF");
            break;
        case TOKEN_KEYWORD_OMG:
            str.append("OMG");
            break;
        case TOKEN_KEYWORD_OMGWTF:
            str.append("OMGWTF");
            break;
        case TOKEN_KEYWORD_IM:
            str.append("IM");
            break;
        case TOKEN_KEYWORD_IN:
            str.append("IN");
            break;
        case TOKEN_KEYWORD_YR:
            str.append("YR");
            break;
        case TOKEN_KEYWORD_UPPIN:
            str.append("UPPIN");
            break;
        case TOKEN_KEYWORD_NERFIN:
            str.append("NERFIN");
            break;
        case TOKEN_KEYWORD_TIL:
            str.append("TIL");
            break;
        case TOKEN_KEYWORD_WILE:
            str.append("WILE");
            break;
        case TOKEN_KEYWORD_OUTTA:
            str.append("OUTTA");
            break;
        case TOKEN_KEYWORD_FOUND:
            str.append("FOUND");
            break;
        case TOKEN_KEYWORD_GTFO:
            str.append("GTFO");
            break;
        case TOKEN_KEYWORD_IF:
            str.append("IF");
            break;
        case TOKEN_KEYWORD_U:
            str.append("U");
            break;
        case TOKEN_KEYWORD_SAY:
            str.append("SAY");
            break;
        case TOKEN_KEYWORD_SO:
            str.append("SO");
            break;
        case TOKEN_KEYWORD_BUKKIT:
            str.append("BUKKIT");
            break;
        case TOKEN_KEYWORD_HOW:
            str.append("HOW");
            break;
        case TOKEN_KEYWORD_R:
            str.append("R");
            break;
        case TOKEN_KEYWORD_Z:
            str.append("Z");
            break;
        case TOKEN_KEYWORD_IT:
            str.append("IT");
            break;
        case TOKEN_KEYWORD_MEBEE:
            str.append("MEBEE");
            break;
        default:
            str.append("Unknown Keyword");
            break;
    }
    str.append("}");

    return str;
}
