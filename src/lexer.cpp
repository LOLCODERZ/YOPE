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

    MapKeywords_initialize();

    while (this->m_current != '\0') {

        if (this->m_current == ' ' || this->m_current == '\t' || this->m_current == '\r' || this->m_current == '\n') {
            this->advance();
            continue;
        } else if (std::isdigit(this->m_current)) {
            tokens.push_back(this->make_number());
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

            std::string str {this->m_current};

            switch (MapKeywords[str]) {
                case HAI :
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_HAI));
                    break;
                case KTHX :
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_KTHX));
                    break;
                case KTHXBYE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_KTHXBYE));
                    break;
                case I:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_I));
                    break;
                case ME:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_ME));
                    break;
                case HAS:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_HAS));
                    break;
                case A:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_A));
                    break;
                case AN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_AN));
                    break;
                case ITZ:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_ITZ));
                    break;
                case IZ:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IZ));
                    break;
                case LIEK:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_LIEK));
                    break;
                case CAN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_CAN));
                    break;
                case MKAY:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MKAY));
                    break;
                case NOW:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NOW));
                    break;
                case NOOB:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NOOB));
                    break;
                case TROOF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_TROOF));
                    break;
                case WIN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WIN));
                    break;
                case FAIL:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_FAIL));
                    break;
                case NUMBR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NUMBR));
                    break;
                case NUMBAR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NUMBAR));
                    break;
                case YARN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_YARN));
                    break;
                case GIMMEH:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_GIMMEH));
                    break;
                case VISIBLE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_VISIBLE));
                    break;
                case BOTH:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_BOTH));
                    break;
                case SAEM:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SAEM));
                    break;
                case MAEK:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MAEK));
                    break;
                case DIFFRINT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_DIFFRINT));
                    break;
                case BIGGR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_BIGGR));
                    break;
                case SMALLR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SMALLR));
                    break;
                case SUM:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SUM));
                    break;
                case DIFF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_DIFF));
                    break;
                case PRODUKT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_PRODUKT));
                    break;
                case QUOSHUNT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_QUOSHUNT));
                    break;
                case MOD:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MOD));
                    break;
                case SMOOSH:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SMOOSH));
                    break;
                case SRS:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SRS));
                    break;
                case O:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_O));
                    break;
                case RLY:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_RLY));
                    break;
                case YA:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_YA));
                    break;
                case NO:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NO));
                    break;
                case WAI:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WAI));
                    break;
                case OIC:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OIC));
                    break;
                case WTF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WTF));
                    break;
                case OMG:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OMG));
                    break;
                case OMGWTF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OMGWTF));
                    break;
                case IM:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IM));
                    break;
                case IN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IN));
                    break;
                case YR:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_YR));
                    break;
                case UPPIN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_UPPIN));
                    break;
                case NERFIN:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NERFIN));
                    break;
                case TIL:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_TIL));
                    break;
                case WILE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_WILE));
                    break;
                case OUTTA:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_OUTTA));
                    break;
                case FOUND:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_FOUND));
                    break;
                case GTFO:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_GTFO));
                    break;
                case IF:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IF));
                    break;
                case U:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_U));
                    break;
                case SAY:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SAY));
                    break;
                case SO:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_SO));
                    break;
                case BUKKIT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_BUKKIT));
                    break;
                case HOW:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_NOW));
                    break;
                case R:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_R));
                    break;
                case Z:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_Z));
                    break;
                case IT:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_IT));
                    break;
                case MEBEE:
                    tokens.push_back(std::make_shared<TokenKeyword>(TokenKeywordT::TOKEN_KEYWORD_MEBEE));
                    break;
                default:
                    std::cout << "Unexpected char '" << this->m_current << "'!" << std::endl;
                    std::exit(1);
            }
        } else {
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

std::shared_ptr<IToken> Lexer::make_number() {
    auto buf = std::string();

    while (std::isdigit(this->m_current) || this->m_current == '.') {
        buf.push_back(this->m_current);
        this->advance();
    }

    return std::make_shared<TokenNumber>(buf);
}

std::shared_ptr<IToken> Lexer::make_identifier() {
    auto buf = std::string();

    while (isalnum(this->m_current) || this->m_current == '_') {
        buf.push_back(this->m_current);
        this->advance();
    }

    if (buf == "HAI") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_HAI);
    } else if (buf == "KTHX") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_KTHX);
    } else if (buf == "KTHXBYE") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_KTHXBYE);
    } else if (buf == "I") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_I);
    } else if (buf == "ME") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_ME);
    } else if (buf == "HAS") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_HAS);
    } else if (buf == "A") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_A);
    } else if (buf == "AN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_AN);
    } else if (buf == "ITZ") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_ITZ);
    } else if (buf == "IZ") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_IZ);
    } else if (buf == "LIEK") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_LIEK);
    } else if (buf == "CAN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_CAN);
    } else if (buf == "MKAY") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_MKAY);
    } else if (buf == "NOW") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_NOW);
    } else if (buf == "NOOB") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_NOOB);
    } else if (buf == "TROOF") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_TROOF);
    } else if (buf == "WIN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_WIN);
    } else if (buf == "FAIL") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_FAIL);
    } else if (buf == "NUMR") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_NUMBR);
    } else if (buf == "NUMBAR") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_NUMBAR);
    } else if (buf == "YARN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_YARN);
    } else if (buf == "GIMMEH") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_GIMMEH);
    } else if (buf == "VISIBLE") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_VISIBLE);
    } else if (buf == "BOTH") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_BOTH);
    } else if (buf == "SAEM") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SAEM);
    } else if (buf == "MAEK") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_MAEK);
    } else if (buf == "DIFFRINT") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_DIFFRINT);
    } else if (buf == "BIGGR") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_BIGGR);
    } else if (buf == "SMALLR") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SMALLR);
    } else if (buf == "SUM") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SUM);
    } else if (buf == "DIFF") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_DIFF);
    } else if (buf == "PRODUKT") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_PRODUKT);
    } else if (buf == "QUOSHUNT") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_QUOSHUNT);
    } else if (buf == "MOD") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_MOD);
    } else if (buf == "SMOOSH") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SMOOSH);
    } else if (buf == "SRS") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SRS);
    } else if (buf == "O") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_O);
    } else if (buf == "RLY") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_RLY);
    } else if (buf == "YA") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_YA);
    } else if (buf == "NO") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_NO);
    } else if (buf == "WAI") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_WAI);
    } else if (buf == "OIC") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_OIC);
    } else if (buf == "WTF") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_WTF);
    } else if (buf == "OMG") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_OMG);
    } else if (buf == "OMGWTF") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_OMGWTF);
    } else if (buf == "IM") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_IM);
    } else if (buf == "IN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_IN);
    } else if (buf == "YR") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_YR);
    } else if (buf == "UPPIN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_UPPIN);
    } else if (buf == "NERFIN") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_NERFIN);
    } else if (buf == "TIL") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_TIL);
    } else if (buf == "WILE") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_WILE);
    } else if (buf == "OUTTA") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_OUTTA);
    } else if (buf == "FOUND") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_FOUND);
    } else if (buf == "GTFO") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_GTFO);
    } else if (buf == "IF") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_IF);
    } else if (buf == "U") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_U);
    } else if (buf == "SAY") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SAY);
    } else if (buf == "SO") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_SO);
    } else if (buf == "BUKKIT") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_BUKKIT);
    } else if (buf == "HOW") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_HOW);
    } else if (buf == "R") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_R);
    } else if (buf == "Z") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_Z);
    } else if (buf == "MEBEE") {
        return std::make_shared<TokenKeyword>(TOKEN_KEYWORD_MEBEE);
    } else {
        return std::make_shared<TokenIdentifier>(buf);
    }

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
    this->advance();

    return std::make_shared<TokenString>(buf);
}




