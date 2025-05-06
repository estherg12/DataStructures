#include "DoublyList.hpp"

DoublyList::DoublyList()
{
    header = nullptr;
}

DoublyList::~DoublyList()
{
    makenull();
}

void DoublyList::insert(int item, int pos)
{//assuming first position is 0
    if (pos>=0)
    {
        ElementDoubly* element = new Element(item, nullptr, nullptr);
        //Case 1: First position
        if ((header==nullptr) || (pos==0)) //first position
        {//if the list is empty or the position asked to insert is 0
            insertFirst(item);
        }
        else
        {
            ElementDoubly* prev = findPosition(pos-1);//find the element just before the position where the new element should be inserted
            
            //Case 3: position out of range
            if(!prev)
            {//prev == nullptr : pos is beyond the list's current length
                delete element; //clean up the allocated memory for the new element
                return; //exit the method insert
            }
            
            //Case 4: General case
            ElementDoubly* n = prev->getNext();
            element->setNext(n);
            element->setPrev(prev);
            prev->setNext(element);
            
            if (n)
            {//update the next element's previous pointer to the new element, if it exists
                n->setPrev(element);
            }
            
            /*WITHOUT THE FINDPOS METHOD
            ElementDoubly* temp = header; //initializes a temporary pointer pointing to the header
            
             * finds the pointer to the position where the element must be inserted
            for (int i = 1; i < pos - 1 && temp; ++i)
            {traverse the linked list to find the element just before the desired position for insertion
               the loop stops at the element just before the position where
                * the new element is to be inserted
                temp = temp->getNext(); //moves temp's pointer to the next element in the list during each iteration
            }
            
            //Case 3: Position out of range
            if (!temp) //temp == nullptr
            {
                delete element;
                return;//exit the insert method because position is invalid and no further operations should be performed
            }

            //Case 4: Any position but first or last
            element->setNext(temp->getNext());
            temp->setNext(element);
            element->setPrev(temp);*/
        }
    }
    
    else
    {//negative position
        return;
    }
    
}

void DoublyList::insertFirst(int item)
{
    ElementDoubly* element = new ElementDoubly(item, nullptr, nullptr);
    element->setNext(header); //if the list is empty, the new and only element (header) will point to null
    header = element;
}

void DoublyList::insertLast(int item)
{
    ElementDoubly* element = new ElementDoubly(item, nullptr, nullptr);
    ElementDoubly* temp = header; //initializes a temporary pointer pointing to the header
    
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
        element->setPrev(temp);
    }
    
}

void DoublyList::deletePos(int pos)
{
    //Case 1: Invalid position or empty list
    if (empty() || pos<0)
    {
        return;
    }
    
    ElementDoubly* temp = findPosition(pos); //find the element to be delated
    
    //Case 2: Element does not exist
    if(!temp)
    {
        return;
    }
    
    //Case 3: General
    ElementDoubly* pr = temp->getPrev();
    ElementDoubly* n = temp->getNext();
    
    if(pr)
    {
        pr->setNext(n);
    }
    else
    {//there is no previous element, temp was the first element
        header = n;//update header
    }
    
    if(n)
    {
        n->setPrev(pr);//Bypass the currant element
    }
    delete(temp);
}

ElementDoubly* DoublyList::locate(int item)
{
    ElementDoubly* temp = header;//start from the header of the list
    //Traverse the list
    while (temp!=nullptr)
    {
        if(temp->getContent()==item)//if the current element's value matches the item
        {
            return temp;//return temp (pointer)
        }
        else
        {
            temp = temp->getNext();//move to the next elem
        }
    }
    return nullptr;//item not found
}

int DoublyList::locatePos(int item)
{
    ElementDoubly* temp = header;//start from the header of the list
    int pos = 0;//initialize the position counter
    
    //Traverse the list
    while(temp!=nullptr)
    {//if the current element's value matches the item
        if(temp->getContent() == item)
        {
            return pos;//return position counter
        }
        temp = temp->getNext();//move to the next element
        pos++;//increment position
    }
    return -1; //item not found
}

int DoublyList::retrieve(int pos)
{//returns item
    ElementDoubly* temp = findPosition(pos);
    if (temp!=nullptr)
    {
        return temp->getContent(); //returns int element
    }
    else
    {
        return -1;
    }
}

ElementDoubly* DoublyList::retrieveP(int pos)
{
    ElementDoubly* temp = findPosition(pos);
    if(temp!=nullptr)
    {
        return temp;
    }
    else
    {
        return nullptr;
    }
}

int DoublyList::next(int pos)
{//returns item
    ElementDoubly* temp = findPosition(pos);
    if(temp->getNext()==nullptr)
    {
        return -1;//temp is the last element
    }
    temp = temp->getNext();
    return temp->getContent();
}

ElementDoubly* DoublyList::nextPtr(int pos)
{
    ElementDoubly* temp = findPosition(pos);
    if (temp->getNext()==nullptr)
    {
        return nullptr; //temp is last element
    }
    return temp->getNext();
}

ElementDoubly* DoublyList::nextPtr_Ptr(ElementDoubly* p)
{
    if (p!=nullptr)
    {
        return p->getNext();
    }
    else
    {
        return nullptr;
    }
}

int List::previous(int pos)
{//returns item
    Element* temp = findPosition(pos);
    if(temp->getPrev()==nullptr)
    {
        return -1;//temp is the last element
    }
    temp = temp->getPrev();
    return temp->getContent();
}

Element* List::prevPtr(int pos)
{
    Element* temp = findPosition(pos);
    if (temp->getPrev()==nullptr)
    {
        return nullptr; //temp is last element
    }
    return temp->getPrev();
}

Element* List::prevPtr_Ptr(Element* p)
{//If p is pointing to null it will return nullptr
    if (p!=nullptr)
    {
        return p->getPrev();
    }
    else
    {
        return nullptr;
    }
}

void List::makenull()
{
    while(!empty())
    {//Continuously delete the first element until the list is empty
        deletePos(0);
    }
    
}

bool List::empty()
{
    return header == nullptr;
}

Element* List::findPosition(int pos)
{
    if (pos<0)
    {//negative options are invalid
        return nullptr;
    }
    
    Element* temp = header;
    while (temp!=nullptr && pos > 0)
    {
        temp = temp->getNext();
        pos--;
    }
    return temp;
}

int List::getTailItem()
{//returns the content (int item) of the last element of the list
    if(header==nullptr)
    {
        return -1; //if list is empty
    }
    Element* temp = header;
    //Goes through all the list
    while(temp->getNext()!=nullptr)
    {
        temp=temp->getNext();
    }
    return temp->getContent();
}

Element* List::getTail()
{
    if(header==nullptr)
    {
        return nullptr;
    }
    Element* temp = header;
    while(temp->getNext()!=nullptr)
    {
        temp=temp->getNext();
    }
    return temp;
}

int List::getSize()
{//returns the content (int item) of the last element of the list
    if(header==nullptr)
    {
        return -1; //if list is empty
    }
    
    int pos=1;
    Element* temp = header;
    //Goes through all the list
    while(temp->getNext()!=nullptr)
    {
        temp=temp->getNext();
        pos++;
    }
    return pos;
}