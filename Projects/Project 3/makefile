#project 3 makefile

project3:	project3.o songlist.o song.o
	g++ -std=gnu++11 project3.o songlist.o song.o -o project3

project3.o: project3.cpp
	g++ -std=gnu++11 -c project3.cpp

songlist.o: songlist.cpp songlist.h
	g++ -std=gnu++11 -c songlist.cpp

song.o: song.cpp song.h
	g++ -std=gnu++11 -c song.cpp

clean:
	rm -f project3 *.o *.h.gch

