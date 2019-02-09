#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_


#include<iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include <vector>

using namespace std;
using namespace Poly;

enum class Shapes{Triangle,Rectangle,Circle};

namespace Composed{
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

		
		
			Shapes getContainerShape();	/*Container Shape class enum getter.*/

			/*Overloaded functions for Polygon*/
	
			const Polygon operator[](int index)const;	
			Polygon operator[](int index);
	
			Polygon operator+=(Polygon &shape); /*Polygon vectors size getter function.*/
			friend ostream& operator<<(ostream &outputStream,ComposedShape Composed);
		
			int getShapeVectorSize();


		private:
			/*Inner and Container shapes.*/
			Rectangle r_c,r_i;
			Circle c_c,c_i;
			Triangle t_c,t_i;

	
			vector<Polygon> shapes; /*Polygon vector. It holds inner shapes.*/
			Shapes Container;		/*Class enum for container shape type.*/

	};
}
/*Circle equation function. I used this inside the optimalfit file circle part.*/


	//inline int circle_equation(double x,double y,double radius);


#endif  /* COMPOSEDSHAPE_H_ */













