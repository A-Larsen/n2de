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
SDL_Window *window = NULL;

int init(lua_State *L) {
    bool canInit = SDL_Init(SDL_INIT_VIDEO);
    PTP_LOG_ERROR(canInit != 0, "Cannot init video");
    printf("sup man!\n");
    return 0;
}

int createWindow(lua_State *L) {
    window = SDL_CreateWindow("PTP", SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SCREEN_WIDTH_PX, SCREEN_HEIGHT_PX,
                                     SDL_WINDOW_SHOWN);
    return 0;

}

int delay(lua_State *L) {
    SDL_Delay(1000);
    return 0;
}

int quit(lua_State *L) {
    SDL_DestroyWindow(window);
    return 0;
}

luaL_Reg test[] = {
    {"init", init},
    {"createWindow", createWindow},
    {"delay", delay},
    {"quit", quit},
    {NULL, NULL}
};

int luaopen_stdlib_lib(lua_State *L)
{
    luaL_newlib(L, test);
    return 1;
}

