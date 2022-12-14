#ifndef YOPE_TOKEN_H
#define YOPE_TOKEN_H

#include <string>

enum TokenType{
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_SYMBOL, // Question_mark, comma, single and double apostrophe
    TOKEN_NUMBER,
    TOKEN_STRING
};

enum TokenSymbolT{
    TOKEN_QUESTION_MARK,
    TOKEN_COMMA,
    TOKEN_SINGLE_APOSTROPHE,
    TOKEN_DOUBLE_APOSTROPHE
};

enum TokenKeywordT{
    TOKEN_KEYWORD_HAI = 0,
    TOKEN_KEYWORD_KTHX,
    TOKEN_KEYWORD_KTHXBYE,
    TOKEN_KEYWORD_I,
    TOKEN_KEYWORD_ME,
    TOKEN_KEYWORD_HAS,
    TOKEN_KEYWORD_A,
    TOKEN_KEYWORD_AN,
    TOKEN_KEYWORD_ITZ,
    TOKEN_KEYWORD_IZ,
    TOKEN_KEYWORD_LIEK,
    TOKEN_KEYWORD_CAN,
    TOKEN_KEYWORD_MKAY,
    TOKEN_KEYWORD_NOW,
    TOKEN_KEYWORD_NOOB,
    TOKEN_KEYWORD_TROOF,
    TOKEN_KEYWORD_WIN,
    TOKEN_KEYWORD_FAIL,
    TOKEN_KEYWORD_NUMBR,
    TOKEN_KEYWORD_NUMBAR,
    TOKEN_KEYWORD_YARN,
    TOKEN_KEYWORD_GIMMEH,
    TOKEN_KEYWORD_VISIBLE,
    TOKEN_KEYWORD_BOTH,
    TOKEN_KEYWORD_SAEM,
    TOKEN_KEYWORD_MAEK,
    TOKEN_KEYWORD_DIFFRINT,
    TOKEN_KEYWORD_BIGGR,
    TOKEN_KEYWORD_SMALLR,
    TOKEN_KEYWORD_SUM,
    TOKEN_KEYWORD_DIFF,
    TOKEN_KEYWORD_PRODUKT,
    TOKEN_KEYWORD_QUOSHUNT,
    TOKEN_KEYWORD_MOD,
    TOKEN_KEYWORD_SMOOSH,
    TOKEN_KEYWORD_SRS,
    TOKEN_KEYWORD_O,
    TOKEN_KEYWORD_RLY,
    TOKEN_KEYWORD_YA,
    TOKEN_KEYWORD_NO,
    TOKEN_KEYWORD_WAI,
    TOKEN_KEYWORD_OIC,
    TOKEN_KEYWORD_WTF,
    TOKEN_KEYWORD_OMG,
    TOKEN_KEYWORD_OMGWTF,
    TOKEN_KEYWORD_IM,
    TOKEN_KEYWORD_IN,
    TOKEN_KEYWORD_YR,
    TOKEN_KEYWORD_UPPIN,
    TOKEN_KEYWORD_NERFIN,
    TOKEN_KEYWORD_TIL,
    TOKEN_KEYWORD_WILE,
    TOKEN_KEYWORD_OUTTA,
    TOKEN_KEYWORD_FOUND,
    TOKEN_KEYWORD_GTFO,
    TOKEN_KEYWORD_IF,
    TOKEN_KEYWORD_U,
    TOKEN_KEYWORD_SAY,
    TOKEN_KEYWORD_SO,
    TOKEN_KEYWORD_BUKKIT,
    TOKEN_KEYWORD_HOW,
    TOKEN_KEYWORD_R,
    TOKEN_KEYWORD_Z,
    TOKEN_KEYWORD_IT,
    TOKEN_KEYWORD_MEBEE
};

class IToken{
public:
    TokenType m_type;

    explicit IToken(TokenType Type);

    virtual std::string to_string() = 0;

    virtual ~IToken() = default;
};

class TokenIdentifier: public IToken{
public:
    std::string m_value;

    TokenIdentifier(std::string& value);

    std::string to_string() override;
};

class TokenSymbol: public IToken{
public:
    TokenSymbolT m_symbol;

    explicit TokenSymbol(TokenSymbolT symbol);

    std::string to_string() override;
};

class TokenNumber: public IToken{
public:
    std::string m_number;

    TokenNumber(std::string& number);

    std::string to_string() override;
};

class TokenString: public IToken{
public:
    std::string m_string;

    explicit TokenString(std::string& string);

    std::string to_string() override;
};


class TokenKeyword: public IToken{
public:
    TokenKeywordT m_keyword;

    explicit TokenKeyword(TokenKeywordT keyword);

    std::string to_string() override;
};




#endif //YOPE_TOKEN_H
