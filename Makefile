

#----------------------------------------------------------------------------
CC = clang++
FLAGS = -std=c++11 -lsqlite3 -L/usr/local/lib -I/usr/local/include 
#-----------------------------------------------------------------------------

compile: *.o
	$(CC) -o manage *.o $(FLAGS)

*.o : *.cpp
	$(CC) -c *.cpp $(FLAGS)

clean:
	rm -f *.o
	rm -f *.db
	rm manage
build:
	clean
	compile

dll:
	
