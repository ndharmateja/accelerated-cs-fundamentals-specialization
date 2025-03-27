#pragma once

#include "HSLAPixel.h"
namespace uiuc
{
    class Cube
    {
    public:
        Cube(double, HSLAPixel);
        Cube(const Cube &);
        double getVolume() const;
        double getSurfaceArea() const;
        double getLength() const;
        void setLength(double length);

    private:
        double length_;
        HSLAPixel color_;
    };
}