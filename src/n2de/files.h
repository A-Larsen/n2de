/* 
 * Copyright (C) 2022  Austin Larsen
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
#ifndef N2DE_FILES_H_
#define N2DE_FILES_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#define F_OK 0
#define access _access
#define MKDIR(path) CreateDirectoryA((LPCSTR)path, NULL);
#else
#include <sys/stat.h>
#define MKDIR(path) mkdir(path, 0700);
#include <unistd.h>
#endif

void getDataPath(char *path, const char *type, const uint8_t index);
void removeDir(const char *path);
void touch(const char *path);
int fileno(FILE *stream);
uint32_t fileSize(FILE *fp);
long int fileToStr(FILE *fp, char *str);

#endif // N2DE_FILES_H_
