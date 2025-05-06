#include "ElementOrder.hpp"

ElementOrder::ElementOrder()
{
    this->sum = 0;
    this->next = nullptr;
}

ElementOrder::~ElementOrder()
{
}

ElementOrder::ElementOrder(int s, ElementOrder* n)
{
    this->sum = s;
    this->next = n;
}

//Getters & Setters
int ElementOrder::getSum()
{
    return sum;
}

void ElementOrder::setSum(int s)
{
    this->sum = s;
}

ElementOrder* ElementOrder::getNext()
{
    return next;
}

void ElementOrder::setNext(ElementOrder *p)
{
    this->next=p;
}
