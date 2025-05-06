#include "ElementListOfList.hpp"

//Constructors
ElementListOfList::ElementListOfList()
{
    this->list = nullptr;
    this->next = nullptr;
}

ElementListOfList::ElementListOfList(ElementListOfList* e, List* l)
{
    this->list = l;
    this->next = e;
}

ElementListOfList::~ElementListOfList()
{
}

ElementListOfList* ElementListOfList::getNext()
{
    return this->next;
} 

List* ElementListOfList::getList()
{
    return this->list;
}

void ElementListOfList::setNext(ElementListOfList* n)
{
    this->next = n;
}

void ElementListOfList::setList(List* l)
{
    this->list = l;
}