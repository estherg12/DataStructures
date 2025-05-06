#include "ListOfList.hpp"

ListOfList::ListOfList()
{
    this->header = nullptr;
}

ListOfList::~ListOfList()
{
    makenull();
}

void ListOfList::insert(List* l, ElementListOfList* n)
{
    ElementListOfList* element = new ElementListOfList(nullptr, l);
    
    //Case 1: If list is empty
    if(header==nullptr)
    {
        insertFirst(l);
    }
    else
    {
        if(n != nullptr)
        {
            n->setNext(element);
        }
    }
}

void ListOfList::insertFirst(List* l)
{
    ElementListOfList* element = new ElementListOfList(nullptr, l);
    element->setNext(header);
    header = element;
}

void ListOfList::insertLast(List* l)
{
    if(empty())//Case 0: empty
    {
        insertFirst(l);
    }
    else
    {
        ElementListOfList* element = new ElementListOfList(nullptr, l);
        ElementListOfList* temp = header;
        
        //Case 1: only 1 element
        if(header->getNext()==nullptr)
        {
            header->setNext(element);
        }
        else
        {
            //Case 2: Last position
            while (temp->getNext())//while next(temp)!=nullptr
            {//find the last element: temp->getNext()==nullptr
                temp=temp->getNext();
            }
            temp->setNext(element);
        }
    }
}

void ListOfList::deleteP(ElementListOfList* p)
{
    //Case 1: null pointer exception
    if(p!=nullptr)
    {
        //Case 2: first and only
        if(header==p && p->getNext()==nullptr)
        {
            delete(header);
            header=nullptr;
        }
        //Case 3: Last one
        if (p->getNext()==nullptr)
        {
            delete(p);
        }
        else{
            //Case 4: general case
            ElementListOfList* temp = p->getNext();
            p->setNext(temp->getNext());
            delete(temp);
        }
    }
    
}

void ListOfList::deletePos(int pos)
{
    if(!empty())//Case 1: invalid position or empty list
    {
        ElementListOfList* prev = findPosition(pos);
        ElementListOfList* temp = findPosition(pos);
        
        if(temp)//Case 2: element does not exist
        {
            ElementListOfList* auxN = temp->getNext();
            //Case 3: first element
            if(temp==header)
            {
                delete(temp);
                header = auxN;//if there was only an element, now header is null
            }
            else
            {
                prev->setNext(auxN);
                delete(temp);
            }
        }
    }
}

ElementListOfList* ListOfList::getNext(ElementListOfList* p)
{
    ElementListOfList* result = nullptr;
    if(p!=nullptr)
    {
        result = p->getNext();
    }
    return result;
}

ElementListOfList* ListOfList::getPrev(ElementListOfList* p)
{
    ElementListOfList* result = nullptr;
    ElementListOfList* temp = header;
    //Case 1: first element
    if(header != p)
    {
        while (temp->getNext() != nullptr)
        {
            if(temp->getNext() == p)
            {
                result = p; //found
            }
            temp = temp->getNext();
        }
    }
    return result;
}

void ListOfList::makenull()
{
    while(!empty())
    {
        deletePos(0);
    }
}

bool ListOfList::empty()
{
    return header==nullptr;
}

ElementListOfList* ListOfList::findPosition(int pos)
{
    ElementListOfList* temp = nullptr;
    if(pos>=0)
    {
        temp = header;
        while(temp!=nullptr && pos>0)
        {
            temp=temp->getNext();
            pos--;
        }
    }
    
    
    return temp;
}

ElementListOfList* ListOfList::getLast()
{
    ElementListOfList* temp = nullptr;
    if(!empty())
    {
        temp = header;
        while(temp->getNext()!=nullptr)
        {//get to the last element
            temp=temp->getNext();
        }
    }
    
    return temp;
}

int ListOfList::getSize()
{
    int result = -1;
    if(!empty())
    {
        int pos=1; //counter
        ElementListOfList* temp = header;
        while(temp->getNext()!=nullptr)
        {
            temp=temp->getNext();
            pos++;
            result = pos;
        }
    }
    
    return result;
}

ElementListOfList* ListOfList::getHeader()
{
    return header;
}

ElementListOfList* ListOfList::getMiddle()
{
    ElementListOfList* result = nullptr;
    int size = getSize();
    int middle = 0;
    
    if(size > 0) //not empty
    {
        if((size%2) == 0) //even number of elements
        {
            middle = size/2;
        }
        else
        {
            middle = (size+1)/2;
        }
        
        ElementListOfList* temp = header;
        for(int i=1; i<middle; i++)
        {
            temp=temp->getNext();
        }
        result = temp;
    }
    return result;
}

void ListOfList::setHeader(ElementListOfList* h)
{
    this->header = h;
}