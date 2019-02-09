#ifndef POLYGON_H_
#define POLYGON_H_
#include <vector>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include<fstream>
#include<cmath>

namespace Poly{
	class Polygon{
			
		public:
			class Polygon2D{

				public:
					Polygon2D(double x_,double y_);
					Polygon2D();
					void setX(double x_);
					void setY(double y_);
					double getX()const;
					double getY()const;
				private:
					double x;
					double y;
			};
			
			Polygon(vector<Polygon2D> polygons);
			Polygon(double x1,double x2);
			Polygon(double x1);
			Polygon();
			Polygon(const Polygon &poly);/*Copy constructor*/
			Polygon(Rectangle rectangle);
			Polygon(Triangle triangle);
			Polygon(Circle circle);
			
			void setPolygon2D_size(int size);
			int getPolygon2D_size()const;
			
			Polygon2D operator[](int index);	/*for l value*/
			const Polygon2D operator[](int index)const;		/*for r value*/
			Polygon operator=(const Polygon &polygon); /*Assignment operator*/
			bool operator==(const Polygon &polygon)const;
			bool operator!=(const Polygon &polygon)const;
			Polygon operator+(const Polygon &polygon);
			friend ostream& operator<<(ostream& outputStream,const Polygon &polygon);
			~Polygon();/*Destructor*/
			
		private:
			Polygon2D *polygon2D;
			int Polygon2D_size=0;

	};
}
	





#endif
