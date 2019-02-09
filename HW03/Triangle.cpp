#include <iostream>
#include "Triangle.h"
/*constructors*/


double Triangle::total_area=0;
double Triangle::total_perimeter=0;

Triangle::Triangle(){
	length=1.;
}
Triangle::Triangle(double len){
	length = len;
	total_perimeter+=3*length;
	total_area+= ( (length*length*sqrt(3))/4 );
	
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
	return x12;
}

double Triangle::getX21() const{
	return x21;
}

double Triangle::getX22() const{
	return x22;
}

double Triangle::getX31() const{
	return x31;
}

double Triangle::getX32() const{
	return x32;
}

/*draw function*/
void Triangle::draw (ofstream &inputStream){
	inputStream << *this;
}

/*Perimeter length getter.*/
double Triangle::perimeterLength(){
	return length*3;
}
/*area getter*/
double Triangle::area(){
	return (length*length*sqrt(3))/4;
}

/*overloaded << operator*/
ostream& operator<<(ostream &outputStream,const Triangle &triangle){
	outputStream << "<polygon points=\"" <<triangle.getX11()<<","<< triangle.getX12() <<" "<<triangle.getX21()<<","<<triangle.getX22() <<" "
						<< triangle.getX31() << "," << triangle.getX32() << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
	return outputStream;
}

/*overloaded prefix and postfix ++ operator.*/

Triangle Triangle::operator++(){
	x11++;
	x12++;
	x21++;
	x22++;
	x31++;
	x32++;

	Triangle triangle(*this);
	return triangle;

}
Triangle Triangle::operator++(int IgnoreMe){
	Triangle temp(*this);
	x11++;
	x12++;
	x21++;
	x22++;
	x31++;
	x32++;
	return temp;
}

/*overloaded prefix and postfix -- operator.*/

Triangle Triangle::operator--(){
	x11--;
	x12--;
	x21--;
	x22--;
	x31--;
	x32--;

	Triangle triangle(*this);
	return triangle;

}
Triangle Triangle::operator--(int IgnoreMe){
	Triangle temp(*this);
	x11--;
	x12--;
	x21--;
	x22--;
	x31--;
	x32--;
	return temp;
}


/*overloaded + operator.*/
const Triangle Triangle::operator+(int number){
	
	Triangle temp(length+number);

	temp.setX11(x11);
	temp.setX12(x12);
	temp.setX21(x21);
	temp.setX22(x22);
	temp.setX31(x31);
	temp.setX32(x32);

	return temp;

}
/*overloaded - operator.*/
const Triangle Triangle::operator-(int number){
	
	Triangle temp(length-number);

	temp.setX11(x11);
	temp.setX12(x12);
	temp.setX21(x21);
	temp.setX22(x22);
	temp.setX31(x31);
	temp.setX32(x32);

	return temp;

}

bool Triangle::operator==(Triangle &triangle){
	double area1=((length*length*sqrt(3))/4);
	double area2=(triangle.area());
	return ( area1  == area2 ); 

	/*	
		Because of that when i write this;
							return ( ((length*length*sqrt(3))/4)  == (triangle.area()) ); 
		it doesn't work , i created double variables.
	*/
}

/*overloaded == != <= >= < > operators.*/

bool Triangle::operator!=(Triangle &triangle){
	double area1=((length*length*sqrt(3))/4);
	double area2=(triangle.area());
	return ( area1  != area2 ); 

}

bool Triangle::operator>=(Triangle &triangle){
	double area1=((length*length*sqrt(3))/4);
	double area2=(triangle.area());
	return ( area1  >= area2 ); 

}

bool Triangle::operator<=(Triangle &triangle){
	double area1=((length*length*sqrt(3))/4);
	double area2=(triangle.area());
	return ( area1  <= area2 ); 

}

bool Triangle::operator>(Triangle &triangle){
	double area1=((length*length*sqrt(3))/4);
	double area2=(triangle.area());
	return ( area1  > area2 ); 

}

bool Triangle::operator<(Triangle &triangle){
	double area1=((length*length*sqrt(3))/4);
	double area2=(triangle.area());
	return ( area1  < area2 ); 

}

/*for static total_area and total_perimeter.*/

void Triangle::increase_total_area(){
	total_area+= ( (length*length*sqrt(3))/4 );	
}
void Triangle::increase_perimeter(){
	total_perimeter+=3*length;
}
double Triangle::show_total_area(){
	return total_area;
}
double Triangle::show_total_perimeter(){
	return total_perimeter;
}



















