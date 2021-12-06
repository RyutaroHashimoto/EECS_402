all: proj5.exe

proj5.o: project5.cpp FIFOQueueClass.h SortedListClass.h
	g++ -std=c++98 -g -Wall -c project5.cpp -o proj5.o

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c SortedListClass.cpp -o SortedListClass.o

proj5.exe: LinkedNodeClass.o FIFOQueueClass.o SortedListClass.o proj5.o
	g++ -std=c++98 -g -Wall LinkedNodeClass.o FIFOQueueClass.o SortedListClass.o proj5.o  -o proj5.exe

clean:
	rm -f *.o *.exe
