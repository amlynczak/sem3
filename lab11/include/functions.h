#pragma once
#include<iostream>
#include<math.h>

/**
 * @brief klasa z funkcja liniowa
 * 
 */
class Linear{
    /**
     * @brief operator << , sluzy do wypisania funkcji w postaci ax+b
     * 
     * @param strm 
     * @param lin dana funkcja
     * @return std::ostream& 
     */
friend std::ostream& operator <<(std::ostream& strm, const Linear& lin){
    strm << lin._a << "*x " << lin._b << std::endl;
    return strm;
};
public:
    /**
     * @brief Construct a new Linear object
     * 
     * @param a 
     * @param b 
     */
    Linear(double a, double b): _a(a), _b(b){};
    /**
     * @brief zwraca wartosc funkcji liniowej w danym punkcje x
     * 
     * @param x 
     * @return double 
     */
    double operator()(double x)const {return _a*x + _b;};

private:
    double _a;
    double _b;
};


class Sqrt{
public:
    /**
     * @brief Construct a new Sqrt object
     * 
     */
    Sqrt(){};
    /**
     * @brief zwraca pierwiastek danej liczby x
     * 
     * @param x 
     * @return double 
     */
    double operator()(double x)const {return sqrt(x);};
private:

};



class Sin{
public:
/**
 * @brief Construct a new Sin object
 * 
 * @param a 
 * @param b 
 */
    Sin(double a, double b): _a(a), _b(b){};
    /**
     * @brief zwraca sinus wartosci funkcji liniowej w danym punkcie x
     * 
     * @param x 
     * @return double 
     */
    double operator()(double x)const {return sin(_a*x + _b);};
private:
    double _a;
    double _b;
};