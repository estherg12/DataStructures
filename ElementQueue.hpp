#ifndef ELEMENTQUEUE_HPP
#define ELEMENTQUEUE_HPP

class ElementQueue
{
    int content;
    ElementQueue* nextElem;
public:
    ElementQueue();
    ElementQueue(int x, Element* next); //constructor with args
    ~ElementQueue();
    ElementQueue* getNext();
    void setContent(int content);
    int getContent();
    void setNext(Element *p);
};

#endif // ELEMENTQUEUE_HPP
