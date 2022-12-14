//
// Created by axelc on 07/12/2022.
//

#include "node.h"

INode::INode(NodeType type): m_type(type) {

}

BinOpNode::BinOpNode(std::shared_ptr<INode> lhs, OpType op, std::shared_ptr<INode> rhs):
INode(NodeType::BIN_OP),
m_lhs{lhs},
m_op{op},
m_rhs{rhs}
{}

std::string BinOpNode::to_string() {
    return std::string();
}

UnOpNode::UnOpNode(std::shared_ptr<INode> lhs, OpType op):
INode(NodeType::UN_OP),
m_lhs{lhs},
m_op{op}
{}

std::string UnOpNode::to_string() {
    return std::string();
}

FunDefNode::FunDefNode(std::string name, ValueType return_type, std::vector<std::shared_ptr<INode>> params, std::shared_ptr<INode> body):
INode(NodeType::FUN_DEF),
m_name{name},
m_return_type{return_type},
m_params{params},
m_body{body}
{

}

std::string FunDefNode::to_string() {
    return std::string();
}

FunCallNode::FunCallNode(std::string name, std::vector<std::shared_ptr<INode>> params):
INode{NodeType::FUN_CALL},
m_name{name},
m_params{params}
{

}

std::string FunCallNode::to_string() {
    return std::string();
}

VarDefNode::VarDefNode(ValueType type, std::string name, std::shared_ptr<INode> value):
INode{NodeType::VAR_DEF},
m_name{name},
m_value{value}
{

}

std::string VarDefNode::to_string() {
    return std::string();
}
