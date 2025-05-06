#ifndef ORDERLIST_HPP
#define ORDERLIST_HPP
#include "ElementOrder.hpp"

class OrderList
{
public:
    OrderList();
    ~OrderList();
    
    //Basic operations
    void insert(int item);
    void insertLast(int item);
    void insertFirst(int item);
    
    bool search(int item);
    
    ElementOrder* getHeader();
};

#endif // ORDERLIST_HPP
