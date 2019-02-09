#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_

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

	class PolygonDyn: public Polygon {

		public:
			PolygonDyn();
			PolygonDyn(vector<Point2D> polygons);
			PolygonDyn(double x1,double x2);
			PolygonDyn(double x1);
			PolygonDyn(Rectangle rectangle);
			PolygonDyn(Triangle triangle);
			PolygonDyn(Circle circle);
			PolygonDyn(Shape &shape);
			PolygonDyn(const PolygonDyn &polygon);
		
			PolygonDyn operator=(const PolygonDyn &polygon);
			int getCapacity()const throw();
			int getUsed()const throw();

			double area()const throw();
			double perimeter()const throw();
			
			void draw(ostream &outputStream)throw();
			friend ostream& operator<<(ostream& outputStream,PolygonDyn &polygon);

			Shape& operator++()throw();
			Shape& operator++(int IgnoreMe)throw();
			Shape& operator--()throw();
			Shape& operator--(int IgnoreMe)throw();

			Point2D operator[](int index) throw();	
			const Point2D operator[](int index)const throw();	
		
			~PolygonDyn();
	
		private:
			Point2D *points;
			int used;
			int capacity;


	};
}


#endif
