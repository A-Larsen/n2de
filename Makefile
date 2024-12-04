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
	$(CC) $^ $(CCFLAGS) -o $(GAME_NAME)/$(GAME_NAME)$(EXECEXTENSION) $(LIBS)

stdlib: ./src/engine/error.c ./src/lua_libraries/stdlib.c
	$(CC) $^ $(CCFLAGS) -shared $(EXTRA) -o lib$(LIBEXTENSION) $(LIBS)
	mv lib$(LIBEXTENSION) $(GAME_NAME)/stdlib/

clean:
	rm -rf game/*.exe *.exe *.obj $(GAME_NAME)/$(GAME_NAME)


.PHONY: clean
