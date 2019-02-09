#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include<iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>

using namespace std;



class ComposedShape{

	public:
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

		/*void setContainerRectangle(Rectangle r);
		void setContainerCircle(Circle c);
		void setContainerTriangle(Triangle t);
	
		void setInsideRectangle(Rectangle r);
		void setInsideCircle(Circle c);
		void setInsideTriangle(Triangle t);

		Rectangle getContainerRectangle() const;
		Circle getContainerCircle() const;
		Triangle getContainerTriangle() const;*/
		Rectangle getContainerVectorRectangle(int i) const;
		Circle getContainerVectorCircle(int i) const;
		Triangle getContainerVectorTriangle(int i) const;

		/*Rectangle getInsideRectangle() const;
		Circle getInsideCircle() const;
		Triangle getInsideTriangle() const;*/
		Rectangle getInsideVectorRectangle(int i) const;
		Circle getInsideVectorCircle(int i) const;
		Triangle getInsideVectorTriangle(int i) const;
		
		void optimalFit(Rectangle r_container,Rectangle r_inside);
		void optimalFit(Rectangle r_container,Circle c_inside);
		void optimalFit(Rectangle r_container,Triangle t_inside);
		void optimalFit(Circle c_container,Rectangle r_inside);
		void optimalFit(Circle c_container,Circle c_inside);
		void optimalFit(Circle c_container,Triangle t_inside);
		void optimalFit(Triangle t_container,Rectangle r_inside);
		void optimalFit(Triangle t_container,Circle c_inside);
		void optimalFit(Triangle t_container,Triangle t_inside);

		int getInsideRectangleVectorSize();
		int getInsideCircleVectorSize();
		int getInsideTriangleVectorSize();

		void DrawContainerRectangle(ofstream &inputStream);
		void DrawContainerCircle(ofstream &inputStream);
		void DrawContainerTriangle(ofstream &inputStream);
		void DrawInsideRectangle(ofstream &inputStream);
		void DrawInsideCircle(ofstream &inputStream);
		void DrawInsideTriangle(ofstream &inputStream);

	private:
		Rectangle r_c,r_i;
		Circle c_c,c_i;
		Triangle t_c,t_i;
		vector<Rectangle> rectangle_i;
		vector<Rectangle> rectangle_c;
		vector<Circle> circle_c;
		vector<Circle> circle_i;
		vector<Triangle> triangle_c;
		vector<Triangle> triangle_i;

};

inline int circle_equation(double x,double y,double radius);

#endif  /* COMPOSEDSHAPE_H_ */













