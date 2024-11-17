#include <iostream>
#include <random>

#include "Radix/Radix.h"

//
// Tiny experimentation with The Least Significant Digit Radix Sort
//

int main() {

    int size;
    std::cout << "Enter a size for your array:";
    std::cin >> size;

    std::cout << "You enter " << size << std::endl;

    unsigned int *array = new unsigned int[size];

    Radix::GenerateArray(array, size);

    Radix::PrintArray(array, size);

    Radix::Sort(array, size);

    Radix::PrintArray(array, size);

    delete array;

    return 0;
}
