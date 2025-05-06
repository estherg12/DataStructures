#include "BST.hpp"

BST::BST()
{
    this->root = nullptr;
}

BST::~BST()
{
}


Node* BST::getRoot()
{
    return this->root;
}

int BST::getRootContent()
{
    return this->root->getNum();
}

bool BST::search(int sum, Node* n)
{
    bool result = false;
    if (n != nullptr)
    {
        if (n->getNum() == sum)
        {
            result = true;
        }
        else if (sum < n->getNum())
        {
            result = search(sum, n->getLeft());
        }
        else if (sum > n->getNum())
        {
            result = search(sum, n->getRight());
        }
    }
    return result;
}

void BST::insert(int value)
{
            if (root== nullptr)
            {
                 root = new Node(value, nullptr, nullptr);
            }
            else
            {
                 insertRec(value, root);
            }
}

void BST::insertRec(int sum, Node* n)
{
    
    if (n != nullptr)//we have a node
    {
        if (sum < n->getNum())
        {
            if (n->getLeft()== nullptr)
            {
                 n->setLeft(new Node(sum, nullptr, nullptr));
            }
            else
            {
                 insertRec(sum, n->getLeft());
            }
        }
        else 
        {
            if (sum > n->getNum())
            {
              if (n->getRight()== nullptr)
                {
                     n->setRight(new Node(sum, nullptr, nullptr));
                }
                else
                {
                     insertRec(sum, n->getRight());
                }
            }
            else
            {
                
            }
        }
    }
}

void BST::remove(int sum, Node* n)
{
    if (n != nullptr)
    {
        if (sum < n->getNum())
        {
            remove(sum, n->getLeft());
        }
        else if (sum > n->getNum())
        {
            remove(sum, n->getRight());
        }
        else if ((n->getLeft() == nullptr) && (n->getRight() == nullptr)) //is a leaf
        {
            delete(n);
        }
        else if (n->getLeft() == nullptr) //only right child
        {
            n=n->getRight();
        }
        else if (n->getRight() == nullptr)
        {
            n=n->getLeft();
        }
        else //has both children
            n->setNum(deletemin(n->getRight()));
    }
}

int BST::deletemin(Node* n)
{
    int result = 0;
    int aux = 0;
    if (n->getLeft() == nullptr)
    {
        aux = n->getNum();
        n = n->getRight();
        result = aux;
    }
    else
    {
        result = deletemin(n->getLeft());
    }
    return result;
}

bool BST::empty()
{
    return root == nullptr;
}


