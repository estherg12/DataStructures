#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "ElementQueue.hpp"

class Queue
{
    ElementQueue* front;
    ElementQueue* rear;
public:
    Queue();
    ~Queue();
    
    //Basic operations
    void enqueue(int elem);
    int dequeue();
    int getFront();
    int getRear();
    void makenull();
    bool isEmpty();
};

#endif // QUEUE_HPP
