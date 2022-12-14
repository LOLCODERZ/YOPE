//
// Created by axelc on 07/12/2022.
//

#include "node.h"

BinOpNode::BinOpNode(std::shared_ptr<INode> lhs, OpType op, std::shared_ptr<INode> rhs):
INode(NodeType::BIN_OP),
m_lhs{lhs},
m_op{op},
m_rhs{rhs}
{

}

std::string BinOpNode::to_string() {
    return std::string();
}

INode::INode(NodeType type): m_type(type) {

}
