#Header components, Flags, Sources, Libraries, and Locations to be compiled.

CC=gcc
###Extra c flags
CFLAGS=-g -O2  -Wall -Wextra -Isrc -rdynamic -fpie -D_FORTIFY_SOURCE=2 -fstack-protector-all -Werror=format-security -DNDEBUG  $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/Users/promisedland/Desktop/CompSci/My_Github/C_recipes/Project

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

###Change TARGET
TARGET=build/slidingwin
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

###Change EXECUTABLE
EXECUTABLE=bin/windowOne

#Target Build Components and Flag options
.PHONY: all dev clean install
all: $(TARGET) $(SO_TARGET) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIBS)

dev: CFLAGS=-g -Wall  -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

#Cleaning 
clean:
	rm -rf build $(OBJECTS) $(TESTS) $(EXECUTABLE) 
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

#Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/
