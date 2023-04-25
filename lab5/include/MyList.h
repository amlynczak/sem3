#pragma once
#include<string>

class Element;

class MyList{
    friend class Element;
public:
    MyList(){};
    ~MyList(){};
    void add(Element *node);
    void add(int *tab, int size);
    void add(const int *tab, int size);
    void removeFirst();
    Element *getHead()const;
    void print(std::string name)const;
    int isEmpty()const;
    void copyRev(MyList *a);
    Element *odwrot(Element *head);
private:
    Element *_head;
};
