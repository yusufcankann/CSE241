#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"
#include <iostream>
#include <fstream>
#define PI 3.14

using namespace std;

class ExceptionErrorr{
	public:
		ExceptionErrorr(){ }
		ExceptionErrorr(double theMessage): message(theMessage) {
		}
		double getMessage( ) { return message; }
	private:
		double message;
};


namespace MyShape{

	

	class Circle:public Shape{

		public:
			/*constructors*/
			Circle(double rad);
			Circle();
		
			double area()const throw();
			double perimeter()const throw();

			double getRadius()const throw();
			double getX()const throw();
			double getY()const throw();
			virtual ~Circle()=default;
			void setRadius(double rad) throw(ExceptionErrorr);
			void setX(double _x) throw(ExceptionErrorr);
			void setY(double _y) throw(ExceptionErrorr);
		
			Shape& operator++() throw();
			Shape& operator++(int IgnoreMe) throw();
			Shape& operator--() throw();
			Shape& operator--(int IgnoreMe) throw();
		
			friend ostream& operator<<(ostream &outputStream,Circle circle);

			void draw(ostream &outputStream) throw();

			void increase_total_area();
			void increase_perimeter();
			/*total area and total periter length getter.*/
			static double show_total_area();
			static double show_total_perimeter();
		private:
			double radius;
			double x,y;

			static double total_area;
			static double total_perimeter;

	};
}

#endif
