all: proj3.exe

proj3.o: proj3.cpp PPMImageClass.h constants.h ModifyFunction.h
	g++ -std=c++98 -g -Wall -c proj3.cpp -o proj3.o

commonFunc.o: commonFunc.cpp commonFunc.h
	g++ -std=c++98 -g -Wall -c commonFunc.cpp -o commonFunc.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h ColorClass.h \
  constants.h
	g++ -std=c++98 -g -Wall -c ColorImageClass.cpp -o ColorImageClass.o

PPMImageClass.o: PPMImageClass.cpp PPMImageClass.h ColorImageClass.h \
  commonFunc.h  constants.h
	g++ -std=c++98 -g -Wall -c PPMImageClass.cpp -o PPMImageClass.o

ModifyFunction.o: ModifyFunction.cpp ModifyFunction.h PPMImageClass.h \
  commonFunc.h constants.h
	g++ -std=c++98 -g -Wall -c ModifyFunction.cpp -o ModifyFunction.o

proj3.exe: ModifyFunction.o PPMImageClass.o ColorImageClass.o ColorClass.o \
  commonFunc.o proj3.o 
	g++ -std=c++98 ModifyFunction.o PPMImageClass.o ColorImageClass.o \
      ColorClass.o commonFunc.o proj3.o -o proj3.exe

clean:
	rm -f *.o *.exe


