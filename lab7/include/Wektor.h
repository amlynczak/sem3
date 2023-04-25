#pragma once
#include "Wymierne.h"

class Wektor{
friend class Wymierne;
public:
  Wektor(): _x(0,1), _y(0,1), _z(0,1) {}
  Wektor(int i): _x(i,1), _y(i,1), _z(i,1) {}
  
  Wektor &SetCoordinate(Wymierne &coordinate, double a, double b);
  Wektor &SetX(double a, double b);
  Wektor &SetY(double a, double b);
  Wektor &SetZ(double a, double b);
  Wymierne &getX();
  Wymierne &getY();
  Wymierne &getZ();
  void print()const;
  
private:
  Wymierne _x;
  Wymierne _y;
  Wymierne _z;
};