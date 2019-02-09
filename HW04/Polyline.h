#ifndef POLYLINE_H_
#define POLYLINE_H_

#include "Polygon.h"
#include <vector>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include<fstream>


using namespace Poly;

namespace Polyl{
	class Polyline{


		public:
			Polyline(vector<Polygon::Polygon2D> polygons);
			Polyline(double x1,double x2);
			Polyline(double x1);
			Polyline();
			Polyline(const Polygon &poly);/*Copy constructor*/
			Polyline(Rectangle rectangle);
			Polyline(Triangle triangle);
			Polyline(Circle circle);

			/*setter and getter for polygon*/
			Polygon getPolygon()const;		
			void setPolygon(Polygon p);

			Polygon::Polygon2D operator[](int index);	/*for l value*/
			const Polygon::Polygon2D operator[](int index)const;		/*for r value*/
			bool operator==(const Polyline &polyline)const;
			bool operator!=(const Polyline &polyline)const;
			Polyline operator+(const Polyline &polyline);	
			friend ostream& operator<<(ostream& outputStream,const Polyline &polyline);

		private:
			Polygon polygon;


	};
}











#endif
