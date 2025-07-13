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
GLFWwindow *window = NULL;

int init(lua_State *L) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return 0;
}

int createWindow(lua_State *L) {
    window = glfwCreateWindow(800, 800, "game", NULL, NULL);
    if (window == NULL) {
        N2DE_ERROR("could not create glfw window\n");
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        N2DE_ERROR("could not initialize glew\n");
    }
    glViewport(0, 0, 800, 800);
    printf("opengl version: %s\n", glGetString(GL_VERSION));

    /* GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); */

    glClearColor(.5,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    float width = .5;
    GLfloat v1[] = {-width, 0};
    GLfloat v2[] = {width, 0};

    glColor3f(.0f,.0f,.0f);

    glBegin(GL_LINES);
        glVertex2fv(v1);
        glVertex2fv(v2);
    glEnd();
    glfwSwapBuffers(window);
    return 0;

}
int getKey(lua_State *L) {
    return 0;
}

int delay(lua_State *L) {
    SDL_Delay(1000);
    return 0;
}

int quit(lua_State *L) {
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

luaL_Reg test[] = {
    {"init", init},
    {"createWindow", createWindow},
    {"delay", delay},
    {"quit", quit},
    {"getKey", getKey},
    {NULL, NULL}
};

int luaopen_libs_stdlib_lib(lua_State *L)
{
    luaL_newlib(L, test);
    return 1;
}

