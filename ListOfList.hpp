#ifndef LISTOFLIST_HPP
#define LISTOFLIST_HPP

class ListOfList
{
    ElementListOfList* header;
    
public:
    ListOfList();
    ~ListOfList();

    void insert(List* l);
    void insertFirst(List* l);
    void insertLast(List* l);
    
    void deleteP(ElementListOfList* p);
    void deletePos(int pos);
    
    ElementListOfList* getNext(ElementListOfList* p);
    ElementListOfList* getPrev(ElementListOfList* p);
    
    
    void makenull();
    bool empty();
    
    //Extra operations
    ElementListOfList* findPosition(int pos);
    int getSize();//returns how many elements
    ElementListOfList* getLast();//returns the last element
    ElementListOfList* getHeader();
    ElementListOfList* getMiddle();
    
    void setHeader(ElementListOfList* h);
};

#endif // LISTOFLIST_HPP
