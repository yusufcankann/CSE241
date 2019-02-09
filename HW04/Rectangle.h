#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include <fstream>

using namespace std;

class Rectangle{

	public:
		/*constructors*/
		Rectangle(double wid,double hei);
		Rectangle(double wid);
		Rectangle();
		/*setters and getters*/
		double getHeight() const;
		double getWidth() const;
		double getX() const;
		double getY() const;
		
		void setHeight(double hei);
		void setWidth(double wid);
		void setX(double _x);
		void setY(double _y);
		/*draw functions*/
		void draw (ofstream &inputStream);

		/*
			This functions returns the perimeter length and area of shape.
		*/
		double perimeterLength();
		double area();

		/*overloaded << operator.*/
		friend ostream& operator<<(ostream &outputStream,const Rectangle &rectangle);

		/*overloaded prefix and postfix ++ -- operators.*/
		Rectangle operator++();
		Rectangle operator++(int IgnoreMe);
		Rectangle operator--();
		Rectangle operator--(int IgnoreMe);

		/*overloaded + and - operator.*/
		const Rectangle operator+(double number);
		const Rectangle operator-(double number);

		/*overloaded == != <= >= < > operators*/
		bool operator==(Rectangle &rectangle);
		bool operator!=(Rectangle &rectangle);
		bool operator<=(Rectangle &rectangle);
		bool operator>=(Rectangle &rectangle);
		bool operator<(Rectangle &rectangle);
		bool operator>(Rectangle &rectangle);
		
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
		double height,width;
		double x,y;

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
