#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"
#include "Definitions.h"

using namespace std;

int main()
{
    cout << "Testing Vector !!!" << endl;

    // Vector length
    const int NX = 100;

    ///////////////////////////////////////////////////////////////////////////
    // Construct a char vector
    Yuri::Vector<char>* vectChar = new Yuri::Vector<char>(NX);

    // Fill the vector with random numbers
    vectChar->Random();

    // Print the vector
    vectChar->Print();

    // Free the vector
    delete vectChar;

    ///////////////////////////////////////////////////////////////////////////
    // Construct a short vector
    Yuri::Vector<short>* vectShort= new Yuri::Vector<short>(NX);

    // Fill the vector with random numbers
    vectShort->Random();

    // Print the vector
    vectShort->Print();

    // Free the vector
    delete vectShort;

    ///////////////////////////////////////////////////////////////////////////
    // Construct an integer vector
    Yuri::Vector<int>* vectInt = new Yuri::Vector<int>(NX);

    // Fill the vector with random numbers
    vectInt->Random();

    // Print the vector
    vectInt->Print();

    // Free the vector
    delete vectInt;

    ///////////////////////////////////////////////////////////////////////////
    // Construct an float vector
    Yuri::Vector<float>* vectFloat = new Yuri::Vector<float>(NX);

    // Fill the vector with random numbers
    vectFloat->Random();

    // Print the vector
    vectFloat->Print();

    // Free the vector
    delete vectFloat;

    ///////////////////////////////////////////////////////////////////////////
    // Construct an double vector
    Yuri::Vector<double>* vectDouble = new Yuri::Vector<double>(NX);

    // Fill the vector with random numbers
    vectDouble->Random();

    // Print the vector
    vectDouble->Print();

    // Free the vector
    delete vectDouble;

    return 0;
}
