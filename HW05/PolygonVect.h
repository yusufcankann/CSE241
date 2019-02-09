#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_

#define PI 3.14

#include "Polygon.h"
#include<iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include <vector>
#include<cmath>
#include<new>

namespace MyShape{

	class PolygonVect : public Polygon{

		public:
			PolygonVect();
			PolygonVect(vector<Point2D> polygons);
			PolygonVect(double x1,double x2);
			PolygonVect(double x1);
			PolygonVect(Rectangle rectangle);
			PolygonVect(Triangle triangle);
			PolygonVect(Circle circle);
			PolygonVect(Shape &shape);

			double area()const throw();
			double perimeter()const throw();
			
			void draw(ostream &outputStream) throw();
			friend ostream& operator<<(ostream& outputStream,PolygonVect &polygon);

			Shape& operator++()throw();
			Shape& operator++(int IgnoreMe)throw();
			Shape& operator--()throw();
			Shape& operator--(int IgnoreMe)throw();

			Point2D operator[](int index) throw();	
			const Point2D operator[](int index)const throw();	
	
		private:
			vector<Point2D> points;


	};
}


#endif
