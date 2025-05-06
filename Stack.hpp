#ifndef STACK_HPP
#define STACK_HPP
#include "ElementStack.hpp"

class Stack
{
    ElementStack* stackTop;
public:
    Stack();
    ~Stack();

    //Basic operations
    bool isEmpty();
    void push(char elem);
    char pop();
    char top();
    void makenull();
};

#endif // STACK_HPP
