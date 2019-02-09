#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include<iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>

using namespace std;

enum class Shapes{Triangle,Rectangle,Circle};


class ComposedShape{

	public:
		/*ComposedShape constructors.*/
		ComposedShape();
		ComposedShape(Rectangle r_container,Rectangle r_inside);
		ComposedShape(Rectangle r_container,Circle c_inside);
		ComposedShape(Rectangle r_container,Triangle t_inside);
		ComposedShape(Circle c_container,Rectangle r_inside);
		ComposedShape(Circle c_container,Circle c_inside);
		ComposedShape(Circle c_container,Triangle t_inside);
		ComposedShape(Triangle t_container,Rectangle r_inside);
		ComposedShape(Triangle t_container,Circle c_inside);
		ComposedShape(Triangle t_container,Triangle t_inside);
		
		/*overloaded optimal fit function.*/
		void optimalFit(Rectangle r_container,Rectangle r_inside);
		void optimalFit(Rectangle r_container,Circle c_inside);
		void optimalFit(Rectangle r_container,Triangle t_inside);
		void optimalFit(Circle c_container,Rectangle r_inside);
		void optimalFit(Circle c_container,Circle c_inside);
		void optimalFit(Circle c_container,Triangle t_inside);
		void optimalFit(Triangle t_container,Rectangle r_inside);
		void optimalFit(Triangle t_container,Circle c_inside);
		void optimalFit(Triangle t_container,Triangle t_inside);
		

		/*
		  This 3 draw functions only for driver file.
		  I used these inside the driver file.
		*/
		void DrawContainerRectangle(ofstream &inputStream);
		void DrawContainerCircle(ofstream &inputStream);
		void DrawContainerTriangle(ofstream &inputStream);

		int getShapeVectorSize(); /*ShapeElem vectors size getter function.*/
		Shapes getContainerShape();	/*Container Shape class enum getter.*/
		
	


		/*ShapeElem class.*/
		class ShapeElem{
			public:
				/*Constructors*/
				ShapeElem(Circle &circle,Shapes shape);
				ShapeElem(Rectangle &rectangle,Shapes shape);
				ShapeElem(Triangle &triangle,Shapes shape);
				/*overloaded <<*/
				friend ostream& operator<<(ostream &outputStream,ComposedShape::ShapeElem ShapeE);
				
				/*getter and setter for void pointer and enum*/
				void* getShapePtr();
				void setShapePtr(void* ptr);
				Shapes getShapeEnum();
				void setShapeEnum(Shapes shape_);
				
				double perimeterLength();	/*perimeter leng getter*/
				double area();				/*area getter*/
			
			private:
				void* shapePtr;/*void pointer*/
				Shapes shape;	/*class enum*/
		};

			/*+= [] and << operators overloads for ComposedShape.*/
		ComposedShape::ShapeElem operator+=(ShapeElem &shape);
		ComposedShape::ShapeElem operator[](int index);
		friend ostream& operator<<(ostream &outputStream,ComposedShape Composed);
		
		/*Gets element of ShapeElem vector.*/
		ComposedShape::ShapeElem getShapeElemVector(int index)const; 



	private:
		/*Inner and Container shapes.*/
		Rectangle r_c,r_i;
		Circle c_c,c_i;
		Triangle t_c,t_i;

	
		vector<ShapeElem> shapes; /*Shape elem vector. It holds inner shapes.*/
		Shapes Container;		/*Class enum for container shape type.*/

};

/*Circle equation function. I used this inside the optimalfit file circle part.*/
inline int circle_equation(double x,double y,double radius);

#endif  /* COMPOSEDSHAPE_H_ */













