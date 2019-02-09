#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include<fstream>
#include<cmath>

using namespace std;

class Triangle {
	public:
		/*constructors*/
		Triangle();
		Triangle(double len);
		/*setters and getters*/
		void setLength(double len);
		void setX11(double _x);
		void setX12(double _x);
		void setX21(double _x);
		void setX22(double _x);
		void setX31(double _x);
		void setX32(double _x);
		
		
		double getLength() const;
		double getX11() const;
		double getX12() const;
		double getX21() const;
		double getX22() const;
		double getX31() const;
		double getX32() const;
		/*draw function*/
		void draw (ofstream &inputStream);

		/*
			Below functions returns the perimeter length and area of shape.
		*/
		double perimeterLength();
		double area();

		/*overloaded << operator*/
		friend ostream& operator<<(ostream &outputStream,const Triangle &triangle);
		/*overloaded ++ and -- operator*/
		Triangle operator++();
		Triangle operator++(int IgnoreMe);
		Triangle operator--();
		Triangle operator--(int IgnoreMe);
		/*overloaded + and - operator*/
		const Triangle operator+(int number);
		const Triangle operator-(int number);

		/*overloaded == != <= >= < > operators.*/
		bool operator==(Triangle &triangle);
		bool operator!=(Triangle &triangle);
		bool operator>=(Triangle &triangle);
		bool operator<=(Triangle &triangle);
		bool operator>(Triangle &triangle);
		bool operator<(Triangle &triangle);

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
		double x11,x12,x21,x22,x31,x32;/*points for drawing circle to svg files.*/
		
		/*
		  Static area and perimeter length parameters only added with parameters constructors. 
		  If customer creates the shape with no parameter than total_area and total_perimeter doesn't increase.
		  When the customer setted the shape then settedPerimeterLength and settedArea function calls and this functions
		  increases the totals.
		*/
		static double total_area;
		static double total_perimeter;
		 
};



#endif /* RATIONALNUM_H_ */



