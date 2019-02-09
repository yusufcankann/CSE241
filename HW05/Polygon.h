#ifndef POLYGON_H_
#define POLYGON_H_
#include "Shape.h"

#include<iostream>
#include "Shape.h"


namespace MyShape{
	class Polygon:public Shape{
			
		public:
			class Point2D{
				public:
					Point2D(double x_,double y_);
					Point2D();
					void setX(double x_);
					void setY(double y_);
					double getX()const;
					double getY()const;
				private:
					double x;
					double y;
			};
			
			Polygon();

			virtual double area()const=0;
			virtual double perimeter()const=0;
			
			virtual void draw(ostream &outputStream)=0;
	
			virtual Shape& operator++() =0;
			virtual Shape& operator++(int IgnoreMe) =0;
			virtual Shape& operator--() throw()=0;
			virtual Shape& operator--(int IgnoreMe)=0;

			~Polygon()=default;/*Destructor*/

	};
}










#endif
