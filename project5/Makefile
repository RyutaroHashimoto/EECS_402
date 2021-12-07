all: proj5.exe

proj5.o: project5.cpp IntersectionSimulationClass.h
	g++ -std=c++98 -g -Wall -c project5.cpp -o proj5.o

IntersectionSimulationClass.o: IntersectionSimulationClass.cpp IntersectionSimulationClass.h SortedListClass.h SortedListClass.inl EventClass.h FIFOQueueClass.h FIFOQueueClass.inl CarClass.h
	g++ -std=c++98 -g -Wall -c IntersectionSimulationClass.cpp -o IntersectionSimulationClass.o

CarClass.o: constants.h CarClass.cpp CarClass.h
	g++ -std=c++98 -g -Wall -c CarClass.cpp -o CarClass.o

EventClass.o: constants.h EventClass.cpp EventClass.h
	g++ -std=c++98 -g -Wall -c EventClass.cpp -o EventClass.o

proj5.exe: IntersectionSimulationClass.o CarClass.o EventClass.o proj5.o
	g++ -std=c++98 -g -Wall IntersectionSimulationClass.o CarClass.o EventClass.o proj5.o  -o proj5.exe

clean:
	rm -f *.o *.exe
