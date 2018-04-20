//
// Created by majaku on 20.04.18.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
template <typename T>
class Vector {
private:
    T*  array_;
    int capacity_;
    int size_;
    void resize(int size);
    void moveLeft(int index);
    void moveRight(int index);
public:
    Vector(int size_ = 16);
    ~Vector();

    int capacity();
    int size();
    bool is_empty();
    T at(int index);
    void push(T item);
    void insert(int index, T value);
    int pop();
    void Delete(int index);
    void remove(T item);
    int find(T item);
    T operator=(int index);

    //void prepend(T item);
    void display() {
        for(int i = 0; i < size_; i++) {
            if(i%5 ==0)
                std::cout << std::endl;
            std::cout << array_[i] << ' ';
        }
    }

};

#include "exceptions.h"


#endif //VECTOR_VECTOR_H
