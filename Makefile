project: main.o board.o player.o snakeLadder.o
	g++ main.o board.o player.o snakeLadder.o -o project

main.o: main.cpp SNL.h
	g++ -c main.cpp -o main.o

board.o: board.cpp SNL.h
	g++ -c board.cpp -o board.o

player.o: player.cpp SNL.h
	g++ -c player.cpp -o player.o

snakeLadder.o: snakeLadder.cpp SNL.h
	g++ -c snakeLadder.cpp -o snakeLadder.o

clean:
	rm -rvf *.o project