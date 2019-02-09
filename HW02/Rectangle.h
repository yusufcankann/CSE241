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

	private:
		double height,width;
		double x,y;


};


#endif
