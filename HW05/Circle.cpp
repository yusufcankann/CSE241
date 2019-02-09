#include "Circle.h"



namespace MyShape{

	
	double Circle::total_area=0;
	double Circle::total_perimeter=0;

	Circle::Circle(double rad):Shape(),radius(rad){ }

	Circle::Circle():Shape(),radius(1.){  }

	double Circle::area()const throw(){ return PI*radius*radius; }
	double Circle::perimeter()const throw(){ return 2.*PI*radius; }

	double Circle::getRadius()const throw(){ return radius; }
	double Circle::getX() const throw(){ return x; }
	double Circle::getY() const throw(){ return y; }

	void Circle::setRadius(double rad) throw(ExceptionErrorr){ 
		try{
			if(rad<0){
				throw ExceptionErrorr(rad);
			}
			radius=rad; 
		
		}
		catch(ExceptionErrorr a){
			cout<<endl<<"Radius cannot be negative"<<endl;
		} 
	
	}
	void Circle::setX(double _x) throw(ExceptionErrorr){ 

		try{
			if(_x<0){	
				throw ExceptionErrorr(_x);
			}
			x=_x; 
		}
		catch(ExceptionErrorr a){
			cout<<endl<<"x:"<<a.getMessage()<<" cannot be negative";
		}
	
	}
	void Circle::setY(double _y) throw(ExceptionErrorr)
	{
		try{
			if(_y<0)
				throw ExceptionErrorr(_y);
		 y=_y; 
		}
		catch(ExceptionErrorr a){
			cout<<endl<<"x:"<<a.getMessage()<<" cannot be negative";
		}
	}

	Shape& Circle::operator++() throw(){
		x++;
		y++;
		return (*this);
	}


	/*!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!
	*
	*	If you use this operator you have 
	*	to delete return adress manually!!!!!!!!!
	*
	*/
	Shape& Circle::operator++(int IgnoreMe) throw(){
		Circle *circle = new Circle(*this);
			x++;
			y++;
		return (*circle);
	}

	Shape& Circle::operator--() throw( ){		
			x--;
			y--;
			return (*this);
	}


	/*!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!
	*
	*	If you use this operator you have 
	*	to delete return adress manually!!!!!!!!!
	*
	*/
	Shape& Circle::operator--(int IgnoreMe) throw( ){
		Circle *circle = new Circle(*this);
			x--;
			y--;
			return (*circle);
	}

	/*overloaded << operator*/
	ostream& operator<<(ostream &outputStream,Circle circle){
		outputStream << " <circle cx=\""<< circle.getX() <<"\" cy=\""<< circle.getY() <<"\" r=\""<<circle.getRadius()
					<<"\" fill=\"blue\" /> " << endl;
		return outputStream;
	}

	void Circle::draw(ostream &outputStream) throw(){
		outputStream << " <circle cx=\""<< x <<"\" cy=\""<< y <<"\" r=\""<<radius
					<<"\" fill=\"blue\" /> " << endl;
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
}




















