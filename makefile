.PHONY: all clean

# Define required variables
PROJECT_NAME	   ?= zhuohongsan
RAYLIB_VERSION	   ?= 3.8.0
RAYLIB_PATH		   ?= raylib

# Define default options

# One of PLATFORM_DESKTOP, PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
PLATFORM		   ?= PLATFORM_WEB

# Locations of your newly installed library and associated headers.
DESTDIR				  ?= /usr/local
RAYLIB_INSTALL_PATH	  ?= $(DESTDIR)/lib
RAYLIB_H_INSTALL_PATH ?= $(DESTDIR)/include
RAYLIB_LIBTYPE		  ?= STATIC
BUILD_MODE			  ?= RELEASE
USE_EXTERNAL_GLFW	  ?= FALSE
USE_WAYLAND_DISPLAY	  ?= FALSE

# Emscripten required variables
EMSDK_PATH		   ?= D:/program/emsdk
EMSCRIPTEN_PATH	   ?= $(EMSDK_PATH)/upstream/emscripten
CLANG_PATH			= $(EMSDK_PATH)/upstream/bin
PYTHON_PATH			= $(EMSDK_PATH)/python/3.9.2-1_64bit
NODE_PATH			= $(EMSDK_PATH)/node/14.15.5_64bit/bin
export PATH			= $(EMSDK_PATH);$(EMSCRIPTEN_PATH);$(CLANG_PATH);$(NODE_PATH);$(PYTHON_PATH);C:\raylib\MinGW\bin:$$(PATH)

RAYLIB_RELEASE_PATH		?= $(RAYLIB_PATH)/src
EXAMPLE_RUNTIME_PATH   ?= $(RAYLIB_RELEASE_PATH)

CC = emcc
MAKE	?= make

CFLAGS += -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces

ifeq ($(BUILD_MODE),DEBUG)
	CFLAGS += -s ASSERTIONS=1 --profiling
else
	CFLAGS += -Os
endif

# CFLAGS += -s USE_GLFW=3 -s TOTAL_MEMORY=67108864 --preload-file resources
# CFLAGS += --shell-file $(RAYLIB_PATH)/src/shell.html
EXT = .html

INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external
LDFLAGS = -L. -L$(RAYLIB_RELEASE_PATH) -L$(RAYLIB_PATH)/src
LDLIBS = $(RAYLIB_RELEASE_PATH)/libraylib.a -s USE_GLFW=3

PROJECT_SOURCE_FILES ?= \
	snake.c

OBJS = $(patsubst %.c, %.o, $(PROJECT_SOURCE_FILES))

# Default target entry
all: $(PROJECT_NAME)

# Project target defined by PROJECT_NAME
$(PROJECT_NAME): $(OBJS)
	cmd /c if not exist web mkdir web
	$(CC) -o web/$(PROJECT_NAME)$(EXT) $(OBJS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -D$(PLATFORM) --shell-file $(RAYLIB_PATH)/src/shell.html
	cmd /c del $(OBJS)
# Compile source files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_PATHS) -D$(PLATFORM)

# Clean everything
clean:
	del *.o web/*.html web/*.js
	@echo Cleaning done