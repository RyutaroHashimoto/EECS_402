all: proj4.exe

proj4.o: project4_memory.cpp LIFOStackClass.h FIFOQueueClass.h SortedListClass.h
	g++ -std=c++98 -g -Wall -c project4.cpp -o proj4.o

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h LinkedNodeClass.h 
	g++ -std=c++98 -g -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c SortedListClass.cpp -o SortedListClass.o

proj4.exe: LinkedNodeClass.o LIFOStackClass.o FIFOQueueClass.o SortedListClass.o proj4.o 
	g++ -std=c++98 -g -Wall LinkedNodeClass.o LIFOStackClass.o FIFOQueueClass.o SortedListClass.o proj4.o  -o proj4.exe

clean:
	rm -f *.o *.exe


