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
#include "n2de.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

GLFWwindow *window = NULL;
int main(int argc, char* argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    while (!glfwWindowShouldClose(window)) {
        glClearColor(.5,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        float width = .5;
        GLfloat v1[] = {-width, 0};
        GLfloat v2[] = {width, 0};

        glColor3f(.0f,.5f,.5f);

        glBegin(GL_LINES);
            glVertex2fv(v1);
            glVertex2fv(v2);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    /* lua_State *L = luaL_newstate(); */
    /* luaL_openlibs(L); */

    /* if (luaL_dofile(L, "./init.lua") != LUA_OK) */
    /*     N2DE_ERROR("Error reading script"); */

    /* lua_close(L); */

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
