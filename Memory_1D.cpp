/*********************************************************************
 * Copyright © 2011-2013,
 * Marwan Abdellah: <abdellah.marwan@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 ********************************************************************/

/// Memory_1D.cpp

#include "Memory_1D.h" /// Interface
#include "Memory_1D.ipp" /// Implementation

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template char* YURI_MEM_1D_NS::Allocate <char>(const int X);
template short* YURI_MEM_1D_NS::Allocate <short>(const int X);
template int* YURI_MEM_1D_NS::Allocate <int>(const int X);
template float* YURI_MEM_1D_NS::Allocate <float>(const int X);
template double* YURI_MEM_1D_NS::Allocate <double>(const int X);

template bool YURI_MEM_1D_NS::Free(char* pData);
template bool YURI_MEM_1D_NS::Free(short* pData);
template bool YURI_MEM_1D_NS::Free(int* pData);
template bool YURI_MEM_1D_NS::Free(float* pData);
template bool YURI_MEM_1D_NS::Free(double* pData);


#ifdef USE_FFTWF
template fftwf_compelx* YURI_MEM_1D_NS::Allocate(const int X);

template bool YURI_MEM_1D_NS::Free(fftwf_compelx* pData);
#endif

#ifdef USE_FFTW
template fftw_compelx* YURI_MEM_1D_NS::Allocate(const int X);

template bool YURI_MEM_1D_NS::Free(fftw_compelx* pData);
#endif

#ifdef USE_CUFFT
template cufftReal* YURI_MEM_1D_NS::Allocate(const int X);
template cufftDoubleReal* YURI_MEM_1D_NS::Allocate(const int X);
template cufftComplex* YURI_MEM_1D_NS::Allocate(const int X);
template cufftDoubleComplex* YURI_MEM_1D_NS::Allocate(const int X);

template bool YURI_MEM_1D_NS::Free(cufftReal* pData);
template bool YURI_MEM_1D_NS::Free(cufftDoubleReal* pData);
template bool YURI_MEM_1D_NS::Free(cufftComplex* pData);
template bool YURI_MEM_1D_NS::Free(cufftDoubleComplex* pData);
#endif

