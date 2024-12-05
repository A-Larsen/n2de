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
#include "stdlib.h"
/* SDL_Window *window = NULL; */
/* SDL_GLContext context = NULL; */

int init(lua_State *L) {
    /* if (SDL_Init(SDL_INIT_VIDEO) != 0) */
    /*     N2DE_ERROR("Cannot init video"); */

    /* printf("sup man!\n"); */
    return 0;
}

int createWindow(lua_State *L) {
    /* window = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, */ 
    /*                                     SDL_WINDOWPOS_UNDEFINED, 800, 800, */ 
    /*                                     SDL_WINDOW_OPENGL | */
    /*                                     SDL_WINDOW_RESIZABLE); */
    /* context = SDL_GL_CreateContext(window); */

    /* GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); */


    /* SDL_GL_SwapWindow(window); */

    return 0;

}

int delay(lua_State *L) {
    /* SDL_Delay(1000); */
    return 0;
}


int quit(lua_State *L) {
    /* SDL_DestroyWindow(window); */
    /* SDL_GL_DeleteContext(window); */
    /* SDL_Quit(); */
    return 0;
}

luaL_Reg test[] = {
    {"init", init},
    {"createWindow", createWindow},
    {"delay", delay},
    {"quit", quit},
    {NULL, NULL}
};

int luaopen_libs_stdlib_lib(lua_State *L)
{
    luaL_newlib(L, test);
    return 1;
}

