//
// Created by remy on 12/15/22.
//

#ifndef YOPE_GENERATOR_H
#define YOPE_GENERATOR_H

#include "node.h"

class Generator {
public:
    std::vector<std::shared_ptr<INode>> m_nodes;
    uintptr_t m_index = 0;

    Generator(std::vector<std::shared_ptr<INode>> nodes);
    std::string generate();
private:
    void advance();
    std::shared_ptr<INode> current();
};

#endif //YOPE_GENERATOR_H
