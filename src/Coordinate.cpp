//
// Created by Administrator on 2022/2/14.
//
#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)        //Constructor with coordinates x and y
        : m_x(x), m_y(y) {
}

bool Coordinate::operator!=(Coordinate coordinate) {                //determine whether the coordinates are equal
    return (this->m_x != coordinate.m_x) || (this->m_y != coordinate.m_y);
}

std::ostream &operator<<(std::ostream &output, Coordinate coordinate) {         //print Coordinate
    output << "coordinate: " << coordinate.m_x << "/" << coordinate.m_y;
    return output;
}