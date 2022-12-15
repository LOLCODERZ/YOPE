//
// Created by axelc on 07/12/2022.
//

#include "node.h"

#include <utility>
#include <sstream>

std::string op_type_to_string(OpType op) {
    switch (op) {
        case SUMOp:
            return "add";
        case MINUS:
            return "subtract";
        case MULTIPLY:
            return "multiply";
        case DIVIDE:
            return "divide";
        case MAX:
            return "max";
        case MIN:
            return "min";
        case MODOp:
            return "mod";
        case INCREMENT:
            return "increment";
        case DECREMENT:
            return "decrement";
        case AND:
            return "and";
        case OR:
            return "or";
        case XOR:
            return "xor";
        case NOT:
            return "not";
        case EQUAL:
            return "equal";
    }
    return "";
}

std::string value_type_to_string(ValueType value_type) {
    switch (value_type) {
        case NULLL: return "NULLL";
        case STRING: return "String";
        case INT: return "Int";
        case FLOAT: return "Float";
        case BOOL: return "Bool";
        case ARRAY: return "Array";
    }
    return "";
}

INode::INode(NodeType type) : m_type(type) {

}

BinOpNode::BinOpNode(std::shared_ptr<INode> lhs, OpType op, std::shared_ptr<INode> rhs) :
        INode(NodeType::BIN_OP),
        m_lhs{std::move(lhs)},
        m_op{op},
        m_rhs{std::move(rhs)} {}

std::string BinOpNode::to_string() {
    std::string buffer;
    buffer.append("BinOP:");
    buffer.append("\n\tlhs: ");
    std::istringstream f(this->m_lhs->to_string());
    std::string line;
    int i = 0;
    while (std::getline(f, line)) {
        if (i != 0) {
            buffer.append("\n\t");
        }
        buffer.append(line);
        i += 1;
    }
    buffer.append("\n\top: ");
    buffer.append(op_type_to_string(this->m_op));
    buffer.append("\n\trhs: ");
    f = std::istringstream(this->m_rhs->to_string());
    i = 0;
    while (std::getline(f, line)) {
        if (i != 0) {
            buffer.append("\n\t");
        }
        buffer.append(line);
        i += 1;
    }
    return buffer;
}

UnOpNode::UnOpNode(std::shared_ptr<INode> lhs, OpType op) :
        INode(NodeType::UN_OP),
        m_lhs{std::move(lhs)},
        m_op{op} {}

std::string UnOpNode::to_string() {
    std::string buffer;
    buffer.append("BinOP:");
    buffer.append("\n\top: ");
    buffer.append(op_type_to_string(this->m_op));
    buffer.append("\n\tvalue: ");
    std::istringstream f(this->m_lhs->to_string());
    std::string line;
    int i = 0;
    while (std::getline(f, line)) {
        if (i != 0) {
            buffer.append("\n\t");
        }
        buffer.append(line);
        i += 1;
    }
    return buffer;
}

FunDefNode::FunDefNode(std::string &name, ValueType return_type, std::vector<std::shared_ptr<INode>> params,
                       std::shared_ptr<INode> body) :
        INode(NodeType::FUN_DEF),
        m_name{name},
        m_return_type{return_type},
        m_params{std::move(params)},
        m_body{std::move(body)} {

}

std::string FunDefNode::to_string() {
    std::string buf;
    buf.append("Function Definition:");
    buf.append("\n\tname: ");
    buf.append(this->m_name);
    buf.append("\n\treturn type: ");
    buf.append(value_type_to_string(this->m_return_type));
    buf.append("\n\tparams:");
    for (const auto& param : this->m_params) {
        std::istringstream f(param->to_string());
        std::string line;
        while (std::getline(f, line)) {
            buf.append("\n\t\t");
            buf.append(line);
        }
    }
    buf.append("\n\tbody:");
    for (const auto& node : this->m_body) {
        std::istringstream f(node->to_string());
        std::string line;
        while (std::getline(f, line)) {
            buf.append("\n\t\t");
            buf.append(line);
        }
    }
    return buf;
}

FunCallNode::FunCallNode(std::string &name, std::vector<std::shared_ptr<INode>> params) :
        INode{NodeType::FUN_CALL},
        m_name{name},
        m_params{std::move(params)} {

}

std::string FunCallNode::to_string() {
    std::string buf;
    buf.append("Function Call:");
    buf.append("\n\tname: ");
    buf.append(this->m_name);
    buf.append("\n\tparams: ");
    for (const auto& param : this->m_params) {
        std::istringstream f(param->to_string());
        std::string line;
        while (std::getline(f, line)) {
            buf.append("\n\t\t");
            buf.append(line);
        }
    }
    return buf;
}

VarDefNode::VarDefNode(ValueType type, std::string &name, std::shared_ptr<INode> value) :
        INode{NodeType::VAR_DEF},
        m_type{type},
        m_name{name},
        m_value{std::move(value)} {

}

std::string VarDefNode::to_string() {
    std::string buf;
    buf.append("Variable Definition:");
    buf.append("\n\ttype: ");
    buf.append(value_type_to_string(this->m_type));
    buf.append("\n\tname: ");
    buf.append(this->m_name);
    buf.append("\n\tvalue: ");
    std::istringstream f(this->m_value->to_string());
    std::string line;
    int i = 0;
    while (std::getline(f, line)) {
        if (i != 0) {
            buf.append("\n\t");
        }
        buf.append(line);
        i += 1;
    }
    return buf;
}

VarCallNode::VarCallNode(std::string &name) :
        INode{NodeType::VAR_CALL},
        m_name{name} {

}

std::string VarCallNode::to_string() {
    std::string buf;
    buf.append("Variable Definition: ");
    buf.append("\n\tname: ");
    buf.append(this->m_name);
    return buf;
}

VarAssNode::VarAssNode(std::string &name, std::shared_ptr<INode> new_value) :
        INode{NodeType::VAR_ASS},
        m_name{name},
        m_new_value{std::move(new_value)} {

}

std::string VarAssNode::to_string() {
    std::string buf;
    buf.append("Variable Assignment:");
    buf.append("\n\tname: ");
    buf.append(this->m_name);
    buf.append("\n\tvalue: ");
    buf.append(this->m_new_value->to_string());
    return buf;
}

ForLoopNode::ForLoopNode() :
        INode{NodeType::FOR_LOOP} {
    // TODO: Incomplete
}

std::string ForLoopNode::to_string() {
    // TODO: Incomplete
    return "???";
}

WhileLoopNode::WhileLoopNode(std::shared_ptr<INode> condition, std::vector<std::shared_ptr<INode>> m_body) :
        INode{NodeType::WHILE_LOOP},
        m_condition{std::move(condition)},
        m_body{std::move(m_body)} {

}

std::string WhileLoopNode::to_string() {
    std::string buf;
    buf.append("While Loop:");
    buf.append("\n\tcondition: ");
    std::istringstream f(this->m_condition->to_string());
    std::string line;
    int i = 0;
    while (std::getline(f, line)) {
        if (i != 0) {
            buf.append("\n\t");
        }
        buf.append(line);
        i += 1;
    }
    buf.append("\n\tbody: ");
    for (const auto& node : this->m_body) {
        f = std::istringstream(node->to_string());
        while (std::getline(f, line)) {
            buf.append("\n\t\t");
            buf.append(line);
        }
    }
    return buf;
}

IncludeNode::IncludeNode(std::string &path) :
        INode{NodeType::INCLUDE},
        m_path{path} {

}

std::string IncludeNode::to_string() {
    std::string buf;
    buf.append("Include:");
    buf.append("\n\tpath: ");
    buf.append(this->m_path);
    return buf;
}

BreakNode::BreakNode() :
        INode{NodeType::BREAK} {

}

std::string BreakNode::to_string() {
    return "Break";
}

ReturnNode::ReturnNode(std::shared_ptr<INode> value) :
        INode{NodeType::RETURN},
        m_value{std::move(value)} {

}

std::string ReturnNode::to_string() {
    std::string buf;
    buf.append("Return:");
    buf.append("\n\tvalue: ");
    std::istringstream f(this->m_value->to_string());
    std::string line;
    int i = 0;
    while (std::getline(f, line)) {
        if (i != 0) {
            buf.append("\n\t");
        }
        buf.append(line);
        i += 1;
    }
    return buf;
}

InterruptNode::InterruptNode() :
        INode{NodeType::INTERRUPT} {

}


std::string InterruptNode::to_string() {
    return "Interrupt";
}

SwitchNode::SwitchNode(std::shared_ptr<INode> condition, std::vector<std::shared_ptr<INode>> body) :
        INode{NodeType::SWITCH},
        m_condition{std::move(condition)},
        m_body{std::move(body)} {

}

std::string SwitchNode::to_string() {
    // TODO: Not sure (for now ignored)
    return "???";
}

ValueNode::ValueNode(ValueType type, std::string &value) :
        INode{NodeType::VALUE},
        m_type{type},
        m_value{value} {

}

std::string ValueNode::to_string() {
    std::string buf;
    buf.append("Value: ");
    buf.append("\n\ttype: ");
    buf.append(value_type_to_string(this->m_type));
    buf.append("\n\tvalue: ");
    buf.append(this->m_value);
    return buf;
}

VisibleNode::VisibleNode(std::string value) : INode(NodeType::VISIBLENode), m_value(std::move(value)) {

}

std::string VisibleNode::to_string() {
    std::string buf;
    buf.append("Visible:");
    buf.append("\n\tvalue: ");
    buf.append(this->m_value);
    return buf;
}
