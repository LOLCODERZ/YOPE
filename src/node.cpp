//
// Created by axelc on 07/12/2022.
//

#include "node.h"

#include <utility>

INode::INode(NodeType type): m_type(type) {

}

BinOpNode::BinOpNode(std::shared_ptr<INode> lhs, OpType op, std::shared_ptr<INode> rhs):
INode(NodeType::BIN_OP),
m_lhs{std::move(lhs)},
m_op{op},
m_rhs{std::move(rhs)}
{}

std::string BinOpNode::to_string() {
    return std::string();
}

UnOpNode::UnOpNode(std::shared_ptr<INode> lhs, OpType op):
INode(NodeType::UN_OP),
m_lhs{std::move(lhs)},
m_op{op}
{}

std::string UnOpNode::to_string() {
    return std::string();
}

FunDefNode::FunDefNode(std::string& name, ValueType return_type, std::vector<std::shared_ptr<INode>> params, std::shared_ptr<INode> body):
INode(NodeType::FUN_DEF),
m_name{name},
m_return_type{return_type},
m_params{std::move(params)},
m_body{body}
{

}

std::string FunDefNode::to_string() {
    return std::string();
}

FunCallNode::FunCallNode(std::string& name, std::vector<std::shared_ptr<INode>> params):
INode{NodeType::FUN_CALL},
m_name{name},
m_params{std::move(params)}
{

}

std::string FunCallNode::to_string() {
    return std::string();
}

VarDefNode::VarDefNode(ValueType type, std::string& name, std::shared_ptr<INode> value):
INode{NodeType::VAR_DEF},
m_type{type},
m_name{name},
m_value{value}
{

}

std::string VarDefNode::to_string() {
    return std::string();
}

VarCallNode::VarCallNode(std::string &name) :
INode{NodeType::VAR_CALL},
m_name{name}
{

}

std::string VarCallNode::to_string() {
    return std::string();
}

VarAssNode::VarAssNode(std::string &name, std::shared_ptr<INode> new_vaule):
INode{NodeType::VAR_ASS},
m_name{name},
m_new_value{std::move(new_vaule)}
{

}

std::string VarAssNode::to_string() {
    return std::string();
}

ForLoopNode::ForLoopNode():
INode{NodeType::FOR_LOOP}
{

}

std::string ForLoopNode::to_string() {
    return std::string();
}

WhileLoopNode::WhileLoopNode(std::shared_ptr<INode> condition, std::vector<std::shared_ptr<INode>> m_body) :
INode{NodeType::WHILE_LOOP},
m_condition{std::move(condition)},
m_body{std::move(m_body)}
{

}

std::string WhileLoopNode::to_string() {
    return std::string();
}

IncludeNode::IncludeNode(std::string& path):
INode{NodeType::INCLUDE},
m_path{path}
{

}

std::string IncludeNode::to_string() {
    return std::string();
}

BreakNode::BreakNode():
INode{NodeType::BREAK}
{

}

std::string BreakNode::to_string() {
    return std::string();
}

ReturnNode::ReturnNode():
INode{NodeType::RETURN}
{

}

std::string ReturnNode::to_string() {
    return std::string();
}

InterruptNode::InterruptNode():
INode{NodeType::INTERRUPT}
{

}



std::string InterruptNode::to_string() {
    return std::string();
}

SwitchNode::SwitchNode(std::shared_ptr<INode> condition, std::vector<std::shared_ptr<INode>> body) :
INode{NodeType::SWITCH},
m_condition{std::move(condition)},
m_body{std::move(body)}
{

}

std::string SwitchNode::to_string() {
    return std::string();
}

ValueNode::ValueNode(ValueType type, std::string& value):
INode{NodeType::VALUE},
m_type{type},
m_value{value}
{

}

std::string ValueNode::to_string() {
    return std::string();
}
