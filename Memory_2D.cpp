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

/// Memory_2D.cpp

#include "Memory_2D.h" /// Interface
#include "Memory_2D.ipp" /// Implementation

///////////////////////////////////////////////////////////////////////////////
/// Template struct explicit instantiation
///////////////////////////////////////////////////////////////////////////////
template char** YURI_MEM_2D_NS::Allocate <char>(const int X, const int Y);
template short** YURI_MEM_2D_NS::Allocate <short>(const int X, const int Y);
template int** YURI_MEM_2D_NS::Allocate <int>(const int X, const int Y);
template float** YURI_MEM_2D_NS::Allocate <float>(const int X, const int Y);
template double** YURI_MEM_2D_NS::Allocate <double>(const int X, const int Y);

template bool YURI_MEM_2D_NS::Free <char> (char** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free <short> (short** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free <int> (int** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free <float> (float** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free <double> (double** pData, const int X, const int Y);

#ifdef USE_FFTWF
template fftwf_compelx** YURI_MEM_2D_NS::Allocate(const int X, const int Y);

template bool YURI_MEM_2D_NS::Free(fftwf_compelx** pData, const int X, const int Y);
#endif

#ifdef USE_FFTW
template fftw_compelx** YURI_MEM_2D_NS::Allocate(const int X, const int Y);

template bool YURI_MEM_2D_NS::Free(fftw_compelx** pData, const int X, const int Y);
#endif

#ifdef USE_CUFFT
template cufftReal** YURI_MEM_2D_NS::Allocate(const int X, const int Y);
template cufftDoubleReal** YURI_MEM_2D_NS::Allocate(const int X, const int Y);
template cufftComplex** YURI_MEM_2D_NS::Allocate(const int X, const int Y);
template cufftDoubleComplex** YURI_MEM_2D_NS::Allocate(const int X, const int Y);

template bool YURI_MEM_2D_NS::Free(cufftReal** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free(cufftDoubleReal** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free(cufftComplex** pData, const int X, const int Y);
template bool YURI_MEM_2D_NS::Free(cufftDoubleComplex** pData, const int X, const int Y);
#endif

