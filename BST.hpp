#ifndef BST_HPP
#define BST_HPP
#include "Node.hpp"

class BST
{
    Node* root;
public:
    BST();
    ~BST();

    bool search(int x, Node* n);
    void insert(int x);
    void insertRec(int x, Node* n);
    void remove(int x, Node* n);
    int deletemin(Node* n);
    bool empty();
    node* getRoot();
    int getRootContent();
};

#endif // BST_HPP
