# auction

How to compile
===============
      1. Put all these files in 1 directory.
        - main.cpp
        - test.cpp
        - Makefile
        - bidder.cpp
        - bidder.hpp
        - auction.cpp
        - auction.hpp

      2. Execute make command from that directory location.

        Example log
        ===========
        ~/auction$ make
        g++ -g -o0 --std=c++11 -c -o bidder.o bidder.cpp
        g++ -g -o0 --std=c++11 -c -o auction.o auction.cpp
        ar cr libabas.a bidder.o auction.o
        g++ -g -o0 --std=c++11 -o auction main.cpp libabas.a
        g++ -g -o0 --std=c++11 -o test test.cpp libabas.a

Running the tests
=================
      1. Execute the "test" executable:

        Example log
        ===========
        ~/auction$ ./test 
        All tests passed
        ~/auction$
	
Running the program
===================
      1. Execute the "auction" executable:

        Example log
        ===========

        ~/auction$ ./auction 
        Enter the number of auctions: 2
        Enter the item name for auction #1: Bike
        Enter the number of bidders for Bike: 2
        Enter the name of bidder for bid #1: Mark
        Enter the starting bid of Mark for Bike: 100
        Enter the maximum bid of Mark for Bike: 150
        Enter the bid increment amount: 4
        Enter the name of bidder for bid #2: Steve
        Enter the starting bid of Steve for Bike: 125
        Enter the maximum bid of Steve for Bike: 145
        Enter the bid increment amount: 3
        Enter the item name for auction #2: Boat
        Enter the number of bidders for Boat: 2
        Enter the name of bidder for bid #1: Mark
        Enter the starting bid of Mark for Boat: 400
        Enter the maximum bid of Mark for Boat: 700
        Enter the bid increment amount: 7
        Enter the name of bidder for bid #2: Sam
        Enter the starting bid of Sam for Boat: 500
        Enter the maximum bid of Sam for Boat: 710
        Enter the bid increment amount: 6
        Auction for Bike won by Mark with bid of $144
        Auction for Boat won by Sam with bid of $698
        ~/auction$


