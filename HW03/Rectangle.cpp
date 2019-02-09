#include <iostream>
#include "Rectangle.h"


double Rectangle::total_area=0;
double Rectangle::total_perimeter=0;

/*Constructors*/
Rectangle::Rectangle(double wid,double hei){
	width=wid;
	height=hei;

	total_area+= width*height;
	total_perimeter+=(2*width)+(2*height);
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
	inputStream << *this;
}


/*perimeterLength getter*/
double Rectangle::perimeterLength(){
	return 2*height+2*width;
}
/*area getter*/
double Rectangle::area(){
	return height*width;
}
/*overloaded << operator*/
ostream& operator<<(ostream &outputStream,const Rectangle &rectangle){
	outputStream << "<rect x=\""<< rectangle.getX() << "\" y=\""<< rectangle.getY() <<"\" width=\""<< rectangle.getWidth() <<"\" height=\""
						<< rectangle.getHeight() <<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
	return outputStream;
}


/*overloaded prefix and postfix ++ operator.*/
Rectangle Rectangle::operator++(){
	x++;
	y++;

	Rectangle rectangle(*this);
	return rectangle;
}

Rectangle Rectangle::operator++(int IgnoreMe){
	Rectangle temp(*this);
	x++;
	y++;
	return temp;
}

/*overloaded prefix and postfix -- operator.*/
Rectangle Rectangle::operator--(){
	x--;
	y--;

	Rectangle rectangle(*this);
	return rectangle;
}

Rectangle Rectangle::operator--(int IgnoreMe){
	Rectangle temp(*this);
	x--;
	y--;
	return temp;
}


/*overloaded + operator.*/
const Rectangle Rectangle::operator+(double number){
	
	Rectangle temp(width+number , height+number);
	temp.setX(x);
	temp.setY(y);
	
	return temp;
}

/*overloaded - operator.*/
const Rectangle Rectangle::operator-(double number){
	
	Rectangle temp(width-number , height-number);
	temp.setX(x);
	temp.setY(y);
	
	return temp;
}


/*overloaded == != <= >= < > operators.*/
bool Rectangle::operator==(Rectangle &rectangle){
	return ( (width*height) == rectangle.area() );
}

bool Rectangle::operator!=(Rectangle &rectangle){
	return ( (width*height) != rectangle.area() );
}

bool Rectangle::operator<=(Rectangle &rectangle){
	return ( (width*height) <= rectangle.area() );
}

bool Rectangle::operator>=(Rectangle &rectangle){
	return ( (width*height) >= rectangle.area() );
}

bool Rectangle::operator<(Rectangle &rectangle){
	return ( (width*height) < rectangle.area() );
}

bool Rectangle::operator>(Rectangle &rectangle){
	return ( (width*height) > rectangle.area() );
}

/*for static total_area and total_perimeter.*/
void Rectangle::increase_total_area(){
	total_area+=width*height;
}
void Rectangle::increase_perimeter(){
	total_perimeter=(2*width)+(2*height);
}
double Rectangle::show_total_area(){
	return total_perimeter;
}
double Rectangle::show_total_perimeter(){
	return total_area;
}









