//
// Created by majaku on 20.04.18.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
#include <stdlib.h>
#include "exceptions.h"
template <typename T>
class Vector {
private:
    T*  array_;
    int capacity_;
    int size_;

    void resize(int size) {

            T *temp = array_;

            while (size > capacity_)
                capacity_ *= 2;

            array_ = new T[capacity_];

            for (int i = 0; i < size_; i++) {
                array_[i] = temp[i];
            }
            delete temp;


    };
    void moveLeft(int index){
        for(int i = index; i <= size_; i++) {
            array_[i] = array_[i+1];
        }
        size_--;
    };
    void moveRight(int index){
        if(size_ == capacity_)
            resize(capacity_);
        for(int i = size_; i >= index; i--) {
            array_[i+1] = array_[i];
        }
        size_++;
    };


public:

    Vector(int capacity = 16) {
        this->size_ = 0;

        while(size_ > capacity)
            capacity*=2;

        this->array_ = new T[capacity];
        this->capacity_ = capacity;

    };
    ~Vector(){
        delete this->array_;
    };

    int capacity(){
        return this->capacity_;
    };

    int size() {
        return this->size_;
    };

    T at(int index){
        if(index <= size_ && index < 0)
            return *(array_ + index);
        else
            throw OutOfTabIndexException();
    };
    void push(T item) {
        if(size_ == capacity_)
            resize(capacity_+1);

        array_[size_] = item;
        size_++;
    };
    void insert(int index, T value){
        moveRight(index);
        array_[index] = value;
    };
    int pop() {
        if(size_ == 0)
            throw EmptyVectorException();
        else {
            size_--;
            return array_[size_];
        }
    };
    void Delete(int index) {
        moveLeft(index);
    };
    void remove(T item){
        if(size_ == 0) {
            throw EmptyVectorException();
        } else {
            for(int i = 0; i <= size_; i++)
                if(array_[i] == item)
                    Delete(i);


        }
    };
    int find(T item){
        for(int i= 0; i <= size_; i++)
            if(array_[i] == item)
                return i;
        return -1;
    };
    T operator=(int index){
        return at(index);
    };

    //void prepend(T item);

    void display() {
        for(int i = 0; i < size_; i++) {
                std::cout << array_[i];
        }
    }

};

#include "exceptions.h"


#endif //VECTOR_VECTOR_H
