//
// Created by Administrator on 2022/2/14.
//

#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

#include "Coordinate.h"
#include <iostream>

class Node {

public:
    Coordinate m_data {-1, -1};
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_top {nullptr};

public:
    Stack() = default;
    virtual ~Stack();

    void push(Coordinate coordinate);
    Coordinate peek();
    void pop();
    bool check(Coordinate coordinate);
    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack);

#endif //ASSIGNMENT_2_STACK_H