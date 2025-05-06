#include "OrderList.hpp"

OrderList::OrderList()
{
    this->header = nullptr;
}

OrderList::~OrderList()
{
}

//Basic operations
void OrderList::insert(int item)
{
    ElmentOrder* element = new ElmentOrder(nullptr, item);
    
    //Case 1: If list is empty
    if(header==nullptr)
    {
        insertFirst(item);
    }
    else
    {
        //Case 2: at beginning
        if(item < header->getSum())
        {
            element->setNext(header);
            header = element;
        }
        else
        {
            //Find the position in which the new element should be inserted
            ElmentOrder* temp = header;
            ElmentOrder* tempN = temp->getNext();
            bool found = false;
            while((tempN != nullptr) && (found == false))
            {
                if ((temp->getSum() < item)&&(item < tempN->getSum()))
                {
                    //if the new element is bigger than the temporal element and it's next, the position is in the middle
                    found = true;
                }
                else
                {
                    //go to the next element
                    temp = tempN;
                    tempN = temp->getNext();
                }
            }
            //position founded or last
            temp->setNext(element);
            element->setNext(tempN); //in case it got to the last, tempN will be nullptr
        }
    }
}

void OrderList::insertLast(int item)
{
    ElementOrder* element = new ElementOrder(item, nullptr);
    ElementOrder* temp = header; //initializes a temporary pointer pointing to the header
    
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

void OrderList::insertFirst(int item)
{
    ElementOrder* element = new ElementOrder(item, nullptr);
    element->setNext(header); //if the list is empty, the new and only element (header) will point to null
    header = element;
}

bool OrderList::search(int item)
{
    bool result = false;
    ElementOrder* temp = this->header;
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

ElementOrder* OrderList::getHeader()
{
    return this->header;
}


