#
#----------------------------------------------------------------------------
CC = g++
FLAGS = -std=c++11 -lsqlite3 -L/usr/local/lib -I/usr/local/include 
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
	
