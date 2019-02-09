
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
#include "Polygon.h"
#include "Polyline.h"

using namespace std;
using namespace Polyl;
using namespace Composed;

int main() {
	
	int choice = 0;
	/*For conversion testing.*/
	Rectangle rectangle(500,600);
	Triangle triangle(600);
	Circle circle(400);

	Poly::Polygon polygon[5];
	Polyline polyline[5];

	ComposedShape composed[5];

	ofstream inputStream;


	cout<<endl<<"1.Polygon Test"<<endl;
	cout<<"2.Polyline Test"<<endl;
	cout<<"3.ComposedShape Test"<<endl;
	cout<<"0.Cikis"<<endl<<endl;
	cout<<"Enter your choice:";
	cin>>choice;

	cout<<endl<<endl<<endl;
	cout<<endl<<endl<<endl;
/*********************************************************************/
/*********************************************************************/
/*****************************FOR POLYGON*****************************/
/*********************************************************************/
/*********************************************************************/

cout<<endl<<endl<<endl;

	while(choice != 0){


	/*********************************************************************/
	/*Constructors tests.*/

		if(choice == 1){
			cout<<"For constructor tests input, please examine the code."<<endl<<endl;

			vector <Poly::Polygon::Polygon2D> test_vector;

	
		/*
		 I created polygons with constructors and combine all with vector.
		  After that created new polygon with vector constructor and print it.
		  In that way i tested every constructor.
		*/
			/*no param and param constructors.*/
			Poly::Polygon test1;
			Poly::Polygon test2(100);
			Poly::Polygon test3(100,200);
	

			test_vector.push_back(test1[0]);
			test_vector.push_back(test2[0]);
			test_vector.push_back(test3[0]);
	
			/*Takes Point2D vector constructor.*/
			Poly::Polygon test4(test_vector);

	
				for(int i=0;i<test4.getPolygon2D_size() ; i++){
					cout<< test4[i].getX()<<"-"<<test4[i].getY()<<" | ";
				}
	
		/*********************************************************************/




			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;
























			/*RECTANGLE,TRIANGLE AND CİRCLE CONVERSİTON TESTS*/
			/*********************************************************************/
			/*RECTANGLE*/

			/************FOR RECTANGLE CONVERSION, << OPERATOR AND BIG THREE TESTS*********************/
			inputStream.open("rectangle_conversion.svg");
	
			inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1000"<<"\" height=\""<<"1000"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;


			Poly::Polygon a(rectangle); /*conversion*/
			polygon[0]=a;			/*assignemnt operator overload tests.*/
	
			inputStream<<polygon[0];		/*<< operator overload tests.*/
			inputStream << "</svg>";
			inputStream.close();
			cout<<"For rectangle conversion test, created 'rectangle_conversion.svg' file";
			/*********************************************************************/

			/*********************************************************************/
			/*TRIANGLE*/
			inputStream.open("triangle_conversion.svg");
	
			inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1000"<<"\" height=\""<<"1000"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;


			Poly::Polygon b(triangle); /*conversion*/
			polygon[0]=b;			/*assignemnt operator overload tests.*/
	
			inputStream<<polygon[0];		/*<< operator overload tests.*/
			inputStream << "</svg>";
			inputStream.close();
			cout<<endl<<endl<<"For triangle conversion test, created 'triangle_conversion.svg' file";
			/*********************************************************************/

			/*********************************************************************/
			/*CIRCLE*/
			inputStream.open("circle_conversion.svg");
	
			inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1000"<<"\" height=\""<<"1000"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;


			Poly::Polygon c(circle); /*conversion*/
			polygon[0]=c;			/*assignemnt operator overload tests.*/
	
			inputStream<<polygon[0];		/*<< operator overload tests.*/
			inputStream << "</svg>";
			inputStream.close();
			cout<<endl<<endl<<"For circle conversion test, created 'circle_conversion.svg' file";
			/*********************************************************************/

			cout<<endl<<endl<<"Overloaded << opetator tested succesfully."<<endl<<endl;



			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;




	



			/*********************************************************************/
			/* [] operator overload test.*/

			Poly::Polygon x(100,100);

			polygon[0] = x;
			cout<<endl<<"[] operator overload tests;";
			cout<< endl <<"Polygon X:"<< (polygon[0])[0].getX()<<endl;
			cout<< "Polygon Y:"<< (polygon[0])[0].getY()<<endl<<endl<<endl;
			/*********************************************************************/

			/*********************************************************************/

			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;










			/*********************************************************************/
			/*== and != operator overload tests.*/

			Poly::Polygon p1(100,200);
			Poly::Polygon p2(100,200);
			Poly::Polygon p3(200,300);
	
			cout<<"== operator overload tests;"<<endl;
			cout<<"p1(100,200) - p2(100-200) - p3(200-300)"<<endl<<endl;
			if(p1==p2)
				cout<<"-Polygon p1 equal to polygon p2"<<endl;
			if(p1==p3)
				cout<<"-Polygon p1 equal to polygon p3"<<endl;
			if(p1!=p3)
				cout<<"-Polygon p1 not equal to polygon p3"<<endl;

			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;


			/*********************************************************************/







			/*+ operator overload test.*/
			/*********************************************************************/
			cout<<"+ operator overload test;"<<endl;
			Poly::Polygon x1(triangle);
			Poly::Polygon x2(rectangle);
			Poly::Polygon x3;
			cout<<endl<<"Polygon 1 points;"<<endl;
			for(int i=0 ; i<x1.getPolygon2D_size() ; i++){
				cout<< x1[i].getX()<<"-"<<x1[i].getY()<<" | ";
			}
			cout<<endl<<endl<<"Polygon 2 points;"<<endl;
			for(int i=0 ; i<x2.getPolygon2D_size() ; i++){
				cout<< x2[i].getX()<<"-"<<x2[i].getY()<<" | ";
			}
			x3=x1+x2;
			cout<<endl<<endl<<"Polygon 1 + Polygon 2 points;"<<endl;
			for(int i=0 ; i<x3.getPolygon2D_size() ; i++){
				cout<< x3[i].getX()<<"-"<<x3[i].getY()<<" | ";
			}
		
			cout<<endl<<endl<<endl;



			/*********************************************************************/

		}








		else if(choice == 2){

		/*********************************************************************/
		/*********************************************************************/
		/*****************************FOR POLYLINE*****************************/
		/*********************************************************************/
		/*********************************************************************/

			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;
			cout<<"---------------------------FOR POLYLINE--------------------------"<<endl<<endl<<endl;


		/*CONSTRUCTORS TEST*/
	
			cout<<endl<<endl<<"For constructor tests input, please examine the code."<<endl<<endl;
			vector <Poly::Polygon::Polygon2D> test2_vector;

		/*
		 I created polylines with constructors and combine all with vector.
		  After that created new polyline with vector constructor and print it.
		  In that way i tested every constructor.
		*/
			Polyline test5;
			Polyline test6(100);
			Polyline test7(100,200);
	

			test2_vector.push_back(test5[0]);
			test2_vector.push_back(test6[0]);
			test2_vector.push_back(test7[0]);
	
			/*Takes Point2D vector constructor.*/
			Polyline test8(test2_vector);

	
			for(int i=0;i<(test8.getPolygon()).getPolygon2D_size() ; i++){
				cout<< test8[i].getX()<<"-"<<test8[i].getY()<<" | ";
			}
	
			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;












	

			/*RECTANGLE,TRIANGLE AND CİRCLE CONVERSİTON TESTS*/
			/*********************************************************************/
			/*RECTANGLE*/

			/************FOR RECTANGLE CONVERSION, << OPERATOR AND BIG THREE TESTS*********************/
			inputStream.open("rectangle_conversion_polyline.svg");
	
			inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1000"<<"\" height=\""<<"1000"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;


			Polyline ax(rectangle); /*conversion*/
			polyline[0]=ax;			/*assignemnt operator overload tests.*/
	
			inputStream<<polyline[0];		/*<< operator overload tests.*/
			inputStream << "</svg>";
			inputStream.close();
			cout<<"For rectangle conversion test, created 'rectangle_conversion_polyline.svg' file";
			/*********************************************************************/

			/*********************************************************************/
			/*TRIANGLE*/
			inputStream.open("triangle_conversion_polyline.svg");
	
			inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1000"<<"\" height=\""<<"1000"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;


			Polyline bx(triangle); /*conversion*/
			polyline[0]=bx;			/*assignemnt operator overload tests.*/
	
			inputStream<<polyline[0];		/*<< operator overload tests.*/
			inputStream << "</svg>";
			inputStream.close();
			cout<<endl<<endl<<"For triangle conversion test, created 'triangle_conversion_polyline.svg' file";
			/*********************************************************************/

			/*********************************************************************/
			/*CIRCLE*/
			inputStream.open("circle_conversion_polyline.svg");
	
			inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<"1000"<<"\" height=\""<<"1000"<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;


			Polyline cx(circle); /*conversion*/
			polyline[0]=cx;			/*assignemnt operator overload tests.*/
	
			inputStream<<polyline[0];		/*<< operator overload tests.*/
			inputStream << "</svg>";
			inputStream.close();
			cout<<endl<<endl<<"For circle conversion test, created 'circle_conversion_polyline.svg' file";
			/*********************************************************************/

			cout<<endl<<endl<<"Overloaded << opetator tested succesfully."<<endl<<endl;



			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;




	










	



			/*********************************************************************/
			/* [] operator overload test.*/
			Polyline xa(100,100);

			polyline[0] = xa;
			cout<<endl<<"[] operator overload tests;";
			cout<< endl <<"Polyline X:"<< (polyline[0])[0].getX()<<endl;
			cout<< "Polline Y:"<< (polyline[0])[0].getY()<<endl<<endl<<endl;
			/*********************************************************************/

			/*********************************************************************/

			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;










			/*********************************************************************/
			/*== and != operator overload tests.*/

			Polyline p6(100,200);
			Polyline p7(100,200);
			Polyline p8(200,300);
	
			cout<<"== operator overload tests;"<<endl;
			cout<<"p1(100,200) - p2(100-200) - p3(200-300)"<<endl<<endl;
			if(p6==p7)
				cout<<"-Polyline p1 equal to polyline p2"<<endl;
			if(p6==p8)
				cout<<"-Polyline p1 equal to polyline p3"<<endl;
			if(p6!=p8)
				cout<<"-Polyline p1 not equal to polyline p3"<<endl;

			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;


			/*********************************************************************/







			/*+ operator overload test.*/
			/*********************************************************************/
			cout<<"+ operator overload test;"<<endl;
			Polyline x6(triangle);
			Polyline x7(rectangle);
			Polyline x8;
			cout<<endl<<"Polyline 1 points;"<<endl;
			for(int i=0 ; i<( x6.getPolygon() ).getPolygon2D_size() ; i++){
				cout<< x6[i].getX()<<"-"<<x6[i].getY()<<" | ";
			}
			cout<<endl<<endl<<"Polyline 2 points;"<<endl;
			for(int i=0 ; i<( x7.getPolygon() ).getPolygon2D_size() ; i++){
				cout<< x7[i].getX()<<"-"<<x7[i].getY()<<" | ";
			}
			x8=x6+x7;
			cout<<endl<<endl<<"Polyline 1 + Polygon 2 points;"<<endl;
			for(int i=0 ; i<( x8.getPolygon() ).getPolygon2D_size() ; i++){
				cout<< x8[i].getX()<<"-"<<x8[i].getY()<<" | ";
			}
		
			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;


			/*********************************************************************/

		}



			else if(choice == 3){


























			/*********************************************************************/
			/*********************************************************************/
			/*********************************************************************/
			/**********************Composed Shape Tests*************************/		

			/*rectangle inside rectangle*/
			Rectangle rec1(1000,1000);
			Rectangle rec2(100,200);

			ComposedShape a1(rec1,rec2);
			composed[0] = a1;
			inputStream.open("output1.svg");
	
			composed[0].optimalFit(rec1,rec2);
			inputStream<<composed[0];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Rectangle inside rectangle printed inside output1.svg succesfully";
			/*********************************************************************/





			/*********************************************************************/
			/*rectangle inside circle*/


			Rectangle rec3(1000,1000);
			Circle circ1(50);

			ComposedShape b1(rec3,circ1);
			composed[1]=b1;
			inputStream.open("output2.svg");
	
			composed[1].optimalFit(rec3,circ1);
			inputStream<<composed[1];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Rectangle inside circle printed inside output2.svg succesfully";

			/*********************************************************************/





			/*********************************************************************/
			/*rectangle inside triangle*/

			Rectangle rec4(1000,1000);
			Triangle tri1(50);

			ComposedShape c1(rec4,tri1);
			composed[2]=c1;
			inputStream.open("output3.svg");
	
			composed[2].optimalFit(rec4,tri1);
			inputStream<<composed[2];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Rectangle inside triangle printed inside output3.svg succesfully";

			/*********************************************************************/





			/*********************************************************************/
			/*circle inside rectangle*/

			Circle circ2(1000);
			Rectangle rec5(100,50);

			ComposedShape d1(circ2,rec5);
			composed[3]=d1;
			inputStream.open("output4.svg");
	
			composed[3].optimalFit(circ2,rec5);
			inputStream<<composed[3];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Circle inside rectangle printed inside output4.svg succesfully";

			/*********************************************************************/







			/*********************************************************************/
			/*circle inside circle*/

			Circle circ3(1000);
			Circle circ4(100);

			ComposedShape e1(circ2,circ4);
			composed[4]=e1;
			inputStream.open("output5.svg");
	
			composed[4].optimalFit(circ2,circ4);
			inputStream<<composed[4];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Circle inside circle printed inside output5.svg succesfully";
			/*********************************************************************/







			/*********************************************************************/
			/*circle inside triangle*/

			Circle circ9(1000);
			Triangle tri2(100);

			ComposedShape f1(circ9,tri2);
			composed[0]=f1;
			inputStream.open("output6.svg");
	
			composed[0].optimalFit(circ9,tri2);
			inputStream<<composed[0];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Circle inside triangle printed inside output6.svg succesfully";
	
			/*********************************************************************/







			/*********************************************************************/
			/*Triangle inside rectangle*/

			Triangle tri3(1000);
			Rectangle rec6(100,50);

			ComposedShape g1(tri3,rec6);
			composed[1]=g1;
			inputStream.open("output7.svg");
	
			composed[1].optimalFit(tri3,rec6);
			inputStream<<composed[1];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Triangle inside rectangle printed inside output7.svg succesfully";
	
			/*********************************************************************/







			/*********************************************************************/
			/*Triangle inside circle*/

			Triangle tri4(1000);
			Circle circ5(100);

			ComposedShape h1(tri3,circ5);
			composed[2]=h1;
			inputStream.open("output8.svg");
	
			composed[2].optimalFit(tri3,circ5);
			inputStream<<composed[2];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Triangle inside circle printed inside output8.svg succesfully";

			/*********************************************************************/







			/*********************************************************************/
			/*Triangle inside triangle*/

			Triangle tri5(1000);
			Triangle tri6(100);

			ComposedShape j1(tri5,tri6);
			composed[3]=j1;
			inputStream.open("output9.svg");
	
			composed[3].optimalFit(tri5,tri6);
			inputStream<<composed[3];
	
			inputStream << "</svg>";
			inputStream.close();

			cout<<endl<<endl<<"Triangle inside triangle printed inside output9.svg succesfully"<<endl<<endl;
		}
		
		cout<<endl<<endl;
		cout<<endl<<"1.Polygon Test"<<endl;
		cout<<"2.Polyline Test"<<endl;
		cout<<"3.ComposedShape Test"<<endl;
		cout<<"0.Cikis"<<endl<<endl;
		cout<<"Enter your choice:";
		cin>>choice;
		cout<<endl<<endl;
		
	}



	return 0;
}












