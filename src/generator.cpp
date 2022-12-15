//
// Created by remy on 12/15/22.
//

#include "generator.h"

#include <utility>

Generator::Generator(std::vector<std::shared_ptr<INode>> nodes) : m_nodes(std::move(nodes)) {

}

std::string Generator::generate() {
    std::string buf;

    auto current = this->current();
    while (current != std::nullptr_t()) {
        switch (current->m_type) {
            case VALUE: {
                auto value_node = std::dynamic_pointer_cast<ValueNode>(current);
                switch (value_node->m_type) {
                    case STRING: {
                        int i = 0;
                        for (auto chr: value_node->m_value) {
                            buf.append("PUSH '");
                            buf.push_back(chr);
                            buf.append("'\n");
                            if (i != 0) {
                                buf.append("APPEND");
                            }
                            i += 1;
                        }
                    }
                        break;
                    default:; // Ignore
                }
            } break;
            case INCLUDE: {// Ignore

            } break;
            case INTERRUPT: {
                buf.append("INTERRUPT\n");
            } break;
            case VISIBLENode: {
                auto visible_node = std::dynamic_pointer_cast<VisibleNode>(current);
                int i = 0;
                for (auto chr: visible_node->m_value) {
                    buf.append("PUSH '");
                    buf.push_back(chr);
                    buf.append("'\n");
                    if (i != 0) {
                        buf.append("APPEND\n");
                    }
                    i += 1;
                }
                buf.append("OUT\n");
            } break;
            default:; // Ignore
        }
        this->advance();
        current = this->current();
    }

    return buf;
}

void Generator::advance() {
    this->m_index += 1;
}

std::shared_ptr<INode> Generator::current() {
    if (this->m_index >= this->m_nodes.size()) {
        return std::nullptr_t();
    } else {
        return this->m_nodes[this->m_index];
    }
}
