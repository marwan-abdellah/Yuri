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

/// Memory_3D.ipp

#ifndef MEMORY_3D_IPP
#define MEMORY_3D_IPP

#include <stdlib.h>
#include "Memory_3D.h"

// Namespace
namespace YURI_MEM_3D_NS = Yuri::Memory::Memory_3D;

template <typename T>
inline T*** YURI_MEM_3D_NS::Allocate(const int X, const int Y, const int Z)
{
    T*** pData;
    pData = (T***) malloc (sizeof(T**) * X);
    for(int i = 0; i < X; i++)
    {
        pData[i] = (T**) malloc (sizeof(T*) * Y);
        for (int j = 0; j < Y; j++)
            pData[i][j] = (T*) malloc (sizeof(T) * Z);
    }

    return pData;
}

template <typename T>
inline bool YURI_MEM_3D_NS::Free(T*** pData, const int X, const int Y, const int Z)
{
    for(int i = 0; i < Y; i++)
    {
        for(int j = 0; j < Z; j++)
            free(pData[i][j]);    // Z-axis release

        free(pData[i]);   // Y-axis release
    }

    free(pData);  // X-axis release

    // Avoiding dangling pointer
    pData = NULL ;

    // Ensure safe memory release
    if (pData == NULL)
        return true;

    return false;
}

#endif // MEMORY_3D_IPP
