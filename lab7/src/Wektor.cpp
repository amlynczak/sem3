#include"Wektor.h"
#include"Wymierne.h"
#include<iostream>

Wektor &Wektor::SetCoordinate(Wymierne &coordinate, double a, double b){
  coordinate.setA(a);
  coordinate.setB(b);
  
  return *this;
}

Wektor &Wektor::SetX(double a, double b){
  return SetCoordinate(_x, a, b);
}

Wektor &Wektor::SetY(double a, double b){
  return SetCoordinate(_y, a, b);
}

Wektor &Wektor::SetZ(double a, double b){
  return SetCoordinate(_z, a, b);
}

Wymierne &Wektor::getX(){
  return _x;
}

Wymierne &Wektor::getY(){
  return _y;
}

Wymierne &Wektor::getZ(){
  return _z;
}

void Wektor::print()const{
  std::cout << "[";
  _x.print();
  std::cout << ", ";
  _y.print();
  std::cout << ", ";
  _z.print();
  std::cout << "]" << std::endl;
}