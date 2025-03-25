#include "Cube.h"

double Cube::getVolume() { return this->length_ * this->length_ * this->length_; }
double Cube::getSurfaceArea() { return 6 * this->length_ * this->length_; }
double Cube::getLength() { return this->length_; }
void Cube::setLength(double length) { this->length_ = length; }