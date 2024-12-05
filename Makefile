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
include config.mk

SHELL := /bin/bash

EXECEXTENSION=

# determine operating system
ifdef LINUX
	include linux.mk
	LIBEXTENSION = .so
else 
	include windows.mk
	LIBEXTENSION = .dll
	EXECEXTENSION = .exe
	CCFLAGS += -D _WIN32
endif

all: n2de database error files memory
	@eval ./scripts/game_folder_check $(GAME_NAME)
	$(CC) $(CCFLAGS) -o $(GAME_NAME)/$(GAME_NAME)$(EXECEXTENSION) *.o $(LIBS)

n2de: src/n2de/n2de.c
	$(CC) -c $^ -o $@.o

database: src/n2de/database.c
	$(CC) -c $^ -o $@.o

error: src/n2de/error.c 
	$(CC) -c $^ -o $@.o

files: src/n2de/files.c
	$(CC) -c $^ -o $@.o

memory: src/n2de/memory.c
	$(CC) -c $^ -o $@.o

lib: ./src/n2de/error.c ./src/lua_libraries/$(LIB).c
	$(CC) $^ $(CCFLAGS) $(SHARED) -o lib$(LIBEXTENSION) $(LIBS)
	mkdir -p $(GAME_NAME)/libs/$(LIB)
	mv lib$(LIBEXTENSION) $(GAME_NAME)/libs/$(LIB)/

clean:
	rm -rf $(GAME_NAME)/$(GAME_NAME) $(GAME_NAME)/$(GAME_NAME).exe *.o


.PHONY: clean
