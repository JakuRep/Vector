#include <iostream>
#include "Vector.h"
int main() {
    Vector<int> vector;
    for(int i = 0; i < 100; i++) {
        vector.push(i%13);
    }
    vector.remove(11);
    vector.display();

    return 0;
}