#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <fstream>

using namespace std;

class Circle{

	public:
		/*constructors*/
		Circle(double rad);
		Circle();
		/*setters and getters*/
		double getRadius() const;
		double getX() const;
		double getY() const;

		void setRadius(double rad);
		void setX(double _x);
		void setY(double _y);
      	
		/*draw function*/
		void draw (ofstream &inputStream);

	private:
		double radius;
		double x;
		double y;

};


#endif
