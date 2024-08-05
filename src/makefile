CC = "g++"
CFLAGS = "-Wall"

all: cpm.cpp util.o cfserver.o init.o
	g++ -o ./../bin/cpm cpm.cpp ./include/util.o ./include/cfserver.o ./include/init.o

util.o: include/util.cpp include/util.hpp
	g++ -c ./include/util.cpp -o ./include/util.o

cfserver.o: include/cfserver.cpp include/cfserver.hpp
	g++ -c ./include/cfserver.cpp -o ./include/cfserver.o

init.o: include/init.cpp include/init.hpp
	g++ -c ./include/init.cpp -o ./include/init.o

clean:
	rm -f cpm
	rm -f ./include/*.o