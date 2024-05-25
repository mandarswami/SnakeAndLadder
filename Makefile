project: main.o board.o
	g++ main.o board.o -o project

main.o: main.cpp SNL.h
	g++ -c main.cpp -o main.o

board.o: board.cpp SNL.h
	g++ -c board.cpp -o board.o

clean:
	rm -rvf *.o project