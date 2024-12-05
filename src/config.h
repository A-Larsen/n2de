/* 
 * Copyright (C) 2024  Austin Larsen
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef _N2DE_CONFIG_H_
#define _N2DE_CONFIG_H_

#include <stdio.h>
#include <stdbool.h>
#if defined(_WIN32)
#include "/mnt/c/Libraries/lua54/include/lua.h"
#include "/mnt/c/Libraries/lua54/include/lauxlib.h"
#include "/mnt/c/Libraries/lua54/include/lualib.h"
#include "/mnt/c/Libraries/SDL2-2.30.9/include/SDL.h"
#include "/mnt/c/Libraries/sqlite3/include/sqlite3.h"
#include "/mnt/c/Libraries/GLEW/include/GL/glew.h"
#else
#include <lua5.4/lua.h>
#include <lua5.4/lauxlib.h>
#include <lua5.4/lualib.h>
#include <SDL2/SDL.h>
#include <sqlite3.h>
#include <GL/gl.h>
#include <GLES3/gl3.h>
#endif

#endif // _N2DE_CONFIG_H_
