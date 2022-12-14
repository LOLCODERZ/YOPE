//
// Created by juejue on 12/7/2022.
//

#include "lexer.h"
#include <iostream>
#include <cstring>

Lexer::Lexer(std::string src) {
    this->m_src = std::move(src);
    this->m_index = 0;
    if (this->m_index >= this->m_src.length()) {
        this->m_current = '\0'; // EOF
    } else {
        this->m_current = this->m_src[this->m_index];
    }
}

void Lexer::advance() {
    this->m_index += 1;
    if (this->m_index >= this->m_src.length()) {
        this->m_current = '\0'; // EOF
    } else {
        this->m_current = this->m_src[this->m_index];
    }
}

std::vector<std::shared_ptr<IToken>> Lexer::tokenize() {
    auto tokens = std::vector<std::shared_ptr<IToken>>();

    while (this->m_current != '\0') {

        if (std::regex_match(std::string{this->m_current}, r)) {
            std::string buf;
            buf.push_back(this->m_current);
            tokens.push_back(std::make_shared<TokenNumber>(buf));

        } else if (this->m_current == '"') {
            tokens.push_back(this->make_string());

        } else if (this->m_current == '?' || this->m_current == ',' || this->m_current == '\''){
            switch (this->m_current) {
                case '?' :
                    tokens.push_back(std::make_shared<TokenSymbol>(TokenSymbolT::TOKEN_QUESTION_MARK));
                    break;
                case ',':
                    tokens.push_back(std::make_shared<TokenSymbol>(TokenSymbolT::TOKEN_COMMA));
                    break;
                case '\'':
                    tokens.push_back(std::make_shared<TokenSymbol>(TokenSymbolT::TOKEN_SINGLE_APOSTROPHE));
                    break;
            }
            this->advance();

        } else if (this->Keyword_check()){

            MapKeywords_initialize();
            std::string str {this->m_current};

            switch (MapKeywords[str]) {
                case HAI :
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_HAI));
                case KTHX :
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_KTHX));
                case KTHXBYE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_KTHXBYE));
                case I:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_I));
                case ME:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_ME));
                case HAS:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_HAS));
                case A:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_A));
                case AN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_AN));
                case ITZ:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_ITZ));
                case IZ:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IZ));
                case LIEK:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_LIEK));
                case CAN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_CAN));
                case MKAY:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MKAY));
                case NOW:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NOW));
                case NOOB:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NOOB));
                case TROOF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_TROOF));
                case WIN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WIN));
                case FAIL:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_FAIL));
                case NUMBR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NUMBR));
                case NUMBAR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NUMBAR));
                case YARN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_YARN));
                case GIMMEH:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_GIMMEH));
                case VISIBLE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_VISIBLE));
                case BOTH:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_BOTH));
                case SAEM:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SAEM));
                case MAEK:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MAEK));
                case DIFFRINT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_DIFFRINT));
                case BIGGR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_BIGGR));
                case SMALLR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SMALLR));
                case SUM:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SUM));
                case DIFF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_DIFF));
                case PRODUKT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_PRODUKT));
                case QUOSHUNT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_QUOSHUNT));
                case MOD:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MOD));
                case SMOOSH:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SMOOSH));
                case SRS:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SRS));
                case O:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_O));
                case RLY:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_RLY));
                case YA:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_YA));
                case NO:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NO));
                case WAI:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WAI));
                case OIC:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OIC));
                case WTF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WTF));
                case OMG:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OMG));
                case OMGWTF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OMGWTF));
                case IM:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IM));
                case IN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IN));
                case YR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_YR));
                case UPPIN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_UPPIN));
                case NERFIN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NERFIN));
                case TIL:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_TIL));
                case WILE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WILE));
                case OUTTA:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OUTTA));
                case FOUND:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_FOUND));
                case GTFO:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_GTFO));
                case IF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IF));
                case U:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_U));
                case SAY:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SAY));
                case SO:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SO));
                case BUKKIT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_BUKKIT));
                case HOW:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NOW));
                case R:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_R));
                case Z:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_Z));
                case IT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IT));
                case MEBEE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MEBEE));
                default:
                    std::cout << "Unexpected char '" << this->m_current << "'!" << std::endl;
                    std::exit(1);
            }
        } else{
            tokens.push_back(this->make_identifier());
        }
    }

    return tokens;
}


bool Lexer::Keyword_check() {

    const char *c = &this->m_current;

    if(!strcmp("HAI", c)      || !strcmp("KTHX", c)   || !strcmp("KTHXBYX", c)  || !strcmp("I", c)       ||
       !strcmp("ME", c)       || !strcmp("HAS", c)    || !strcmp("A", c)        || !strcmp("AN", c)      ||
       !strcmp("ITZ", c)      || !strcmp("IZ", c)     || !strcmp("LIEK", c)     || !strcmp("CAN", c)     ||
       !strcmp("MKAY", c)     || !strcmp("NOW", c)    || !strcmp("NOOB", c)     || !strcmp("TROOF", c)   ||
       !strcmp("WIN", c)      || !strcmp("FAIL", c)   || !strcmp("NUMBR", c)    || !strcmp("NUMBAR", c)  ||
       !strcmp("YARN", c)     || !strcmp("GIMMEH", c) || !strcmp("VISIBLE", c)  || !strcmp("BOTH", c)    ||
       !strcmp("SAEM", c)     || !strcmp("MAEK", c)   || !strcmp("DIFFRINT", c) || !strcmp("BIGGR", c)   ||
       !strcmp("SMALLR", c)   || !strcmp("SUM", c)    || !strcmp("DIFF", c)     || !strcmp("PRODUKT", c) ||
       !strcmp("QUOSHUNT", c) || !strcmp("MOD", c)    || !strcmp("SMOOSH", c)   || !strcmp("SRS", c)     ||
       !strcmp("O", c)        || !strcmp("RLY", c)    || !strcmp("YA", c)       || !strcmp("NO", c)      ||
       !strcmp("WAI", c)      || !strcmp("OIC", c)    || !strcmp("WTF", c)      || !strcmp("OMG", c)     ||
       !strcmp("OMGWTF", c)   || !strcmp("IM", c)     || !strcmp("IN", c)       || !strcmp("YR", c)      ||
       !strcmp("UPPIN", c)    || !strcmp("NERFIN", c) || !strcmp("TIL", c)      || !strcmp("WILE", c)    ||
       !strcmp("OUTTA", c)    || !strcmp("FOUND", c)  || !strcmp("GTFO", c)     || !strcmp("IF", c)      ||
       !strcmp("U", c)        || !strcmp("SAY", c)    || !strcmp("SO", c)       || !strcmp("BUKKIT", c)  ||
       !strcmp("HOW", c)      || !strcmp("R", c)      || !strcmp("Z", c)        || !strcmp("IT", c)      ||
       !strcmp("MEBEE", c)){

        return true;
    }

    return false;
}

void Lexer::MapKeywords_initialize() {
    MapKeywords["HAI"] = HAI;
    MapKeywords["KTHX"] = KTHX;
    MapKeywords["KTHXBYE"] = KTHXBYE;
    MapKeywords["I"] = I;
    MapKeywords["ME"] = ME;
    MapKeywords["HAS"] = HAS;
    MapKeywords["A"] = A;
    MapKeywords["AN"] = AN;
    MapKeywords["ITZ"] = ITZ;
    MapKeywords["IZ"] = IZ;
    MapKeywords["LIEK"] = LIEK;
    MapKeywords["CAN"] = CAN;
    MapKeywords["MKAY"] = MKAY;
    MapKeywords["NOW"] = NOW;
    MapKeywords["NOOB"] = NOOB;
    MapKeywords["TROOF"] = TROOF;
    MapKeywords["WIN"] = WIN;
    MapKeywords["FAIL"] = FAIL;
    MapKeywords["NUMBR"] = NUMBR;
    MapKeywords["NUMBAR"] = NUMBAR;
    MapKeywords["YARN"] = YARN;
    MapKeywords["GIMMEH"] = GIMMEH;
    MapKeywords["VISIBLE"] = VISIBLE;
    MapKeywords["BOTH"] = BOTH;
    MapKeywords["SAEM"] = SAEM;
    MapKeywords["MAEK"] = MAEK;
    MapKeywords["DIFFRINT"] = DIFFRINT;
    MapKeywords["BIGGR"] = BIGGR;
    MapKeywords["SMALLR"] = SMALLR;
    MapKeywords["SUM"] = SUM;
    MapKeywords["DIFF"] = DIFF;
    MapKeywords["PRODUKT"] = PRODUKT;
    MapKeywords["QUOSHUNT"] = QUOSHUNT;
    MapKeywords["MOD"] = MOD;
    MapKeywords["SMOOTH"] = SMOOSH;
    MapKeywords["SRS"] = SRS;
    MapKeywords["O"] = O;
    MapKeywords["RLY"] = RLY;
    MapKeywords["YA"] = YA;
    MapKeywords["NO"] = NO;
    MapKeywords["WAI"] = WAI;
    MapKeywords["OIC"] = OIC;
    MapKeywords["WTF"] = WTF;
    MapKeywords["OMG"] = OMG;
    MapKeywords["OMGWTF"] = OMGWTF;
    MapKeywords["IM"] = IM;
    MapKeywords["IN"] = IN;
    MapKeywords["YR"] = YR;
    MapKeywords["UPPIN"] = UPPIN;
    MapKeywords["NERFIN"] = NERFIN;
    MapKeywords["TIL"] = TIL;
    MapKeywords["WILE"] = WILE;
    MapKeywords["OUTTA"] = OUTTA;
    MapKeywords["FOUND"] = FOUND;
    MapKeywords["GTFO"] = GTFO;
    MapKeywords["IF"] = IF;
    MapKeywords["U"] = U;
    MapKeywords["SAY"] = SAY;
    MapKeywords["SO"] = SO;
    MapKeywords["BUKKIT"] = BUKKIT;
    MapKeywords["HOW"] = HOW;
    MapKeywords["R"] = R;
    MapKeywords["Z"] = Z;
    MapKeywords["IT"] = IT;
    MapKeywords["MEBEE"] = MEBEE;

}

std::shared_ptr<IToken> Lexer::make_identifier() {
    auto buf = std::string();

    while (isalnum(this->m_current) || this->m_current == '_') {
        buf.push_back(this->m_current);
        this->advance();
    }

    return std::make_shared<TokenIdentifier>(buf);
}

std::shared_ptr<IToken> Lexer::make_string() {
    auto buf = std::string();
    this->advance();

    while (this->m_current != '"') {
        if (this->m_current == '\0') {
            std::cout << "Unexpected char EOF!" << std::endl;
            std::exit(1);
        }
        buf.push_back(this->m_current);
        this->advance();
    }

    return std::make_shared<TokenString>(buf);
}




