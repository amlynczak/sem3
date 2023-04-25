#pragma once
#include<string>

class Element{
    friend class MyList;
public:
    Element(){};
    Element(const int *a, int size);
    void printElem()const;
    ~Element(){};
    int getSize()const;
    Element *odwrot(Element *head);
private:
    const int *_a;
    Element *_next;
    int _size;
};
