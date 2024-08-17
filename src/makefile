CC = "g++"
CFLAGS = "-Wall"

all: cpm.cpp util.o cfserver.o init.o start.o deploy.o run.o test.o build.o clean.o update.o install.o
	mkdir -p ./../bin
	g++ -o ./../bin/cpm cpm.cpp ./include/util.o ./include/cfserver.o ./include/init.o ./include/start.o ./include/deploy.o ./include/run.o ./include/test.o ./include/build.o ./include/clean.o ./include/update.o ./include/install.o

util.o: include/util.cpp include/util.hpp
	g++ -c ./include/util.cpp -o ./include/util.o

cfserver.o: include/cfserver.cpp include/cfserver.hpp
	g++ -c ./include/cfserver.cpp -o ./include/cfserver.o

init.o: include/init.cpp include/init.hpp
	g++ -c ./include/init.cpp -o ./include/init.o

start.o: include/start.cpp include/start.hpp
	g++ -c ./include/start.cpp -o ./include/start.o

deploy.o: include/deploy.cpp include/deploy.hpp
	g++ -c ./include/deploy.cpp -o ./include/deploy.o

run.o: include/run.cpp include/run.hpp
	g++ -c ./include/run.cpp -o ./include/run.o

test.o: include/test.cpp include/test.hpp
	g++ -c ./include/test.cpp -o ./include/test.o

build.o: include/build.cpp include/build.hpp
	g++ -c ./include/build.cpp -o ./include/build.o

install.o: include/install.cpp include/install.hpp
	g++ -c ./include/install.cpp -o ./include/install.o

clean.o: include/clean.cpp include/clean.hpp
	g++ -c ./include/clean.cpp -o ./include/clean.o

update.o: include/update.cpp include/update.hpp
	g++ -c ./include/update.cpp -o ./include/update.o

clean:
	rm -f cpm
	rm -f ./include/*.o