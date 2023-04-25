#include"MapPoint.h"
#include<iostream>
#include<cmath>
#include<string>

/**
 * @brief ustala dane dla klasy
 * 
 * @param name 
 * @param longitude 
 * @param latitude 
 */
void MapPoint::setPoint(std::string name, double longitude, double latitude){
    _name = name;
    _longitude = longitude;
    _latitude = latitude;
}

/**
 * @brief drukuje wszystkie dane z klasy
 * 
 */
void MapPoint::print()const{
    char x, y;
    
    if(_longitude<0){
      x = 'W';
    }else{
      x = 'E';
    }
    if(_latitude<0){
      y = 'S';
    }else{
      y = 'N';
    }
    std::cout << "wspolzedne dla " << _name << ": " << fabs(_longitude) << x << ", " << fabs(_latitude) << y << std::endl;
}


/**
 * @brief dlugosc geograficzna
 * 
 * @return double 
 */
double MapPoint::getLongitude()const{
    return _longitude;
}

/**
 * @brief szerokosc geograficzna
 * 
 * @return double 
 */
double MapPoint::getLatitude()const{
    return _latitude;
}

/**
 * @brief nazwa miasta
 * 
 * @return char* 
 */
std::string MapPoint::getName() const{
    return _name;
}

/**
 * @brief dodaje wspolzedne
 * 
 * @param longitudeNew 
 * @param latitudeNew 
 */
void MapPoint::move(double longitudeNew, double latitudeNew){
    _longitude = _longitude + longitudeNew;
    _latitude = _latitude + latitudeNew;
}

/**
 * @brief liczy dystans pomiedzy dwoma miastami
 * 
 * @param X 
 * @param Y 
 * @return double 
 */
double distance(MapPoint X, MapPoint Y){
    double delta_x = X.getLatitude() - Y.getLatitude();
    double delta_y = X.getLongitude() - X.getLongitude();
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

/**
 * @brief ustala ktore miasto jest blizsze miastu X
 * 
 * @param X 
 * @param Y 
 * @param Z 
 * @return MapPoint* 
 */
const class MapPoint *closestPlace(const class MapPoint X, const class MapPoint Y, const class MapPoint Z){
    double distA = distance(X, Y);
    double distB = distance(X, Z);
    if(distA < distB){
        const class MapPoint *tmp = &Y;
        return tmp;
    }else{
        const class MapPoint *tmp = &Z;
        return tmp;
    }
}

/**
 * @brief tworzy nowe miejsce w srodku 
 * 
 * @param X 
 * @param Y 
 * @param name 
 * @return MapPoint 
 */
class MapPoint inTheMiddle(const class MapPoint *X, const class MapPoint *Y, std::string name){
    double varX = ((*X).getLongitude() + (*Y).getLongitude())/2;
    double varY = ((*X).getLatitude() + (*Y).getLatitude())/2;
    const MapPoint Middle(name, varX, varY);

    return Middle;
}