#include "Polyline.h"


namespace Polyl{
	/*Constructors*/
	Polyline::Polyline(vector<Polygon::Polygon2D> polygons){
		Polygon temp(polygons);
		polygon = temp;
	}

	Polyline::Polyline(double x1,double x2){
		Polygon temp(x1,x2);
		polygon = temp;
	}

	Polyline::Polyline(double x1){
		Polygon temp(x1);
		polygon = temp;
	}

	Polyline::Polyline(){
		Polygon temp;
		polygon = temp;
	}
	Polyline::Polyline(Rectangle rectangle){
		Polygon temp(rectangle);
		polygon = temp;

	}
	Polyline::Polyline(Triangle triangle){
		Polygon temp(triangle);
		polygon = temp;
	}
	Polyline::Polyline(Circle circle){
		Polygon temp(circle);
		polygon = temp;
	}

	/*setter and getter for polygon*/
	Polygon Polyline::getPolygon()const{
		return polygon;
	}
	void Polyline::setPolygon(Polygon p){
		polygon = p;
	}

	/*for l value*/
	Polygon::Polygon2D Polyline::operator[](int index){
		return polygon[index];
	}
	/*for r value*/
	const Polygon::Polygon2D Polyline::operator[](int index)const{
		return polygon[index];
	}		


	bool Polyline::operator==(const Polyline &polyline)const{
		if(polygon == polyline.getPolygon())
			return true;
		else 
			return false;
	}
	bool Polyline::operator!=(const Polyline &polyline)const{
		if(polygon == polyline.getPolygon())
			return false;
		else 
			return true;
	}


	Polyline Polyline::operator+(const Polyline &polyline){
		Polygon temp;
		Polyline tempp;

		temp = polygon + polyline.getPolygon();

		tempp.setPolygon(temp);
	
		return tempp;
	}
	ostream& operator<<(ostream& outputStream,const Polyline &polyline){
		outputStream << "<polyline points=\"";

		for(int i=0;i< (polyline.getPolygon() ).getPolygon2D_size() ; i++){
			outputStream <<  polyline[i].getX()<<","<<polyline[i].getY() <<" ";
		}

		outputStream << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
		return outputStream;
	}
}












