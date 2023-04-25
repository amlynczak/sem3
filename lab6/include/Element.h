#pragma once
#include<string>

int objects_created = 0;

class Element{
    friend class MyList;
public:
    Element(){};
    Element(const int *a, int size) : _a(a), _next(nullptr), _size(size) {
    objects_created++;}
    void printElem()const;
    ~Element(){};
    int getSize()const;
    static int getObjects(){
        return objects_created;
    }
    Element(const Element& other) : _a(other._a), _next(other._next), _size(other._size) {
    objects_created++;
    }

    Element(const Element&& other) : _a(other._a), _next(other._next), _size(other._size) {
    objects_created++;
    }

    Element addElemRev(Element& tmp);
private:
    const int *_a;
    Element *_next;
    int _size;
};
