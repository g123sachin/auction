# "all" is not a file
.PHONY: all
# Create command line app and test executable binary
all: main test

# ABAS (Auto-bid Auction System) Library with C++ API
# Compilation of Bidder unit
bidder.o: bidder.cpp bidder.hpp
	g++ -g -o0 --std=c++11 -c -o bidder.o bidder.cpp

# Compilation of Auction unit
auction.o: auction.cpp auction.hpp bidder.hpp
	g++ -g -o0 --std=c++11 -c -o auction.o auction.cpp
	
# Preparing static library
libabas.a: bidder.o auction.o
	ar cr libabas.a bidder.o auction.o

# Command-line Application which uses ABAS (Auto-bid Auction System) Library via C++ API
main: main.cpp libabas.a
	g++ -g -o0 --std=c++11 -o auction main.cpp libabas.a

# Test
test: test.cpp libabas.a
	g++ -g -o0 --std=c++11 -o test test.cpp libabas.a

.PHONY: clean
clean:
	rm -f test
	rm -f auction
	rm -f libabas.a
	rm -f bidder.o
	rm -f auction.o

