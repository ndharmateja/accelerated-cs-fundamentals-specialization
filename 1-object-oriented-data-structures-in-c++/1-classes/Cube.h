#pragma once

class Cube
{
public:
    double getVolume();
    double getSurfaceArea();
    double getLength();
    void setLength(double length);

private:
    double length_;
};