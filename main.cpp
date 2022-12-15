#include "lexer.h"
#include "parser.h"
#include "generator.h"
#include <iostream>

int main() {
    std::string src = "HAI 1.2\n"
                      "  CAN HAS STDIO?\n"
                      "  VISIBLE \"HAI_WORLD!!!1!\"\n"
                      "KTHXBYE";

    Lexer lexer { src };
    auto tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        std::cout << token->to_string() << std::endl;
    }

    std::cout << std::endl;

    Parser parser { tokens };
    auto ast = parser.parse();

    for (const auto& node : ast) {
        std::cout << node->to_string() << std::endl;
    }

    std::cout << std::endl;
    Generator generator { ast };
    std::cout << generator.generate() << std::endl;

    return 0;
}
