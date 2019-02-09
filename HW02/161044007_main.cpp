
/*
	Yusuf Can Kan
	161044007
*/

/*

	This file tests each function with customers choices.
	I created a menu for easy testing.

	It tests setters and getter, constructors, draw functions, optimalFit function,
	and the others.

*/

#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ComposedShape.h"

using namespace std;

int main() {

	ofstream inputStream;
	int choice;
	int condition=0;
	Rectangle rectangle[4];
	Triangle triangle[4];
	Circle circle[4];

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

				cout<<endl<<"Inside shapes vector size:"<<RR.getInsideRectangleVectorSize();
				cout<<endl;
			
				RR.DrawContainerRectangle(inputStream);
				RR.DrawInsideRectangle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();

			}
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

				cout<<endl<<"Inside shapes vector size:"<<RC.getInsideCircleVectorSize();
				cout<<endl;
			
				RC.DrawContainerRectangle(inputStream);
				RC.DrawInsideCircle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();


			}
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

				cout<<endl<<"Inside shapes vector size:"<<RT.getInsideTriangleVectorSize();
				cout<<endl;
			
				RT.DrawContainerRectangle(inputStream);
				RT.DrawInsideTriangle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();
			}
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

				cout<<endl<<"Inside shapes vector size:"<<CR.getInsideRectangleVectorSize();
				cout<<endl;
			
				CR.DrawContainerCircle(inputStream);
				CR.DrawInsideRectangle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();

			}
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

				cout<<endl<<"Inside shapes vector size:"<<CC.getInsideCircleVectorSize();
				cout<<endl;
			
				CC.DrawContainerCircle(inputStream);
				CC.DrawInsideCircle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();
			
			}
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

				cout<<endl<<"Inside shapes vector size:"<<CT.getInsideTriangleVectorSize();
				cout<<endl;
			
				CT.DrawContainerCircle(inputStream);
				CT.DrawInsideTriangle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();
			}
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

				cout<<endl<<"Inside shapes vector size:"<<TR.getInsideRectangleVectorSize();
				cout<<endl;
			
				TR.DrawContainerTriangle(inputStream);
				TR.DrawInsideRectangle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();
			}
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

				cout<<endl<<"Inside shapes vector size:"<<TC.getInsideCircleVectorSize();
				cout<<endl;
			
				TC.DrawContainerTriangle(inputStream);
				TC.DrawInsideCircle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();
			

			
			}
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

				cout<<endl<<"Inside shapes vector size:"<<TT.getInsideTriangleVectorSize();
				cout<<endl;
			
				TT.DrawContainerTriangle(inputStream);
				TT.DrawInsideTriangle(inputStream);
			
				inputStream << "</svg>";
				inputStream.close();
			}
			else
				cout<<endl<<"Invalid input, Please try again"<<endl;
		}

	return 0;
}
