#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include<fstream>
#include<cmath>

using namespace std;

class Triangle {
	public:
		/*constructors*/
		Triangle();
		Triangle(double len);
		/*setters and getters*/
		void setLength(double len);
		void setX11(double _x);
		void setX12(double _x);
		void setX21(double _x);
		void setX22(double _x);
		void setX31(double _x);
		void setX32(double _x);
		
		
		double getLength() const;
		double getX11() const;
		double getX12() const;
		double getX21() const;
		double getX22() const;
		double getX31() const;
		double getX32() const;
		/*draw function*/
		void draw (ofstream &inputStream);


	private:
		double length;
		double x11,x12,x21,x22,x31,x32;/*points for drawing circle to svg files.*/
};




#endif /* RATIONALNUM_H_ */
