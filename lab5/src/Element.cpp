#include"Element.h"
#include<iostream>
#include<string>

Element::Element(const int *a, int size){
    _a = a;
    _next = nullptr;
    _size = size;
}


int Element::getSize()const{
    return _size;
}

void Element::printElem()const{
    std::cout << "(" ;
    int n = getSize();
    for(int i=0; i<n-1; i++){
        std::cout << _a[i] << ", " ;
    }
    std::cout << _a[n-1] << ")";
}

Element *Element::odwrot(Element *head){
  Element *prev = nullptr;
  Element *current = head;
  Element *next = nullptr;

  while (current != nullptr) {
    next = current->_next;
    current->_next = prev;
    prev = current;
    current = next;
  }

  return prev;
}