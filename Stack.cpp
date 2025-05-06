#include "Stack.hpp"

//Constructor
Stack::Stack()
{
    stackTop = nullptr; //initialize top to null
}

//Destructor
Stack::~Stack()
{
}

//Basic Operations
char Stack::pop()
{
    char v = ' ';
    if(!isEmpty())
    {
        ElementStack* aux;//pointer
        aux=stackTop;
        stackTop=stackTop->getNext(); //we change the top to the next pointer
        v=aux->getContent();//store the value in the next element
        delete (aux);
    }
    return v;
}

void Stack::push(char elem) //elem is the content of the data we want to store
{
    ElementStack* element = new ElementStack(elem, nullptr);
    if(!(isEmpty()))
    {
        element->setNext(stackTop);
    }
    stackTop = element;
}

bool Stack::isEmpty() //returns true if stack is empty, false otherwise
{
    return stackTop == nullptr;
}

void Stack::makenull()
{
    while (stackTop != nullptr) 
    {
        pop();
    }
}

char Stack::top()
{
    char result = ' ';
    if (!isEmpty())
    { //so that the top returns smt when the stack is empty
        result = stackTop->getContent();;
    }
    return result;
}
