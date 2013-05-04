#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
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
        // Allocate Vector data chumk
        pData = YURI_MEM_1D_NS::Allocate <T> (X);
    }

    // Retruns X dimension
    int GetX( void ) const { return X; }

    // Retruns a pointer to the Vector 2D data in arranged in a flast 1D array
    T** GetPVectorData( void ) { return pData; }

    // Destructor
    ~Vector ( void )
    {
        // Free Vector data
        YURI_MEM_1D_NS::Free <T> (pData);
    }

private:
    const int X;    // Width - X-axis
    const int Y;    // Height - Y-axis

    // Pointer to Vector data in 2D array
    T** pData;
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
