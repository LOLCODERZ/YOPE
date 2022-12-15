//
// Created by juejue on 12/7/2022.
//

#ifndef YOPE_LEXER_H
#define YOPE_LEXER_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "token.h"
#include <regex>

enum TokenKeywordS{
    HAI,
    KTHX,
    KTHXBYE,
    I,
    ME,
    HAS,
    A,
    AN,
    ITZ,
    IZ,
    LIEK,
    CAN,
    MKAY,
    NOW,
    NOOB,
    TROOF,
    WIN,
    FAIL,
    NUMBR,
    NUMBAR,
    YARN,
    GIMMEH,
    VISIBLE,
    BOTH,
    SAEM,
    MAEK,
    DIFFRINT,
    BIGGR,
    SMALLR,
    SUM,
    DIFF,
    PRODUKT,
    QUOSHUNT,
    MOD,
    SMOOSH,
    SRS,
    O,
    RLY,
    YA,
    NO,
    WAI,
    OIC,
    WTF,
    OMG,
    OMGWTF,
    IM,
    IN,
    YR,
    UPPIN,
    NERFIN,
    TIL,
    WILE,
    OUTTA,
    FOUND,
    GTFO,
    IF,
    U,
    SAY,
    SO,
    BUKKIT,
    HOW,
    R,
    Z,
    IT,
    MEBEE
};

class Lexer {
private:
    std::string m_src;
    uintptr_t m_index;
    char m_current;

    void advance();

    std::shared_ptr<IToken> make_number();
    std::shared_ptr<IToken> make_identifier();
    std::shared_ptr<IToken> make_string();

public:
    std::map<std::string, TokenKeywordS> MapKeywords;
    void MapKeywords_initialize();

    Lexer(std::string src);

    std::vector<std::shared_ptr<IToken>> tokenize();

    bool Keyword_check();

};


#endif //YOPE_LEXER_H
