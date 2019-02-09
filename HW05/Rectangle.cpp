#include "Rectangle.h"

namespace MyShape{

	
	double Rectangle::total_area=0;
	double Rectangle::total_perimeter=0;

	Rectangle::Rectangle(double Width,double Height):Shape(),width(Width),height(Height){ }
	Rectangle::Rectangle(double Width):Shape(),width(Width),height(1.){  }

	Rectangle::Rectangle():Shape(),width(1.),height(1.){ }

	double Rectangle::area()const{ return height*width; }
	double Rectangle::perimeter()const{ return 2*height+2*width; }


	double Rectangle::getWidth()const throw(){ return width; }
	double Rectangle::getHeight()const throw(){ return height; }
	double Rectangle::getX() const throw(){ return x; }
	double Rectangle::getY() const throw(){ return y; }

	void Rectangle::setWidth(double Width) throw(ExceptionErrorrr){ 
		try{
			if(Width < 0)
				throw ExceptionErrorrr(Width);

			width=Width; 
		}
		catch(ExceptionErrorrr a){
			cout<<endl<<"width:"<<a.getMessage()<<" cannot be negative";
		}
	}
	void Rectangle::setHeight(double Height) throw(ExceptionErrorrr){ 
		try{
			if(Height <0)
				throw ExceptionErrorrr(Height);
		}
		catch(ExceptionErrorrr a){
			cout<<endl<<"Height:"<<a.getMessage()<<" cannot be negative";
		}
		height=Height;

	}
	void Rectangle::setX(double _x) throw(ExceptionErrorrr){ 
		try{
			if(_x<0){	
				throw ExceptionErrorrr(_x);
			}
			x=_x; 
		}
		catch(ExceptionErrorrr a){
			cout<<endl<<"x:"<<a.getMessage()<<" cannot be negative";
		}
	}
	void Rectangle::setY(double _y) throw(ExceptionErrorrr){ 
		try{
			if(_y<0)
				throw ExceptionErrorrr(_y);
		 y=_y; 
		}
		catch(ExceptionErrorrr a){
			cout<<endl<<"y:"<<a.getMessage()<<" cannot be negative";
		}
	}

	Shape& Rectangle::operator++() throw(){
		x++;
		y++;
		return (*this);
	}

	Shape& Rectangle::operator++(int IgnoreMe) throw(){
		Rectangle *rectangle = new Rectangle(*this);
		x++;
		y++;
		return (*rectangle);
	}

	Shape& Rectangle::operator--() throw(){	
				x--;
				y--;
			return (*this);
	}

	Shape& Rectangle::operator--(int IgnoreMe) throw(){		
		Rectangle *rectangle = new Rectangle(*this);	
				x--;
				y--;
			return (*rectangle);
	}

	ostream& operator<<(ostream &outputStream,Rectangle rectangle){
		outputStream << "<rect x=\""<< rectangle.getX() << "\" y=\""<< rectangle.getY() <<"\" width=\""<< rectangle.getWidth() <<"\" height=\""
							<< rectangle.getHeight() <<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
		return outputStream;
	}

	void Rectangle::draw(ostream &outputStream) throw(){
		outputStream << "<rect x=\""<< x << "\" y=\""<< y <<"\" width=\""<< width <<"\" height=\""
					<< height <<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
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

}





