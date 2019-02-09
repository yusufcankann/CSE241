#include <iostream>
#include "Triangle.h"
/*constructors*/
Triangle::Triangle(){
	length=1.;
}
Triangle::Triangle(double len){
	length = len;
}

/*setters and getters*/
void Triangle::setLength(double len) {
	length=len;
}

void Triangle::setX11(double _x){
	x11=_x;
}

void Triangle::setX12(double _x){
	x12=_x;
}

void Triangle::setX21(double _x){
	x21=_x;
}

void Triangle::setX22(double _x){
	x22=_x;
}

void Triangle::setX31(double _x){
	x31=_x;
}

void Triangle::setX32(double _x){
	x32=_x;
}

double Triangle::getLength() const{
	return length;
}

double Triangle::getX11() const{
	return x11;
}

double Triangle::getX12() const{
	return x11;
}

double Triangle::getX21() const{
	return x11;
}

double Triangle::getX22() const{
	return x11;
}

double Triangle::getX31() const{
	return x11;
}

double Triangle::getX32() const{
	return x11;
}

/*draw function*/
void Triangle::draw (ofstream &inputStream){

	inputStream << "<polygon points=\"" <<x11<<","<< x12 <<" "<<x21<<","<<x22 <<" "
						<< x31 << "," << x32 << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
}




