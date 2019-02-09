#include "Triangle.h"


namespace MyShape{

	
	
	double Triangle::total_area=0;
	double Triangle::total_perimeter=0;


	Triangle::Triangle(double len):Shape(),length(len){
		x1= 0;
		y1= ( len*sqrt(3.) ) / 2.;
		x2= len/2.;
		y2= 0;
		x3=len;
		y3=( len*sqrt(3.) ) / 2. ;
	

	 }

	Triangle::Triangle():Shape(),length(1.){ }

	double Triangle::area()const{ return ( (length*length*sqrt(3))/4 ); }
	double Triangle::perimeter()const{ return length*3; }


	/*setters and getters*/
	void Triangle::setLength(double len)throw(ExceptionError) { 
		try{
			if(len<0)
				throw ExceptionError(len);
			length=len;
		} 
		catch(ExceptionError a){
			cout<<endl<<"Length:"<<a.getMessage()<<" cannot be negative";
		}
	}

	void Triangle::setX1(double x)throw(ExceptionError){ 
		try{
			if(x<0)
				throw ExceptionError(x);
			x1=x;
		} 
		catch(ExceptionError a){
			cout<<endl<<"x1:"<<a.getMessage()<<" cannot be negative";
		}
	}

	void Triangle::setY1(double y)throw(ExceptionError){ 
		try{
			if(y<0)
				throw ExceptionError(y);
			y1=y;
		} 
		catch(ExceptionError a){
			cout<<endl<<"y1:"<<a.getMessage()<<" cannot be negative";
		}
	}
	void Triangle::setX2(double x)throw(ExceptionError){ 
		try{
			if(x<0)
				throw ExceptionError(x);
			x2=x;
		} 
		catch(ExceptionError a){
			cout<<endl<<"x2:"<<a.getMessage()<<" cannot be negative";
		}
	}
	void Triangle::setY2(double y)throw(ExceptionError){
		try{
			if(y<0)
				throw ExceptionError(y);
			y2=y;
		} 
		catch(ExceptionError a){
			cout<<endl<<"y2:"<<a.getMessage()<<" cannot be negative";
		}
	}
	void Triangle::setX3(double x)throw(ExceptionError){ 
		try{
			if(x<0)
				throw ExceptionError(x);
			x3=x;
		} 
		catch(ExceptionError a){
			cout<<endl<<"x3:"<<a.getMessage()<<" cannot be negative";
		}
	}
	void Triangle::setY3(double y)throw(ExceptionError){
		try{
			if(y<0)
				throw ExceptionError(y);
			y3=y;
		} 
		catch(ExceptionError a){
			cout<<endl<<"y3:"<<a.getMessage()<<" cannot be negative";
		}
	}
	double Triangle::getLength() const throw(){ return length; }
	double Triangle::getX1() const throw(){ return x1; }
	double Triangle::getY1() const throw(){ return y1; }
	double Triangle::getX2() const throw(){ return x2; }
	double Triangle::getY2() const throw(){ return y2; }
	double Triangle::getX3() const throw(){	return x3; }
	double Triangle::getY3() const throw(){ return y3; }


	Shape& Triangle::operator++() throw(){
		x1++;
		y1++;
		x2++;
		y2++;
		x3++;
		y3++;
		return (*this);
	}

	Shape& Triangle::operator++(int IgnoreMe) throw(){
		Triangle *triangle =new Triangle(*this);
		x1++;
		y1++;
		x2++;
		y2++;
		x3++;
		y3++;
		return (*triangle);
	}

	Shape& Triangle::operator--() throw(){		
			x1--;
			y1--;
			x2--;
			y2--;
			x3--;
			y3--;		
		return (*this);
	}

	Shape& Triangle::operator--(int IgnoreMe) throw(){
		Triangle *triangle = new Triangle(*this);
		
			x1--;
			y1--;
			x2--;
			y2--;
			x3--;
			y3--;
		return (*triangle);
	}

	/*overloaded << operator*/
	ostream& operator<<(ostream &outputStream,Triangle triangle){
		outputStream << "<polygon points=\"" <<triangle.getX1()<<","<< triangle.getY1() <<" "<<triangle.getX2()<<","<<triangle.getY2() <<" "
							<< triangle.getX3() << "," << triangle.getY3() << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
		return outputStream;
	}

	void Triangle::draw(ostream &outputStream) throw(){
		outputStream << "<polygon points=\"" <<x1<<","<< y1 <<" "<<x2<<","<<y2 <<" "
							<< x3 << "," << y3 << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
	}

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

}















