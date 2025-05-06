#include "Node.hpp"

Node::Node()
{
    this->num = 0;
    this->rchild = nullptr;
    this->lchild = nullptr;
}

Node::Node(int n, Node* l, Node* r)
{
    this->num = n;
    this->rchild = r;
    this->lchild = l;
}

Node::~Node()
{
}

int Node::getNum()
{
    return this->num;
}

void Node::setNum(int n)
{
    this->num = n;
}

Node* Node::getRight()
{
    return this->rchild;
}

void Node::setRight(Node* r)
{
    this->rchild = r;
}

Node* Node::getLeft()
{
    return this->lchild;
}

void Node::setLeft(Node* l)
{
    this->lchild = l;
}
