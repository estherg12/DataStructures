#ifndef DOUBLYLIST_HPP
#define DOUBLYLIST_HPP
#include "ElementDoubly.hpp"

class DoublyList
{
    ElementDoubly* header;
public:
    DoublyList();
    ~DoublyList();
    
    void insert(int item, int pos);
    void insertFirst(int item);
    void insertLast(int item);
    void deletePos(int pos);
    ElementDoubly* locate(int item); //returns pointer
    int locatePos(int item); //returns position
    int retrieve(int pos); //returns item
    ElementDoubly* retrieveP(int pos);
    
    int next(int pos); //returns item
    ElementDoubly* nextPtr(int pos); //returns pointer
    ElementDoubly* nextPtr_Ptr(ElementDoubly* p); //returns pointer
    
    int previous(int pos); //returns item
    ElementDoubly* prevPtr(int pos); //returns pointer
    ElementDoubly* prevPtr_Ptr(ElementDoubly* p); //returns pointer
    
    void makenull();
    bool empty();
    
    //Extra operations
    ElementDoubly* findPosition(int pos);
    int getTailItem();
    ElementDoubly* getTail();
    int getSize();
};

#endif // DOUBLYLIST_HPP
