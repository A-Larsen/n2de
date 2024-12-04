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
