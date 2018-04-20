//
// Created by majaku on 20.04.18.
//

#ifndef VECTOR_EXCEPTIONS_H
#define VECTOR_EXCEPTIONS_H
#include <exception>
using namespace std;

struct OutOfTabIndexException : public exception
{
    const char* what() const throw()
    {
        return "you try to get item at index bigger than size of array";
    }
};

struct EmptyVectorException: public exception {
    const char* what() const throw() {
        return "you try to pop element from empty vector";
    }
};
#endif //VECTOR_EXCEPTIONS_H
