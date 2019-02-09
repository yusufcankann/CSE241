
#include "Shape.h"

namespace MyShape{	

	Shape::Shape(){ }


		bool Shape::operator==(const Shape &s)throw(){ return ( this->area() == s.area() ); }
		bool Shape::operator!=(const Shape &s)throw(){ return ( this->area() != s.area() ); }
		bool Shape::operator<=(const Shape &s)throw(){ return ( this->area() <= s.area() ); }
		bool Shape::operator>=(const Shape &s)throw(){ return ( this->area() >= s.area() ); }
		bool Shape::operator<(const Shape &s)throw(){ return ( this->area() < s.area() ); }
		bool Shape::operator>(const Shape &s)throw(){ return ( this->area() > s.area() ); }

		ostream& operator<<(ostream &outputStream,const Shape &shape){
			outputStream << shape;
			return outputStream;
	}
}



