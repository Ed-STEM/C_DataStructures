UNAME_S := $(shell uname -s)

#Header components, Flags, Sources, Libraries, and Locations to be compiled.
CC=clang 
###Extra c flags  -Isrc
CFLAGS=-g -O0  -Wall -Wextra -Isrc  $(OPTFLAGS)
ifeq ($(UNAME_S),Darwin)
	INCLUDES=-I/opt/homebrew/opt/gsl/include 
	LDLIBS=-L/opt/homebrew/opt/gsl/lib $(OPTLIBS)
endif
ifeq ($(UNAME_S),Linux)
	INCLUDES= -I/usr/include/gsl
	LDLIBS=-L/usr/lib64 $(OPTLIBS)
endif
LIBS=-lgsl -lgslcblas -lm $(OPTLIBS)

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_test.c)
#TESTS=$(patsubst %.c,%.so,$(TEST_SRC))
TESTS=$(patsubst tests/%.c,bin/%,$(TEST_SRC))


TARGET=build/count
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

EXECUTABLE=bin/count

#Target Build Components and Flag options
.PHONY: all dev clean install
all: $(TARGET) $(SO_TARGET) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJECTS)  $(LDLIBS) $(LIBS)
	chmod +x $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

dev: CFLAGS=-g  -Isrc -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS) 
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS) $(INCLUDES) $(LDLIBS) $(LIBS)

build:
	@mkdir -p build
	@mkdir -p bin

tests: $(TESTS)
$(TESTS): bin/% : tests/%.c $(OBJECTS)
	$(CC) $(CFLAGS) -DTEST_BUILD $(INCLUDES) $< -o bin/tests $(OBJECTS) $(LDLIBS) $(LIBS)
	@echo "Compiled $@"

#Cleaning 
clean:
	rm -rf build $(OBJECTS) $(TESTS) $(EXECUTABLE) 
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

#Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/