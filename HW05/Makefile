# very simple makefile
# top down 

161044007_main : Circle.o Rectangle.o Triangle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o Shape.o 161044007_main.o 
	g++ -o 161044007_main Circle.o Rectangle.o Triangle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o Shape.o 161044007_main.o 

Circle.o : Circle.cpp
	g++ -c -std=c++0x Circle.cpp

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++0x Rectangle.cpp

Triangle.o : Triangle.cpp
	g++ -c -std=c++0x Triangle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++0x  ComposedShape.cpp

Polygon.o : Polygon.cpp
	g++ -c -std=c++0x Polygon.cpp

PolygonVect.o : PolygonVect.cpp
	g++ -c -std=c++0x PolygonVect.cpp

PolygonDyn.o : PolygonDyn.cpp
	g++ -c -std=c++0x PolygonDyn.cpp

Shape.o : Shape.cpp
	g++ -c -std=c++0x Shape.cpp

161044007_main.o : 161044007_main.cpp
	g++ -c -std=c++0x 161044007_main.cpp

run : 
	./161044007_main

clean:
	rm *.o 161044007_main


