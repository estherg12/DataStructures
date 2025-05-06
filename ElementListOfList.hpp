#ifndef ELEMENTLISTOFLIST_HPP
#define ELEMENTLISTOFLIST_HPP

#include "../List.hpp"

class ElementListOfList
{
    ElementListOfList* next;
    List* list;
public:
    ElementListOfList();
    ElementListOfList(ElementListOfList* n, List* l);
    ~ElementListOfList();

    //Basic operations
    ElementListOfList* getNext();
    void setNext(ElementListOfList* e);
    
    List* getList();
    void setList(List* l);
};

#endif // ELEMENTLISTOF_HPP
