#include "ElementDoubly.hpp"

ElementDoubly::ElementDoubly(int c, ElementDoubly* nextEl, ElementDoubly* prevEl)
{
    this->content = c;
    this->nextElem = nextEl;
    this->prevElem = prevEl;
}

ElementDoubly::ElementDoubly()
{
    this->content = 0;
    this->nextElem = nullptr;
    this->prevElem = nullptr;
}

ElementDoubly::~ElementDoubly()
{
}

//Getters & Setters
int ElementDoubly::getContent()
{
    return content;
}

ElementDoubly* ElementDoubly::getNext()
{
    return nextElem;
}

void ElementDoubly::setNext(ElementDoubly *p)
{
    nextElem=p;
}

ElementDoubly* ElementDoubly::getPrev()
{
    return prevElem;
}

void ElementDoubly::setPrev(ElementDoubly *p)
{
    prevElem=p;
}




