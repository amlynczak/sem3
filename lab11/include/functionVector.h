#pragma once
#include<functional>
#include<iostream>

class FunctionVector{
public:
    /**
     * @brief Construct a new Function Vector object
     * 
     */
    FunctionVector(): _list(nullptr), _size(0){};
    ~FunctionVector(){};
    void insert(std::function<double (double)> fun)const;
    double calc(double x) const;

    /**
     * @brief zwraca funkcje na danym miejscu w liscie klasy
     * 
     * @param n ktore miejsce z kolei
     * @return double 
     */
    double operator[](int n){
        return 0;
    };

private:
    std::function<double (double)> *_list;
    int _size;
};