#ifndef ELEMENTLIST_HPP
#define ELEMENTLIST_HPP

class ElementList
{
    int sum;
    ElementList* next;
public:
    ElementList();
    ElementList(int x, ElementList* n);
    ~ElementList();
    
    int getSum();
    void setSum(int s);

    ElementList* getNext();
    void setNext(ElementList* n);
};

#endif // ELEMENTLIST_HPP
