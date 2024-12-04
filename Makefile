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

build: src/engine/*.c
	@eval ./scripts/game_folder_check $(GAME_NAME)
	$(CC) $^ $(CCFLAGS) -o $(GAME_NAME)/$(GAME_NAME)$(EXECEXTENSION) $(LIBS)

lib: ./src/engine/error.c ./src/lua_libraries/$(LIB).c
	$(CC) $^ $(CCFLAGS) -shared $(EXTRA) -o lib$(LIBEXTENSION) $(LIBS)
	mv lib$(LIBEXTENSION) $(GAME_NAME)/$(LIB)/

clean:
	rm -rf game/*.exe *.exe *.obj $(GAME_NAME)/$(GAME_NAME)


.PHONY: clean
