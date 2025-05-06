#include "ElementList.hpp"

ElementList::ElementList()
{
    this->sum = 0;
    this->next = nullptr;
}

ElementList::~ElementList()
{
}

ElementList::ElementList(int s, ElementList* n)
{
    this->sum = s;
    this->next = n;
}

//Getters & Setters
int ElementList::getSum()
{
    return sum;
}

void ElementList::setSum(int s)
{
    this->sum = s;
}

ElementList* ElementList::getNext()
{
    return next;
}

void ElementList::setNext(ElementList *p)
{
    this->next=p;
}
