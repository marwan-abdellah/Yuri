#ifndef VOLUME_H
#define VOLUME_H

#include <stdlib.h>
#include "Memory_3D.h"

// Namespace
namespace YURI_MEM_3D_NS = Yuri::Memory::Memory_3D;

namespace Yuri
{
template <typename T>
struct Volume
{
public:
    // Constructor
    Volume(const int iX, const int iY, const int iZ): X(iX), Y(iY), Z(iZ)
    {
        int XX = iX;
        // Allocate data chunk
        pData = YURI_MEM_3D_NS::Allocate <T> (X, Y, Z);
    }

    // Retruns X dimension
    int GetX( void ) const { return X; }

    // Retruns Y dimension
    int GetY( void ) const { return Y; }

    // Retruns Z dimension
    int GetZ( void ) const { return Z; }

    // Retruns a pointer to the volume 3D data in arranged in a flast 1D array
    T*** GetPVolumeData( void ) { return pData; }

    // Destructor
    ~Volume( void )
    {
        // Free volume data
        YURI_MEM_3D_NS::Free <T> (pData, X, Y, Z);

        //TODO:: Add exception if the data is not released
    }

private:
    const int X;    // Width - X-axis
    const int Y;    // Height - Y-axis
    const int Z;    // Depth - Z-axis

    // Pointer to volume data in 1D array
    T*** pData;
};

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template class Volume<char>;                /// char
template class Volume<short>;               /// short
template class Volume<int>;                 /// int
template class Volume<float>;               /// float
template class Volume<double>;              /// double

#ifdef USE_FFTWF
template class Volume<fftwf_compelx>;       /// fftwf_compelx
#endif

#ifdef USE_FFTW
template class Volume<fftw_compelx>;        /// fftw_compelx
#endif

#ifdef USE_CUFFT
template class Volume<cufftReal>;           /// cufftReal
template class Volume<cufftDoubleReal>;     /// cufftDoubleReal
template class Volume<cufftComplex>;        /// cufftComplex
template class Volume<cufftDoubleComplex>;  /// cufftDoubleComplex
#endif
///////////////////////////////////////////////////////////////////////////////
}

#endif // VOLUME_H
