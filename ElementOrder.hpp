#ifndef ELEMENTORDER_HPP
#define ELEMENTORDER_HPP

class ElementOrder
{
    int sum;
    ElementOrder* next;
public:
    ElementOrder();
    ElementOrder(int x, ElementOrder* n);
    ~ElementOrder();
    
    int getSum();
    void setSum(int s);

    ElementOrder* getNext();
    void setNext(ElementOrder* n);

};

#endif // ELEMENTORDER_HPP
