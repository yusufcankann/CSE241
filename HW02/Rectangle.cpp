#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(double wid,double hei){
	width=wid;
	height=hei;
}

Rectangle::Rectangle(double wid){
	width=wid;
	height=1.;
}

Rectangle::Rectangle(){
	width=1.;
	height=1.;
}
/*setters and getters*/
double Rectangle::getHeight() const{
	return height;
}

double Rectangle::getWidth() const{
	return width;
}

double Rectangle::getX() const{
	return x;
}

double Rectangle::getY() const{
	return y;
}

void Rectangle::setHeight(double hei){
	height=hei;
}

void Rectangle::setWidth(double wid){
	width=wid;
}

void Rectangle::setX(double _x){
	x=_x;
}

void Rectangle::setY(double _y){
	y=_y;
}
/*draw function*/
void Rectangle::draw (ofstream &inputStream){
	inputStream << "<rect x=\""<< x << "\" y=\""<< y <<"\" width=\""<< width <<"\" height=\""
						<< height <<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
}















