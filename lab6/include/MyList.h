#pragma once
#include<string>

class Element;

class MyList{
    friend class Element;
public:
    MyList(){};
    ~MyList(){};
    void add(Element *node);
    void add(int *tab, int n);
    void add(const int *tab, int n);
    void removeFirst();
    Element *getHead()const;
    void print(std::string name)const;
    int isEmpty()const;
    void copyRev(MyList *a);
    Element *odwrot(Element *head);
    void append(const void *nowy)const;
    void append(const void *nowy, int n)const;
    Element *getTail()const;
private:
    Element *_head;
};
