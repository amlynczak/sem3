#include "Wymierne.h"
#include<iostream>
#include<string>

namespace wymierne{
/**
 * @brief zwraca _a
 * 
 * @return int 
 */
int Wymierne::getA()const{
  return _a;
}

/**
 * @brief zwraca b
 * 
 * @return int 
 */
int Wymierne::getB()const{
  return _b;
}

/**
 * @brief drukuje
 * 
 */
void Wymierne::print()const{
  if(_b == 1) std::cout << _a;
  if(_b != 1) std::cout << _a << "/" << _b;
}

/**
 * @brief drukuje ale inaczej
 * 
 * @param name 
 */
void Wymierne::print(std::string name)const{
    std::cout<< name;
    if(_b == 1) std::cout << _a;
    if(_b != 1) std::cout << _a << "/" << _b;
    std::cout << std::endl;
}

/**
 * @brief mnozy dwa dane ulamki
 * 
 * @param a ulamek 1
 * @param b ulamek 2
 * @return Wymierne 
 */
Wymierne pomnoz(Wymierne a, Wymierne b){
    Wymierne tmp;
    int x = a.getA() * b.getA();
    int y = a.getB() * b.getB();
    tmp.setL(x);
    tmp.setM(y);
    return tmp;
}

Wymierne::operator double()const{
  return static_cast<double> (_a)/(_b);
}

/**
 * @brief mnozy dwa dane ulamki ale inaczej
 * 
 * @param a ulamek 1
 * @param b ulamek 2
 * @return Wymierne 
 */
Wymierne Wymierne::pomnoz(const Wymierne &a, const Wymierne &b){
    Wymierne tmp;
    int x = a.getA() * b.getA();
    int y = a.getB() * b.getB();
    tmp.setL(x);
    tmp.setM(y);
    tmp.simplify();
    return tmp;
};



int nwd(int m, int n){
  int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
      m = oldn;
      n = oldm % oldn;
  }
    return n;
}

void Wymierne::simplify(){
    int dzielnik = nwd(_a, _b);
    _a = (_a/dzielnik);
    _b = (_b/dzielnik);
}

}; //koniec namespace