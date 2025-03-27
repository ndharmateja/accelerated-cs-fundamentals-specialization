#pragma once

// we do this so as to avoid confusion with other Cube classes
// from other packages.
namespace uiuc
{
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
}