#include "ElementQueue.hpp"

ElementQueue::ElementQueue(int content, ElementQueue* nextElem)
{
    this->content = content;
    this->nextElem = nextElem;
}

ElementQueue::ElementQueue()
{
    this->content = 0;
    this->nextElem = nullptr;
}

ElementQueue::~ElementQueue()
{
}

//Getters & Setters
ElementQueue* ElementQueue::getNext()
{
    return nextElem;
}

int ElementQueue::getContent()
{
    return content;
}

void ElementQueue::setNext(ElementQueue *p)
{
    nextElem=p;
}



