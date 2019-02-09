#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"
#include<iostream>
#include <fstream>

using namespace std;

class ExceptionErrorrr{
	public:
		ExceptionErrorrr(){ }
		ExceptionErrorrr(double theMessage): message(theMessage) {
		}
		double getMessage( ) { return message; }
	private:
		double message;
};

namespace MyShape{

	class Rectangle:public Shape{

		public:
			/*constructors*/
			Rectangle(double Width,double Height);
			Rectangle(double Width);
			Rectangle();
		
			double area()const;
			double perimeter()const;

			double getWidth()const throw();
			double getHeight()const throw();
			double getX()const throw();
			double getY()const throw();
		
			virtual ~Rectangle()=default;	
	
			void setWidth(double Width) throw(ExceptionErrorrr);
			void setHeight(double Height) throw(ExceptionErrorrr);
			void setX(double _x) throw(ExceptionErrorrr);
			void setY(double _y) throw(ExceptionErrorrr);
		
			Shape& operator++() throw();
			Shape& operator++(int IgnoreMe) throw();
			Shape& operator--() throw();
			Shape& operator--(int IgnoreMe) throw();
		
			friend ostream& operator<<(ostream &outputStream,Rectangle 	rectangle);
			void draw(ostream &outputStream) throw();

			/*
		 	 Total area and total permeter length increaser.
		  	For sets and gets shapes values.
			*/
			void increase_total_area();
			void increase_perimeter();
			/*total area and total periter length getter.*/
			static double show_total_area();
			static double show_total_perimeter();

		private:
			double width,height;
			double x,y;
	
			static double total_area;
			static double total_perimeter;

	};
}



#endif
