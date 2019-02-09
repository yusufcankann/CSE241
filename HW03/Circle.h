#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <fstream>
#include <iostream>
#define PI 3.14

using namespace std;

class Circle{

	public:
		/*constructors*/
		Circle(double rad);
		Circle();
		/*setters and getters*/
		double getRadius() const;
		double getX() const;
		double getY() const;

		void setRadius(double rad);
		void setX(double _x);
		void setY(double _y);
      	
		/*draw function*/
		void draw (ofstream &inputStream);
		
		/*
			This functions returns the perimeter length and area of shape.
		*/
		double perimeterLength();
		double area();
		/*overloaded << operator*/
		friend ostream& operator<<(ostream &outputStream,const Circle &circle);
		
		/*overloaded prefix and postfix ++ and -- operator.*/
		Circle operator++();
		Circle operator++(int IgnoreMe);
		Circle operator--();
		Circle operator--(int IgnoreMe);
		
		/*overloaded + and - operator*/
		const Circle operator+(double number);
		const Circle operator-(double number);
	
		/*overloaded == != <= >= < > operators.*/
		bool operator==(Circle &circle);
		bool operator!=(Circle &circle);
		bool operator<=(Circle &circle);
		bool operator>=(Circle &circle);
		bool operator<(Circle &circle);
		bool operator>(Circle &circle);
		
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
		double radius;
		double x;
		double y;

		/*
		  Static area and perimeter length parameters only added with parameters constructors. 
		  If customer creates the shape with no parameter than total_area and total_perimeter doesn't increase.
		  When the customer setted the shape then settedPerimeterLength and settedArea function calls and this functions
		  increases the totals.
		*/
		static double total_area;
		static double total_perimeter;

};


#endif
