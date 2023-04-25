#include"assoc.h"
#include<string>

Assoc::Assoc(int l): _l(l), _head(new Subject[l]) {};
    
Assoc::Assoc(const Assoc &copy): Assoc(copy._l){
    for(int i=0; i<_l; i++){
        _head[i]._name = copy._head[i]._name;
        _head[i]._val = copy._head[i]._val;
    }
}
    
Assoc::Assoc(Assoc &&move): Assoc(move){delete[] move._head;}
    
Assoc::~Assoc(){
    delete[] _head;
    _l = 0;
}
    
    
void Assoc::insert(const std::string name, double val){
    Assoc tmp(std::move(*this));
    _l++;
    _head=new Subject[_l];
    for(int i=0; i<_l-1; i++){
        _head[i]._name = tmp._head[i]._name;
        _head[i]._val = tmp._head[i]._val;
    }
    _head[_l-1]._name = name;
    _head[_l-1]._val = val;
}

void Assoc::print(const std::string preambule)const{
    for(int i=0; i<_l; i++){
        std::cout << preambule << " klucz: " << _head[i]._name << " wartosc: " << _head[i]._val << std::endl;
    }
}

double &Assoc::operator[](const std::string name){
    for(int i=0; i<_l; i++){
        if(_head[i]._name == name) return _head[i]._val;
    }
    insert(name, 0);
    return _head[_l-1]._val;
}

double &Assoc::operator[](const std::string name)const{
    for(int i=0; i<_l; i++){
        if(_head[i]._name == name) return _head[i]._val;
    }
    return _head[_l-1]._val;
}

Assoc &Assoc::operator=(const Assoc &assign){
    if(this == &assign) return *this;
    
    delete[] _head;
    _l = assign._l;
    _head = new Subject[_l];
    
    for(int i=0; i<_l; i++){
        _head[i]._name = assign._head[i]._name;
        _head[i]._val = assign._head[i]._val;
    }
    
    return *this;
}

bool Assoc::contains(const std::string name)const{
    for(int i=0; i<_l; i++){
        if(_head[i]._name == name) return true;
    }
    return false;
}



std::string print(bool check){
    std::string found = "Znaleziono";
    std::string nfound = "Nie Znalezono";
    if(check) return found;
    return nfound;
}

