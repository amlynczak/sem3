#include"MyList.h"
#include"Element.h"
#include<iostream>
#include<string>


void MyList::add(Element *node){
    if (_head == nullptr) {
        _head = node;
    }
    else {
        Element *current = _head;
        while (current->_next != nullptr) {
            current = current->_next;
        }
        current->_next = node;
    }
}

void MyList::add(int *tab, int size){
    add(new Element(tab, size)); 
}

void MyList::add(const int *tab, int size){
    int *copy = new int[size];
    for (int i = 0; i < size; i++) {
        copy[i] = tab[i];
    }
    add(copy, size);
}

void MyList::removeFirst(){
      if(_head == nullptr) return;
      Element *tmp = _head;
      _head = _head -> _next;
      delete tmp;
}

Element *MyList::getHead()const{
    return _head;
}

void MyList::print(std::string name)const{
    Element *el = _head;
    std::cout << name << "= <";
    while(el != nullptr){
      el->printElem();
      el = el -> _next;
    }
    std::cout << ">" << std::endl;
}

int MyList::isEmpty()const{
    return _head == nullptr;
}

Element *MyList::odwrot(Element *head){
  if (head == nullptr || head->_next == nullptr) {
        return head;
    }
    Element *newHead = odwrot(head->_next);
    head->_next->_next = head;
    head->_next = nullptr;
    return newHead;
}

void MyList::copyRev(MyList *a){
    Element *current = _head;
    while (current != nullptr) {
        int size = current->getSize();
        int *copy = new int[size];
        const int *data = current->_a;
        for (int i = size - 1; i >= 0; i--) {
            copy[i] = data[i];
        }
        a->add(copy, size);
        current = current->_next;
    }
    
}