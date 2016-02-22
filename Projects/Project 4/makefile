#project 4 makefile

project4:	project4.o songlist.o song.o
	g++ -std=gnu++11 project4.o songlist.o song.o -o project4

project4.o: project4.cpp
	g++ -std=gnu++11 -c project4.cpp

songlist.o: songlist.cpp songlist.h
	g++ -std=gnu++11 -c songlist.cpp

song.o: song.cpp song.h
	g++ -std=gnu++11 -c song.cpp

clean:
	rm -f project4 *.o *.h.gch

