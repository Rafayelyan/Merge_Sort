CC:=g++

CC_OPTS:=

SRCS:=$(wildcard src/*.cpp)

HEADERS:=$(wildcard src/*h)

OBJECTS:=$(patsubst src/%.cpp,bin/%.o,$(SRCS))

bin/myprogram : $(OBJECTS)
	$(CC) $^ $(CC_OPTS) -o $@

bin/%.o : src/%.cpp $(HEADERS)
	$(CC) $< $(CC_OPTS) -c -o $@


