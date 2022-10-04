CXX = g++
CXXFLAGS = -Wall

all: Datafile.o Item.o Drink.o Snack.o Vending.o driver.cpp
	$(CXX) $(CXXFLAGS) Datafile.o Item.o Drink.o Snack.o Vending.o driver.cpp -o all

test: Datafile.o Item.o Drink.o Snack.o Vending.o extra_driver.cpp
	$(CXX) $(CXXFLAGS) Datafile.o Item.o Drink.o Snack.o Vending.o extra_driver.cpp -o test

Vending.o: Item.o Drink.o Snack.o Vending.h Vending.cpp
	$(CXX) $(CXXFLAGS) -c Vending.cpp

Snack.o: Item.o Snack.h Snack.cpp
	$(CXX) $(CXXFLAGS) -c Snack.cpp

Drink.o: Item.o Drink.h Drink.cpp
	$(CXX) $(CXXFLAGS) -c Drink.cpp

Item.o: Item.h Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp

Datafile.o: Datafile.h Datafile.cpp
	$(CXX) $(CXXFLAGS) -c Datafile.cpp

clean:
	rm *.o*
	rm *~

run:
	./all directory.txt input.txt

testrun:
	./test directory.txt input.txt

val:
	valgrind ./all

val1:
	valgrind ./test
