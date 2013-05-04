#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"
#include "Definitions.h"

int main()
{
    std::cout << "Testing Vector Operators !!!" << std::endl;

    // Vector length
    const int NX = 10;

    // Construct two integer vectors
    Yuri::Vector<int> *vec1, *vec2;
    vec1 = new Yuri::Vector<int>(NX);
    vec2 = new Yuri::Vector<int>(NX * 2);

    // Fill the vectosr with linear numbers starting from 0
    vec1->Linear();
    vec2->Linear();

    // Print the vectors
    std::cout << "Vector 1" << std::endl; vec1->Print();
    std::cout << "Vector 2" << std::endl; vec2->Print();

    // Add vector 2 to vector 1
    vec1->operator +(vec2);

    // Print the first vector after adding the second one to it
    vec1->Print();

    // Free the vector
    delete vec1;
    delete vec2;

    return 0;
}
