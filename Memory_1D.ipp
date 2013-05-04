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

/// Memory_1D.ipp

#ifndef MEMORY_1D_IPP
#define MEMORY_1D_IPP

#include <stdlib.h>
#include "Memory_1D.h" /// Interface

// Namespace
namespace YURI_MEM_1D_NS = Yuri::Memory::Memory_1D;

template <typename T>
inline T* YURI_MEM_1D_NS::Allocate(const int X)
{
    T* pData = (T*) malloc (sizeof(T) * X);
    return pData;
}

template <typename T>
inline bool YURI_MEM_1D_NS::Free(T* pData)
{
    free(pData);

    // Avoiding dangling pointer
    pData = NULL ;

    // Ensure safe memory release
    if (pData == NULL)
        return true;

    return false;
}

#endif // MEMORY_1D_IPP
