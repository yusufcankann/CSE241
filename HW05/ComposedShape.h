#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include<iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include <vector>
#include<cmath>
#include<new>


class ExceptionError1{
	public:
		ExceptionError1(){ }
		ExceptionError1(double theMessage): message(theMessage) {
		}
		double getMessage( ) { return message; }
	private:
		double message;
};

namespace MyShape{
	class ComposedShape:public Shape{

		public:
			/*ComposedShape constructors.*/
			ComposedShape();
			ComposedShape(Shape &container,Shape &inside);
			ComposedShape(vector<Shape*> shapee);
			ComposedShape(vector<Shape*> shapee,Shape &containerr,Shape &innerr);
			ComposedShape(const ComposedShape& cs);


			ComposedShape operator=(ComposedShape &cs)throw();

			double area()const throw();
			double perimeter()const throw();

			Shape& operator++()throw();
			Shape& operator++(int IgnoreMe)throw();
			Shape& operator--() throw();
			Shape& operator--(int IgnoreMe) throw();

			Shape* operator[](int index)throw(ExceptionError1);
			const Shape* operator[](int index)const throw(ExceptionError1);

			void DrawContainerRectangle(ostream &inputStream)const throw();
			void DrawContainerCircle(ostream &inputStream)const throw();
			void DrawContainerTriangle(ostream &inputStream)const throw();
			
			friend ostream& operator<<(ostream &outputStream,ComposedShape &composed);

			int getVectorSize()const throw();
			vector<Shape*> getVector()const throw();

			Shape* getContainer()const throw();
			Shape* getInner()const throw();

			void draw(ostream &outputStream) throw();

			virtual ~ComposedShape();

			Shape* operator+=(Shape *shapee)throw();

			void optimalFit(Rectangle r_container,Rectangle r_inside) throw();
			void optimalFit(Rectangle r_container,Circle c_inside) throw();
			void optimalFit(Rectangle r_container,Triangle t_inside) throw();
			void optimalFit(Circle c_container,Rectangle r_inside) throw();
			void optimalFit(Circle c_container,Circle c_inside) throw();
			void optimalFit(Circle c_container,Triangle t_inside) throw();
			void optimalFit(Triangle t_container,Rectangle r_inside) throw();
			void optimalFit(Triangle t_container,Circle c_inside) throw();
			void optimalFit(Triangle t_container,Triangle t_inside) throw();
			void optimalFit() throw();

		


		private:
			Shape *container,*inner;
			vector<Shape*> shape;



	};

}








#endif
