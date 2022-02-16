//
// Created by Administrator on 2022/2/14.
//
#include "Stack.h"
#include <iostream>

Stack::~Stack() {
}

void Stack::push(Coordinate num) {              //store data to stack

    auto new_node = new Node();
    new_node->m_data = num;
    new_node->m_next = m_top;
    m_top = new_node;
}

Coordinate Stack::peek() {          //Return the data of the top node
    if (m_top != nullptr)
        return m_top->m_data;
    return {-1, -1};
}

void Stack::pop() {                 //delete the data of the top node
    if (m_top != nullptr) {
        auto node = m_top;
        m_top = m_top->m_next;
        delete node;
    } else {
        std::cout << "There are no more nodes to remove..." << std::endl;
    }
}

bool Stack::check(Coordinate coordinate) {               //Check if the stack contains this data
    auto node = m_top;
    if (!node) {
        return false;
    } else if (node->m_data.m_x == coordinate.m_x & node->m_data.m_y == coordinate.m_y) {
        return true;
    }
    while (node->m_next != nullptr) {
        node = node->m_next;
        if (node->m_data.m_x == coordinate.m_x & node->m_data.m_y == coordinate.m_y) {
            return true;
        }

    }
    return false;
}

std::ostream &operator<<(std::ostream &output, Stack &stack) {
    auto node = stack.m_top;                    //print the data on the stack
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}
