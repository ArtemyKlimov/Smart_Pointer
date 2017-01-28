CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -g

EXECUTABLE_NAME = prog.out
SOURCES = main.cpp smart.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUABLE_NAME)
