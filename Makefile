all: full clean

full: static prog.o libmyfunc.a
	g++ prog.o -L. -lmyfunc -o prog
        
static: input.o library.o
	ar rc libmyfunc.a input.o library.o
	ranlib libmyfunc.a

prog.o: prog.cpp 
	g++ -c prog.cpp 

input.o: input.cpp
	g++ -c input.cpp

library.o: library.cpp
	g++ -c library.cpp

clean:
	rm -f *.o	
	rm -f *.a
