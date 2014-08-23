.PHONY: all test clean

all: CommandLineArguments.o test

test: CommandLineArgumentsTest

CommandLineArguments.o: CommandLineArguments.h CommandLineArguments.cpp
	g++ -g -Wall -c CommandLineArguments.cpp

CommandLineArgumentsTest: CommandLineArguments.h CommandLineArguments.cpp CommandLineArguments.o CommandLineArgumentsTest.cpp
	g++ -g -Wall -o CommandLineArgumentsTest CommandLineArgumentsTest.cpp CommandLineArguments.o -lcppunit

clean:
	rm *.o *~ *.gch CommandLineArgumentsTest
