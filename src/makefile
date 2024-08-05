CC = "g++"
CFLAGS = "-Wall"

all: cpm.cpp util.o cfserver.o
	g++ -o ./../bin/cpm cpm.cpp ./include/util.o ./include/cfserver.o

util.o: include/util.cpp include/util.hpp
	g++ -c ./include/util.cpp -o ./include/util.o

cfserver.o: include/cfserver.cpp include/cfserver.hpp
	g++ -c ./include/cfserver.cpp -o ./include/cfserver.o

clean:
	rm -f cpm