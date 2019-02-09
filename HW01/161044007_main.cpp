/*
	Yusuf Can Kan
	161044007
*/

#include "shapes.h"

#define PI 3.14159265

using namespace std;

void choices(ofstream &inputStream);


int main(){

	ofstream inputStream;
	inputStream.open("result.svg");
	
	choices(inputStream);

	inputStream.close();
	
	return 0;
}
/*It takes the inputs and all informations from user and 
  it calls the functions.*/
void choices(ofstream &inputStream){
	char containerShape,smallShape;
	int wContainer,hContainer,wSmall,hSmall,radius,sradius;
	double length,slength;
	Shapes shape;
	Shapes inshape;
	cout << "Please enter the main container shape (R, C, T):" << endl;
	cin >> containerShape;
	
	if(containerShape == 'R' || containerShape=='r'){
		cout << "Enter the width:";
		cin >> wContainer;
		cout << endl << "Enter the height:";
		cin >> hContainer;
		shape = Shapes::Rectangle;
	}
	else if(containerShape == 'T' || containerShape =='t'){
		cout << "Please enter the length of sides:";
		cin >> length;
		shape = Shapes::Triangle;
	}
	else if(containerShape == 'C' || containerShape =='c'){
		cout << "Enter the radius:";
		cin >> radius;
		shape = Shapes::Circle;
	}

	cout <<"Please enter the small shape (R, C, T):";
	cin >> smallShape;
	
	if(smallShape=='C' || smallShape=='c')
		inshape = Shapes::Circle;
	else if(smallShape=='T' || smallShape=='t')
		inshape = Shapes::Triangle;
	else if(smallShape == 'R' || smallShape=='r')
		inshape = Shapes::Rectangle;
	
	if(shape==Shapes::Rectangle && inshape == Shapes::Circle){
		cout << "Please enter the radius:";
		cin >> radius;
		containerRectangleInsideCircle(wContainer,hContainer,radius,inputStream);
	}
	else if(shape == Shapes::Rectangle && inshape == Shapes::Triangle){
		cout << "Please enter the length of sides:";
		cin >> length;
		containerRectangleInsideTriangle(static_cast<double>(wContainer),static_cast<double>(hContainer),length,inputStream);
	}
	else if(shape == Shapes::Rectangle && inshape == Shapes::Rectangle){
		cout << "Enter the small rectangle width:";
		cin >> wSmall;
		cout << endl << "Enter the small rectangle height:";
		cin >> hSmall;
		containerRectangleInsideRectangle(wContainer,hContainer,wSmall,hSmall,inputStream);
	}
	else if( shape == Shapes::Triangle && inshape == Shapes::Triangle){
		cout << "Please enter the small triangles length of sides:";
		cin >> slength;
		containerTriangleInsideTriangle(length,slength,inputStream);
	}
	else if( shape == Shapes::Triangle && inshape == Shapes::Circle ){
		cout << "Please enter the radius of circles:";
		cin >> sradius;
		containerTriangleInsideCircle(length,sradius,inputStream);
	}
	else if( shape == Shapes::Triangle && inshape == Shapes::Rectangle){
		cout << "Enter the small rectangle width:";
		cin >> wSmall;
		cout << endl << "Enter the small rectangle height:";
		cin >> hSmall;
		containerTriangleInsideRectangle(length,static_cast<double>(wSmall),static_cast<double>(hSmall),inputStream);
	}
	else if(shape == Shapes::Circle && inshape == Shapes::Circle){
		cout << endl << "Enter the small circle radius:";
		cin >> sradius;
		containerCircleInsideCircle(static_cast<double>(radius),static_cast<double>(sradius),inputStream);
	}
	else if(shape == Shapes::Circle && inshape == Shapes::Rectangle){
		cout << "Enter the small rectangle width:";
		cin >> wSmall;
		cout << endl << "Enter the small rectangle height:";
		cin >> hSmall;
		containerCircleInsideRectangle(radius,wSmall,hSmall,inputStream);
	}
	else if(shape == Shapes::Circle && inshape == Shapes::Triangle){
		cout << "Please enter the small triangles length of sides:";
		cin >> slength;
		containerCircleInsideTriangle(static_cast<double>(radius),slength,inputStream);
	}
}



























