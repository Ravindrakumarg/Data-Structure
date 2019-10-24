#ifndef STACK_H_
#define STACK_H_

#include <iostream>

#define MAX_STACK_SIZE 10

template <typename T>
class Stack
{
    T data[MAX_STACK_SIZE];
    T top;
public:
    Stack()
    {
        top = -1;
    }

    void push(T data);
    T pop();
    bool is_stack_empty();
    void display_stack();
    void reverse_stack();
};

#include "StackImpl.h"

#endif