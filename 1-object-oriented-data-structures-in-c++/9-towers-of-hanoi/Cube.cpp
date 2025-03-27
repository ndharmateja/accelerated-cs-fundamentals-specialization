#include "Cube.h"
namespace uiuc
{
    Cube::Cube(double length, HSLAPixel color)
    {
        this->length_ = length;
        this->color_ = color;
    }
    Cube::Cube(const Cube &cube)
    {
        this->length_ = cube.length_;
        this->color_ = cube.color_;
    }
    double Cube::getVolume() const { return this->length_ * this->length_ * this->length_; }
    double Cube::getSurfaceArea() const { return 6 * this->length_ * this->length_; }
    double Cube::getLength() const { return this->length_; }
    void Cube::setLength(double length) { this->length_ = length; }
}