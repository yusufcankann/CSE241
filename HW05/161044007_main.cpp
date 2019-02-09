#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "PolygonVect.h"
#include "PolygonDyn.h"
#include <fstream>
using namespace std;
using namespace MyShape;
/*Global << function is inside the end of the Shape.cpp file.*/
/*Other global function inside this file. At the top.*/


/*It prints all the vector inside the svg file.*/
void printAll(vector <Shape*> vec)throw (){
	ofstream stream;
	stream.open("printAll.svg");
	stream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<2000<<"\" height=\""<<2000<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	for(auto x:vec)
		(x)->draw(stream);

	stream<<"</svg>";
	stream.close();

}





/*
	This function prints only polygons.
*/
/*					
					!!!IMPORTANT NOTE!!!
	Because of the polygon code colors it may seems doesn't print the file.
		Please examine the 'svg' file codes!.
*/
void printPoly(vector <Shape*> vec) throw(std::exception){
	try{
		ofstream stream;
		stream.open("printPoly.svg");

		stream << "<svg version=\"1.1\" " << endl
					<<" baseProfile=\"full\" " << endl
					<< " width=\""<<2000<<"\" height=\""<<2000<<"\" " << endl
					<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;
		int size = vec.size();
		/*This part it uses downcasting.*/
		for(int i=0;i<size;i++){
			PolygonDyn *ptr;
			PolygonVect *ptr2;
			ptr = dynamic_cast<PolygonDyn*> (vec[i]);
			if(ptr != nullptr)
				stream<<(*ptr);	
			ptr2 = dynamic_cast<PolygonVect*> (vec[i]);
			if(ptr2 != nullptr)
				stream<<(*ptr2);	
		}
		stream<<"</svg>";
		stream.close();
	}
	catch(exception &bc){
		cout<<endl<<"There is something wrong casting..."<<endl;
	}
}
	
/*
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	  If you use convertAll() fuction, after using  you have to delete all adress inside the returned vector.
	  In addition if one of the pointers is composedshape you have to delete all inner shapes adresses.
		
	Example delete code =>>>>>

-----------------------------------------------
		for(auto x:convertAllTestOutput){
		ComposedShape *ptr;
		ptr=dynamic_cast<ComposedShape*>(x);
		if(ptr != nullptr){
			delete (ptr->getContainer());
			delete (ptr->getInner());
			int size = ptr->getVectorSize();
			for(int k=0;k<size;k++){
				delete (&ptr[k]);
			}
		}
		else
			delete x;	
		}	
-------------------------------------------------
*/
vector <Shape*> convertAll(vector <Shape*> shapes)throw (std::exception){
	
		vector <Shape*> temp;
		int size=shapes.size();
		Triangle *ptr1;
		Rectangle *ptr2;
		Circle *ptr3;
		ComposedShape *ptr4;
	try{
		for(int i=0;i<size;i++){
			/*First it uses upcasting.*/
			
			ptr1=dynamic_cast<Triangle*> (shapes[i]);
			ptr2=dynamic_cast<Rectangle*> (shapes[i]);
			ptr3=dynamic_cast<Circle*> (shapes[i]);
			ptr4=dynamic_cast<ComposedShape*>(shapes[i]);
			if(ptr1 != nullptr || ptr2 != nullptr || ptr3!= nullptr){
				PolygonVect *add = new PolygonVect(*(shapes[i]));
				temp.push_back(add);
			}
			/*In this part it convers all the inner shapes inside the composedshape.*/
			else if(ptr4 != nullptr){

				vector<Shape*> composedinner; /*First stores and converts inner shapes.*/
				for(int j=0;j<ptr4->getVectorSize();j++){
					PolygonVect *addcomposedinner = new PolygonVect(ptr4[j]);
					composedinner.push_back(addcomposedinner);
				}
				/*After inner shapes it converts container and inner pointers which are in the private part of composedshape.*/
				PolygonVect *addinner = new PolygonVect( *(ptr4->getInner() ));
				PolygonVect *addcontainer = new PolygonVect( *(ptr4->getContainer() ));
				ComposedShape *cptr=new ComposedShape(composedinner,(*addcontainer),(*addinner));
				
				temp.push_back(cptr);	
			}
		}
	}
	catch(exception &bc){
		cout<<endl<<"There is something wrong casting..."<<endl;
	}
	return temp;
}

/*It sorts all shapes with looking its areas.*/
void sortShapes(vector <Shape*> &shapes)throw(){
	Shape *temp;	
	int size=shapes.size();
	for(int k=0;k<size;k++){
		for(int i=0;i<size-1;i++){
			if( (shapes[i]->area()) > (shapes[i+1]->area()) ){
				temp=shapes[i];
				shapes[i]=shapes[i+1];
				shapes[i+1]=temp;
			}
		}
	}
}

int main(){

	/*-------------------------------------------------------------------------------------------------------------------*/
	/*OVERLOADED ++ AND -- OPERATORS TEST*/
	cout<<"------------ \'++\' AND \'--\' OPERATOR OVERLOAD ------------"<<endl;
	cout<<"-------CIRCLE------";
	cout << endl;
	Circle circle(5);
	circle.setX(5);
	circle.setY(5);
	cout<<"Circle x:"<<circle.getX()<<" Circle y:"<<circle.getY()<<endl;
	++circle;
	cout<<"After ++circle;"<<endl;
	cout<<"Circle x:"<<circle.getX()<<" Circle y:"<<circle.getY()<<endl;
	
	cout<<endl;
	
	cout<<"Circle x:"<<circle.getX()<<"Circle y:"<<circle.getY()<<endl;
	Shape *del=new ComposedShape;
	del=&(circle++);
	delete (del);
	cout<<"After circle++;"<<endl;
	cout<<"Circle x:"<<circle.getX()<<" Circle y:"<<circle.getY()<<endl;
	
	
	cout<<endl;
	cout<<"Circle x:"<<circle.getX()<<"Circle y:"<<circle.getY()<<endl;	
	--circle;
	cout<<"After --circle;"<<endl;
	cout<<"Circle x:"<<circle.getX()<<" Circle y:"<<circle.getY()<<endl;
	
	cout<<endl;
	cout<<"Circle x:"<<circle.getX()<<"Circle y:"<<circle.getY()<<endl;
	del=&(circle--);
	delete (del);
	cout<<"After circle--;"<<endl;
	cout<<"Circle x:"<<circle.getX()<<" Circle y:"<<circle.getY()<<endl;
	cout << "-------------------";
	cout << endl<< endl;

	cout<<"-------RECTANGLE------";
	cout << endl<< endl;
	/*Rectangle ++ and -- tests.*/
	Rectangle rectangle(10,10);
	rectangle.setX(15);
	rectangle.setY(15);
	cout<<"Rectangle x:"<<rectangle.getX()<<" Rectangle y:"<<rectangle.getY()<<endl;
	++rectangle;
	cout<<"After ++rectangle;"<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<" Rectangle y:"<<rectangle.getY()<<endl;
	
	cout<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<"Rectangle y:"<<rectangle.getY()<<endl;
	del=&(rectangle++);
	delete (del);
	cout<<"After rectangle++;"<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<" Rectangle y:"<<rectangle.getY()<<endl;

	cout<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<"Rectangle y:"<<rectangle.getY()<<endl;	
	--rectangle;
	cout<<"After --rectangle;"<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<" Rectangle y:"<<rectangle.getY()<<endl;
	
	cout<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<"Rectangle y:"<<rectangle.getY()<<endl;
	del=&(rectangle--);
	delete del;
	cout<<"After rectangle--;"<<endl;
	cout<<"Rectangle x:"<<rectangle.getX()<<" Rectangle y:"<<rectangle.getY()<<endl;

	
	cout<<"----------------------";
	cout << endl<< endl;
	
	cout<<"-------TRIANGLE-----";
	/*Triangle ++ and -- test.*/
	cout << endl;

	Triangle triangle(20);
	triangle.setX1(20);
	triangle.setY1(20);
	triangle.setX2(20);
	triangle.setY2(20);
	triangle.setX3(20);
	triangle.setY3(20);
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	++triangle;
	cout<<"After ++triangle;"<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	
	cout<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	del=&(triangle++);
	delete (del);
	cout<<"After triangle++;"<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;

	cout<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	--triangle;
	cout<<"After --triangle;"<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	
	cout<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	del=&(triangle--);
	delete del;
	cout<<"After triangle--;"<<endl;
	cout<<"Triangle x1:"<<triangle.getX1()<<" Triangle y1:"<<triangle.getY1()<<endl;
	cout<<"Triangle x2:"<<triangle.getX2()<<" Triangle y2:"<<triangle.getY2()<<endl;
	cout<<"Triangle x3:"<<triangle.getX3()<<" Triangle y3:"<<triangle.getY3()<<endl;
	
	cout<<"----------------------";
	cout << endl<< endl;
	/*-------------------------------------------------------------------------------------------------------------------*/
	cout << endl<< endl;
	cout<<"------------Area and Perimeter function tests------------"<<endl<<endl;
	/*Circle area and perimeter function tests*/	
		cout<<"Circle radius:"<<circle.getRadius()<<endl<<" Circle area:"<<circle.area()
			<<endl<<" Circle perimeter:"<<circle.perimeter()<<endl;
		cout<<"Triangle lenth:"<<triangle.getLength()<<endl<<" Triangle area:"<<triangle.area()
			<<endl<<" Triangle perimeter"<< triangle.perimeter()<<endl;
		cout<<"Rectangle width:"<<rectangle.getWidth()<<endl<<" Rectangle height:"<<rectangle.getHeight()
			<<endl<<" Rectangle area:"<<rectangle.area()<<endl<< " Rectangle perimeter:"<< rectangle.perimeter()<<endl;
	/*-------------------------------------------------------------------------------------------------------------------*/
	cout << endl<< endl;
	
	/*OVERLOADED == != <= >= < > OPERATORS TEST*/
	cout<<"------------OVERLOADED == != <= >= < > OPERATORS TEST------------"<<endl<<endl;
	Triangle t1(10),t2(20),t3(10);
	Circle c1(20),c2(30),c3(20);
	Rectangle r1(10),r2(15),r3(10);	

	cout<<"Triangle1 area:"<< t1.area()<<endl<<"Triangle2 area:"<< t2.area() 	
		<<endl<<"Triangle3 area:"<<t3.area()<<endl<<endl;
	cout<<"Rectangle1 area:"<< r1.area()<<endl<<"Rectangle2 area:"<< r2.area() 
		<<endl<<"Rectangle3 area:"<<r3.area()<<endl<<endl;
	cout<<"Circle1 area:"<< c1.area()<<endl<<"Circle2 area:"<< c2.area() 
		<<endl<<"Circle3 area:"<<c3.area()<<endl<<endl;

	cout<<"After this part please examine the code."<<endl<<endl;

	if(c1>c2)
		cout<<"c1>c2"<<endl;
	if(c1<c2)
		cout<<"c1<c2"<<endl;
	if(c1>c3)
		cout<<"c1>c3"<<endl;
	if(c1<c3)
		cout<<"c1<c3"<<endl;
	if(c1>=c2)
		cout<<"c1>=c2"<<endl;
	if(c1<=c2)
		cout<<"c1<=c2"<<endl;
	if(c1>=c3)
		cout<<"c1>=c3"<<endl;
	if(c1<=c3)
		cout<<"c1<=c3"<<endl;
	if(c1==c3)
		cout<<"c1==c3"<<endl;
	if(c1!=c2)
		cout<<"c1!=c3"<<endl;
	if(c1>r1)
		cout<<"c1>r1"<<endl;
	if(r2<c1)
		cout<<"r2<c1"<<endl;
	if(t1>=t3)
		cout<<"t1>=t3"<<endl;
	if(r1<=r3)
		cout<<"r1<=r3"<<endl;
	if(c1!=c3)
		cout<<"c1!=c3"<<endl;
	if(t3<=c3)
		cout<<"t3<=c3"<<endl;
	
	
	cout<<endl<<endl;

	/*OVERLOADED << OPERATOR TEST*/

	cout<<"----------OVERLOADED << OPERATOR TEST----------"<<endl;
	cout<<"----------CIRCLE----------"<<endl;
	ofstream overload;
	overload.open("circle_test.svg");
	
	circle.setRadius(500);
	circle.setY(500);
	circle.setX(500);

	overload << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<circle.getRadius()*2<<"\" height=\""<<circle.getRadius()*2<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< " <circle cx=\""<<circle.getRadius()<<"\" cy=\""<<circle.getRadius()<<"\" r=\""<<circle.getRadius()
				<<"\" fill=\"red\" /> " << endl;

	
	overload << circle;
	
	overload <<"</svg>";
	overload.close();
	cout<<"Circle << operator tested. It produced 'circle_test.svg' file."<<endl;
	cout<<endl;
	
	cout<<"----------RECTANGLE----------"<<endl;
	overload.open("rectangle_test.svg");
	
	rectangle.setWidth(500);
	rectangle.setHeight(500);
	rectangle.setY(0);
	rectangle.setX(0);

	overload << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<rectangle.getWidth()<<"\" height=\""<<rectangle.getHeight()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;

	
	overload << rectangle;
	
	overload <<"</svg>";
	overload.close();
	cout<<"Rectangle << operator tested. It produced 'rectangle_test.svg' file."<<endl;
	cout<<endl<<endl;
	
	cout<<"----------TRIANGLE----------"<<endl;
	overload.open("triangle_test.svg");
	
	triangle.setLength(1000.);
	triangle.setX1(490.);
	triangle.setY1(100.);
	triangle.setX2(240.);
	triangle.setY2(533.013);
	triangle.setX3(740.);
	triangle.setY3(533.013);

	overload << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<triangle.getLength()<<"\" height=\""<<triangle.getLength()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl 	
			<< " <polygon points=\"" << triangle.getLength()/2 << ",0 0,"<<triangle.getLength()*(sqrt(3)/2)<<" "
			<< triangle.getLength() << "," << triangle.getLength()*(sqrt(3)/2) << "\" fill=\"red\"/> " << endl;

	
	overload << triangle;
	
	overload <<"</svg>";
	overload.close();
	cout<<"Triangle << operator tested. It produced 'rectangle_test.svg' file."<<endl;
	cout<<endl<<endl;
	cout<<endl<<endl;
	cout<<"----------STATIC TOTAL AREA AND TOTAL PERIMETER TEST----------"<<endl;

cout<<"Static functions tests"<<endl;
	cout<<"Total area and Total perimeter Length Static functions tests"<<endl;
	cout<<endl<<"------------"<<endl;
	Triangle triangle1(100);
	
	triangle1.increase_total_area();
	triangle1.increase_perimeter();
	cout<<"Triangle total area="<<Triangle::show_total_area()<<endl;
	cout<<"Triangle total perimeter length="<<Triangle::show_total_perimeter();
	
	cout<<endl;
	cout<<endl;
	
	Circle circle1(100);

	circle1.increase_total_area();
	circle1.increase_perimeter();

	cout<<"Circle total area="<<Circle::show_total_area()<<endl;
	cout<<"Circle total perimeter length="<<Circle::show_total_perimeter();

	cout<<endl<<"------------";

	cout<<endl<<endl;
	cout<<endl<<endl;


	cout<<"----------COMPOSEDSHAPE AREA AND PERİMETER FUNCTİON TESTS----------"<<endl;
	/*area() and perimeter() function tests.*/
	circle.setRadius(10);
	triangle.setLength(10);
	
	ComposedShape composed(circle,triangle);

	composed.optimalFit(circle,triangle);
	cout<<endl<<"(container)Triangle Area:"<<triangle.area();
	cout<<endl<<"(inner)Circle Area:"<<circle.area()<<endl;
	cout<<"Composed Shape area:(it adds all the inner shapes.)"<<composed.area()<<endl<<endl;
	cout<<endl<<"(container)Triangle perimeter:"<<triangle.perimeter();
	cout<<endl<<"(inner)Circle perimeter:"<<circle.perimeter()<<endl;
	cout<<"Composed Shape perimeter:(it adds all the inner shapes.)"<<composed.perimeter()<<endl<<endl;

	cout<<endl<<endl;


	cout<<"---------- COMPOSEDSHAPE ++ AND -- OVERRİDES AND [] OVERLOADS TESTS ----------"<<endl;
	/*++ and -- operators tests for composedshape*/
	cout<<"++ operator increases 1.0 all the shapes positions which inside the vector."<<endl<<endl;
	cout<<"ComposedShape *Shape vector first element X position:"<<(*(static_cast<Circle*>(composed[0]))).getX()<<endl;
	cout<<"ComposedShape *Shape vector first element Y position:"<<(*(static_cast<Circle*>(composed[0]))).getY()<<endl;
	++composed;
	cout<<"After ++composed"<<endl;
	cout<<"ComposedShape *Shape vector first element X position:"<<(*(static_cast<Circle*>(composed[0]))).getX()<<endl;
	cout<<"ComposedShape *Shape vector first element Y position:"<<(*(static_cast<Circle*>(composed[0]))).getY()<<endl;

	cout<<endl<<endl;
	/* You have to delete the returned pointer for postfix ++*/	
	Shape *p1=new ComposedShape;
	p1=&(composed++);
	delete(p1);

	cout<<"After composed++"<<endl;
	cout<<"ComposedShape *Shape vector first element X position:"<<(*(static_cast<Circle*>(composed[0]))).getX()<<endl;
	cout<<"ComposedShape *Shape vector first element Y position:"<<(*(static_cast<Circle*>(composed[0]))).getY()<<endl;

	cout<<endl<<endl;	
	--composed;
	cout<<"After --composed"<<endl;
	cout<<"ComposedShape *Shape vector first element X position:"<<(*(static_cast<Circle*>(composed[0]))).getX()<<endl;
	cout<<"ComposedShape *Shape vector first element Y position:"<<(*(static_cast<Circle*>(composed[0]))).getY()<<endl;
	
	/* You have to delete the returned pointer for postfix --*/
	cout<<endl<<endl;
	composed--;	
	p1=&(composed--);
	delete(p1);

	cout<<"After composed--"<<endl;
	cout<<"ComposedShape *Shape vector first element X position:"<<(*(static_cast<Circle*>(composed[0]))).getX()<<endl;
	cout<<"ComposedShape *Shape vector first element Y position:"<<(*(static_cast<Circle*>(composed[0]))).getY()<<endl<<endl;

	cout<<endl<<endl;
	

	cout<<"---------- DRAW CONTAİNER RECTANGLE-CİRCLE-TRİANGLE FUNCTİON TEST ----------"<<endl;

	rectangle.setWidth(500);
	rectangle.setHeight(500);
	circle.setRadius(200);
	triangle.setLength(500);
	

	ofstream test;
	ComposedShape drawShapeRectangle(rectangle,triangle);
	test.open("draw_rectangle_test.svg");
	drawShapeRectangle.DrawContainerRectangle(test);
	test <<"</svg>";
	test.close();
	cout<<"\'DrawContainerRectangle\' function tested. It produced 'draw_rectangle_test.svg' file."<<endl;

	ComposedShape drawShapeTriangle(triangle,triangle);
	test.open("draw_triangle_test.svg");
	drawShapeTriangle.DrawContainerTriangle(test);
	test <<"</svg>";
	test.close();
	cout<<"\'DrawContainerTriangle\' function tested. It produced 'draw_triangle_test.svg' file."<<endl;

	ComposedShape drawShapeCircle(circle,triangle);
	test.open("draw_circle_test.svg");
	drawShapeCircle.DrawContainerCircle(test);
	test <<"</svg>";
	test.close();
	cout<<"\'DrawContainerCircle\' function tested. It produced 'draw_circle_test.svg' file."<<endl;

	cout<<endl<<endl;

	cout<<"---------- COMPOSEDSHAPE << OPERATOR TEST ----------"<<endl;
	rectangle.setWidth(1000);
	rectangle.setHeight(1000);
	circle.setRadius(50);

	ComposedShape comp(rectangle,circle);
	
	comp.optimalFit(rectangle,circle);

	ofstream test1;
	test1.open("composedshape_test.svg");
	
	test1<<comp;

	test1.close();
	cout<<" << operator tested and it produced \'composedshape_test.svg\'"<<endl;

	cout<<endl<<endl;

	cout<<"---------- COMPOSEDSHAPE-RECTANGLE-CIRCLE-TRIANGLE DRAW FUNCTİON TEST ----------"<<endl;

	
	/*draw() function tests for composedshape - rectangşe - circle - triangle*/

	/*--------------------------------------------------------------------------*/
	test1.open("composedshape_draw_function_test.svg");
	comp.draw(test1);

	test1.close();
	cout<<"composedshape draw function tested and it produced \'composedshape_draw_function_test.svg\'"<<endl;
	/*--------------------------------------------------------------------------*/
	/*--------------------------------------------------------------------------*/
	/*--------------------------------------------------------------------------*/
	rectangle.setWidth(500);
	rectangle.setHeight(500);
	rectangle.setY(0);
	rectangle.setX(0);

	circle.setRadius(500);
	circle.setY(500);
	circle.setX(500);

	triangle.setLength(1000.);
	triangle.setX1(490.);
	triangle.setY1(100.);
	triangle.setX2(240.);
	triangle.setY2(533.013);
	triangle.setX3(740.);
	triangle.setY3(533.013);
	/*--------------------------------------------------------------------------*/
	/*--------------------------------------------------------------------------*/
	/*--------------------------------------------------------------------------*/

	test1.open("rectangle_draw_function_test.svg");
	
	test1 << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<rectangle.getWidth()<<"\" height=\""<<rectangle.getHeight()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;

	rectangle.draw(test1);

	test1<<"</svg>";
	test1.close();
	cout<<"rectangle draw function tested and it produced \'rectangle_draw_function_test.svg\'"<<endl;
	/*--------------------------------------------------------------------------*/
	test1.open("circle_draw_function_test.svg");

	test1 << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<circle.getRadius()*2<<"\" height=\""<<circle.getRadius()*2<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;

	circle.draw(test1);

	test1<<"</svg>";
	test1.close();
	cout<<"circle draw function tested and it produced \'circle_draw_function_test.svg\'"<<endl;
	/*--------------------------------------------------------------------------*/
	test1.open("triangle_draw_function_test.svg");
	
	test1 << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<triangle.getLength()<<"\" height=\""<<triangle.getLength()<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;

	triangle.draw(test1);

	test1<<"</svg>";
	test1.close();
	cout<<"triangle draw function tested and it produced \'triangle_draw_function_test.svg\'"<<endl;

	cout<<endl<<endl;

	cout<<"---------- COMPOSEDSHAPE COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR TEST ----------"<<endl;
	
	rectangle.setWidth(1000);
	rectangle.setHeight(1000);
	circle.setRadius(50);

	ComposedShape a(rectangle,circle);
	a.optimalFit(rectangle,circle);
	
	cout<<endl<<"A.area()="<<a.area()<<endl;
	cout<<"After copied a to b;"<<endl;
	ComposedShape b(a);
	cout<<"B.area()="<<b.area()<<endl;

	cout<<"After assigned a to c;"<<endl;

	ComposedShape c;
	c=a;
	cout<<"C.area()="<<c.area()<<endl;

	cout<<endl<<endl;
	
	cout<<"---------- OVERLOADED OPTIMALFIT FUNCTION TEST ----------"<<endl;
	Rectangle rec1(1000,1000);
	Rectangle rec2(100,100);
	
	Circle cir1(1000);
	Circle cir2(50);
	
	Triangle tri1(1000);
	Triangle tri2(100);

	ofstream test3;

	test3.open("output1.svg");
	ComposedShape composed1(rec1,rec2);
	composed1.optimalFit();
	composed1.draw(test3);
	test3.close();
	cout<<"->optimalFit(r,r) tested and result printed the 'output1.svg' file"<<endl;	

	test3.open("output2.svg");
	ComposedShape composed2(rec1,cir2);
	composed2.optimalFit();
	composed2.draw(test3);
	test3.close();	
	cout<<"->optimalFit(r,c) tested and result printed the 'output2.svg' file"<<endl;	

	test3.open("output3.svg");
	ComposedShape composed3(rec1,tri2);
	composed3.optimalFit();
	composed3.draw(test3);
	test3.close();
	cout<<"->optimalFit(r,t) tested and result printed the 'output3.svg' file"<<endl;	

	test3.open("output4.svg");
	ComposedShape composed4(cir1,rec2);
	composed4.optimalFit();
	composed4.draw(test3);
	test3.close();
	cout<<"->optimalFit(c,r) tested and result printed the 'output4.svg' file"<<endl;	
	
	test3.open("output5.svg");
	ComposedShape composed5(cir1,cir2);
	composed5.optimalFit();
	composed5.draw(test3);
	test3.close();
	cout<<"->optimalFit(c,c) tested and result printed the 'output5.svg' file"<<endl;	

	test3.open("output6.svg");
	ComposedShape composed6(cir1,tri2);
	composed6.optimalFit();
	composed6.draw(test3);
	test3.close();
	cout<<"->optimalFit(c,t) tested and result printed the 'output6.svg' file"<<endl;	

	test3.open("output7.svg");
	ComposedShape composed7(tri1,rec2);
	composed7.optimalFit();
	composed7.draw(test3);
	test3.close();
	cout<<"->optimalFit(t,r) tested and result printed the 'output7.svg' file"<<endl;	

	test3.open("output8.svg");
	ComposedShape composed8(tri1,cir2);
	composed8.optimalFit();
	composed8.draw(test3);
	test3.close();
	cout<<"->optimalFit(t,c) tested and result printed the 'output8.svg' file"<<endl;	

	test3.open("output9.svg");
	ComposedShape composed9(tri1,tri2);
	composed9.optimalFit();
	composed9.draw(test3);
	test3.close();
	cout<<"->optimalFit(t,t) tested and result printed the 'output9.svg' file"<<endl;	
	
	cout<<endl<<endl;




	
	cout<<"---------- OVERLOADED += OPERATOR TEST ----------"<<endl;
	/*+= operators tests*/
	ComposedShape test10(rec1,rec2);

	Triangle triangletest(10);
	test10.optimalFit();
	Triangle *trii=new Triangle;
	(*trii)=triangletest;

	cout<<"ComposedShape size :"<<test10.getVectorSize()<<endl;
	test10+=(trii);
	cout<<"After += :"<<test10.getVectorSize()<<endl<<endl;
	
	
	cout<<endl<<endl;
	cout<<endl<<endl;
	
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------POLYGONVECT CLASS TESTS-------------"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<endl<<endl;


	cout<<"---------------POLYGONVECT CLASS CONSTRUCTERS TEST------------"<<endl;
	
	rec1.setX(0);
	rec1.setY(0);
	
	cir1.setX(1000);
	cir2.setY(1000);
	
	tri1.setLength(1000.);
	tri1.setX1(490.);
	tri1.setY1(100.);
	tri1.setX2(240.);
	tri1.setY2(533.013);
	tri1.setX3(740.);
	tri1.setY3(533.013);

	
	
	
	
	cout<<"PolygonVect() constructor test"<<endl;
	PolygonVect PV0;
	cout<<"-PolygonVect() x parameter:"<<PV0[0].getX()<<endl;
	cout<<"-PolygonVect() y parameter:"<<PV0[0].getY()<<endl;

	cout<<endl;

	cout<<"PolygonVect(rectangle) constructor test"<<endl;
	PolygonVect PV1(rec1);
	cout<<"-PolygonVect(rectangle) x parameter:"<<PV1[3].getX()<<endl;
	cout<<"-PolygonVect(rectangle) y parameter:"<<PV1[3].getY()<<endl;

	cout<<endl;
	
	cout<<"PolygonVect(circle) constructor test"<<endl;
	PolygonVect PV2(cir1);
	cout<<"-PolygonVect(circle) x parameter:"<<PV2[1].getX()<<endl;
	cout<<"-PolygonVect(circle) y parameter:"<<PV2[1].getY()<<endl;
	
	cout<<endl;
	
	cout<<"PolygonVect(triangle) constructor test"<<endl;
	PolygonVect PV3(tri1);
	cout<<"-PolygonVect(triangle) x parameter:"<<PV3[1].getX()<<endl;
	cout<<"-PolygonVect(triangle) y parameter:"<<PV3[1].getY()<<endl;
	
	cout<<endl;

	cout<<"PolygonVect(10,20) constructor test"<<endl;
	PolygonVect PV4(10,20);
	cout<<"-PolygonVect(10,20) x parameter:"<<PV4[0].getX()<<endl;
	cout<<"-PolygonVect(10,20) y parameter:"<<PV4[0].getY()<<endl;
	
	

	cout<<"PolygonVect(15) constructor test"<<endl;
	PolygonVect PV5(15);
	cout<<"-PolygonVect(15) x parameter:"<<PV5[0].getX()<<endl;
	cout<<"-PolygonVect(15) y parameter:"<<PV5[0].getY()<<endl;
	
	cout<<endl;
	
	cout<<"PolygonVect(vector<Point2D*>) constructor test"<<endl;
	cout<<"vector<Point2D*>: It has 10,20."<<endl;
	vector <Polygon::Point2D> vec2D;
	Polygon::Point2D temp2D(10,20);
	vec2D.push_back(temp2D);
	
	PolygonVect PV6(vec2D);
	cout<<"-PolygonVect(vector<Point2D*>) x parameter:"<<PV6[0].getX()<<endl;
	cout<<"-PolygonVect(vector<Point2D*>) y parameter:"<<PV6[0].getY()<<endl;
	
	cout<<endl;

	cout<<"PolygonVect(Shape&) constructor test"<<endl;
	Shape *ptr1;
	ptr1=&tri1;
	PolygonVect PV7(*ptr1);
	cout<<"-PolygonVect(Shape&) x parameter:"<<PV7[1].getX()<<endl;
	cout<<"-PolygonVect(Shape&) y parameter:"<<PV7[1].getY()<<endl;

		
	cout<<endl<<endl;

	
	cout<<"---------------POLYGONVECT << OPERATOR OVERLOAD AND DRAW() FUNCTION TEST------------"<<endl;

	tri1.setLength(300);
	rec1.setWidth(300);
	rec1.setHeight(500);
	cir1.setRadius(100);
	ofstream polygon_v;

	polygon_v.open("draw_polygonvec_test.svg");

	polygon_v << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<900<<"\" height=\""<<900<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	PolygonVect PV8(tri1);
	
	PV8.draw(polygon_v);
	
	polygon_v <<"</svg>";
	polygon_v.close();
	cout<<"->PolygonVec draw() function tested and result printed in the 'draw_polygonvec_test.svg' file"<<endl;	


	polygon_v.open("polygonvec_print_test.svg");
	polygon_v << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1750"<<"\" height=\""<<"1750"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;
	cir1.setRadius(400);
	PolygonVect PV9(cir1);
	
	polygon_v<<PV9;
	
	polygon_v <<"</svg>";
	polygon_v.close();
	cout<<"->PolygonVec '<<' operator tested and result printed in the 'polygonvec_print_test.svg' file"<<endl;	
	
	cout<<endl<<endl;

	
	cout<<"---------------POLYGONVECT AREA() AND PERIMETER FUNCTION TEST------------"<<endl;

	cir1.setRadius(1000);
	rec1.setWidth(30);
	rec1.setHeight(50);


	cout<<"rectangle area():"<<rec1.area()<<endl;
	PolygonVect area_test2(rec1);
	cout<<"After converted PolygonVect area():"<<area_test2.area()<<endl;
	cout<<endl;
	cout<<"circle perimeter():"<<cir1.perimeter()<<endl;
	PolygonVect area_test3(cir1);
	cout<<"After converted PolygonVect perimeter():"<<area_test3.perimeter()<<endl;
	
	cout<<endl<<endl;
	
	cout<<"---------------POLYGONVECT ++ and -- and [] OPERATORS OVERLOAD TEST------------"<<endl;

	PolygonVect overload_test(rec1);
	
	cout<<"PolyVect[0].X:"<<overload_test[0].getX()<<endl;
	cout<<"PolyVect[0].Y:"<<overload_test[0].getY()<<endl;
	/* You have to delete the returned pointer for postfix ++*/
	Shape *ptr_vec=new PolygonVect;
	ptr_vec=&(overload_test++);
	cout<<"After postfix ++;"<<endl;
	cout<<"PolyVect[0].X:"<<overload_test[0].getX()<<endl;
	cout<<"PolyVect[0].Y:"<<overload_test[0].getY()<<endl;
	delete ptr_vec;
	/* You have to delete the returned pointer for postfix ++*/
	ptr_vec=&(overload_test--);
	delete ptr_vec;
	cout<<"After postfix --;"<<endl;
	cout<<"PolyVect[0].X:"<<overload_test[0].getX()<<endl;
	cout<<"PolyVect[0].Y:"<<overload_test[0].getY()<<endl;
	++overload_test;
	cout<<"After prefix ++;"<<endl;
	cout<<"PolyVect[0].X:"<<overload_test[0].getX()<<endl;
	cout<<"PolyVect[0].Y:"<<overload_test[0].getY()<<endl;
	--overload_test;
	cout<<"After prefix --;"<<endl;
	cout<<"PolyVect[0].X:"<<overload_test[0].getX()<<endl;
	cout<<"PolyVect[0].Y:"<<overload_test[0].getY()<<endl;


	cout<<endl<<endl;
	cout<<endl<<endl;
	
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------POLYGONDYN CLASS TESTS-------------"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<endl<<endl;

	
	cout<<"---------------POLYGONDYN CLASS CONSTRUCTERS TEST AND [] OPERATOR OVERLOAD TEST------------"<<endl;
	
	rec1.setX(0);
	rec1.setY(0);
	
	cir1.setX(1000);
	cir2.setY(1000);
	
	tri1.setLength(1000.);
	tri1.setX1(490.);
	tri1.setY1(100.);
	tri1.setX2(240.);
	tri1.setY2(533.013);
	tri1.setX3(740.);
	tri1.setY3(533.013);

	
	
	
	
	cout<<"PolygonDyn() constructor test"<<endl;
	PolygonDyn PD0;
	cout<<"-PolygonDyn() x parameter:"<<PD0[0].getX()<<endl;
	cout<<"-PolygonDyn() y parameter:"<<PD0[0].getY()<<endl;

	cout<<endl;

	cout<<"PolygonDyn(rectangle) constructor test"<<endl;
	PolygonDyn PD1(rec1);
	cout<<"-PolygonDyn(rectangle) x parameter:"<<PD1[3].getX()<<endl;
	cout<<"-PolygonDyn(rectangle) y parameter:"<<PD1[3].getY()<<endl;

	cout<<endl;

	cout<<"PolygonDyn(circle) constructor test"<<endl;
	PolygonDyn PD2(cir1);
	cout<<"-PolygonDyn(circe) x parameter:"<<PD2[1].getX()<<endl;
	cout<<"-PolygonDyn(circle) y parameter:"<<PD2[1].getY()<<endl;
	
	cout<<endl;
	
	cout<<"PolygonDyn(triangle) constructor test"<<endl;
	PolygonDyn PD3(tri1);
	cout<<"-PolygonDyn(triangle) x parameter:"<<PD3[1].getX()<<endl;
	cout<<"-PolygonDyn(triangle) y parameter:"<<PD3[1].getY()<<endl;
	
	cout<<endl;

	cout<<"PolygonDyn(10,20) constructor test"<<endl;
	PolygonDyn PD4(10,20);
	cout<<"-PolygonDyn(10,20) x parameter:"<<PD4[0].getX()<<endl;
	cout<<"-PolygonDyn(10,20) y parameter:"<<PD4[0].getY()<<endl;
	
	cout<<endl;

	cout<<"PolygonDyn(15) constructor test"<<endl;
	PolygonVect PD5(15);
	cout<<"-PolygonDyn(15) x parameter:"<<PD5[0].getX()<<endl;
	cout<<"-PolygonDyn(15) y parameter:"<<PD5[0].getY()<<endl;
	
	cout<<endl;
	
	cout<<"PolygonDyn(vector<Point2D>) constructor test"<<endl;
	cout<<"vector<Point2D>: It has 10,20."<<endl;
	vector <Polygon::Point2D> vec2D1;
	Polygon::Point2D temp2D1(10,20);
	vec2D1.push_back(temp2D1);
	
	PolygonDyn PD6(vec2D1);
	cout<<"-PolygonVect(vector<Point2D*>) x parameter:"<<PD6[0].getX()<<endl;
	cout<<"-PolygonVect(vector<Point2D*>) y parameter:"<<PD6[0].getY()<<endl;
	
	cout<<endl;

	cout<<"PolygonDyn(Shape&) constructor test"<<endl;
	Shape *ptr11;
	ptr11=&tri1;
	PolygonVect PD7(*ptr11);
	cout<<"-PolygonDyn(Shape&) x parameter:"<<PD7[1].getX()<<endl;
	cout<<"-PolygonDyn(Shape&) y parameter:"<<PD7[1].getY()<<endl;

	cout<<endl<<endl;

	cout<<"PolygonDyn(PolygonDyn&) constructor test(copy constructor)"<<endl;
	PolygonDyn copy(rec1);
	
	cout<<"-PolygonDyn x parameter:"<<copy[1].getX()<<endl;
	cout<<"-PolygonDyn y parameter:"<<copy[1].getY()<<endl;
	PolygonDyn copy1(copy);
	cout<<"After copy operation, copied item values are;"<<endl;
	cout<<"-PolygonDyn x parameter:"<<copy1[1].getX()<<endl;
	cout<<"-PolygonDyn y parameter:"<<copy1[1].getY()<<endl;
	cout<<endl<<endl;
	
	cout<<"---------------POLYGONDYN ASSIGNMENT OPERATOR TEST------------"<<endl;

	PolygonDyn assign(tri1);
	PolygonDyn assign1(rec1);
	cout<<"PolygonDyn A -> x value:"<<assign[1].getX()<<endl;
	cout<<"PolygonDyn B -> x value:"<<assign1[1].getX()<<endl;
	cout<<"After A=B"<<endl;
	assign=assign1;
	cout<<"PolygonDyn A -> x value:"<<assign[1].getX()<<endl;
	cout<<"PolygonDyn B -> x value:"<<assign1[1].getX()<<endl;
	
	cout<<endl<<endl;

	cout<<"---------------POLYGONDYN GETUSED AND GETCAPACITY FUNCTION TEST------------"<<endl;
	PolygonDyn PD10(10,20);
	cout<<"PolygonDyn x(10,20)"<<endl;
	cout<<"x.getUsed():"<<PD10.getUsed()<<endl;
	cout<<"x.getCapacity():"<<PD10.getCapacity()<<endl;

	cout<<endl<<endl;

	cout<<"---------------POLYGONDYN AREA AND PERIMETER FUNCTION TEST------------"<<endl;

	cir1.setRadius(1000);
	rec1.setWidth(30);
	rec1.setHeight(50);


	cout<<"rectangle area():"<<rec1.area()<<endl;
	PolygonDyn dyn_area_test2(rec1);
	cout<<"After converted PolygonVect area():"<<dyn_area_test2.area()<<endl;
	cout<<endl;
	cout<<"circle perimeter():"<<cir1.perimeter()<<endl;
	PolygonDyn dyn_area_test3(cir1);
	cout<<"After converted PolygonVect perimeter():"<<dyn_area_test3.perimeter()<<endl;
	
	cout<<endl<<endl;


	cout<<"---------------POLYGONDYN ++ and -- OPERATORS OVERLOAD TEST------------"<<endl;
	
	PolygonDyn overload_test_d(rec1);

	cout<<"PolyDyn[0].X:"<<overload_test_d[0].getX()<<endl;
	cout<<"PolyDyn[0].Y:"<<overload_test_d[0].getY()<<endl;
	/* You have to delete the returned pointer for postfix ++*/
	Shape *ptr_vec1=new PolygonVect;
	ptr_vec1=&(overload_test_d++);
	cout<<"After postfix ++;"<<endl;
	cout<<"PolyDyn[0].X:"<<overload_test_d[0].getX()<<endl;
	cout<<"PolyDyn[0].Y:"<<overload_test_d[0].getY()<<endl;
	delete ptr_vec1;
	/* You have to delete the returned pointer for postfix ++*/
	ptr_vec1=&(overload_test_d--);
	delete ptr_vec1;
	cout<<"After postfix --;"<<endl;
	cout<<"PolyDyn[0].X:"<<overload_test_d[0].getX()<<endl;
	cout<<"PolyDyn[0].Y:"<<overload_test_d[0].getY()<<endl;

	++overload_test_d;

	cout<<"After prefix ++;"<<endl;
	cout<<"PolyDyn[0].X:"<<overload_test_d[0].getX()<<endl;
	cout<<"PolyDyn[0].Y:"<<overload_test_d[0].getY()<<endl;
	--overload_test_d;
	cout<<"After prefix --;"<<endl;
	cout<<"PolyDyn[0].X:"<<overload_test_d[0].getX()<<endl;
	cout<<"PolyDyn[0].Y:"<<overload_test_d[0].getY()<<endl;


	cout<<endl<<endl;
	cout<<endl<<endl;

	cout<<"---------------POLYGONDYN << OPERATOR OVERLOAD AND DRAW() FUNCTION TEST------------"<<endl;

	tri1.setLength(300);
	rec1.setWidth(300);
	rec1.setHeight(500);
	cir1.setRadius(100);
	ofstream polygon_d;

	polygon_d.open("draw_polygondyn_test.svg");

	polygon_d << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<900<<"\" height=\""<<900<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	PolygonDyn PV11(tri1);
	
	polygon_d<<PV11;
	
	polygon_d <<"</svg>";
	polygon_d.close();
	cout<<"->PolygonDyn draw() function tested and result printed in the 'draw_polygondyn_test.svg' file"<<endl<<endl;	


	polygon_d.open("polygondyn_print_test.svg");
	polygon_d << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1750"<<"\" height=\""<<"1750"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;
	cir1.setRadius(400);
	PolygonDyn PV12(cir1);
	
	polygon_d<<PV12;
	
	polygon_d <<"</svg>";
	polygon_d.close();
	cout<<"->PolygonDyn '<<' operator tested and result printed in the 'polygondyn_print_test.svg' file"<<endl;	
	
	cout<<endl<<endl;


	cout<<"---------------PRINTALL() FUNCTION TEST------------"<<endl;
	Rectangle shape1(300,300);
	Triangle shape11(1000);
	Rectangle shape2(2000,2000);
	
	ComposedShape shape3(shape2,shape1);
	
	shape3.optimalFit();
	
	vector <Shape*> shap;
	
	shap = shape3.getVector();
	
	printAll(shap);
	
	cout<<"->PrintAll() function tested and result printed in the 'printAll.svg' file"<<endl<<endl;
	
	PolygonDyn shape4(shape2);
	PolygonDyn shape5(shape11);
	PolygonVect shape6(shape1);
	
	shap.push_back(&shape4);
	shap.push_back(&shape6);
	shap.push_back(&shape5);
	
	printPoly(shap);

	cout<<"->PrintPoly() function tested and result printed in the 'printPolly.svg' file"<<
		endl<<"NOTE!!!"<<endl<<"Because of the polygon colors it seems doesn't print the file."<<
		"Please examine the 'svg' file codes!."<<endl<<endl;
		
	
	cout<<endl<<endl;


	cout<<"---------------CONVERTALL() FUNCTION TEST------------"<<endl;
	/*
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	  If you use this fuction after that you have to delete all adress inside the returned vector.
	  In addition if one of the pointers is composedshape you have to delete all inner shapes adresses.

	*/

	vector<Shape*> convertAllTestInput;
	vector<Shape*> convertAllTestOutput;
	
	convertAllTestInput.push_back(&shape1);
	convertAllTestInput.push_back(&shape11);
	convertAllTestInput.push_back(&shape2);
	convertAllTestInput.push_back(&shape4);
	convertAllTestInput.push_back(&shape6);
	convertAllTestInput.push_back(&shape5);
	
	convertAllTestOutput = convertAll(convertAllTestInput);

	ofstream convertAll;

	convertAll.open("convertAll_Input.svg");

	convertAll << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<900<<"\" height=\""<<900<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	
	convertAllTestInput[0]->draw(convertAll);
	
	
	convertAll <<"</svg>";
	convertAll.close();


	convertAll.open("convertAll_Output.svg");

	convertAll << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<900<<"\" height=\""<<900<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	
	convertAllTestOutput[0]->draw(convertAll);
	
	convertAll <<"</svg>";
	convertAll.close();

	cout<<"convertAll() function tested."<<endl
		<<"=>It's input values first element printed 'convertAll_Input.svg' file"<<endl
		<<"=>It's output values first element printed 'convertAll_Output.svg' file"<<endl
		<<"To verify the conversion please examine the svg files codes."<<endl;
	
	
/*!!!!!!!!!!!!!!!!DELETING INPUT VALUES!!!!!!!!!!!!!!!!!*/
	for(auto x:convertAllTestOutput){
		ComposedShape *ptr;
		ptr=dynamic_cast<ComposedShape*>(x);
		if(ptr != nullptr){
			delete (ptr->getContainer());
			delete (ptr->getInner());
			int size = ptr->getVectorSize();
			for(int k=0;k<size;k++){
				delete (&ptr[k]);
			}
		}
		else
			delete x;	
	}
/*!!!!!!!!!!!!!!!!DELETING INPUT VALUES!!!!!!!!!!!!!!!!!*/
cout<<endl<<endl;
cout<<"----------------------SHORTSHAPES() FUNCTION TEST------------------"<<endl;
	
	Triangle tt1(10);
	Triangle tt2(20);
	Circle cc1(30);
	Circle cc2(40);
	Rectangle rr1(50);
	Rectangle rr2(60);

	vector <Shape*> sort;
	
	/*creating a vector*/
	sort.push_back(&rr1);
	sort.push_back(&cc2);
	sort.push_back(&tt1);
	sort.push_back(&cc1);
	sort.push_back(&tt2);
	sort.push_back(&rr2);
	
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	cout<<"Areas before sorting:"<<endl;
	for(auto x:sort)
		cout<<"-"<<"("<<x->area()<<")";

	sortShapes(sort);

	cout<<endl<<endl<<"Areas after sorting:"<<endl;
	for(auto x:sort)
		cout<<"-"<<"("<<x->area()<<")";


	cout<<endl<<endl;
	


	cout<<"---------------EXCEPTIONS TESTS------------"<<endl;

	Circle exception1(5);
	exception1.setX(-10);
	exception1.setY(-20);
	exception1.setRadius(-20);
	
	cout<<endl;
	Rectangle exception2(10,10);
	
	exception2.setX(-10);
	exception2.setY(-20);
	exception2.setWidth(-20);
	exception2.setHeight(-20);
	
	cout<<endl;
	Triangle exception3(10);
	
	exception3.setX1(-10);
	exception3.setY1(-20);
	exception3.setX2(-60);
	exception3.setY2(-80);
	exception3.setX3(-100);
	exception3.setY3(-2);
	exception3.setLength(-30);

	cout<<endl;

	PolygonVect exception4;
	PolygonDyn exception5;







}




