
#include "Polygon.h"
#define PI 3.14

namespace Poly{
	/*Constructors for Polygon2D inner class*/
	Polygon::Polygon2D::Polygon2D(double x_,double y_){
		if(x<0)
			cout<<endl<<"Invalid x. Please enter a positive number"<<endl;
		if(y<0)
			cout<<endl<<"Invalid y. Please enter a positive number"<<endl;
		if( x>= 0 && y>=0){
			x=x_;
			y=y_;
		}
		else
			cout<<"Invalid Input";
	}
	Polygon::Polygon2D::Polygon2D(){
		x=0;
		y=0;
	}

	/*getters and setters*/
	void Polygon::Polygon2D::setX(double x_){
		if(x_<0)
			cout<<"Invalid Input.Please enter a positive number for x."<<endl;
		else
			x=x_;
	}
	void Polygon::Polygon2D::setY(double y_){
		if(y_<0)
			cout<<"Invalid Input.Please enter a positive number for y."<<endl;
		else
			y=y_;	
	}
	double Polygon::Polygon2D::getX()const{
		return x;
	}
	double Polygon::Polygon2D::getY()const{
		return y;
	}


	/*Construtors for Polygon*/
	
	Polygon::Polygon(vector<Polygon::Polygon2D> polygons){
		polygon2D = new Polygon2D[polygons.size()];		
		Polygon2D_size = polygons.size();

		for(int i=0;i< Polygon2D_size ; ++i){
			polygon2D[i].setX( polygons[i].getX() );
			polygon2D[i].setY( polygons[i].getY() );
		}

	}
	Polygon::Polygon(double x1,double x2){
		polygon2D = new Polygon2D;
		Polygon2D_size=1;
		(*polygon2D).setX(x1);
		(*polygon2D).setY(x2);
	}
	/*If customer gives one parameter y coordinate automatically sets 0.*/
	Polygon::Polygon(double x1){
		polygon2D = new Polygon2D;
		Polygon2D_size=1;
		(*polygon2D).setX(x1);
		(*polygon2D).setY(0);
	}
	/*No parameter constructor*/
	Polygon::Polygon(){
		polygon2D = new Polygon2D;
		Polygon2D_size=1;
		(*polygon2D).setX(0);
		(*polygon2D).setY(0);
	}
	/*Copy Constructor*/
	Polygon::Polygon(const Polygon &poly):Polygon2D_size(poly.getPolygon2D_size()) {
		
		polygon2D = new Polygon2D[poly.getPolygon2D_size()];
		
		for(int i=0;i<Polygon2D_size;i++){
			polygon2D[i] = poly[i];
		}
	}	

	/*conversion constructor for rectangle*/
	Polygon::Polygon(Rectangle rectangle){
		polygon2D = new Polygon2D[4];
		Polygon2D_size=4;
		polygon2D[0].setX(rectangle.getX());
		polygon2D[0].setY(rectangle.getY());
		polygon2D[1].setX( rectangle.getX()+rectangle.getWidth() );
		polygon2D[1].setY( rectangle.getY() );
		polygon2D[2].setX( rectangle.getX() + rectangle.getWidth() );
		polygon2D[2].setY( rectangle.getY() + rectangle.getHeight() );
		polygon2D[3].setX( rectangle.getX() );
		polygon2D[3].setY( rectangle.getY() + rectangle.getHeight() );
	}
	/*conversion constructor for triangle*/
	Polygon::Polygon(Triangle triangle){
		polygon2D = new Polygon2D[3];
		Polygon2D_size=3;
		polygon2D[0].setX( triangle.getX11() );
		polygon2D[0].setY( triangle.getX12() );
		polygon2D[1].setX( triangle.getX21() );
		polygon2D[1].setY( triangle.getX22() );
		polygon2D[2].setX( triangle.getX31() );
		polygon2D[2].setY( triangle.getX32() );	
	}
	
	/*conversion constructor for circle*/
	/*I used point rotation formule here */
	Polygon::Polygon(Circle circle){

		double x,y,x_t,y_t;
		double ang =3.6;
		double angle = (ang*PI)/180.; /*I convert the angle to radian.*/
		polygon2D = new Polygon2D[100];
		Polygon2D_size=100;

		x=circle.getRadius();
		y=0;
		x_t=x;
		y_t=y;
		for(int i=0;i<100;i++){
			polygon2D[i].setX( x_t*cos(angle)-y_t*sin(angle) + circle.getRadius() + circle.getX() - circle.getRadius() );
			polygon2D[i].setY( x_t*sin(angle)+y_t*cos(angle) + circle.getRadius() + circle.getY() - circle.getRadius());
			ang += 3.6;
			angle =  (ang*PI)/180.;
		}


	}

	/*setter and getter for Polygon2D pointer size.*/
	void Polygon::setPolygon2D_size(int size){
		Polygon2D_size = size;
	}
	int Polygon::getPolygon2D_size()const{
		return Polygon2D_size;
	}
	
	/* [] operator overload*/
	Polygon::Polygon2D Polygon::operator[](int index){
		return polygon2D[index];
	}
	const Polygon::Polygon2D Polygon::operator[](int index)const{
		return polygon2D[index];
	}
	
	/*Assignment Operator*/
	Polygon Polygon::operator=(const Polygon &polygon){

		if(Polygon2D_size != polygon.getPolygon2D_size() ){
			delete [] polygon2D;
			polygon2D = new Polygon2D[polygon.getPolygon2D_size()];
			Polygon2D_size = polygon.getPolygon2D_size();
		}
		for(int i=0;i<Polygon2D_size;i++){
			polygon2D[i] = polygon[i];
		}

		return *this;

	}
	
	/*== operator overload.*/
	bool Polygon::operator==(const Polygon &polygon)const{
		int counter=0;

		if(Polygon2D_size == polygon.getPolygon2D_size()){
			for(int i=0 ; i<Polygon2D_size ; i++){
				if(polygon2D[i].getX() == polygon[i].getX() && polygon2D[i].getY() == polygon[i].getY() )
					counter++;
			}
				
			if(counter == Polygon2D_size)
				return true;
			else 
				return false;
		}
		else 
			return false;
	}
	/*!= operator overload.*/
	bool Polygon::operator!=(const Polygon &polygon)const{
		int counter=0;

		if(Polygon2D_size == polygon.getPolygon2D_size()){
			for(int i=0 ; i<Polygon2D_size ; i++){
				if(polygon2D[i].getX() == polygon[i].getX() && polygon2D[i].getY() == polygon[i].getY()) 
					counter++;
			}
				
			if(counter != Polygon2D_size)
				return true;
			else 
				return false;
		}
		else 
			return true;
	}
	/*+ operator overload.*/
	Polygon Polygon::operator+(const Polygon &polygon){

		vector <Polygon::Polygon2D> sum;
		for(int i=0 ; i<Polygon2D_size ; i++){
			sum.push_back(polygon2D[i]);
		}
		for(int j=0; j< (polygon.getPolygon2D_size()) ; j++){
			sum.push_back(polygon[j]);
		}

		return Polygon(sum);
		
	}
	
	/*<< operator overload.*/
	ostream& operator<<(ostream& outputStream,const Polygon &polygon){
		outputStream << "<polygon points=\"";

		for(int i=0;i< polygon.getPolygon2D_size() ; i++){
			outputStream <<polygon[i].getX()<<","<< polygon[i].getY() <<" ";
		}

		outputStream << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
		return outputStream;
	}


	/*Destructor*/
	Polygon::~Polygon(){

		delete []polygon2D;

	}

}













