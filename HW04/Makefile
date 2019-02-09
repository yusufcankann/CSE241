# very simple makefile
# top down 

161044007_main : Triangle.o Rectangle.o Circle.o ComposedShape.o Polygon.o Polyline.o 161044007_main.o 
	g++ -o 161044007_main Triangle.o Rectangle.o Circle.o ComposedShape.o Polygon.o Polyline.o 161044007_main.o 

Triangle.o : Triangle.cpp
	g++ -c -std=c++0x -Wall Triangle.cpp

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++0x -Wall Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++0x -Wall Circle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++0x -Wall ComposedShape.cpp

Polygon.o : Polygon.cpp
	g++ -c -std=c++0x -Wall Polygon.cpp

Polyline.o : Polyline.cpp
	g++ -c -std=c++0x -Wall Polyline.cpp

161044007_main.o : 161044007_main.cpp
	g++ -c -std=c++0x -Wall 161044007_main.cpp

run : 
	./161044007_main

clean:
	rm *.o 161044007_main


