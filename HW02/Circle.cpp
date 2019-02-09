#include <iostream>
#include "Circle.h"

Circle::Circle(double rad){
	radius=rad;
}

Circle::Circle(){
	radius=1;
}

/*setters and getters*/
double Circle::getRadius() const{
	return radius;
}

double Circle::getX() const{
	return x;
}

double Circle::getY() const{
	return y;
}

void Circle::setRadius(double rad){
	radius=rad;
}

void Circle::setX(double _x){
	x=_x;
}

void Circle::setY(double _y){
	y=_y;
}
/*draw function*/
void Circle::draw (ofstream &inputStream){
	inputStream << " <circle cx=\""<< x <<"\" cy=\""<< y <<"\" r=\""<<radius
				<<"\" fill=\"blue\" /> " << endl;
}







