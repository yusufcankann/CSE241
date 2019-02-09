#ifndef SHAPE_H_
#define SHAPE_H_

#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace MyShape{
	class Shape{
		public:
			
			Shape();
			
			virtual double area()const=0;
			virtual double perimeter()const=0;
			
			virtual void draw(ostream &outputStream)=0;
	

			virtual Shape& operator++() =0;
			virtual Shape& operator++(int IgnoreMe) =0;
			virtual Shape& operator--() throw()=0;
			virtual Shape& operator--(int IgnoreMe)=0;

			virtual ~Shape()=default;
			
			bool operator==(const Shape &s)throw();
			bool operator!=(const Shape &s)throw();
			bool operator<=(const Shape &s)throw();
			bool operator>=(const Shape &s) throw();
			bool operator<(const Shape &s)throw();
			bool operator>(const Shape &s)throw();
	};
}



#endif
