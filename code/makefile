#makefile that compiles all the files for hash
hash: node.o hash.o main.o
	g++ -Wall -g -o hash node.o hash.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

hash.o: hash.cpp hash.h
	g++ -c -g hash.cpp
	
main.o: main.cpp hash.h
	g++ -c -g main.cpp
	
clean:
	rm *.o hash