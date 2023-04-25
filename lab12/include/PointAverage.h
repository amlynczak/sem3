#pragma once
#include<iostream>
#include"Point2DSmartPtr.h"

class PointAverage{
public:
    PointAverage(){};
    ~PointAverage(){};

    void operator()(Point2D cp);

    void print();
    void reset();

    static double _avgX;
    static double _avgY;
    static int _counter;
};