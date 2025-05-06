#include "Queue.hpp"

//Constructor
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

//Destructor
Queue::~Queue()
{
    makenull();
}

//Basic operations
void Queue::enqueue(int elem)
{
    ElementQueue* element = new ElementQueue(elem, nullptr);
    if (isEmpty())
        {
        //ElementQueue* element = new ElementQueue(elem, front);
        front = element;
        rear = element;
        //rear->setNext(nullptr);
    }
    else
        {
        //rear->getNext();
        //ElementQueue* element = new ElementQueue(elem, rear);
        rear->setNext(element);
        rear=element;
        
    }
    /*
    ElementQueue* element = new ElementQueue(elem, rear);
    rear = element;*/
}

int Queue::dequeue()
{
    if (isEmpty())
    { 
        return -1;
    }
    else {
        ElementQueue* auxc = front; //aux is a pointer
        int auxe = front->getContent();
        front=front->getNext();
        
        delete(auxc);
        
        if (front == nullptr){//the queue is now empty
            rear = nullptr;
        }
        return auxe;
    }
}

int Queue::getFront()
{
    if (isEmpty())
    { //so that the top returns smt when the stack is empty
        return -1;
    }else
        {
        return front->getContent();
        }
}

int Queue::getRear()
{
    if (isEmpty())
    { //so that the top returns smt when the stack is empty
        return -1;
    }
    else
        {
        return rear->getContent();
        }
}

void Queue::makenull()
{
    while (front != nullptr) 
    {
        dequeue();
    }
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

