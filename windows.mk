# 
# Copyright (C) 2024  Austin Larsen
# 
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; either version 2 of the License, or (at your option) any later
# version.
# 
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
# 
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 51
# Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# 
CC = x86_64-w64-mingw32-gcc

LIBS = -lopengl32\
	   /mnt/c/Libraries/lua54/lua54.lib \
	   /mnt/c/Libraries/SDL2-2.30.9/lib/x64/SDL2.lib

SHARED = -shared
CFLAGS =
