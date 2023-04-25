#include"MyList.h"
#include"Element.h"
#include<iostream>
#include<string>


void MyList::add(Element *node){
    node -> _next = _head;
    _head = node;
}

void MyList::add(int *tab, int size){
    Element *nowy = new Element(tab, size);
    add(nowy); 
}

void MyList::add(const int *tab, int size){
    Element *nowy = new Element(tab, size);
    add(nowy);
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
    int n=1;
    while(el -> _next != nullptr){
      n++;
      el = el -> _next;
    }
    for(int i=0; i<n; i++){
      el -> printElem();
      el = el -> _next;
    }
    std::cout << ">" << std::endl;
}

int MyList::isEmpty()const{
    if(_head == nullptr){
        return 1;
    }else{return 0;}
}

Element *MyList::odwrot(Element *head){
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
}

void MyList::copyRev(MyList *a){
    Element *tmp = a -> _head;
    
    Element *cur = tmp;
    Element *prev = nullptr;
    Element *next = nullptr;
    
    while(cur){
      next = cur -> _next;
      cur -> _next = prev;
      prev = cur;
      cur = next;
    }
    
    _head = prev;
    
}

Element *MyList::getTail()const{
  Element *tail = this->_head;
  while (tail->_next != nullptr) {
    tail = tail->_next;
  }
  return tail;
}

void append(Element *nowy)const{
  const int *tab = static_cast<const int*>(nowy);
  int n = sizeof(tab)/sizeof(tab[0]);
  this->add(tab, n);
}


void append(Element *nowy, int n)const{
  const int *tab = static_cast<const int*>(nowy);
  this->add(tab, n);
}