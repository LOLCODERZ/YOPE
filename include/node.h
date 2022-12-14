//
// Created by axelc on 07/12/2022.
//

#ifndef YOPE_NODE_H
#define YOPE_NODE_H
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

};

class INode {
public:
    NodeType m_type;
    INode(NodeType type);
    std::string to_string;
};

class BinOpNode : public INode {
public:
    INode lhs;
    OpType op;
    INode rhs;
};

class node {

};


#endif //YOPE_NODE_H
