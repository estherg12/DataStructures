#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    int num;
    Node* rchild;
    Node* lchild;
public:
    Node();
    Node(int n, Node* r, Node* l);
    ~Node();

    int getNum();
    void setNum(int n);
    
    Node* getRight();
    void setRight(Node* r);
    
    Node* getLeft();
    void setLeft(Node* l);
};

#endif // NODE_HPP
