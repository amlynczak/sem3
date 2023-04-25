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

Element Element::addElemRev(Element& tmp){
  int size = tmp._size;
  int* revArr = new int[size];
  for (int i = 0; i < size; i++) {
    revArr[i] = tmp._a[size - i - 1];
  }
  Element revElem(revArr, size);
  delete[] revArr;
  return revElem;
}

/*Element *Element::odwrot(Element *head){
  Element *cur = head;
  Element *prev = nullptr;
  Element *next = nullptr;
  
  while(cur){
    next = cur -> _next;
    cur -> _next = prev;
    prev = cur;
    cur = next;
  }
  
  return prev;
}*/