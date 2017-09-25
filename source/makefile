all: QuadraticFunctions.exe

QuadraticFunctions.exe: QuadraticFunctions.o
	 g++ -o QuadraticFunctions.exe QuadraticFunctions.o

QuadraticFunctions.o: QuadraticFunctions.cpp
	 g++ -c QuadraticFunctions.cpp
     
clean:
	 rm QuadraticFunctions.o QuadraticFunctions.exe