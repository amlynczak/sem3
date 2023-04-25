#pragma once
#include<string>

class MapPoint{
public:
    void setPoint(std::string name, double longitude, double latitude);
    void print() const;
    double getLongitude() const;
    double getLatitude() const;
    std::string getName() const;
    void move(double longitudeNew, double latitudeNew);
    MapPoint(){}

    MapPoint(std::string name, double longitude, double latitude){
        _name = name;
        _longitude = longitude;
        _latitude = latitude;
    }

private:
    std::string _name;
    double _longitude;
    double _latitude;
};

double distance(const MapPoint X, const MapPoint Y);

const class MapPoint *closestPlace(const class MapPoint X, const class MapPoint Y, const class MapPoint Z);

class MapPoint inTheMiddle(const class MapPoint *X, const class MapPoint *Y, std::string name);