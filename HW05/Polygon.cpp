#include "Polygon.h"
namespace MyShape{
	Polygon::Polygon(){};

	/*Constructors for Point2D inner class*/
	Polygon::Point2D::Point2D(double x_,double y_){
		if(x<0)
			cout<<endl<<"Invalid x. Please enter a positive number"<<endl;
		if(y<0)
			cout<<endl<<"Invalid y. Please enter a positive number"<<endl;
		if( x>= 0 && y>=0){
			x=x_;
			y=y_;
		}
		else
			cout<<"Invalid Input";
	}
	Polygon::Point2D::Point2D(){
		x=0;
		y=0;
	}

	/*getters and setters*/
	void Polygon::Point2D::setX(double x_){
			x=x_;
	}
	void Polygon::Point2D::setY(double y_){
			y=y_;	
	}
	double Polygon::Point2D::getX()const{
		return x;
	}
	double Polygon::Point2D::getY()const{
		return y;
	}
}













