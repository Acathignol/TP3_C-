all : main

main: main.o DLA.o Image.o CellularAutomaton.o
	g++ -g main.o DLA.o Image.o CellularAutomaton.o -o main -std=c++11
	
main.o: main.cpp DLA.h Image.h CellularAutomaton.h
	g++ -g -c main.cpp -o main.o -std=c++11

DLA.o: DLA.cpp DLA.h
	g++ -g -c DLA.cpp -Wall -o DLA.o --std=c++11 
	
Image.o: Image.cpp Image.h
	g++ -g -c Image.cpp -Wall -o Image.o --std=c++11 
	
CellularAutomaton.o: CellularAutomaton.cpp CellularAutomaton.h
	g++ -g -c CellularAutomaton.cpp -Wall -o CellularAutomaton.o --std=c++11 

clean : 
	rm -f *.o
