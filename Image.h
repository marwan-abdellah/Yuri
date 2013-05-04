#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>
#include "Memory_2D.h"

// Namespace
namespace YURI_MEM_2D_NS = Yuri::Memory::Memory_2D;

namespace Yuri
{
template <typename T>
struct Image
{
public:
    // Constructor
    Image(const int iX, const int iY): X(iX), Y(iY)
    {
        // Allocate image data chumk
        pData = YURI_MEM_2D_NS::Allocate <T> (X, Y);
    }

    // Retruns X dimension
    int GetX( void ) const { return X; }

    // Retruns Y dimension
    int GetY( void ) const { return Y; }

    // Retruns a pointer to the Image 2D data in arranged in a flast 1D array
    T** GetPImageData( void ) { return pData; }

    // Destructor
    ~Image ( void )
    {
        // Free image data
        YURI_MEM_2D_NS::Free <T> (pData, X, Y);
    }

private:
    const int X;    // Width - X-axis
    const int Y;    // Height - Y-axis

    // Pointer to Image data in 2D array
    T** pData;
};

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template class Image<char>;                /// char
template class Image<short>;               /// short
template class Image<int>;                 /// int
template class Image<float>;               /// float
template class Image<double>;              /// double

#ifdef USE_FFTWF
template class Image<fftwf_compelx>;       /// fftwf_compelx
#endif

#ifdef USE_FFTW
template class Image<fftw_compelx>;        /// fftw_compelx
#endif

#ifdef USE_CUFFT
template class Image<cufftReal>;           /// cufftReal
template class Image<cufftDoubleReal>;     /// cufftDoubleReal
template class Image<cufftComplex>;        /// cufftComplex
template class Image<cufftDoubleComplex>;  /// cufftDoubleComplex
#endif
///////////////////////////////////////////////////////////////////////////////
}

#endif // IMAGE_H
