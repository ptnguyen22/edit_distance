EDistance: EDistance.o main.o
	g++ -g -O3 EDistance.o main.o -o EDistance -lsfml-system
EDistance.o: EDistance.h EDistance.cpp
	g++ -c EDistance.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o EDistance
