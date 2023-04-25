#include "Wymierne.h"
#include<iostream>

double Wymierne::ToDouble(const Wymierne &w){
  return static_cast<double>(w.getA()/w.getB());
}

int Wymierne::getA()const{
  return _a;
}

int Wymierne::getB()const{
  return _b;
}

void Wymierne::print()const{
  if(_b == 1) std::cout << _a;
  if(_b != 1) std::cout << _a << "/" << _b;
}

Wymierne::operator double()const{
  return static_cast<double> (_a)/(_b);
}