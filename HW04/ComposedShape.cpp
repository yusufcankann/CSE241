#include <iostream>
#include<cmath>
#include "ComposedShape.h"
namespace{
	/*Circle equation formule for calculating circle inside circle*/
	inline int circle_equation(double x,double y,double radius){
		if( pow(x-radius,2) + pow(y-radius,2) <= pow(radius,2) )
			return 1;
		else
			return 0;
	}
}

/*Constructors for every situations.*/
namespace Composed{
	ComposedShape::ComposedShape(){}

	ComposedShape::ComposedShape(Rectangle r_container,Rectangle r_inside):r_c(r_container),r_i(r_inside),Container(Shapes::Rectangle){
	}
	ComposedShape::ComposedShape(Rectangle r_container,Circle c_inside):r_c(r_container),c_i(c_inside),Container(Shapes::Rectangle){
	}
	ComposedShape::ComposedShape(Rectangle r_container,Triangle t_inside):r_c(r_container),t_i(t_inside),Container(Shapes::Rectangle){
	}
	ComposedShape::ComposedShape(Circle c_container,Rectangle r_inside):r_i(r_inside),c_c(c_container),Container(Shapes::Circle){
	}
	ComposedShape::ComposedShape(Circle c_container,Circle c_inside):c_c(c_container),c_i(c_inside),Container(Shapes::Circle){
	}
	ComposedShape::ComposedShape(Circle c_container,Triangle t_inside):c_c(c_container),t_i(t_inside),Container(Shapes::Circle){
	}
	ComposedShape::ComposedShape(Triangle t_container,Rectangle r_inside):r_i(r_inside),t_c(t_container),Container(Shapes::Triangle){
	}
	ComposedShape::ComposedShape(Triangle t_container,Circle c_inside):c_i(c_inside),t_c(t_container),Container(Shapes::Triangle){
	}
	ComposedShape::ComposedShape(Triangle t_container,Triangle t_inside):t_c(t_container),t_i(t_inside),Container(Shapes::Triangle){
	}

	/*
	  This 3 draw functions only for driver file.
	  I used these inside the driver file.
	*/
	void ComposedShape::DrawContainerRectangle(ofstream &inputStream){
		inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<r_c.getWidth()<<"\" height=\""<<r_c.getHeight()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;
	}
	void ComposedShape::DrawContainerTriangle(ofstream &inputStream){
		inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<t_c.getLength()<<"\" height=\""<<t_c.getLength()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl 	
			<< " <polygon points=\"" << t_c.getLength()/2 << ",0 0,"<<t_c.getLength()*(sqrt(3)/2)<<" "
			<< t_c.getLength() << "," << t_c.getLength()*(sqrt(3)/2) << "\" fill=\"red\"/> " << endl;
	}
	void ComposedShape::DrawContainerCircle(ofstream &inputStream){
		inputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<c_c.getRadius()*2<<"\" height=\""<<c_c.getRadius()*2<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< " <circle cx=\""<<c_c.getRadius()<<"\" cy=\""<<c_c.getRadius()<<"\" r=\""<<c_c.getRadius()
				<<"\" fill=\"red\" /> " << endl;
	}


	/*for r value*/
	const Polygon ComposedShape::operator[](int index)const{
		return shapes[index];
	}
	/*for l value*/
	Polygon ComposedShape::operator[](int index){
		return shapes[index];
	}			

	Polygon ComposedShape::operator+=(Polygon &shape){
		shapes.push_back(shape);
		return shape;
	}

	/*
		Optimal Fit << operator overload.
		This function prints the file container and inner shapes.
		It prints all things.
	*/

	ostream& operator<<(ostream &outputStream,ComposedShape Composed){

		/*First it check the container part and prints the container shape.*/
		if( ( Composed.getContainerShape() ) == ( Shapes::Rectangle) ){  /*If container rectangle*/
			outputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<Composed.r_c.getWidth()<<"\" height=\""<<Composed.r_c.getHeight()<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;
		}
		else if((Composed.getContainerShape()) == (Shapes::Triangle)){	/*If container triangle*/
			outputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<Composed.t_c.getLength()<<"\" height=\""<<Composed.t_c.getLength()<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl 	
				<< " <polygon points=\"" << Composed.t_c.getLength()/2 << ",0 0,"<<Composed.t_c.getLength()*(sqrt(3)/2)<<" "
				<< Composed.t_c.getLength() << "," << Composed.t_c.getLength()*(sqrt(3)/2) << "\" fill=\"red\"/> " << endl;
		}
		else if((Composed.getContainerShape()) == (Shapes::Circle)){	/*If container circle*/
			outputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<Composed.c_c.getRadius()*2<<"\" height=\""<<Composed.c_c.getRadius()*2<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< " <circle cx=\""<<Composed.c_c.getRadius()<<"\" cy=\""<<Composed.c_c.getRadius()<<"\" r=\""<<Composed.c_c.getRadius()
				<<"\" fill=\"red\" /> " << endl;
		}

		/*
		  For the inner shapes part.
		  Overloaded << operator prints the shapes to the svg file automaticly.
		  It uses the polygon which holds small shapes.
		*/
		for(int i=0; i< int(Composed.shapes.size()) ;i++){
			outputStream << Composed[i];
		}

		return outputStream;
	}
/*Getters*/
	
	/*Container shape class enum getter function.*/
	Shapes ComposedShape::getContainerShape(){
		return Container;
	}
	
	/*Polygon vector size getters.*/
	int ComposedShape::getShapeVectorSize(){
		return shapes.size();
	}


/*-----------------------------------------------OPTIMAL FIT FUNCTION OVERLOADS----------------------------------------------------*/
/*Overloaded optimal fit functions for each cases.*/

		void ComposedShape::optimalFit(Rectangle r_container,Rectangle r_inside){
		int i,j,k,l;
		auto counter=0;
		decltype(r_inside) fit;

/*It calculates and adds small shapes to the vector*/

		for(i=0; i+(r_inside.getHeight()) <= r_container.getHeight() ; i+=r_inside.getHeight() ){
			for(j=0; j+ (r_inside.getWidth() ) <= r_container.getWidth() ; j+=(r_inside.getWidth() )){
				fit.setX(j);
				fit.setY(i);
				fit.setWidth( r_inside.getWidth() );
				fit.setHeight( r_inside.getHeight() );
				Polygon polygon(fit);
				shapes.push_back( polygon );
				counter++;
				
			}	
		}
		/*After that it controls the bottom,top,right and left sides and fills the gaps.*/
		if(i+(r_inside.getHeight()) > r_container.getHeight() && (r_container.getHeight() - i) >= r_inside.getWidth() && r_container.getWidth() >= r_inside.getHeight() ){
			for(k=i;k+ (r_inside.getWidth()) <= r_container.getHeight() ; k+=(r_inside.getWidth() ) ){
				for(l=0;l+r_inside.getHeight()<=r_container.getWidth();l+=r_inside.getHeight()){
					fit.setX(l);
					fit.setY(k);
					fit.setWidth( r_inside.getHeight() );
					fit.setHeight( r_inside.getWidth() );
					Polygon polygon(fit);
					shapes.push_back( polygon );
					counter++;
				}
			}
		}
		if( (j+r_inside.getWidth() > r_container.getWidth()) && ((r_container.getWidth() - j)) >= (r_inside.getHeight() && r_container.getHeight() >= r_inside.getWidth() ) ){
			for(k=0;k+r_inside.getWidth() <= r_container.getHeight() ;k+=r_inside.getWidth()){
				for(l=j ; (l+r_inside.getHeight()) <= r_container.getWidth() ;l+=r_inside.getHeight()){
					fit.setX(l);
					fit.setY(k);
					fit.setWidth( r_inside.getHeight() );
					fit.setHeight( r_inside.getWidth() );
					Polygon polygon(fit);
					shapes.push_back( polygon );
					counter++;
				}
			}
		}
	}


	void ComposedShape::optimalFit(Rectangle r_container,Circle c_inside){
		int i,j;
		auto line=1;
		auto condition1=0,condition2=0;
		decltype(c_inside) fitC;		
		
		/*First it calculates the most efficient way.
		  There is 2 way which is one under the other or cross way.*/
		for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+((c_inside.getRadius())*sqrt(3))){
			for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
				if(j==c_inside.getRadius() && line %2 == 0)
					j+=c_inside.getRadius();
				condition1++;
			}
			line++;
		}	
		for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+(c_inside.getRadius()*2)){
			for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
				condition2++;	
			}
		}
/*After calculation it chooses the most efficient way.*/
		/*It applies the cross condition.*/
		if(condition1 >= condition2){
			for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+(c_inside.getRadius()*sqrt(3))){
				for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
				
					if(j==c_inside.getRadius() && line %2 == 0)
						j+=c_inside.getRadius();

					fitC.setRadius(c_inside.getRadius());
					fitC.setX(j);
					fitC.setY(i);
					Polygon polygon(fitC);
					shapes.push_back( polygon );
				}
				line++;
			}	
		}
		else{/*It applies the one under the other condition.*/
			for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+(c_inside.getRadius()*2)){
				for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
					fitC.setRadius(c_inside.getRadius());
					fitC.setX(j);
					fitC.setY(i);
					Polygon polygon(fitC);
					shapes.push_back( polygon );

				}
			}
		}
	}

	void ComposedShape::optimalFit(Rectangle r_container,Triangle t_inside){
		double i,j;
		auto line = 1;
		auto counter=0;
		decltype(t_inside) fitT;


/*It calculates and after that it adds small shape to the vector.*/
		for(i=0 ; (i+ ((t_inside.getLength()*sqrt(3.0))/2.0) ) <= r_container.getHeight() ; i+= (t_inside.getLength()*sqrt(3.0)/2.0) ){
			for(j=0; (j+ (t_inside.getLength()) ) <= r_container.getWidth() ; j+=t_inside.getLength() ){
				fitT.setLength(t_inside.getLength());
				fitT.setX11(j);
				fitT.setX12(i);
				fitT.setX21(j+t_inside.getLength());
				fitT.setX22(i);
				fitT.setX31( j+(t_inside.getLength()/2));
				fitT.setX32( t_inside.getLength()*(sqrt(3)/2)+i );
				Polygon polygon(fitT);
				shapes.push_back( fitT );

				/*Reverse triangle calculation.*/
				if( ( j+(t_inside.getLength()/2)+(t_inside.getLength()) ) <= r_container.getWidth()){
					
					fitT.setLength(t_inside.getLength());
					fitT.setX11(j+t_inside.getLength());
					fitT.setX12(i);
					fitT.setX21(j+t_inside.getLength()/2);
					fitT.setX22(i+t_inside.getLength()*(sqrt(3)/2));
					fitT.setX31( j+t_inside.getLength()+(t_inside.getLength()/2) );
					fitT.setX32( t_inside.getLength()*(sqrt(3)/2)+i );
					Polygon polygon(fitT);
					shapes.push_back( fitT );

						counter++;
					}
				counter++;
				}
			line++;
		}

	}
	
	void ComposedShape::optimalFit(Circle c_container,Rectangle r_inside){
		double i,j,k,l;
		double square_side=sqrt(2.0)*c_container.getRadius();
		double square_x,square_y;
		double temp;
		double hSmall_t;
		int flag=0;
		auto counter=0;
		hSmall_t=r_inside.getHeight();
		decltype(r_inside) fitR;

		square_y=c_container.getRadius()-(square_side/2.0);
		square_x=square_y;


		for(i=square_y;i+r_inside.getHeight()<=square_side;i+=r_inside.getHeight()){
			for(j=square_x;j<=square_side+r_inside.getWidth();j+=r_inside.getWidth()){
				if(pow((i-c_container.getRadius()),2) +  pow((j+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ) {
					fitR.setWidth(r_inside.getWidth());
					fitR.setHeight(r_inside.getHeight());
					fitR.setX(j);
					fitR.setY(i);
					Polygon polygon(fitR);
					shapes.push_back( polygon );
					counter++;
                }
			}
		}
	/*
		After here the function changes width and height and it controls the empty areas for filling the gap.
		When it change width and height it finds the empty area more.
	*/
		/*It controls the empty areas.*/
		if(r_inside.getHeight() > r_inside.getWidth()){
			temp=fitR.getHeight();
			fitR.setHeight(r_inside.getWidth());
			fitR.setWidth(temp);
			flag=1;
		}
	/*It fills the empty areas.*/
		for(k=square_y-r_inside.getHeight();k>=0;k-=r_inside.getHeight()){
			for(l=square_x+r_inside.getWidth();l<=2*c_container.getRadius();l+=r_inside.getWidth()){
				if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){
					
					fitR.setWidth(r_inside.getWidth());
					fitR.setHeight(r_inside.getHeight());
					fitR.setX(l);
					fitR.setY(k);
					Polygon polygon(fitR);
					shapes.push_back( polygon );
				}
			}	
		}
		if(flag==1)
			i+=6* fitR.getHeight();
		else
			i+=fitR.getWidth();

		for(k=i;k<=c_container.getRadius()*2;k+=r_inside.getHeight()){
			for(l=c_container.getRadius()-(square_side/2.0);l<=2*c_container.getRadius();l+=r_inside.getWidth()){
				if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){

					fitR.setWidth(r_inside.getWidth());
					fitR.setHeight(r_inside.getHeight());
					fitR.setX(l);
					fitR.setY(k);
					Polygon polygon(fitR);
					shapes.push_back( polygon );
					fitR.increase_total_area();
					fitR.increase_perimeter();
				}
			}
		}
		if(flag==1){
			temp=r_inside.getHeight();
			fitR.setHeight(r_inside.getWidth());
			fitR.setWidth(temp);
		}
		if(flag==0 && r_inside.getHeight() < r_inside.getWidth()){
			temp=r_inside.getHeight();
			fitR.setHeight(r_inside.getWidth());
			fitR.setWidth(temp);
		}
	
		for(k=square_y+r_inside.getHeight();k<=2*c_container.getRadius();k+=r_inside.getHeight()){
			for(l=c_container.getRadius()-(square_side/2.0);l<=2*c_container.getRadius();l+=r_inside.getWidth()){
					
					if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){

						fitR.setWidth(r_inside.getWidth());
						fitR.setHeight(r_inside.getHeight());
						fitR.setX(l);
						fitR.setY(k);
						Polygon polygon(fitR);
						shapes.push_back( polygon );
					}
			}
		}
		for(k=square_y+hSmall_t;k<=c_container.getRadius()*2;k+=r_inside.getHeight()){
			for(l=square_x-r_inside.getWidth();l>=0;l-=r_inside.getWidth()){
				
				if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
					pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){

					fitR.setWidth(r_inside.getWidth());
					fitR.setHeight(r_inside.getHeight());
					fitR.setX(l);
					fitR.setY(k);
					Polygon polygon(fitR);
					shapes.push_back( polygon );
				}
			}
		}

	}

	void ComposedShape::optimalFit(Circle c_container,Circle c_inside){
	
		double angle;
		double anglee;
		double i,j;
		double x,y;/*Coordinates of circles.*/
		double x_t,y_t;/*For temprary coordinates.*/
		int number_of_circle;
		auto counter=0;
		double sradius_temp,radius_temp;
		int counter_circle=0;
		decltype(c_inside) fitC;

		/*COSINUS THEOREM C^2 = A^2+B^2+2AB*COS*/
		angle= acos(1.0 - ( pow( (2.0*c_inside.getRadius()) , 2.0 ) ) / (2.0* pow( (c_container.getRadius()-c_inside.getRadius()),2.0 )) );
		anglee= (angle*180.0) / PI;
		number_of_circle = 360/anglee;
	

		x=c_container.getRadius();
		y=c_inside.getRadius();
		radius_temp=c_container.getRadius();
		sradius_temp=c_inside.getRadius();
		/*First it add circle to most external part after that it comes to center of circle. */
		for(i=sradius_temp;i+sradius_temp*3<=(c_container.getRadius()+2*c_inside.getRadius());i+=sradius_temp*2){
			for(j=0;j<=number_of_circle-(1);j++){
				
				x_t=x-c_container.getRadius();
				y_t=y-c_container.getRadius();
			/*Rotation formules*/
				x=x_t*cos(angle)-y_t*sin(angle);
				y=x_t*sin(angle)+y_t*cos(angle);
	
				x+=c_container.getRadius();
				y+=c_container.getRadius();	
	
				fitC.setX(x);
				fitC.setY(y);
				fitC.setRadius(c_inside.getRadius());
				Polygon polygon(fitC);
				shapes.push_back( polygon );

				counter_circle++;
			}
			/*This part does the same calculations for other interior part.*/
			radius_temp-=2*(c_inside.getRadius());
			counter++;
			x=c_container.getRadius();
			y=c_inside.getRadius()+(2*counter*c_inside.getRadius());
			angle= acos(1.0 - ( pow( (2.0*c_inside.getRadius()) , 2.0 ) ) / (2.0* pow( (radius_temp-c_inside.getRadius()),2.0 )) );
			anglee= (angle*180.0) / PI;
			number_of_circle = 360/anglee;
		}
	
		if(c_inside.getRadius()*2 == c_container.getRadius()){
			fitC.setX(c_container.getRadius());
			fitC.setY(c_container.getRadius()-c_inside.getRadius());
			fitC.setRadius(c_inside.getRadius());
			Polygon polygon(fitC);
			shapes.push_back( polygon );
		}
	
		if( c_container.getRadius()- (i-c_inside.getRadius()) > c_inside.getRadius()){
			fitC.setX(c_container.getRadius());
			fitC.setY(c_container.getRadius());
			fitC.setRadius(c_inside.getRadius());
			Polygon polygon(fitC);
			shapes.push_back( polygon );
		}

		
	}

	void ComposedShape::optimalFit(Circle c_container,Triangle t_inside){

		double i;
		double y;
		double h_triangle=(t_inside.getLength()*sqrt(3.0))/2.0;
		int line=0;
		auto counter=1;
		decltype(t_inside) fitT;

	/*First it calculates the y coordinate because i started the filling the gaps from center and with reverse radius.*/
		y=sqrt(pow(c_container.getRadius(),2)-pow(t_inside.getLength()/2,2))+c_container.getRadius();
		y=2*c_container.getRadius()-y;
	/*It controls the situations with circle equation formules.*/
		if(circle_equation(c_container.getRadius(),y+h_triangle,c_container.getRadius())==1){
			fitT.setLength(t_inside.getLength());
			fitT.setX11(c_container.getRadius()-(t_inside.getLength()/2));
			fitT.setX12(y);
			fitT.setX21(c_container.getRadius()+(t_inside.getLength()/2));
			fitT.setX22(y);
			fitT.setX31( c_container.getRadius());
			fitT.setX32( y+((t_inside.getLength()*sqrt(3))/2) );
			Polygon polygon(fitT);
			shapes.push_back( polygon );
	
			if(circle_equation(c_container.getRadius()-t_inside.getLength(),y+h_triangle,c_container.getRadius())==1){
				fitT.setLength(t_inside.getLength());
				fitT.setX11(c_container.getRadius()-(t_inside.getLength()/2));
				fitT.setX12(y);
				fitT.setX21(c_container.getRadius());
				fitT.setX22(y+h_triangle);
				fitT.setX31(c_container.getRadius()-(t_inside.getLength()));
				fitT.setX32(y+h_triangle);
				Polygon polygon(fitT);
				shapes.push_back( polygon );
	
				fitT.setLength(t_inside.getLength());
				fitT.setX11(c_container.getRadius()+(t_inside.getLength()/2));
				fitT.setX12(y);
				fitT.setX21(c_container.getRadius());
				fitT.setX22(y+h_triangle);
				fitT.setX31(c_container.getRadius()+t_inside.getLength());
				fitT.setX32(y+h_triangle);
				Polygon polygon1(fitT);
				shapes.push_back( polygon1 );
			}
		}
		/*For height*/
		for(i=y;i+2*(h_triangle)<=2*c_container.getRadius()+h_triangle;i+=((t_inside.getLength()*sqrt(3.0))/2.0)){
				/*Left sides normal triangle.*/
			while(circle_equation((c_container.getRadius()-(t_inside.getLength()/2))-((static_cast<double>(counter)-1)*t_inside.getLength()),i+(2.0*h_triangle),c_container.getRadius())==1 &&
				  circle_equation(c_container.getRadius()-(static_cast<double>(counter)*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1){
				
					fitT.setLength(t_inside.getLength());
					fitT.setX11(c_container.getRadius()-((static_cast<double>(counter)-1)*t_inside.getLength()));
					fitT.setX12(y+(h_triangle*(line+1)));
					fitT.setX21(c_container.getRadius()-(static_cast<double>(counter)*t_inside.getLength()));
					fitT.setX22(y+(h_triangle*(line+1)));
					fitT.setX31(c_container.getRadius()-(t_inside.getLength()/2)-((counter-1)*t_inside.getLength()));
					fitT.setX32(y+((line+2)*h_triangle));
					Polygon polygon(fitT);
					shapes.push_back( polygon );

					counter++;
				}
				counter=1;
				/*Left sides reverse triangle.*/
				while(circle_equation((c_container.getRadius()-(t_inside.getLength()/2.0))-((static_cast<double>(counter)-1)*t_inside.getLength()),i+(h_triangle/2.0),c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()-((static_cast<double>(counter)-1)*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1 && i!=y){
					
					fitT.setLength(t_inside.getLength());
					fitT.setX11(c_container.getRadius()-(t_inside.getLength()/2)
					-((static_cast<double>(counter)-1)*t_inside.getLength())+(t_inside.getLength()/2.0));
					fitT.setX12(i);

					fitT.setX21(c_container.getRadius()-
					(static_cast<double>(counter)*t_inside.getLength())+(t_inside.getLength()/2.0));

					fitT.setX22(y+(h_triangle*(line+1.0)));

					fitT.setX31(c_container.getRadius()-
					((static_cast<double>(counter)-1)*t_inside.getLength())+(t_inside.getLength()/2.0));

					fitT.setX32(y+(h_triangle*(line+1)));
					Polygon polygon(fitT);
					shapes.push_back( polygon );
					counter++;
				
				}
				counter=1;
				/*Right sides normal triangle.*/
				while(circle_equation((c_container.getRadius()+(t_inside.getLength()/2.0))+((counter-1.0)*t_inside.getLength()),i+(2.0*h_triangle),c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()+(counter*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1){
				
				fitT.setLength(t_inside.getLength());
				fitT.setX11(c_container.getRadius()+((counter-1)*t_inside.getLength()));
				fitT.setX12(y+(h_triangle*(line+1)));
				fitT.setX21(c_container.getRadius()+(counter*t_inside.getLength()));
				fitT.setX22(y+(h_triangle*(line+1)));
				fitT.setX31(c_container.getRadius()+(t_inside.getLength()/2)+((counter-1)*t_inside.getLength()) );
				fitT.setX32(y+((line+2)*h_triangle));
				Polygon polygon(fitT);
				shapes.push_back( polygon );	


					counter++;
				}

				counter=1;
				/*Right sides reverse triangle.*/
				while(circle_equation((c_container.getRadius()+(t_inside.getLength()/2.0))+((static_cast<double>(counter)-1.0)*t_inside.getLength())+
					t_inside.getLength(),i+h_triangle,c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()+(static_cast<double>(counter)*t_inside.getLength()),
						i+h_triangle,c_container.getRadius())==1 && i!=y){

					fitT.setLength(t_inside.getLength());
					fitT.setX11(c_container.getRadius()+(t_inside.getLength()/2.0)+
						((static_cast<double>(counter)-1.0)*t_inside.getLength())+(t_inside.getLength()/2.0));
					fitT.setX12(i);
					fitT.setX21(c_container.getRadius()+(static_cast<double>(counter)*t_inside.getLength())+(t_inside.getLength()/2.0));
					fitT.setX22(y+(h_triangle*(line+1)));
					fitT.setX31(c_container.getRadius()+((static_cast<double>(counter)-1.0)*t_inside.getLength())+(t_inside.getLength()/2.0));
					fitT.setX32(y+(h_triangle*(line+1)));
					Polygon polygon(fitT);
					shapes.push_back( polygon );

					counter++;
				}
			counter=1;
			line++;
		}


	}

	void ComposedShape::optimalFit(Triangle t_container,Rectangle r_inside){
	
		double i,j;
		int temp;
		double line=0;
		double horizontal,vertical;
		double lineHorizontalLong;
		auto counter=0;
		decltype(r_inside) fitR;
		
		
		if(r_inside.getHeight() > r_inside.getWidth()){
			temp=r_inside.getWidth();
			r_inside.setWidth(r_inside.getHeight());
			r_inside.setHeight(temp);
		}
		/*It calculates the first coordinate to put.*/
		vertical = (r_inside.getWidth())/(2.0/(sqrt(3.0)));
		horizontal = (t_container.getLength()/2.0) - (r_inside.getWidth()/2.0); 

		lineHorizontalLong= (( ( ((line*r_inside.getHeight()) + ((r_inside.getWidth()/2)*sqrt(3.0))) ) /sqrt(3.0) ) *2) +horizontal;
		/*After that it calculates the other points with geometric calculations.*/
		for(i=vertical; (i+r_inside.getHeight()) <= t_container.getLength()*(sqrt(3.0)/2.0);i+=r_inside.getHeight()){
			for(j=horizontal; (j+r_inside.getWidth()) <= (lineHorizontalLong);j+=r_inside.getWidth()){
				fitR.setWidth(r_inside.getWidth());
				fitR.setHeight(r_inside.getHeight());
				fitR.setX(j);
				fitR.setY(i);
				Polygon polygon(fitR);
				shapes.push_back( polygon );
				counter++;
				
			}
			line++;
			horizontal -=(r_inside.getHeight()/sqrt(3.0));
			lineHorizontalLong= (( ( ((line*r_inside.getHeight()) + ((r_inside.getWidth()/2)*sqrt(3.0))) ) /sqrt(3.0) ) *2) +horizontal;
		}
	}

	void ComposedShape::optimalFit(Triangle t_container,Circle c_inside){
		double i,j;
		double linePoint = t_container.getLength()/2.0;
		int line=1,linecounter=1;
		auto counter=0;
		decltype(c_inside) fitC;
		

		/*It prints the circles with a spesific pattern.
			First it places the top and after that it goes to the bottom.*/
		for(i=2*c_inside.getRadius();(i+c_inside.getRadius())<=t_container.getLength()*(sqrt(3.0)/2.0);i=i+(c_inside.getRadius()*sqrt(3))){
			for(j=linePoint;linecounter<=line;j=j+(c_inside.getRadius()*2)){
				
				fitC.setRadius(c_inside.getRadius());
				fitC.setRadius(c_inside.getRadius());
				fitC.setX(j);
				fitC.setY(i);
	
				Polygon polygon(fitC);
				shapes.push_back( polygon );
				
				counter++;
				linecounter++;
			}
			line++;
			linecounter=1;
			linePoint-=c_inside.getRadius();
		}
		
	}

	void ComposedShape::optimalFit(Triangle t_container,Triangle t_inside){
		double i,j;
		double line=1.0;
		double linePoint = t_container.getLength()/2.0;
		auto counter=0;
		decltype(t_inside) fitT;

		/*It prints the triangles inside a triangle. It decreases the row width every 
		  line and it prints one normal one reverse triangle.*/
		for(i=0; i+((t_inside.getLength()*sqrt(3.0))/2.0) <= ( (t_container.getLength() * sqrt(3.0))/2.0 ) ; i+= ((t_inside.getLength()*sqrt(3.0))/2.0)){
			for(j=linePoint ; j <=((linePoint)+((line-1)*t_inside.getLength())) ; j+= t_inside.getLength()){
			fitT.setLength(t_inside.getLength());
			fitT.setX11(j);
			fitT.setX12(i);
			fitT.setX21(j-(t_inside.getLength()/2.0));
			fitT.setX22(i+t_inside.getLength()*(sqrt(3.0)/2.0));
			fitT.setX31( j+(t_inside.getLength()/2.0));
			fitT.setX32( i+t_inside.getLength()*(sqrt(3.0)/2.0) );
			Polygon polygon(fitT);
			shapes.push_back( polygon );

			counter++;
				if(line != 1 && j !=((linePoint)+((line-1)*t_inside.getLength()))){
					
					fitT.setLength(t_inside.getLength());
					fitT.setX11(j);
					fitT.setX12(i);
					fitT.setX21(j+t_inside.getLength());
					fitT.setX22(i);
					fitT.setX31( j+(t_inside.getLength()/2.0) );
					fitT.setX32( i+t_inside.getLength()*(sqrt(3.0)/2.0) );
					Polygon polygon(fitT);
					shapes.push_back( polygon );
				}
			}
			linePoint-=t_inside.getLength()/2.0;
			line++;
		}
	}
}




















