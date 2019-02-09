
#include "Circle.h"


double Circle::total_area=0;
double Circle::total_perimeter=0;

Circle::Circle(double rad){
	radius=rad;
	x=rad;
	y=rad;
	total_area+= PI*radius*radius;
	total_perimeter+=2*PI*radius;
}

Circle::Circle(){
	radius=1;
	x=radius;
	y=radius;
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
	inputStream << *this;
}
/*perimeter length and area getter.*/
double Circle::perimeterLength(){
	return 2*PI*radius;
}
double Circle::area(){
	return PI*radius*radius;
}

/*overloaded << operator*/
ostream& operator<<(ostream &outputStream,const Circle &circle){
	outputStream << " <circle cx=\""<< circle.getX() <<"\" cy=\""<< circle.getY() <<"\" r=\""<<circle.getRadius()
				<<"\" fill=\"blue\" /> " << endl;
	return outputStream;
}

/*overloaded prefix and postfix ++ operator.*/
Circle Circle::operator++(){
	x++;
	y++;
	Circle circle(*this);
	return circle;
}

Circle Circle::operator++(int IgnoreMe){
	Circle temp(*this);
	x++;
	y++;
	return temp;
}

/*overloaded prefix and postfix -- operator.*/
Circle Circle::operator--(){
	x--;
	y--;
	Circle circle(*this);
	return circle;
}

Circle Circle::operator--(int IgnoreMe){
	Circle temp(*this);
	x--;
	y--;
	return temp;
}

/*overloaded + operator.*/
const Circle Circle::operator+(double number){

	Circle temp(radius + number);
	temp.setX(x);
	temp.setY(y);

	return temp;
}

/*overloaded - operator.*/
const Circle Circle::operator-(double number){

	Circle temp(radius - number);
	temp.setX(x);
	temp.setY(y);

	return temp;
}

/*overloaded == != <= >= < > operators.*/

bool Circle::operator==(Circle &circle){
	double area1 = PI*radius*radius;
	double area2 = circle.area();
	return (area1 == area2);
}

bool Circle::operator!=(Circle &circle){
	double area1 = PI*radius*radius;
	double area2 = circle.area();
	return (area1 != area2);
}

bool Circle::operator<=(Circle &circle){
	double area1 = PI*radius*radius;
	double area2 = circle.area();
	return (area1 <= area2);
}

bool Circle::operator>=(Circle &circle){
	double area1 = PI*radius*radius;
	double area2 = circle.area();
	return (area1 >= area2);
}

bool Circle::operator<(Circle &circle){
	double area1 = PI*radius*radius;
	double area2 = circle.area();
	return (area1 < area2);
}

bool Circle::operator>(Circle &circle){
	double area1 = PI*radius*radius;
	double area2 = circle.area();
	return (area1 > area2);
}

/*for static total_area and total_perimeter.*/
void Circle::increase_total_area(){
	total_area+= PI*radius*radius;
}
void Circle::increase_perimeter(){
	total_perimeter+=2*PI*radius;
}

/*total area and total perimeter length getter.*/
double Circle::show_total_area(){
	return total_area;
}
double Circle::show_total_perimeter(){
	return total_perimeter;
}


























