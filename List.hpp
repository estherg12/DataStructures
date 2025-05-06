#ifndef LIST_HPP
#define LIST_HPP
#include "ElementList.hpp"

class List
{
public:
    List();
    ~List();
    
    //Basic operations
    void insertLast(int item);
    void insertFirst(int item);
    
    bool search(int item);
    
    ElementList* getHeader();
};

#endif // LIST_HPP
