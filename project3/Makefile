all: proj3.exe

# proj3.o: proj3.cpp Stats.h Areas.h
# 	g++ -std=c++98 -g -Wall -c math.cpp -o math.o

# Stats.o: Stats.cpp Stats.h
# 	g++ -std=c++98 -g -Wall -c Stats.cpp -o Stats.o

# Areas.o: Areas.cpp Areas.h
# 	g++ -std=c++98 -g -Wall -c Areas.cpp -o Areas.o

# proj3.exe: Stats.o Areas.o math.o
# 	g++ -std=c++98 Stats.o Areas.o math.o -o math.exe


proj3.o: proj3.cpp PPMImageClass.o constants.h UtilsFunction.h
	g++ -std=c++98 -g -Wall -c proj3.cpp -o proj3.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -g -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h ColorClass.o RowColumnClass.o constants.h
	g++ -std=c++98 -g -Wall -c ColorImageClass.cpp -o ColorImageClass.o

PPMImageClass.o: PPMImageClass.cpp PPMImageClass.h ColorImageClass.o constants.h
	g++ -std=c++98 -g -Wall -c PPMImageClass.cpp -o PPMImageClass.o

proj3.exe: proj3.o
	g++ -std=c++98 proj3.o -o proj3.exe

clean:
	rm -f *.o *.exe


