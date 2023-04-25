#include <iostream>
#include "PointAverage.h"

using std::cout;
using std::endl;

double PointAverage::_avgX = .0;
double PointAverage::_avgY = .0;
int PointAverage::_counter = 0;

/**
 * @brief przeladowanie operatora ()
 * 
 * @param cp 
 */
void PointAverage::operator()(Point2D cp) {
    if(!_counter) {
        _counter = 1;
        _avgX = cp.getx();
        _avgY = cp.gety();
        return;
    }
    

    _avgX = (_avgX + cp.getx())/2;
    _avgY = (_avgY + cp.gety())/2;
}

/**
 * @brief drukuje PointAverage
 * 
 */
void PointAverage::print() {
    cout << "Average Point:: (" << _avgX << "," << _avgY << ")" << endl;
}

/**
 * @brief ustawia wartosci w klasie na 0
 * 
 */
void PointAverage::reset() { 
    _counter = 0;
    _avgX = 0;
    _avgY = 0;
}