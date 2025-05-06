#ifndef ELEMENTDOUBLY_HPP
#define ELEMENTDOUBLY_HPP

class ElementDoubly
{
    int content;
    ElementDoubly* nextElem;
    ElementDoubly* prevElem;
public:
    ElementDoubly();
    ElementDoubly(int x, ElementDoubly* next, ElementDoubly* prev); //constructor with args
    ~ElementDoubly();
    
    void setContent(int content);
    int getContent();
    
    ElementDoubly* getNext();
    void setNext(ElementDoubly *p);
    
    ElementDoubly* getPrev();
    void setPrev(ElementDoubly *p);
};

#endif // ELEMENTDOUBLY_HPP
