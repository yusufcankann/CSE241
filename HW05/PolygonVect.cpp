#include "PolygonVect.h"
namespace MyShape{
	PolygonVect::PolygonVect(){
		Point2D point;
		point.setX(0);
		point.setY(0);
		points.push_back(point);
	}

	PolygonVect::PolygonVect(vector<Point2D> polygons){
		for(auto a:polygons)
			points.push_back(a);
	}
	PolygonVect::PolygonVect(double x1,double x2){
		Point2D point;
		point.setX(x1);
		point.setY(x2);
		points.push_back(point);
	}
	PolygonVect::PolygonVect(double x1){
		Point2D point;
		point.setX(x1);
		point.setY(0);
		points.push_back(point);
	}

	PolygonVect::PolygonVect(Rectangle rectangle){
		Point2D polygon[4];

		polygon[0].setX(rectangle.getX());
		polygon[0].setY(rectangle.getY());
		polygon[1].setX( rectangle.getX()+rectangle.getWidth() );
		polygon[1].setY( rectangle.getY() );
		polygon[2].setX( rectangle.getX() + rectangle.getWidth() );
		polygon[2].setY( rectangle.getY() + rectangle.getHeight() );
		polygon[3].setX( rectangle.getX() );
		polygon[3].setY( rectangle.getY() + rectangle.getHeight() );
	
		points.push_back(polygon[0]);
		points.push_back(polygon[1]);
		points.push_back(polygon[2]);
		points.push_back(polygon[3]);
	}

	PolygonVect::PolygonVect(Triangle triangle){
		Point2D  polygon[3];
		polygon[0].setX( triangle.getX1() );
		polygon[0].setY( triangle.getY1() );
		polygon[1].setX( triangle.getX2() );
		polygon[1].setY( triangle.getY2() );
		polygon[2].setX( triangle.getX3() );
		polygon[2].setY( triangle.getY3() );	
	
		points.push_back(polygon[0]);
		points.push_back(polygon[1]);
		points.push_back(polygon[2]);
	}

	PolygonVect::PolygonVect(Circle circle){

		double x,y,x_t,y_t;
		double ang =3.6;
		double angle = (ang*PI)/180.; /*I convert the angle to radian.*/
		Point2D Polygon2D[100];

		x=circle.getRadius();
		y=0;
		x_t=x;
		y_t=y;

		for(int i=0;i<100;i++){
			Polygon2D[i].setX( x_t*cos(angle)-y_t*sin(angle) + circle.getRadius() + circle.getX() - circle.getRadius()  );
			Polygon2D[i].setY( x_t*sin(angle)+y_t*cos(angle) + circle.getRadius() + circle.getY() + circle.getRadius()  );
			ang += 3.6;
			angle =  (ang*PI)/180.;
		}
	
		for(auto x:Polygon2D)
			points.push_back(x);
	}

	/*Here i used downcasting*/
	PolygonVect::PolygonVect(Shape &shape){
	
		Rectangle *rec;
		Circle *cir;
		Triangle *tri;
	
		Shape *ptr1=&shape;
		rec=dynamic_cast<Rectangle*>(ptr1);
		if(rec!=nullptr){
			PolygonVect temp1(*rec);
			*this=temp1;
		}	
	
		Shape *ptr2=&shape;
		cir=dynamic_cast<Circle*>(ptr2);
		if(cir!=nullptr){
			PolygonVect temp2(*cir);
			*this=temp2;
		}

		Shape *ptr3=&shape;
		tri=dynamic_cast<Triangle*>(ptr3);
		if(tri!=nullptr){
			PolygonVect temp3(*tri);
			*this=temp3;
		}
	}

	double PolygonVect::area()const throw(){
		int size=points.size();
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=((points[i].getX() * points[i+1].getY() )-(points[i].getY() * points[i+1].getX() ));
		}
		return abs(sum/2.0);

	}
	double PolygonVect::perimeter()const throw(){
		int size=points.size();
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=(sqrt(pow((points[i].getX() - points[i+1].getX() ), 2)+ pow( (points[i].getY() - points[i+1].getY() ), 2)));
		}
		sum+=(sqrt(pow((points[0].getX() - points[size-1].getX() ), 2)+ pow( (points[0].getY() - points[size-1].getY() ), 2)));
		return sum;
	}
			
	void PolygonVect::draw(ostream &outputStream) throw(){
		outputStream << "<polygon points=\"";

		for(auto a:points){
			outputStream <<a.getX()<<","<< a.getY() <<" ";
		}
		outputStream << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
	}

	ostream& operator<<(ostream& outputStream,PolygonVect &polygon){
		polygon.draw(outputStream);
		return outputStream;
	}
	
	Shape& PolygonVect::operator++()throw(){ 
		vector<Point2D> temp;
		for(auto x:points){
		
			Point2D *ptr=new Point2D;
			ptr->setX((x.getX()) +1.);	
			ptr->setY((x.getY()) + 1.);	
			temp.push_back(*ptr);
		
			delete ptr;
		}
		points=temp;
		return *this;
	}

	/*!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!
	*
	*	If you use this(postfix++) operator you have 
	*	to delete return adress manually!!!!!!!!!
	*
	*/
	Shape& PolygonVect::operator++(int IgnoreMe)throw(){
		PolygonVect *poly = new PolygonVect(*this);
		vector<Point2D> temp;
		for(auto x:points){
		
			Point2D *ptr=new Point2D;
			ptr->setX((x.getX()) + 1.);	
			ptr->setY((x.getY()) + 1.);	
			temp.push_back(*ptr);
		
			delete ptr;
		}
		points=temp;
		return *poly;
	}

	Shape& PolygonVect::operator--() throw(){ 
		vector<Point2D> temp;
		for(auto x:points){
		
			Point2D *ptr=new Point2D;
			ptr->setX((x.getX()) - 1.);	
			ptr->setY((x.getY()) - 1.);	
			temp.push_back(*ptr);
		
			delete ptr;
		}
		points=temp;
		return *this;
	}

	/*!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!
	*
	*	If you use this(postfix--) operator you have 
	*	to delete return adress manually!!!!!!!!!
	*
	*/
	Shape& PolygonVect::operator--(int IgnoreMe)throw(){
		PolygonVect *poly = new PolygonVect(*this);
		vector<Point2D> temp;
		for(auto x:points){
		
			Point2D *ptr=new Point2D;
			ptr->setX((x.getX()) - 1.);	
			ptr->setY((x.getY()) - 1.);	
			temp.push_back(*ptr);
		
			delete ptr;
		}
		points=temp;
		return *poly;
	}

	Polygon::Point2D PolygonVect::operator[](int index) throw(){
		try{
			if(index<0)
				throw(index);
		
			return points[index];
		}
		catch(int a){
			cout<<endl<<"Invalid Index!!"<<endl;
		}
		return points[index];
	}

	const Polygon::Point2D PolygonVect::operator[](int index)const throw(){
	
		try{
			if(index<0)
				throw(index);
		
			return points[index];
		}
		catch(int a){
			cout<<endl<<"Invalid Index!!"<<endl;
		}
		return points[index];
	}

}











