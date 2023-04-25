#include"Point2DSmartPtr.h"
#include<stdlib.h>

/**
 * @brief zwieksza wartosci x i y o 1
 * 
 * @param x 
 * @return Point2D 
 */
Point2D Point2D::operator++(int x){
    Point2D tmp(_x+1, _y+1);
    return tmp;
}

/**
 * @brief zmniejsza wartosci x i y 0 1
 * 
 * @return Point2D 
 */
Point2D Point2D::operator--(){
    Point2D tmp(_x-1, _y-1);
    return tmp;
}

/**
 * @brief dodawanie Point2D do drugiego Point2D
 * 
 * @param add 
 * @return Point2D 
 */
Point2D Point2D::operator+(Point2D add){
    Point2D tmp;
    tmp._x = _x + add._x;
    tmp._y = _y + add._y;
    return tmp;
}

/**
 * @brief przypisuje wartosc Point2D cp do danego Point2D
 * 
 * @param cp 
 * @return Point2D 
 */
void Point2D::operator=(Point2D cp){
    double x = cp._x;
    double y = cp._y;
    setx(x);
    sety(y);
}

/**
 * @brief alokuje nowa pamiec wraz z cout
 * 
 * @param size 
 * @return void* 
 */
void *Point2D::operator new(size_t size){
    std::cout << "Point2D:: alokowanie " << size << " bajtow" << std::endl;
    Point2D *tmp = (Point2D*)malloc(size);
    return tmp;
}

/**
 * @brief zwalnia pamiec wraz z cout
 * 
 * @param ptr 
 */
void Point2D::operator delete(void *ptr){
    std::cout << "Point2D:: zwalnianie wskaznika" << std::endl;
    free(ptr);
}

/**
 * @brief drukuje dany obiekt Point2D
 * 
 */
void Point2D::print(){
    std::cout << "Point2D:: (" << _x << ", " << _y << ")" << std::endl;
}

/**
 * @brief przeladowanie operatora
 * 
 * @return Point2D* 
 */
Point2D *Point2DSmartPtr::operator->(){
    return _ptr;
}

/**
 * @brief dodaje liczbe double do Point2D
 * 
 * @param x 
 * @param add 
 * @return Point2D 
 */
Point2D operator+(double x, Point2D add){
    add.addx(x);
    add.addy(x);
    return add;
}