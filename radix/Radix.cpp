//
// Created by theoc on 17/11/2024.
//

#include <iostream>
#include <vector>
#include <random>
#include "Radix.h"

void Radix::Sort(unsigned int *arrayToSort, const int size)
{
    std::cout << "Begin Radix sorting" << std::endl;

    int bitComparator = 1;

    for (int bit = 0; bit < 32; ++bit)
    {
        std::vector<unsigned int> radixVectors[2];

        // Separate array into 2 vectors with bit comparison
        for (int i = 0; i < size; ++i)
        {
            bool bitTest = arrayToSort[i] & bitComparator;

            radixVectors[bitTest].push_back(arrayToSort[i]);
        }

        // overide array with 2 vectors
        for (int v0 = 0; v0 < radixVectors[0].size(); ++v0)
            arrayToSort[v0] = radixVectors[0][v0];

        for (int v1 = 0; v1 < radixVectors[1].size(); ++v1)
            arrayToSort[radixVectors[0].size() + v1] = radixVectors[1][v1];

//        std::cout << "V0: " << std::endl;
//        PrintVector(radixVectors[0]);
//        std::cout << "V1: " << std::endl;
//        PrintVector(radixVectors[1]);
//
//        PrintArray(arrayToSort, size);

        bitComparator <<= 1;
    }

    std::cout << "Finish Radix sorting\n" << std::endl;
}


unsigned int* Radix::GenerateArray(unsigned int *arrayPtr, const int size)
{
    std::mt19937 mt{ std::random_device{}() }; // Instantiate a 32-bit Mersenne Twister

    // Print a bunch of random numbers
    for (int count = 0; count < size; ++count)
        arrayPtr[count] = mt();

    return arrayPtr;
}


void Radix::PrintVector(const std::vector<unsigned int> vector)
{
    std::string message;

    for (int i = 0; i < vector.size(); ++i)
        message += std::to_string(i) + " - " + std::to_string(vector[i]) + "\n";

    std::cout << message << std::endl;

}

void Radix::PrintArray(unsigned int* array, const int size)
{
    std::cout << "Array of " << std::to_string(size) << " elements:" << std::endl;

    std::string message;
    for (int i=0; i < size; ++i)
        message += std::to_string(i) + " - " + std::to_string(*(array+i)) + "\n";

    std::cout << message << std::endl;
}