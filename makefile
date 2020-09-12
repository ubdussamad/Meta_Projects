CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++17
TARGET= lex
SRCS= test2.cpp

all: tool

tool:
    $(CXX) -o $(TARGET) $(SRCS) $(CPPFLAGS)

clean:
    $(RM) $(OBJS)
