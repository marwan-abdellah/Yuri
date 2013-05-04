#ifndef FLATIMAGE_H
#define FLATIMAGE_H

#include <stdlib.h>
#include "Memory_1D.h"

// Namespace
namespace YURI_MEM_1D = Yuri::Memory::Memory_1D;

namespace Yuri
{
template <typename T>
struct FlatImage
{
public:
    // Constructor
    FlatImage( const int iX, const int iY ): X( iX ), Y( iY )
    {
        // Image size (number of pixels)
        const int imageSize = X * Y;

        // Allocate image data
        pData = YURI_MEM_1D::Allocate <T> (imageSize);
    }

    // Retruns X dimension
    int GetX( void ) const { return X; }

    // Retruns Y dimension
    int GetY( void ) const { return Y; }

    // Retruns a pointer to the image 2D data in arranged in a flast 1D array
    T* GetPImageData( void ) { return pData; }

    // Destructor
    ~FlatImage( void )
    {
        YURI_MEM_1D::Free <T>( pData );
    }

private:
    const int X;    // Width - X-axis
    const int Y;    // Height - Y-axis

    // Pointer to image data in 1D array
    T* pData;
};

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template class FlatImage<char>;                /// char
template class FlatImage<short>;               /// short
template class FlatImage<int>;                 /// int
template class FlatImage<float>;               /// float
template class FlatImage<double>;              /// double

#ifdef USE_FFTWF
template class FlatImage<fftwf_compelx>;       /// fftwf_compelx
#endif

#ifdef USE_FFTW
template class FlatImage<fftw_compelx>;        /// fftw_compelx
#endif

#ifdef USE_CUFFT
template class FlatImage<cufftReal>;           /// cufftReal
template class FlatImage<cufftDoubleReal>;     /// cufftDoubleReal
template class FlatImage<cufftComplex>;        /// cufftComplex
template class FlatImage<cufftDoubleComplex>;  /// cufftDoubleComplex
#endif
///////////////////////////////////////////////////////////////////////////////
}

#endif // FLATIMAGE_H
