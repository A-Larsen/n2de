include config.mk

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
	$(CC) $^ $(CCFLAGS) -o game/$(GAME_NAME)$(EXECEXTENSION) $(LIBS)

libs: ./src/engine/error.c ./src/lua-libs/libs.c
	$(CC) $^ $(CCFLAGS) -shared $(EXTRA) -o lib$(LIBEXTENSION) $(LIBS)
	mv lib$(LIBEXTENSION) game/libs/

clean:
	rm -rf game/*.exe *.exe *.obj game/$(GAME_NAME)

.PHONY: clean
