#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"
#include<iostream>
#include<cmath>
#include <fstream>



class ExceptionError
{
	public:
		ExceptionError(){ }
		ExceptionError(double theMessage): message(theMessage) {
		}
		double getMessage( ) { return message; }
	private:
		double message;
};


using namespace std;
namespace MyShape{

	class Triangle:public Shape{

		public:
			/*constructors*/
			Triangle(double len);
			Triangle();
		
			double area()const;
			double perimeter()const;
			virtual ~Triangle()=default;
			/*setters and getters*/
			void setLength(double len)throw(ExceptionError);
			void setX1(double x)throw(ExceptionError);
			void setY1(double y)throw(ExceptionError);
			void setX2(double x)throw(ExceptionError);
			void setY2(double y)throw(ExceptionError);
			void setX3(double x)throw(ExceptionError);
			void setY3(double y)throw(ExceptionError);
		
		
			double getLength() const throw();
			double getX1() const throw();
			double getY1() const throw();
			double getX2() const throw();
			double getY2() const throw();
			double getX3() const throw();
			double getY3() const throw();
	
			Shape& operator++() throw();
			Shape& operator++(int IgnoreMe) throw();
			Shape& operator--() throw();
			Shape& operator--(int IgnoreMe) throw();

			/*overloaded << operator*/
			friend ostream& operator<<(ostream &outputStream,Triangle triangle);
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
			double length;
			double x1,y1,x2,y2,x3,y3;
			
			static double total_area;
			static double total_perimeter;

	};
}






#endif
