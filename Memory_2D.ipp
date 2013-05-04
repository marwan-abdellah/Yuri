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

/// Memory_2D.ipp

#ifndef MEMORY_2D_IPP
#define MEMORY_2D_IPP

#include <stdlib.h>
#include "Memory_2D.h"

// Namespace
namespace YURI_MEM_2D_NS = Yuri::Memory::Memory_2D;

template <typename T>
inline T** YURI_MEM_2D_NS::Allocate(const int X, const int Y)
{
    T** pData = (T**) malloc (sizeof(T*) * X);
    for(int i = 0; i < X; i++)
        pData[i] = (T*) malloc (sizeof(T) * Y);

    return pData;
}

template <typename T>
inline bool YURI_MEM_2D_NS::Free(T** pData, const int X, const int Y)
{
    // Y-axis release
    for (int i = 0; i < Y; i++)
        free(pData[i]);

    // X-axis release
    free(pData);

    // Avoiding dangling pointer
    pData = NULL ;

    // Ensure safe memory release
    if (pData == NULL)
        return true;

    return false;
}

#endif // MEMORY_2D_IPP

