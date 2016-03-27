cherie: main.o cherieStates.o cherie.o	
	g++ main.o cherieStates.o cherie.o -o cherie.exe
	rm *.o
main.o: main.cpp
	g++ -c main.cpp
cherie.o: cherie.h cherie.cpp
	g++ -c cherie.cpp
cherieStates.o: cherieStates.cpp cherieStates.h
	g++ -c cherieStates.cpp