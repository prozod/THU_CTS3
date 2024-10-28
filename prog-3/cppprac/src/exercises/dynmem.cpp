#include <iostream>

void dynamic_array() {
    const int STARTSIZE = 4;
    int *pArray = new int[STARTSIZE]{2, 4, 6}; // dynamic alloc mem
    int size = STARTSIZE;
    int number = 3;
    int value;

    while (std::cin >> value) {
        if (number >= size) {
            //case: enlarge array
            int *pArrayNew = new int[2 * size];
            for (int i = 0; i < size; ++i) {
                // copy all values
                std::cout << "Copying " << pArray[i] << std::endl;
                pArrayNew[i] = pArray[i];
            }
            size *= 2;
            delete[] pArray;
            pArray = pArrayNew; // continue with new array

            std::cout << "--- NEW ARRAY CREATED ---" << size << std::endl;
        }
        pArray[number++] = value;
        std::cout << "Added " << value << " to the array." << std::endl;
        std::cout << "Array size is: " << size << " and contains values: " << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << "i: " << i << " has value: " << pArray[i] << std::endl;
        }
    }

    delete [] pArray;
}
