//
// Created by Administrator on 2022/2/14.
//

#ifndef ASSIGNMENT_2_COORDINATE_H
#define ASSIGNMENT_2_COORDINATE_H
#include <iostream>

class Coordinate {
public:
    int m_x;
    int m_y;
    Coordinate(int, int);

    bool operator!=(Coordinate coordinate);
};

std::ostream& operator<<(std::ostream& output, Coordinate coordinate);

#endif //ASSIGNMENT_2_COORDINATE_H
