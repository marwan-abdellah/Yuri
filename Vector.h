#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <iostream>
#include <typeinfo>

#include "Memory_1D.h"

// Namespace
namespace YURI_MEM_1D_NS = Yuri::Memory::Memory_1D;

namespace Yuri
{
template <typename T>
struct Vector
{
public:
    // Constructor
    Vector(const int iX): X(iX)
    {
        // Allocate Vector data chunk
        pData = YURI_MEM_1D_NS::Allocate <T> (X);

        // Initialize the vector to zeros
        this->Zeros();
    }

    // Fill the vector with random numbers
    void Random( void )
    {
        for (int i = 0; i < X; i++)
            pData[i] = (T) rand();
    }

    // Fill the vector with constant values
    void Constant( const T iValue )
    {
        for (int i = 0; i < X; i++)
            pData[i] = (T) iValue;
    }

    // Fill the vector with zeros
    void Zeros( void )
    {
       this->Constant(0);
    }

    // Fill the vector with zeros
    void Ones( void )
    {
       this->Constant(1);
    }

    // Fill the vector with continuous numbers starting 0
    void Linear( void )
    {
        for (int i = 0; i < X; i++)
            pData[i] = (T) i;
    }

    // Print the vector to the standard output
    void Print( void )
    {
        for (int i = 0; i < X; i++)
            std::cout << (T) pData[i] << std::endl;
        std::cout << std::endl;
    }

    // Retruns X dimension
    int GetX( void ) const { return X; }

    // Retruns a pointer to the Vector 2D data in arranged in a flast 1D array
    T* GetPVectorData( void ) { return pData; }

    // Destructor
    ~Vector ( void )
    {
        // Free Vector data
        YURI_MEM_1D_NS::Free <T> (pData);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// Operators
    ///////////////////////////////////////////////////////////////////////////////
    // Addition
    void operator+(const Vector *iVector)
    {
        if (X != iVector->GetX())
        {
            std::cout << "The vectors can't be added because " <<
                         "they don't have the same size" << std::endl;

            return;
        }
        for (int i = 0; i < X; i++)
            this->pData[i] += (T) iVector->GetPVectorData()[i];
    }

    // Subtraction
    void operator+(const Vector *iVector)
    {
        if (X != iVector->GetX())
        {
            std::cout << "The vectors can't be added because " <<
                         "they don't have the same size" << std::endl;

            return;
        }
        for (int i = 0; i < X; i++)
            this->pData[i] += (T) iVector->GetPVectorData()[i];
    }

private:
    const int X;    // Vector length

    // Pointer to Vector data in 1D array
    T* pData;
};

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template class Vector<char>;                /// char
template class Vector<short>;               /// short
template class Vector<int>;                 /// int
template class Vector<float>;               /// float
template class Vector<double>;              /// double

#ifdef USE_FFTWF
template class Vector<fftwf_compelx>;       /// fftwf_compelx
#endif

#ifdef USE_FFTW
template class Vector<fftw_compelx>;        /// fftw_compelx
#endif

#ifdef USE_CUFFT
template class Vector<cufftReal>;           /// cufftReal
template class Vector<cufftDoubleReal>;     /// cufftDoubleReal
template class Vector<cufftComplex>;        /// cufftComplex
template class Vector<cufftDoubleComplex>;  /// cufftDoubleComplex
#endif
///////////////////////////////////////////////////////////////////////////////
}

#endif // VECTOR_H
