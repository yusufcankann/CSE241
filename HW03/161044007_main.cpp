
/*
	Yusuf Can Kan
	161044007
*/


#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ComposedShape.h"

using namespace std;




/*
*******************************************************************************************************************
*******************************************************************************************************************
***************************************IMPORTANT NOTE**************************************************************
*******************************************************************************************************************
*******************************************************************************************************************
*																												  
*	
*	In first part i tested all the tasks which wanted to HW3.
*	Only i tested the ComposedShape << overload to part2.
*
*
*	Part1 creates appropreate variables and tests the tasks.
*
*	For example if i test << operator overload, i created
*	appropriate variable and did this;
*	inputstream << variable;
*	and prints the rigth results on the terminal.
*	At first it seems to complicated but i divide the codes with "-----------------" on the terminal
*	and cpp file.
*
*	When customer stars the program part1 is automaticly prints the result on the terminal.
*	After that ask customer that= Do you want to test part2?.
*
*	In part2, I created the menu for printing the main purpose of this program.
*	Customer choses container and inner shapes and it automaticly prints the svg files.
*
*
*
*
*
*	About svg files;
*	While testing for shapes '<<' overload operator i created shapename.svg.
*	While testing for ShapeElem '<<' overload operator i created ShapeElemTest.svg.
*	
*	The other svg files printf composed shape elements(Container and inner shapes.)
*	They are named with order; output1,output2,output3,....,output9. (With part2 menu order).
*
*
*
*******************************************************************************************************************
*******************************************************************************************************************
*****************************************IMPORTANT NOTE************************************************************
*******************************************************************************************************************
*******************************************************************************************************************
*/



int main() {
cout<<"a";

	ofstream inputStream;
	int choice;
	int condition=0;
	Rectangle rectangle[4];
	Triangle triangle[4];
	Circle circle[4];

/********************************************PART1********************************************************/
	cout<<endl;
	cout<<endl;
	/*
	  Static area and perimeter length parameters only added with parameters constructors. 
	  If customer creates the shape with no parameter than total_area and total_perimeter doesn't increase.
	  When the customer setted the shape then increase_perimeter and increase_total_area function calls and this functions
	  increases the totals.
	*/

	/****************************Static area and Perimeter Length function tests.*********************************/
	/*This part prints the result to the terminal.*/
	/*************************************************************************************************************/
	cout<<"Static functions tests"<<endl;
	cout<<"Total area and Total perimeter Length Static functions tests"<<endl;
	cout<<endl<<"------------"<<endl;
	Triangle triangle1(100);
	Triangle triangle2(200);
	
	cout<<"Triangle total area="<<Triangle::show_total_area()<<endl;
	cout<<"Triangle total perimeter length="<<Triangle::show_total_perimeter();
	
	cout<<endl;
	cout<<endl;
	
	Circle circle1(100);
	Circle circle2(200);

	cout<<"Circle total area="<<Circle::show_total_area()<<endl;
	cout<<"Circle total perimeter length="<<Circle::show_total_perimeter();
	
	cout<<endl;
	cout<<endl;
	
	Rectangle rectangle1(100,100);
	Rectangle rectangle2(200,200);
	
	cout<<"Rectangle total area="<<Rectangle::show_total_area()<<endl;
	cout<<"Rectangle total perimeter length="<<Rectangle::show_total_perimeter();
	cout<<endl<<"------------";
	
	cout<<endl;
	cout<<endl;



	cout<<endl<<endl<<"Perimeter Length and Area";
	cout<<endl<<"------------";
	/*perimeter length and area functions tests.*/
	circle[0].setRadius(5);
	cout << endl <<"Primeter length of circle(radius=5):"<< circle[0].perimeterLength()
		 << endl<< "Area of circle:"<< circle[0].area() << endl;
			


	rectangle[0].setWidth(100);
	rectangle[0].setHeight(135);
	cout << endl << endl << "Primeter length of rectangle(width=100 height=135):" << rectangle[0].perimeterLength() 
		 << endl << "Area of rectangle:"<< rectangle[0].area() << endl;
	

 

	triangle[0].setLength(100);
	cout << endl << endl << "Primeter length of triangle(side length=100):"<< triangle[0].perimeterLength() << endl <<"Area of triangle:"<< triangle[0].area() << endl;


	cout<<"------------"<<endl<<endl;


	




	/*--------------------------------------------------------------*/

	/*overloading << function tests.*/
	
	/*--------------------------------------------------------------*/

	/*
	  For circle.
	  I printed inside circle with << function.
	*/
	ofstream overload;
	overload.open("circle.svg");
			
	circle[0].setRadius(500);
	circle[1].setRadius(1000);
	circle[0].setX(1000);
	circle[0].setY(1000);
	ComposedShape cc(circle[1],circle[0]);
		
	cc.DrawContainerCircle(overload);
	
	overload << circle[0];
	
	overload <<"</svg>";
	overload.close();
	/*--------------------------------------------------------------*/

	/*
	  For rectangle.
	  I printed inside rectangle with << function.
	*/

	ofstream overload1;
	overload1.open("rectangle.svg");
			
	rectangle[0].setWidth(1000);
	rectangle[0].setHeight(1000);
	rectangle[1].setWidth(500);
	rectangle[1].setHeight(500);
	rectangle[1].setX(250);
	rectangle[1].setY(250);
	ComposedShape rr(rectangle[0],rectangle[1]);
		
	rr.DrawContainerRectangle(overload1);
	
	overload1 << rectangle[1];
	
	overload1 <<"</svg>";
	overload1.close();

	/*--------------------------------------------------------------*/
	
	/*
	  For triangle.
	  I printed inside triangle with << function.
	*/

	ofstream overload2;
	overload2.open("triangle.svg");
	triangle[0].setLength(1000.);


	triangle[1].setLength(100.);
	triangle[1].setX11(490.);
	triangle[1].setX12(100.);
	triangle[1].setX21(240.);
	triangle[1].setX22(533.013);
	triangle[1].setX31(740.);
	triangle[1].setX32(533.013);

	ComposedShape TT(triangle[0],triangle[1]);

	TT.DrawContainerTriangle(overload2);

	overload2 << triangle[1];
	overload2 << "</svg>";
	overload2.close();



	cout<<"<< operator overload testing. Please examine the code"<<endl<<endl;

cout<<"------------"<<endl<<endl;




	/*--------------------------------------------------------------*/

		/*++ and -- operators overload tests.*/
	/*--------------------------------------------------------------*/
	cout<<endl<<endl<<"++ AND -- OPERATOR OVERLOAD";
	/*for circle*/


	cout<<endl<<"------------";
	cout<<endl<<"=>Circle"<<endl;
	circle[0].setRadius(500);
	circle[0].setX(1000);
	circle[0].setY(1000);
/*---------------------------------------------------------------------------------------------------------------*/
	/*First it prints the initial value.*/
	cout<<endl<<"Circle x="<<circle[0].getX();
	cout<<endl<<"Circle y="<<circle[0].getY()<<endl;
	
	/*It applies circle++ and circle-- and it prints the returned value.*/
	cout<<endl<<"circle++ return value x:"<<(circle[0]++).getX()<<endl;
	cout<<"After circle++;";
	cout<<endl<<"Circle x="<<circle[0].getX();
	cout<<endl<<"Circle y="<<circle[0].getY();
	
	cout<<endl<<endl<<"circle-- return value x:"<<(circle[0]--).getX()<<endl;
	cout<<"After circle--;";
	cout<<endl<<"Circle x="<<circle[0].getX();
	cout<<endl<<"Circle y="<<circle[0].getY();
/*---------------------------------------------------------------------------------------------------------------*/	
	/*It applies ++circle and --circle and it prints the returned value.*/
	cout<<endl<<endl<<"++circle return value x:"<<(++circle[0]).getX()<<endl;
	cout<<"After ++circle;";
	cout<<endl<<"Circle x="<<circle[0].getX();
	cout<<endl<<"Circle y="<<circle[0].getY()<<endl;

	cout<<endl<<endl<<"--circle return value x:"<<(--circle[0]).getX()<<endl;
	cout<<"After --circle;";
	cout<<endl<<"Circle x="<<circle[0].getX();
	cout<<endl<<"Circle y="<<circle[0].getY()<<endl;

	/*for rectangle*/
	cout<<endl<<endl<<"=>Rectangle"<<endl;
	rectangle[0].setWidth(1000);
	rectangle[0].setHeight(1000);
	rectangle[0].setX(1000);
	rectangle[0].setY(1000);
/*---------------------------------------------------------------------------------------------------------------*/
	/*First it prints the initial value.*/
	cout<<endl<<"Rectangle x="<<rectangle[0].getX();
	cout<<endl<<"Rectangle y="<<rectangle[0].getY()<<endl;
	
	/*It applies rectangle++ and rectangle-- and it prints the returned value.*/
	cout<<endl<<"Rectangle++ return value x:"<<(rectangle[0]++).getX()<<endl;
	cout<<"After rectangle++;";
	cout<<endl<<"Rectangle x="<<rectangle[0].getX();
	cout<<endl<<"Rectangle y="<<rectangle[0].getY();
	
	cout<<endl<<endl<<"Rectangle-- return value x:"<<(rectangle[0]--).getX()<<endl;
	cout<<"After rectangle--;";
	cout<<endl<<"Rectangle x="<<rectangle[0].getX();
	cout<<endl<<"Rectangle y="<<rectangle[0].getY();
/*---------------------------------------------------------------------------------------------------------------*/	
	/*It applies ++rectangle and --rectangle and it prints the returned value.*/
	cout<<endl<<endl<<"++rectangle return value x:"<<(++rectangle[0]).getX()<<endl;
	cout<<"After ++rectangle;";
	cout<<endl<<"Rectangle x="<<rectangle[0].getX();
	cout<<endl<<"Rectangle y="<<rectangle[0].getY()<<endl;
	
	cout<<endl<<"--rectangle return value x:"<<(--rectangle[0]).getX()<<endl;
	cout<<"After --rectangle;";
	cout<<endl<<"Rectangle x="<<rectangle[0].getX();
	cout<<endl<<"Rectangle y="<<rectangle[0].getY()<<endl;
	
	/*for triangle*/
	cout<<endl<<endl<<"=>Triangle"<<endl;
	triangle[0].setLength(1000);
	triangle[0].setX11(10);
	triangle[0].setX12(10);
	triangle[0].setX21(10);
	triangle[0].setX22(10);
	triangle[0].setX31(10);
	triangle[0].setX32(10);
	/*First it prints the initial value.*/
	cout<<endl<<"Triangle X11="<<triangle[0].getX11();
	cout<<endl<<"Triangle X12="<<triangle[0].getX12();
	cout<<endl<<"Triangle X21="<<triangle[0].getX21();
	cout<<endl<<"Triangle X22="<<triangle[0].getX22();
	cout<<endl<<"Triangle X31="<<triangle[0].getX31();
	cout<<endl<<"Triangle X32="<<triangle[0].getX32();
/*---------------------------------------------------------------------------------------------------------------*/	
	/*It applies ++triangle and --triangle and it prints the returned value.*/
	cout<<endl<<endl<<"Triangle++ return value X11:"<<(triangle[0]++).getX11()<<endl;
	cout<<"After triangle++;";
	cout<<endl<<"Triangle x11="<<triangle[0].getX11();
	cout<<endl<<"Triangle x12="<<triangle[0].getX12();
	cout<<endl<<"Triangle x21="<<triangle[0].getX21();
	cout<<endl<<"Triangle x22="<<triangle[0].getX22();
	cout<<endl<<"Triangle x31="<<triangle[0].getX31();
	cout<<endl<<"Triangle x32="<<triangle[0].getX32();

	cout<<endl<<endl<<"Triangle-- return value X11:"<<(triangle[0]--).getX11()<<endl;
	cout<<"After triangle--;";
	cout<<endl<<"Triangle x11="<<triangle[0].getX11();
	cout<<endl<<"Triangle x12="<<triangle[0].getX12();
	cout<<endl<<"Triangle x21="<<triangle[0].getX21();
	cout<<endl<<"Triangle x22="<<triangle[0].getX22();
	cout<<endl<<"Triangle x31="<<triangle[0].getX31();
	cout<<endl<<"Triangle x32="<<triangle[0].getX32();
/*---------------------------------------------------------------------------------------------------------------*/
	/*It applies ++triangle and --triangle and it prints the returned value.*/
	cout<<endl<<endl<<"--triangle return value X11:"<<(--triangle[0]).getX11()<<endl;
	cout<<"After --rectangle;";
	cout<<endl<<"Triangle x11="<<triangle[0].getX11();
	cout<<endl<<"Triangle x12="<<triangle[0].getX12();
	cout<<endl<<"Triangle x21="<<triangle[0].getX21();
	cout<<endl<<"Triangle x22="<<triangle[0].getX22();
	cout<<endl<<"Triangle x31="<<triangle[0].getX31();
	cout<<endl<<"Triangle x32="<<triangle[0].getX32()<<endl;

	cout<<"------------"<<endl<<endl;
/*---------------------------------------------------------------------------------------------------------------*/	







/*********************************************************************************************************************/
	/*+ and - operator overload tests*/
/*********************************************************************************************************************/

	cout<<endl<<endl;
	cout<<"Overloaded + and - operator tests"<<endl<<endl<<endl;

	/*circle*/

	/*Fist it prints the initial value of circle.*/
	circle[0].setRadius(8);
	
	cout<<"Initial value of circle="<<circle[0].getRadius();
	cout<<endl<<"After 'circle_other=circle+7';"<<endl;
	circle[1]=circle[0]+7.;
	cout<<"Incremented value of circle="<<circle[1].getRadius()<<endl<<endl;

	cout<<"Initial value of circle="<<circle[0].getRadius();
	cout<<endl<<"After 'circle_other=circle-7';"<<endl;
	circle[1]=circle[0]-7.;
	cout<<"Incremented value of circle="<<circle[1].getRadius()<<endl<<endl;

	/*rectangle*/
	rectangle[0].setWidth(100);
	rectangle[0].setHeight(40);
	cout<<"Initial value of rectangle width="<<rectangle[0].getWidth()<<endl;
	cout<<"Initial value of rectangle height="<<rectangle[0].getHeight()<<endl;
	cout<<"After rectangle_other = rectangle+3;"<<endl;
	rectangle[1]=rectangle[0]+3.;
	cout<<"rectangle_other rectangle width="<<rectangle[1].getWidth()<<endl;
	cout<<"rectangle_other rectangle height="<<rectangle[1].getHeight()<<endl<<endl;
	cout<<"After rectangle_other = rectangle-3;"<<endl;

	cout<<"Initial value of rectangle width="<<rectangle[0].getWidth()<<endl;
	cout<<"Initial value of rectangle height="<<rectangle[0].getHeight()<<endl;

	rectangle[1]=rectangle[0]-3.;
	cout<<"rectangle_other rectangle width="<<rectangle[1].getWidth()<<endl;
	cout<<"rectangle_other rectangle height="<<rectangle[1].getHeight()<<endl<<endl;
	
	/*triangle*/

	triangle[0].setLength(100);
	cout<<"Initial value of triangle length="<<triangle[0].getLength()<<endl;
	cout<<"After triangle_other=triangle+10"<<endl;
	triangle[1]=triangle[0]+10.;
	cout<<"Incremented value of new triangle length="<<triangle[1].getLength()<<endl<<endl;
	
	cout<<"Initial value of triangle length="<<triangle[0].getLength()<<endl;
	cout<<"After triangle_other=triangle-10"<<endl;
	triangle[1]=triangle[0]-10.;
	cout<<"Incremented value of new triangle length="<<triangle[1].getLength()<<endl<<endl;


	cout<<"------------"<<endl<<endl;


















/*---------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------*/
	/* >= <= != == > < opereators overload tests*/
	/*First it sets prints and after that it controls the operators and prints its result.*/
	
	/*Circle*/
	cout<<"-----Circle-----"<<endl;
	circle[0].setRadius(500);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<"circle[0].area = 500  circle[1].area = 500"<<endl<<"circle[0] == circle [1]";

	if(( circle[0] == circle[1] ))		/*It controls the operations works or not*/
		cout<<endl<<"Circles are equal";

	cout<<endl;

	circle[0].setRadius(400);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<endl<<"circle[0].area = 400  circle[1].area = 500"<<endl<<"circle[0] != circle [1]";

	if(( circle[0] != circle[1] ))	/*It controls the operations works or not*/
		cout<<endl<<"Circles are not equal"<<endl;
	
	circle[0].setRadius(400);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<endl<<"circle[0].area = 400  circle[1].area = 500"<<endl<<"circle[0] <= circle [1]";

	if(( circle[0] <= circle[1] ))	/*It controls the operations works or not*/
		cout<<endl<<"Circle[0] is smaller than circle[1]."<<endl;

	cout<<endl;

	circle[0].setRadius(500);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<"circle[0].area = 500  circle[1].area = 500"<<endl<<"circle[0] <= circle [1]";

	if(( circle[0] <= circle[1] ))	/*It controls the operations works or not*/
		cout<<endl<<"Circles are equal"<<endl;

	cout<<endl;

	circle[0].setRadius(600);	/*It sets the values*/	
	circle[1].setRadius(500);
	cout<<"circle[0].area = 600  circle[1].area = 500"<<endl<<"circle[0] >= circle [1]";

	if(( circle[0] >= circle[1] ))	/*It controls the operations works or not*/
		cout<<endl<<"Circle[0] is bigger than circle[1]."<<endl;

	cout<<endl;

	circle[0].setRadius(500);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<"circle[0].area = 500  circle[1].area = 500"<<endl<<"circle[0] >= circle[1]";

	if(( circle[0] >= circle[1] ))
		cout<<endl<<"Circles are equal"<<endl;

	cout<<endl;

	circle[0].setRadius(700);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<"circle[0].area = 700  circle[1].area = 500"<<endl<<"circle[0] > circle[1]";

	if(( circle[0] > circle[1] ))	/*It controls the operations works or not*/
		cout<<endl<<"Circle[0] is bigger than circle[1]."<<endl;

	cout<<endl;
	
	cout<<endl;

	circle[0].setRadius(200);	/*It sets the values*/
	circle[1].setRadius(500);
	cout<<"circle[0].area = 200  circle[1].area = 500"<<endl<<"circle[0] < circle[1]";

	if(( circle[0] < circle[1] ))
		cout<<endl<<"Circle[0] is smaller than circle[1]."<<endl;

	cout<<endl;
/*---------------------------------------------------------------------------------------------------------------*/
	cout<<"-----Rectangle-----"<<endl;
	cout<<endl;
	rectangle[0].setWidth(100);	/*It sets the values*/
	rectangle[0].setHeight(100);
		
	rectangle[1].setWidth(100);	/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 100  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 100  rectangle[1].height=100";
	cout<<endl<<"recangle[0] == rectangle[1]";
	if(rectangle[0] == rectangle [1])
		cout<<endl<<"Rectangles are equal.";
	
	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(200);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(100);		/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 200  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 100  rectangle[1].height=100";
	cout<<endl<<"recangle[0] != rectangle[1]";
	if(rectangle[0] != rectangle [1])	/*It controls the operations works or not*/
		cout<<endl<<"Rectangles are not equal.";

	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(50);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(200);
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 50  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 200  rectangle[1].height=100";
	cout<<endl<<"recangle[0] <= rectangle[1]";
	if(rectangle[0] <= rectangle [1])
		cout<<endl<<"Rectangles[0] is smaller than rectangle[1].";

	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(100);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(100);		/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 100  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 100  rectangle[1].height=100";
	cout<<endl<<"recangle[0] <= rectangle[1]";
	if(rectangle[0] <= rectangle [1])
		cout<<endl<<"Rectangles are equals.";

	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(200);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(50);		/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 200  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 50  rectangle[1].height=100";
	cout<<endl<<"recangle[0] >= rectangle[1]";
	if(rectangle[0] >= rectangle [1])
		cout<<endl<<"Rectangles[0] is bigger than rectangle[1].";

	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(100);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(100);		/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 100  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 100  rectangle[1].height=100";
	cout<<endl<<"recangle[0] >= rectangle[1]";
	if(rectangle[0] >= rectangle [1])
		cout<<endl<<"Rectangles are equals.";
	

	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(50);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(100);		/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 50  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 100  rectangle[1].height=100";
	cout<<endl<<"recangle[0] < rectangle[1]";
	if(rectangle[0] < rectangle [1])
		cout<<endl<<"Rectangle[0] is smaller than rectangle[1].";
	

	cout<<endl;
	cout<<endl;

	rectangle[0].setWidth(100);		/*It sets the values*/
	rectangle[0].setHeight(100);
	
	rectangle[1].setWidth(50);		/*It sets the values*/
	rectangle[1].setHeight(100);

	cout<<"rectangle[0].width = 100  rectangle[0].height=100"<<endl;
	cout<<"rectangle[1].width = 50  rectangle[1].height=100";
	cout<<endl<<"recangle[0] > rectangle[1]";
	if(rectangle[0] > rectangle [1])
		cout<<endl<<"Rectangle[0] is bigger than rectangle[1].";
	

	cout<<endl;
	cout<<endl;
/*---------------------------------------------------------------------------------------------------------------*/
	cout<<"-----Triangle-----"<<endl;

	cout<<endl;
	triangle[0].setLength(100);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 100"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] == triangle[1]";
	if(triangle[0] == triangle[1])
		cout<<endl<<"Triangles are equal.";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(200);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 200"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] != triangle[1]";
	if(triangle[0] != triangle[1])
		cout<<endl<<"Triangles are not equal.";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(50);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 50"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] <= triangle[1]";
	if(triangle[0] <= triangle[1])
		cout<<endl<<"triangle[0] is smaller than triangle[1].";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(100);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 100"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] <= triangle[1]";
	if(triangle[0] <= triangle[1])
		cout<<endl<<"Triangles are equal.";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(200);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 200"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] >= triangle[1]";
	if(triangle[0] >= triangle[1])
		cout<<endl<<"triangle[0] is bigger than triangle[1].";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(100);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 100"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] >= triangle[1]";
	if(triangle[0] >= triangle[1])
		cout<<endl<<"Triangles are equal.";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(300);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 300"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] > triangle[1]";
	if(triangle[0] > triangle[1])
		cout<<endl<<"triangle[0] is bigger than triangle[1].";

	cout<<endl;
	cout<<endl;

	triangle[0].setLength(50);		/*It sets the values*/
	triangle[1].setLength(100);

	cout<<"triangle[0].length = 50"<<endl;
	cout<<"triangle[1].length = 100"<<endl;
	cout<<"triangle[0] < triangle[1]";
	if(triangle[0] < triangle[1])
		cout<<endl<<"triangle[0] is smaller than triangle[1].";

	cout<<endl;
	cout<<endl;
















/*---------------------------------------------------------------------------------------------------------------*/	
		/*ShapeElem class works test.*/
/*---------------------------------------------------------------------------------------------------------------*/	

	
	cout<<"----------------------------------"<<endl<<endl;
	
	cout<<"ShapeElem class testing.Please examine the code."<<endl<<endl;
	
	Circle circle_(100);
	circle_.setX(1000);
	circle_.setY(1000);

	Rectangle rectangle_(40);
	
	ComposedShape cr(circle_,rectangle_);
	
	ComposedShape::ShapeElem c(circle_,Shapes::Circle);
	
	if(c.getShapeEnum() == Shapes::Circle)
		cout<<"ShapeElem class is works!!"<<endl;
		













/*----------------------------------------------------------*/
	/* << operator overload test for ShapeElem class */
/*----------------------------------------------------------*/
	cout<<"----------------------------------"<<endl<<endl;
	cout<<"<< operator overload testing please examine the code."<<endl<<endl;
	ofstream shapeElemm;

	shapeElemm.open("ShapeElemTest.svg");

	Circle circle_cont(1000);



	ComposedShape elem(circle_cont,circle_);
		
	elem.DrawContainerCircle(shapeElemm);
	shapeElemm<<c;	
	shapeElemm<<"</svg>";
	shapeElemm.close();
	
	cout<<endl;
	cout<<endl;
	cout<<"----------------------------------"<<endl;















/*----------------------------------------------------------*/
/*ShapeElem class area and perimeterLength return functions tests.*/
/*----------------------------------------------------------*/
	cout<<"ShapeElem area and premeter length function tests"<<endl;
	cout<<"Circle radius="<< circle_.getRadius()<<endl;
	cout<<"Perimeter Length="<<c.perimeterLength()<<endl;
	cout<<"Area="<<c.area()<<endl;
	cout<<"----------------------------------";
	
	cout<<endl;
	cout<<endl;


















/*----------------------------------------------------------*/
/*ComposedShape += and [] operators overload tests.*/
/*----------------------------------------------------------*/
	Circle circ(120);
	Circle circ_(1000);
	ComposedShape shp(circ_,circ);
	
	ComposedShape::ShapeElem element(circ,Shapes::Circle);
	
	shp+=element;

/*
	In below line it follow this road and prints the radius;

	ComposedShape =>ShapeElem vector element => ShapeElem => void* => getRadius() 
		
	I used static cast for convert 'void pointer' to 'circle class pointer'.
*/
	cout<<"After ComposedShape+=ShapeElem opetarion;"<<endl;
	/*Without [] overload operations.*/
	cout<<"Radius="<< (* ( static_cast<Circle*>(shp.getShapeElemVector(0).getShapePtr()) )).getRadius()<<endl; 

	/*With [] overload operations.*/
	cout<<"Radius="<< (* ( static_cast<Circle*>(shp[0].getShapePtr()) )).getRadius()<<endl;	

	cout<<"----------------------------------";
	
	cout<<endl;
	cout<<endl;




/**********************************************PART 2****************************************************************/


	/*
		This menu calculates and prints all the small and big shapes inside the svg files.
		In here i test <<(for ComposedShape) overloads.
		Inside <<(for ComposedShape) overload there are [] and <<(ShapeElem.) overloads using.
		I also test [] and <<(ShapeElem.) overloads to above side.
	*/

	cout<<endl<<endl<<endl<<"Dou you want to creates svg files with inner and container shapes?"<<endl;
	cout<<endl<<"If you want to create svg file, for reaching the menu enter '0'.";
	cout<<endl<<"If you want to exit, enter '1'.";
	cout<<endl<<endl<<"Choice:";
	cin>>condition;

	if(condition!=0 && condition != 1){
		cout<<"Invalid Input"<<endl<<endl;
	}
	while(condition==0){
		cout<<"Please select the combination;"<<endl<<endl;
		cout<<"1.Rectangle inside rectangle."<<endl;
		cout<<"2.Rectangle inside circle."<<endl;
		cout<<"3.Rectangle inside triangle."<<endl;
		cout<<"4.Circle inside rectangle."<<endl;
		cout<<"5.Circle inside circle."<<endl;
		cout<<"6.Circle inside triangle."<<endl;
		cout<<"7.Triangle inside rectangle"<<endl;
		cout<<"8.Triangle inside circle"<<endl;
		cout<<"9.Triangle inside triangle"<<endl;
		cout<<"0.Exit"<<endl<<endl;

		cout<<"Choice=";
		cin>>choice;

			if(choice == 0)
				condition++;
			/*
			  Test Rectangle inside Rectangle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 1){

				inputStream.open("output1.svg");	
				rectangle[0].setWidth(1000);
				cout<<endl<<endl<<"Container rectangle width:"<<rectangle[0].getWidth();
				rectangle[0].setHeight(1000);
				cout<<endl<<"Container rectangle height:"<<rectangle[0].getHeight();
				rectangle[0].setX(0);
				cout<<endl<<"Container rectangle X coordinate:"<<rectangle[0].getX();
				rectangle[0].setY(0);
				cout<<endl<<"Container rectangle Y coordinate:"<<rectangle[0].getY();

				rectangle[1].setWidth(135);
				cout<<endl<<endl<<"Small rectangle width:"<<rectangle[1].getWidth();
				rectangle[1].setHeight(217);
				cout<<endl<<"Small rectangle height:"<<rectangle[1].getHeight();
				rectangle[1].setX(0);
				cout<<endl<<"Small rectangle X coordinate:"<<rectangle[1].getX();
				rectangle[1].setY(0);
				cout<<endl<<"Small rectangle Y coordinate:"<<rectangle[1].getY()<<endl;

				
				ComposedShape RR(rectangle[0],rectangle[1]);
				RR.optimalFit(rectangle[0],rectangle[1]);
				
				inputStream << RR;
			
				inputStream << "</svg>";
				inputStream.close();

			}
			/*
			  Test Rectangle inside circle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 2){
				inputStream.open("output2.svg");
	
				rectangle[0].setWidth(1000);
				cout<<endl<<endl<<"Container rectangle width:"<<rectangle[0].getWidth();
				rectangle[0].setHeight(1000);
				cout<<endl<<"Container rectangle height:"<<rectangle[0].getHeight();
				rectangle[0].setX(0);
				cout<<endl<<"Container rectangle X coordinate:"<<rectangle[0].getX();
				rectangle[0].setY(0);
				cout<<endl<<"Container rectangle Y coordinate:"<<rectangle[0].getY();

			
				circle[1].setRadius(100);
				cout<<endl<<endl<<"Small circle radius:"<<circle[1].getRadius();
				circle[1].setX(0);
				cout<<endl<<endl<<"Small circle X coordinate:"<<circle[1].getX();
				circle[1].setY(0);
				cout<<endl<<endl<<"Small circle Y coordinate:"<<circle[1].getY()<<endl;
		
				ComposedShape RC(rectangle[0],circle[1]);
				RC.optimalFit(rectangle[0],circle[1]);
			
				inputStream<<RC;
			
				inputStream << "</svg>";
				inputStream.close();


			}
			/*
			  Test Rectangle inside Triangle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 3){
				inputStream.open("output3.svg");	

				rectangle[0].setWidth(1000);
				cout<<endl<<endl<<"Container rectangle width:"<<rectangle[0].getWidth();
				rectangle[0].setHeight(1000);
				cout<<endl<<"Container rectangle height:"<<rectangle[0].getHeight();
				rectangle[0].setX(0);
				cout<<endl<<"Container rectangle X coordinate:"<<rectangle[0].getX();
				rectangle[0].setY(0);
				cout<<endl<<"Container rectangle Y coordinate:"<<rectangle[0].getY();

				triangle[1].setLength(100);
				cout<<endl<<endl<<"Small triangle length:"<<triangle[1].getLength()<<endl;
				triangle[1].setX11(0);
				triangle[1].setX12(0);
				triangle[1].setX21(0);
				triangle[1].setX22(0);
				triangle[1].setX31(0);
				triangle[1].setX32(0);
		
				cout<<"Triangle X11:"<< triangle[1].getX11()<<" X12:"
				<< triangle[1].getX12() <<" X21:"<<triangle[1].getX21() <<" X22:"
				<< triangle[1].getX22() <<" X31:"<< triangle[1].getX31() <<" X32:"
				<< triangle[1].getX32() << endl << endl;

				ComposedShape RT(rectangle[0],triangle[1]);
				RT.optimalFit(rectangle[0],triangle[1]);

				inputStream<<RT;
			
				inputStream << "</svg>";
				inputStream.close();
			}
			/*
			  Test Circle inside rectangle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 4){
				inputStream.open("output4.svg");
			
				circle[0].setRadius(1000);
				cout<<endl<<endl<<"Container circle radius:"<<circle[0].getRadius();
				circle[0].setX(0);
				cout<<endl<<"Container circle X coordinate:"<<circle[0].getX();
				circle[0].setY(0);
				cout<<endl<<"Container circle Y coordinate:"<<circle[0].getY();


				rectangle[2].setWidth(100);
				cout<<endl<<endl<<"Small rectangle width:"<<rectangle[2].getWidth();
				rectangle[2].setHeight(200);
				cout<<endl<<"Small rectangle height:"<<rectangle[2].getHeight();
				rectangle[2].setX(0);
				cout<<endl<<"Small rectangle X coordinate:"<<rectangle[2].getX();
				rectangle[2].setY(0);
				cout<<endl<<"Small rectangle Y coordinate:"<<rectangle[2].getY()<<endl<<endl;

				ComposedShape CR(circle[0],rectangle[2]);
				CR.optimalFit(circle[0],rectangle[2]);
			
				inputStream <<CR;
			
				inputStream << "</svg>";
				inputStream.close();

			}
			/*
			  Test Circle inside Circle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 5){
				inputStream.open("output5.svg");
			
				circle[0].setRadius(1000);
				cout<<endl<<endl<<"Container circle radius:"<<circle[0].getRadius();
				circle[0].setX(0);
				cout<<endl<<"Container circle X coordinate:"<<circle[0].getX();
				circle[0].setY(0);
				cout<<endl<<"Container circle Y coordinate:"<<circle[0].getY();

				circle[2].setRadius(100);
				cout<<endl<<endl<<"Small circle radius:"<<circle[2].getRadius();
				circle[2].setX(0);
				cout<<endl<<"Small circle X coordinate:"<<circle[2].getX();
				circle[2].setY(0);
				cout<<endl<<"Small circle Y coordinate:"<<circle[2].getY()<<endl<<endl;
				
				ComposedShape CC(circle[0],circle[2]);
				CC.optimalFit(circle[0],circle[2]);
			
				inputStream<<CC;
			
				inputStream << "</svg>";
				inputStream.close();
			
			}
			/*
			  Test Circle inside Triangle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 6){
				inputStream.open("output6.svg");
			
				circle[0].setRadius(1000);
				cout<<endl<<endl<<"Container circle radius:"<<circle[0].getRadius();
				circle[0].setX(0);
				cout<<endl<<"Container circle X coordinate:"<<circle[0].getX();
				circle[0].setY(0);
				cout<<endl<<"Container circle Y coordinate:"<<circle[0].getY();

				triangle[2].setLength(100);
				cout<<endl<<endl<<"Small triangle length:"<<triangle[2].getLength()<<endl;
				triangle[2].setX11(0);
				triangle[2].setX12(0);
				triangle[2].setX21(0);
				triangle[2].setX22(0);
				triangle[2].setX31(0);
				triangle[2].setX32(0);
		
				cout<<"Triangle X11:"<< triangle[2].getX11()<<" X12:"
				<< triangle[2].getX12() <<" X21:"<<triangle[2].getX21() <<" X22:"
				<< triangle[2].getX22() <<" X31:"<< triangle[2].getX31() <<" X32:"
				<< triangle[2].getX32() << endl << endl;

				ComposedShape CT(circle[0],triangle[2]);
				CT.optimalFit(circle[0],triangle[2]);
			
				inputStream<<CT;
			
				inputStream << "</svg>";
				inputStream.close();
			}
			/*
			  Test Triangle inside Rectangle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 7){
				inputStream.open("output7.svg");
	
				triangle[0].setLength(1000);
				cout<<endl<<endl<<"Container triangle length:"<<triangle[0].getLength()<<endl;
				triangle[0].setX11(0);
				triangle[0].setX12(0);
				triangle[0].setX21(0);
				triangle[0].setX22(0);
				triangle[0].setX31(0);
				triangle[0].setX32(0);
		
				cout<<"Triangle X11:"<< triangle[0].getX11()<<" X12:"
				<< triangle[0].getX12() <<" X21:"<<triangle[0].getX21() <<" X22:"
				<< triangle[0].getX22() <<" X31:"<< triangle[0].getX31() <<" X32:"
				<< triangle[0].getX32() << endl << endl;
		
				rectangle[3].setWidth(100);
				cout<<endl<<endl<<"Small rectangle width:"<<rectangle[3].getWidth();
				rectangle[3].setHeight(200);
				cout<<endl<<"Small rectangle height:"<<rectangle[3].getHeight();
				rectangle[3].setX(0);
				cout<<endl<<"Small rectangle X coordinate:"<<rectangle[3].getX();
				rectangle[3].setY(0);
				cout<<endl<<"Small rectangle Y coordinate:"<<rectangle[3].getY()<<endl<<endl;

				ComposedShape TR(triangle[0],rectangle[3]);
				TR.optimalFit(triangle[0],rectangle[3]);
			
				inputStream<<TR;
			
				inputStream << "</svg>";
				inputStream.close();
			}
			/*
			  Test Triangle inside circle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 8){
				inputStream.open("output8.svg");

				triangle[0].setLength(1000);
				cout<<endl<<endl<<"Container triangle length:"<<triangle[0].getLength()<<endl;
				triangle[0].setX11(0);
				triangle[0].setX12(0);
				triangle[0].setX21(0);
				triangle[0].setX22(0);
				triangle[0].setX31(0);
				triangle[0].setX32(0);
		
				cout<<"Triangle X11:"<< triangle[0].getX11()<<" X12:"
				<< triangle[0].getX12() <<" X21:"<<triangle[0].getX21() <<" X22:"
				<< triangle[0].getX22() <<" X31:"<< triangle[0].getX31() <<" X32:"
				<< triangle[0].getX32() << endl << endl;

				circle[3].setRadius(100);
				cout<<endl<<endl<<"Small circle radius:"<<circle[3].getRadius();
				circle[3].setX(0);
				cout<<endl<<"Small circle X coordinate:"<<circle[3].getX();
				circle[3].setY(0);
				cout<<endl<<"Small circle Y coordinate:"<<circle[3].getY()<<endl<<endl;
				
				ComposedShape TC(triangle[0],circle[3]);
				TC.optimalFit(triangle[0],circle[3]);

				inputStream<<TC;
			
				inputStream << "</svg>";
				inputStream.close();
			

			
			}
			/*
			  Test Triangle inside triangle.
			  It sets values and prints on the screen and after that it creates ComposedShape.
			  After that it fills ShapeElem vector with OptimalFit function.
			  After that it prints the shapes to the svg files with '<<' overloaded operator.
			*/
			else if(choice == 9){

				inputStream.open("output9.svg");

				triangle[0].setLength(1000);
				cout<<endl<<endl<<"Container triangle length:"<<triangle[0].getLength()<<endl;
				triangle[0].setX11(0);
				triangle[0].setX12(0);
				triangle[0].setX21(0);
				triangle[0].setX22(0);
				triangle[0].setX31(0);
				triangle[0].setX32(0);
		
				cout<<"Triangle X11:"<< triangle[0].getX11()<<" X12:"
				<< triangle[0].getX12() <<" X21:"<<triangle[0].getX21() <<" X22:"
				<< triangle[0].getX22() <<" X31:"<< triangle[0].getX31() <<" X32:"
				<< triangle[0].getX32() << endl << endl;

				triangle[3].setLength(100);
				cout<<endl<<endl<<"Small triangle length:"<<triangle[3].getLength()<<endl;
				triangle[3].setX11(0);
				triangle[3].setX12(0);
				triangle[3].setX21(0);
				triangle[3].setX22(0);
				triangle[3].setX31(0);
				triangle[3].setX32(0);
		
				cout<<"Triangle X11:"<< triangle[1].getX11()<<" X12:"
				<< triangle[3].getX12() <<" X21:"<<triangle[3].getX21() <<" X22:"
				<< triangle[3].getX22() <<" X31:"<< triangle[3].getX31() <<" X32:"
				<< triangle[3].getX32() << endl << endl;

				ComposedShape TT(triangle[0],triangle[3]);
				TT.optimalFit(triangle[0],triangle[3]); 
			
				inputStream<<TT;
			
				inputStream << "</svg>";
				inputStream.close();
			}
			else
				cout<<endl<<"Invalid input, Please try again"<<endl;
		}

	return 0;
}
