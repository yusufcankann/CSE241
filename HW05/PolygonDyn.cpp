#include "PolygonDyn.h"
namespace MyShape{
	
	/*constructors.*/
	PolygonDyn::PolygonDyn(){
		points = new Point2D;
		points->setX(0);
		points->setY(0);
		used=1;
		capacity=1;
	}

	PolygonDyn::PolygonDyn(vector<Point2D> polygons){
		capacity = polygons.size();
		used = polygons.size();
		points = new Point2D[capacity];
		for(int i=0;i<capacity;i++)
			points[i]=polygons[i];
	}
	PolygonDyn::PolygonDyn(double x1,double x2){
		points = new Point2D;
		points->setX(x1);
		points->setY(x2);
		used=1;
		capacity=1;
	}
	PolygonDyn::PolygonDyn(double x1){
	points = new Point2D;
		points->setX(x1);
		points->setY(0);
		used=1;
		capacity=1;
	}
	PolygonDyn::PolygonDyn(Rectangle rectangle){
		points = new Point2D[4];

		points[0].setX(rectangle.getX());
		points[0].setY(rectangle.getY());
		points[1].setX( rectangle.getX()+rectangle.getWidth() );
		points[1].setY( rectangle.getY() );
		points[2].setX( rectangle.getX() + rectangle.getWidth() );
		points[2].setY( rectangle.getY() + rectangle.getHeight() );
		points[3].setX( rectangle.getX() );
		points[3].setY( rectangle.getY() + rectangle.getHeight() );
		used=4;
		capacity=4;
	}

	PolygonDyn::PolygonDyn(Triangle triangle){
		points = new Point2D[4];
		points[0].setX( triangle.getX1() );
		points[0].setY( triangle.getY1() );
		points[1].setX( triangle.getX2() );
		points[1].setY( triangle.getY2() );
		points[2].setX( triangle.getX3() );
		points[2].setY( triangle.getY3() );	
		used=3;
		capacity=3;
	}

	PolygonDyn::PolygonDyn(Circle circle){

		double x,y,x_t,y_t;
		double ang =3.6;
		double angle = (ang*PI)/180.; /*I convert the angle to radian.*/
		points = new Point2D[100];

		x=circle.getRadius();
		y=0;
		x_t=x;
		y_t=y;

		for(int i=0;i<100;i++){
			points[i].setX( x_t*cos(angle)-y_t*sin(angle) + circle.getRadius() + circle.getX() - circle.getRadius()  );
			points[i].setY( x_t*sin(angle)+y_t*cos(angle) + circle.getRadius() + circle.getY() + circle.getRadius()  );
			ang += 3.6;
			angle =  (ang*PI)/180.;
		}
	
		used=100;
		capacity=100;
	
	}

	PolygonDyn::PolygonDyn(Shape &shape){
	
		Rectangle *rec;
		Circle *cir;
		Triangle *tri;
	
		Shape *ptr1=&shape;
		rec=dynamic_cast<Rectangle*>(ptr1);
		if(rec!=nullptr){
			PolygonDyn temp1(*rec);
			*this=temp1;
			used=4;
			capacity=4;
		}
	
		Shape *ptr2=&shape;
		cir=dynamic_cast<Circle*>(ptr2);
		if(cir!=nullptr){
			PolygonDyn temp2(*cir);
			*this=temp2;
			used=100;
			capacity=100;
		}

		Shape *ptr3=&shape;
		tri=dynamic_cast<Triangle*>(ptr3);
		if(tri!=nullptr){
			PolygonDyn temp3(*tri);
			*this=temp3;
			used=3;
			capacity=3;
		}
	}
	PolygonDyn::PolygonDyn(const PolygonDyn &polygon){
		points = new Point2D[polygon.getCapacity()];
		capacity = polygon.getCapacity();
		used = polygon.getUsed();
		for(int i=0;i<used;i++){
			points[i] = polygon[i];
		}
	}

	PolygonDyn PolygonDyn::operator=(const PolygonDyn &polygon){
		if(capacity != polygon.getCapacity()){
			delete []points;
			capacity = polygon.getCapacity();
			used = polygon.getUsed();
			points = new Point2D[capacity];
		}
	
		for(int i=0;i<used;i++){
			points[i]=polygon[i];
		}
		return *this;

	}




	int PolygonDyn::getCapacity()const throw(){return capacity;}
	int PolygonDyn::getUsed()const throw(){return used;}

	double PolygonDyn::area()const throw(){
		int size=capacity;
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=((points[i].getX() * points[i+1].getY() )-(points[i].getY() * points[i+1].getX() ));
		}
		return abs(sum/2.0);

	}
	double PolygonDyn::perimeter()const throw(){
		int size=capacity;
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=(sqrt(pow((points[i].getX() - points[i+1].getX() ), 2)+ pow( (points[i].getY() - points[i+1].getY() ), 2)));
		}
		sum+=(sqrt(pow((points[0].getX() - points[size-1].getX() ), 2)+ pow( (points[0].getY() - points[size-1].getY() ), 2)));
		return sum;
	}
			
	void PolygonDyn::draw(ostream &outputStream)throw(){
		outputStream << "<polygon points=\"";

		for(int i=0;i<used;i++){
			outputStream <<points[i].getX()<<","<< points[i].getY() <<" ";
		}
		outputStream << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
	}

	/*<< operator uses draw function.*/
	ostream& operator<<(ostream& outputStream,PolygonDyn &polygon){
		polygon.draw(outputStream);
		return outputStream;
	}



	Shape& PolygonDyn::operator++()throw(){
		for(int i=0;i<used;i++){
			points[i].setX(points[i].getX() + 1.);
			points[i].setY(points[i].getY() + 1.);
		}
		return *this;
	}
	Shape& PolygonDyn::operator++(int IgnoreMe)throw(){	
		PolygonDyn *temp = new PolygonDyn(*this); 
		for(int i=0;i<used;i++){
			points[i].setX(points[i].getX() + 1.);
			points[i].setY(points[i].getY() + 1.);
		}
		return *temp;
	}
	Shape& PolygonDyn::operator--()throw(){
		for(int i=0;i<used;i++){
			points[i].setX(points[i].getX() - 1.);
			points[i].setY(points[i].getY() - 1.);
		}
		return *this;
	}
	Shape& PolygonDyn::operator--(int IgnoreMe)throw(){
		PolygonDyn *temp = new PolygonDyn(*this); 
		for(int i=0;i<used;i++){
			points[i].setX(points[i].getX() - 1.);
			points[i].setY(points[i].getY() - 1.);
		}
		return *temp;
	}


	Polygon::Point2D PolygonDyn::operator[](int index)throw( ){	
			return (points[index]);
	}

	const Polygon::Point2D PolygonDyn::operator[](int index)const throw( ){
			if(index<0)
				throw(index);
		
			return (points[index]);
	
	}
	/*Destructor.*/
	PolygonDyn::~PolygonDyn(){
		delete []points;
	}

}


