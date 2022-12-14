//
// Created by axelc on 07/12/2022.
//

#ifndef YOPE_NODE_H
#define YOPE_NODE_H

#include <string>
#include <memory>
#include <vector>

enum NodeType {
    VALUE, //store value type
    BIN_OP,
    UN_OP,
    IF, // this includes else and else if's in a vector
    FUN_DEF,
    FUN_CALL,
    VAR_DEF,
    VAR_ASS,
    VAR_CALL,
    FOR_LOOP,
    WHILE_LOOP,
    INCLUDE,
    BREAK,
    RETURN,
    INTERRUPT,
    SWITCH
};

enum OpType {
    SUM,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MAX,
    MIN,
    MOD,
    INCREMENT,
    DECREMENT,
    AND,
    OR,
    XOR,
    NOT,
    EQUAL
};

enum ValueType {
    NULLL,
    STRING,
    INT,
    FLOAT,
    BOOL,
    ARRAY
};

class INode {
public:
    NodeType m_type;
    INode(NodeType type);
    virtual std::string to_string() = 0;
};

class BinOpNode : public INode {
public:
    BinOpNode(std::shared_ptr<INode>  lhs, OpType op, std::shared_ptr<INode>  rhs);
    std::string to_string() override;

    std::shared_ptr<INode> m_lhs;
    OpType m_op;
    std::shared_ptr<INode> m_rhs;
};

class UnOpNode : public INode {
public:
    UnOpNode(std::shared_ptr<INode> lhs, OpType op);
    std::string to_string() override;

    std::shared_ptr<INode> m_lhs;
    OpType m_op;
};

class IfNode : public INode {
public:
    IfNode(std::shared_ptr<INode> );
    std::string to_string() override;

    std::shared_ptr<INode> m_condition;
};

class FunDefNode : public INode {
public:
    FunDefNode(std::string name, ValueType return_type, std::vector<std::shared_ptr<INode>> params, std::shared_ptr<INode> body);
    std::string to_string() override;

    std::string m_name;
    ValueType m_return_type;
    std::vector<std::shared_ptr<INode>> m_params;
    std::vector<std::shared_ptr<INode>> m_body;
};

class FunCallNode : public INode {
public:
    FunCallNode(std::string name, std::vector<std::shared_ptr<INode>> params);
    std::string to_string() override;

    std::string m_name;
    std::vector<std::shared_ptr<INode>> m_params;
};

class VarDefNode : public INode {
public:
    VarDefNode(ValueType type, std::string name, std::shared_ptr<INode> value);
    std::string to_string() override;

    ValueType m_type;
    std::string m_name;
    std::shared_ptr<INode> m_value;
};

class VarCallNode : public INode {
public:
    VarCallNode();
    std::string to_string() override;

    std::string m_name;
};

class VarAssNode : public INode {
    VarAssNode();
    std::string to_string() override;

    std::string m_name;
    std::shared_ptr<INode> m_new_value;
};

class ForLoopNode : public INode {
    ForLoopNode();
    std::string to_string() override;

};

class WhileLoopNode : public INode {
    WhileLoopNode();
    std::string to_string() override;

};

class IncludeNode : public INode {
    IncludeNode();
    std::string to_string() override;

    std::string m_path;
};

class BreakNode : public INode {
    BreakNode();
    std::string to_string() override;
};

class ReturnNode : public INode {
    ReturnNode();
    std::string to_string() override;

    ValueType m_return_type;
};

class InterruptNode : public INode {
    InterruptNode();
    std::string to_string() override;
};

class SwitchNode : public INode {
    SwitchNode();
    std::string to_string() override;
};


class node {

};

#endif //YOPE_NODE_H
