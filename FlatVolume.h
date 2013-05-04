#ifndef FLATVOLUME_H
#define FLATVOLUME_H

#include <stdlib.h>
#include "Memory_1D.h"

// Namespace
namespace YURI_MEM_1D_NS = Yuri::Memory::Memory_1D;

namespace Yuri
{
template <typename T>
struct FlatVolume
{
public:
    // Constructor
    FlatVolume(const int iX, const int iY, const int iZ): X(iX), Y(iY), Z(iZ)
    {
        // Volume size (number of voxels)
        const int volumeSize = X * Y * Z;

        // Allocate volume data
        pData = YURI_MEM_1D_NS::Allocate <T> (volumeSize);
    }

    // Retruns X dimension
    int GetX( void ) const { return X; }

    // Retruns Y dimension
    int GetY( void ) const { return Y; }

    // Retruns Z dimension
    int GetZ( void ) const { return Z; }

    // Retruns a pointer to the volume 3D data in arranged in a flast 1D array
    T* GetPVolumeData( void ) { return pData; }

    // Destructor
    ~FlatVolume( void )
    {
        // Release the volume data
        free( pData );
    }

private:
    const int X;    // Width - X-axis
    const int Y;    // Height - Y-axis
    const int Z;    // Depth - Z-axis

    // Pointer to volume data in 1D array
    T* pData;
};

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template class FlatVolume<char>;                /// char
template class FlatVolume<short>;               /// short
template class FlatVolume<int>;                 /// int
template class FlatVolume<float>;               /// float
template class FlatVolume<double>;              /// double

#ifdef USE_FFTWF
template class FlatVolume<fftwf_compelx>;       /// fftwf_compelx
#endif

#ifdef USE_FFTW
template class FlatVolume<fftw_compelx>;        /// fftw_compelx
#endif

#ifdef USE_CUFFT
template class FlatVolume<cufftReal>;           /// cufftReal
template class FlatVolume<cufftDoubleReal>;     /// cufftDoubleReal
template class FlatVolume<cufftComplex>;        /// cufftComplex
template class FlatVolume<cufftDoubleComplex>;  /// cufftDoubleComplex
#endif
///////////////////////////////////////////////////////////////////////////////
}

#endif // FLATVOLUME_H
