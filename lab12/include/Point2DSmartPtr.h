#pragma once
#include<stddef.h>
#include<iostream>

/**
 * @brief klasa point2D zawierajaca dwie wspolzedne x i y
 * 
 */
class Point2D{
public:
    /**
     * @brief Construct a new Point 2 D object
     * 
     * @param x 
     * @param y 
     */
    Point2D(double x=0, double y=0): _x(x), _y(y) {};
    ~Point2D(){};

    Point2D operator++(int x);
    Point2D operator--();
    Point2D operator+(Point2D add);
    void operator=(Point2D cp);

    static void *operator new(size_t size);
    static void operator delete(void *ptr);

    void print();
    double getx()const{return _x;};
    double gety()const{return _y;};
    /**
     * @brief dodaje do wartosci _x wartosc x
     * 
     * @param x 
     */
    void addx(double x) {_x = _x + x;};
    /**
     * @brief dodaje do wartosci _y wartosc y
     * 
     * @param y 
     */
    void addy(double y) {_y = _y + y;};
    /**
     * @brief usala wartosc x
     * 
     * @param x 
     */
    void setx(double x) {_x = x;};
    /**
     * @brief ustala wartosc y
     * 
     * @param y 
     */
    void sety(double y) {_y = y;};
private:
    double _x;
    double _y;
};


/**
 * @brief klasa zawierajaca wskaznik na obiekt Point2D
 * 
 */
class Point2DSmartPtr{
public:
    /**
     * @brief Construct a new Point 2 D Smart Ptr object
     * 
     * @param ptr 
     */
    Point2DSmartPtr(Point2D *ptr): _ptr(ptr) {};
    ~Point2DSmartPtr() {delete _ptr;};

    Point2D *operator->();
private:
    Point2D *_ptr;
};

Point2D operator+(double x, Point2D add);