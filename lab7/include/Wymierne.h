#pragma once

class Wymierne{
public:
  Wymierne(int a, int b): _a(a), _b(b) {};
  
  explicit operator double()const;
  static double ToDouble(const Wymierne &w);
  void setA(int a) {_a = a;}
  void setB(int b) {_b = b;}
  int getA()const;
  int getB()const;
  void print()const;
  
private:
  int _a;
  int _b;
};