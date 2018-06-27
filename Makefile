#-----------------------------------------------------------------------------
CC = g++
FLAGS = -std=c++11
#-----------------------------------------------------------------------------

compile: *.o
	$(CC) -o manage *.o $(FLAGS)

*.o : *.cpp
	$(CC) -c *.cpp $(FLAGS)

clean:
	rm -f *.o

build:
	clean
	compile

dll:
	
