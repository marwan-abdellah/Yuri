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

/// Memory_2D.h

#ifndef Memory_2D_H
#define Memory_2D_H

namespace Yuri
{
namespace Memory
{
namespace Memory_2D
{
// Memory allocation
template <typename T>
T** Allocate(const int X, const int Y);

// Memory release
template <typename T>
bool Free(T** pData, const int X, const int Y);
}
}
}

#endif // Memory_2D_H
