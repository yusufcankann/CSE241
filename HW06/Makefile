# very simple makefile
# top down 

161044007_main : Collection.o List.o Set.o Queue.o Iterator.o LinkedList.o HashSet.o ArrayList.o 161044007_main.o 
	g++ -o 161044007_main Collection.o List.o Set.o Queue.o Iterator.o LinkedList.o HashSet.o ArrayList.o 161044007_main.o 

Collection.o : Collection.cpp
	g++ -c -std=c++0x Collection.cpp

List.o : List.cpp
	g++ -c -std=c++0x List.cpp

Set.o : Set.cpp
	g++ -c -std=c++0x Set.cpp

Queue.o : Queue.cpp
	g++ -c -std=c++0x  Queue.cpp

Iterator.o : Iterator.cpp
	g++ -c -std=c++0x Iterator.cpp

LinkedList.o : LinkedList.cpp
	g++ -c -std=c++0x LinkedList.cpp

HashSet.o : HashSet.cpp
	g++ -c -std=c++0x HashSet.cpp

ArrayList.o : ArrayList.cpp
	g++ -c -std=c++0x ArrayList.cpp

161044007_main.o : 161044007_main.cpp
	g++ -c -std=c++0x 161044007_main.cpp

run : 
	./161044007_main

clean:
	rm *.o 161044007_main


