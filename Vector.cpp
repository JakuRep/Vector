//
// Created by majaku on 20.04.18.
//
#include "exception"
#include "Vector.h"
#include "exceptions.h"

template <typename T>
Vector<T>::Vector(int size_) {
    int capacity;

    //finding proper size that will be power of 2
    for(capacity=16; size_ > capacity; capacity*=2);
    //allocating array with counted size
    this->array_ = new T[capacity];
    this->capacity_ = capacity;
    this->size_ = 0;



}
template <typename T>
Vector<T>::~Vector() {
    delete this->array_;
}
template <typename T>
int Vector<T>::capacity() {
    return this->capacity_;
}
template <typename T>
bool Vector<T>::is_empty() {
    return (this->size_ == 0);
}

template <typename T>
T Vector<T>::at(int index) {
    if(index < capacity_ && index >=0)
        return *(array_ + index);
    else
        throw OutOfTabIndexException();
}

template <typename T>
void Vector<T>::push(T item) {
    if(size_ == capacity_)
        resize(capacity_);

    array_[size_] = item;
    size_++;
}


template <typename T>
void Vector<T>::resize(int size) {
    //pass
}

template <typename T>
void Vector<T>::moveRight(int index) {
    if(size_ == capacity_)
        resize(capacity_);
    for(int i = size_; i >= index; i--) {
        array_[i+1] = array_;
    }
}
template <typename T>
void Vector<T>::moveLeft(int index) {
    for(int i = index; i <= size_; i++) {
        array_[i] = array_[i+1];
    }
}

template <typename T>
void Vector<T>::insert(int index, T value) {
    moveLeft(index);
    array_[index] = value;
}

template <typename T>
void Vector<T>::Delete(int index) {
    moveRight(index);
    size_--;
}
template <typename T>
int Vector<T>::pop() {
    if(size_ == 0)
        throw EmptyVectorException();
    else {
        size_--;
        return array_[size_+1];
    }
}

template <typename T>
void Vector<T>::remove(T item) {
    if(size_ == 0) {
        throw EmptyVectorException();
    } else {
        for(int i = 0; i <= size_; i++)
            if(array_[i] == item)
                Delete(i);
    }
}

template <typename T>
int Vector<T>::find(T item) {
    for(int i= 0; i <= size_; i++)
        if(array_[i] == item)
            return i;
    return -1;
}



template <typename T>
T Vector<T>::operator=(int index) {
    return at(index);
}