#include "List.hpp"

//Constructor
List::List()
{
    this->header = nullptr;
}

//Destructor
List::~List()
{
}

//Basic operations
void List::insertLast(int item)
{
    ElementList* element = new ElementList(item, nullptr);
    ElementList* temp = header; //initializes a temporary pointer pointing to the header
    
    if(header == nullptr)
    {
        insertFirst(item);
    }
    else
    {
        //Case 2: Last position
        while (temp->getNext())
        {//find the last element: temp->getNext() == nullptr
            temp=temp->getNext();
        }
        temp->setNext(element);
    }
}

void List::insertFirst(int item)
{
    ElementList* element = new ElementList(item, nullptr);
    element->setNext(header); //if the list is empty, the new and only element (header) will point to null
    header = element;
}

bool List::search(int item)
{
    bool result = false;
    ElementList* temp = this->header;
    while(temp != nullptr)
    {
        if(temp->getSum() == item)
        {
            result = true;
        }
        temp = temp->getNext();
    }
    return result;
}

ElementList* List::getHeader()
{
    return this->header;
}
