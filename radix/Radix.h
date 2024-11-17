//
// Tiny experimentation with The Least Significant Digit Radix Sort
// (Took inspiration from the video "Visualization of Radix sort" - https://youtu.be/mVRHvZF8xtg?feature=shared&t=271
//

#ifndef RADIXUSAGE_RADIX_H
#define RADIXUSAGE_RADIX_H


class Radix {

    public:
        // Sort an array using LSD Radix Sort
        static void Sort(unsigned int* arrayToSort, const int size);

        // Generate an array filled with random numbers
        static unsigned int* GenerateArray(unsigned int *arrayPtr, const int size);

        // Display functions
        inline static void PrintVector(const std::vector<unsigned int> vector);
        static void PrintArray(unsigned int* array, const int size);
};

#endif //RADIXUSAGE_RADIX_H
