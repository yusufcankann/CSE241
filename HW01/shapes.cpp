#include "shapes.h"

#define PI 3.14159265

using namespace std;

/*It writes file circle codes as a container.*/
void containerCircleWriteFile(int radius,ofstream &inputStream){
	inputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<radius*2<<"\" height=\""<<radius*2<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< " <circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius
				<<"\" fill=\"red\" /> " << endl;
}
/*It writes file circle codes as a rectangle.*/
void containerRectangleWriteFile(int wContainer,int hContainer,ofstream &inputStream){
	inputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<wContainer<<"\" height=\""<<hContainer<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl 	
				<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;
}
/*It writes file circle codes as a triangle.*/
void containerTriangleWriteFile(double length,ofstream &inputStream){
	inputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<length<<"\" height=\""<<length<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl 	
				<< " <polygon points=\"" << length/2 << ",0 0,"<<length*(sqrt(3)/2)<<" "
				<< length << "," << length*(sqrt(3)/2) << "\" fill=\"red\"/> " << endl;
}


void containerRectangleInsideCircle(int wContainer,int hContainer,int radius,ofstream &inputStream){
	int i,j;
	int line=1;
	int condition1=0,condition2=0;
	int counter=0;
	/*First it calculates the most efficient way.
	  There is 2 way which is one under the other or cross way.*/
	for(i=radius;(i+radius)<=hContainer;i=i+(radius*sqrt(3))){
		for(j=radius;(j+radius)<=wContainer;j=j+(radius*2)){
			if(j==radius && line %2 == 0)
				j+=radius;
			condition1++;
		}
		line++;
	}	
	for(i=radius;(i+radius)<=hContainer;i=i+(radius*2)){
		for(j=radius;(j+radius)<=wContainer;j=j+(radius*2)){
			condition2++;	
		}
	}
	/*It writes the container.*/
	containerRectangleWriteFile(wContainer,hContainer,inputStream);

	/*It applies the cross condition.*/
	if(condition1 >= condition2){
		counter=condition1;
		for(i=radius;(i+radius)<=hContainer;i=i+(radius*sqrt(3))){
			for(j=radius;(j+radius)<=wContainer;j=j+(radius*2)){
				if(j==radius && line %2 == 0)
					j+=radius;
				inputStream << "<circle cx=\""<<j<<"\" cy=\""<<i<<"\" r=\""<<radius<<"\" fill=\"blue\" />"<< endl;
			}
			line++;
		}	
	}
	else{/*It applies the one under the other condition.*/
		counter=condition2;
		for(i=radius;(i+radius)<=hContainer;i=i+(radius*2)){
			for(j=radius;(j+radius)<=wContainer;j=j+(radius*2)){
				inputStream << "<circle cx=\""<<j<<"\" cy=\""<<i<<"\" r=\""<<radius<<"\" fill=\"blue\" />"<< endl;
			}
		}
	}
	cout<<"I can fit at most "<< counter <<" small shapes into the main container."
		<<"The empty area (red) in container is "<<(wContainer*hContainer) - (counter*pow(radius,2)*PI)<<endl;
	inputStream << "</svg>";
}

void containerRectangleInsideTriangle(double wContainer,double hContainer,double length, ofstream &inputStream){
	double i,j;
	int line = 1;
	int counter=0;
	/*It prints the background recrangle.*/
	containerRectangleWriteFile(wContainer,hContainer,inputStream);
	/*It writes the codes to file.
	  It prints triWangles one normal,one reverse.*/
	for(i=0 ; (i+ ((length*sqrt(3.0))/2.0) ) <= hContainer ; i+= (length*sqrt(3.0)/2.0) ){
		for(j=0; (j+ (length) ) <= wContainer ; j+=length ){
			inputStream << "<polygon points=\"" << j <<","<< i <<" "<<j+length<<","<<i <<" "
						<< j+(length/2) << "," << length*(sqrt(3)/2)+i << "\" style=\"fill:blue;stroke:pink;stroke-width:5\" /> " << endl;
			if( ( j+(length/2)+(length) )<= wContainer){
				inputStream << "<polygon points=\"" << j+length <<","<< i <<" "<<j+(length/2)<<","<<i+length*(sqrt(3)/2)<<" "
							<< j+length+(length/2) << "," << length*(sqrt(3)/2)+i << "\" style=\"fill:blue;stroke:pink;stroke-width:2\" /> " << endl;
					counter++;
				}
			counter++;
			}
		line++;
	}
	cout<<"I can fit at most "<< counter <<" small shapes into the main container. The empty area (red) in container is "
		<< (wContainer*hContainer)-( counter*((pow(length,2)*sqrt(3)) /4)    )<<endl;
	inputStream << "</svg>";
}

void containerRectangleInsideRectangle(int wContainer,int hContainer,int wSmall,int hSmall,ofstream &inputStream){	
	int i,j,k,l;
	int counter=0;
	/*It writes the file the background.*/
	containerRectangleWriteFile(wContainer,hContainer,inputStream);
	/*First it fill the main gaps.*/
	for(i=0; i+hSmall <= hContainer ; i+=hSmall){
		for(j=0; j+wSmall <= wContainer ; j+=wSmall){
			inputStream << "<rect x=\""<< j << "\" y=\""<< i <<"\" width=\""<<wSmall<<"\" height=\""
						<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
			counter++;
		}	
	}
	/*After that it controls the bottom,top,right and left sides and fills the gaps.*/
	if(i+hSmall > hContainer && (hContainer - i) >= wSmall && wContainer >= hSmall ){
		for(k=i;k+wSmall<=hContainer;k+=wSmall){
			for(l=0;l+hSmall<=wContainer;l+=hSmall){
				inputStream << "<rect x=\""<< l << "\" y=\""<< k <<"\" width=\""<<hSmall<<"\" height=\""<<wSmall
							<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
				counter++;
			}
		}
	}
	if( (j+wSmall > wContainer) && ((wContainer - j)) >= (hSmall && hContainer >= wSmall) ){
		for(k=0;k+wSmall<=hContainer;k+=wSmall){
			for(l=j;(l+hSmall)<=wContainer;l+=hSmall){
				inputStream << "<rect x=\""<< l << "\" y=\""<< k <<"\" width=\""<<hSmall<<"\" height=\""<<wSmall
							<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
				counter++;
			}
		}
	}
	cout<<"I can fit at most "<< counter <<" small shapes into the main container."
		<<"The empty area (red) in container is "<< 
			(wContainer*hContainer)-(counter*wSmall*hSmall)<<endl;
	inputStream << "</svg>";
}

void containerTriangleInsideTriangle(double length,double smallLength,ofstream &inputStream){
	
	double i,j;
	double line=1.0;
	double linePoint = length/2.0;
	int counter=0;
	containerTriangleWriteFile(length,inputStream);
	/*It prints the triangles inside a triangle. It decreases the row width every 
	  line and it prints one normal one reverse triangle.*/
	for(i=0; i+((smallLength*sqrt(3.0))/2.0) <= ( (length * sqrt(3.0))/2.0 ) ; i+= ((smallLength*sqrt(3.0))/2.0)){
		for(j=linePoint ; j <=((linePoint)+((line-1)*smallLength)) ; j+= smallLength){
			inputStream << "<polygon points=\"" << j <<","<< i <<" "<<j-(smallLength/2.0)<<","
							<<i+smallLength*(sqrt(3.0)/2.0)<<" "
							<< j+(smallLength/2.0) << "," << i+smallLength*(sqrt(3.0)/2.0) 
							<< "\" stroke=\"white\" fill=\"blue\"/> " << endl;
							counter++;
			if(line != 1 && j !=((linePoint)+((line-1)*smallLength))){
				inputStream << "<polygon points=\"" << j <<","<< i <<" "
							<<j+smallLength<<","<<i<<" "
							<< j+(smallLength/2.0) << "," << i+smallLength*(sqrt(3.0)/2.0)
							<<"\" stroke=\"white\" fill=\"blue\"/> " << endl;
							counter++;
			}
		}
		linePoint-=smallLength/2.0;
		line++;
	}
	if(length == smallLength)
		cout<<"I can fit at most "<< counter <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<"0"<<endl;
	else if(length < smallLength){
		cout<<"I can fit at most "<< counter <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<(pow(length,2)*sqrt(3)) /4<<endl;
	}
	else
		cout<<"I can fit at most "<< counter <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<( ((pow(length,2)*sqrt(3)) /4)-((pow(smallLength,2)*sqrt(3)) /4) )<<endl;	

	inputStream << "</svg>";
}

void containerTriangleInsideCircle(double length,int sradius,ofstream &inputStream){
	double i,j;
	double linePoint = length/2.0;
	int line=1,linecounter=1;
	int counter=0;
	containerTriangleWriteFile(length,inputStream);
	/*It prints the circles with a spesific pattern.
		First it places the top and after that it goes to the bottom.*/
	for(i=2*sradius;(i+sradius)<=length*(sqrt(3.0)/2.0);i=i+(sradius*sqrt(3))){
		for(j=linePoint;linecounter<=line;j=j+(sradius*2)){
			inputStream << "<circle cx=\""<<j<<"\" cy=\""<<i<<"\" r=\""<<sradius<<"\" fill=\"blue\" />"<< endl;
			counter++;
			linecounter++;
		}
		line++;
		linecounter=1;
		linePoint-=sradius;
	}
	cout<<"I can fit at most "<< counter <<" small shapes into the main container."
		<<"The empty area (red) in container is "<<( ((pow(length,2)*sqrt(3)) /4)-( counter*PI*pow(sradius,2) ) )<<endl;
	inputStream <<"</svg>";
}
/*I used trigonotmetric functions and calculations in here.*/
void containerTriangleInsideRectangle(double length,double wSmall, double hSmall,ofstream &inputStream){	
	double i,j;
	int temp;
	double line=0;
	double horizontal,vertical;
	double lineHorizontalLong;
	int counter=0;
	if(hSmall > wSmall){
		temp=wSmall;
		wSmall = hSmall;
		hSmall=temp;
	}
	/*It calculates the first coordinate to put.*/
	vertical = (wSmall)/(2.0/(sqrt(3.0)));
	horizontal = (length/2.0) - (wSmall/2.0); 
	containerTriangleWriteFile(length,inputStream);

	lineHorizontalLong= (( ( ((line*hSmall) + ((wSmall/2)*sqrt(3.0))) ) /sqrt(3.0) ) *2) +horizontal;
	/*After that it calculates the other points with geometric calculations.*/
	for(i=vertical; (i+hSmall) <= length*(sqrt(3.0)/2.0);i+=hSmall){
		for(j=horizontal; (j+wSmall) <= (lineHorizontalLong);j+=wSmall){
			inputStream << "<rect x=\""<< j << "\" y=\""<< i <<"\" width=\""<<wSmall<<"\" height=\""
			<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:1\"/>" << endl;
			counter++;
		}
		line++;
		horizontal -=(hSmall/sqrt(3.0));
		lineHorizontalLong= (( ( ((line*hSmall) + ((wSmall/2)*sqrt(3.0))) ) /sqrt(3.0) ) *2) +horizontal;
	}
	cout<<"I can fit at most "<< counter <<" small shapes into the main container."
		<<"The empty area (red) in container is "<<((pow(length,2)*sqrt(3)) /4)-(counter*wSmall*hSmall)<<endl;
	inputStream <<"</svg>";
}

/*
	This function works with rotation formules of point. 
	First it calculates the angle between 2 shape with cosinus theorem. After that it divides
  	that angle to 360 and finds how many circle must add this line.

	It does same thing for every line of circle.
*/
void containerCircleInsideCircle(double radius,double sradius,ofstream &inputStream){
	/*angle= angle between 2 circle.*/
	double angle;
	double anglee;
	double i,j;
	double x,y;/*Coordinates of circles.*/
	double x_t,y_t;/*For temprary coordinates.*/
	int number_of_circle;
	int counter=0;
	double sradius_temp,radius_temp;
	int counter_circle=0;
	
	/*COSINUS THEOREM C^2 = A^2+B^2+2AB*COS*/
	angle= acos(1.0 - ( pow( (2.0*sradius) , 2.0 ) ) / (2.0* pow( (radius-sradius),2.0 )) );
	anglee= (angle*180.0) / PI;
	number_of_circle = 360/anglee;
	
	containerCircleWriteFile(radius,inputStream); /*For the container circle.*/

	x=radius;
	y=sradius;
	radius_temp=radius;
	sradius_temp=sradius;
	/*First it add circle to most external part after that it comes to center of circle. */
	for(i=sradius_temp;i+sradius_temp*3<=(radius+2*sradius);i+=sradius_temp*2){
		for(j=0;j<=number_of_circle-(1);j++){
			x_t=x-radius;
			y_t=y-radius;
		/*Rotation formules*/
			x=x_t*cos(angle)-y_t*sin(angle);
			y=x_t*sin(angle)+y_t*cos(angle);
	
			x+=radius;
			y+=radius;	
			inputStream << " <circle cx=\""<<x<<"\" cy=\""<<y<<"\" r=\""<<sradius<<"\" fill=\"blue\" /> " << endl;
			counter_circle++;
		}
		/*This part does the same calculations for other interior part.*/
		radius_temp-=2*(sradius);
		counter++;
		x=radius;
		y=sradius+(2*counter*sradius);
		angle= acos(1.0 - ( pow( (2.0*sradius) , 2.0 ) ) / (2.0* pow( (radius_temp-sradius),2.0 )) );
		anglee= (angle*180.0) / PI;
		number_of_circle = 360/anglee;
	}
	
	if(sradius*2 == radius){
		inputStream << " <circle cx=\""<<radius<<"\" cy=\""<<radius-sradius<<"\" r=\""<<sradius<<"\" fill=\"blue\" /> " << endl;
		counter_circle=2;
	}
	
	if( radius - (i-sradius) > sradius){
		inputStream << " <circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<sradius<<"\" fill=\"blue\" /> " << endl;
		counter_circle++;
	}
	if(radius==sradius){
		cout<<"I can fit at most "<< 1 <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<"0"<<endl;
	}
	
	else if(counter_circle==0){
		cout<<"I can fit at most "<< counter_circle <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<( PI*pow(radius,2) )<<endl;
	}
	else
		cout<<"I can fit at most "<< counter_circle <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<( ( PI*pow(radius,2) )-( PI*pow(sradius,2)*counter_circle ))<<endl;

	inputStream <<"</svg>";
}

/*First the program creates a square inside a circle. After that it takes the rectangles inside the squares.
  After that if controls the empty area. */
void containerCircleInsideRectangle(double radius,double wSmall, double hSmall,ofstream &inputStream){
	
	double i,j,k,l;
	double square_side=sqrt(2.0)*radius;
	double square_x,square_y;
	double temp;
	double hSmall_t;
	int flag=0;
	int counter=0;
	hSmall_t=hSmall;
	

	square_y=radius-(square_side/2.0);
	square_x=square_y;

	containerCircleWriteFile(radius,inputStream); 
	/*It fits the squares inside a rectangle.*/
	for(i=square_y;i+hSmall<=square_side;i+=hSmall){
		for(j=square_x;j<=square_side+wSmall;j+=wSmall){
			if(pow((i-radius),2) +  pow((j+wSmall-radius),2) <= pow(radius,2) )
				inputStream << "<rect x=\""<< j << "\" y=\""<< i <<"\" width=\""<<wSmall<<"\" height=\""
							<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
				counter++;
		}
	}
	/*It controls the empty areas.*/
	if(hSmall > wSmall){
		temp=hSmall;
		hSmall=wSmall;
		wSmall=temp;
		flag=1;
	}
	
	for(k=square_y-hSmall;k>=0;k-=hSmall){
		for(l=square_x+wSmall;l<=2*radius;l+=wSmall){
			if( pow((k-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
				pow((k+hSmall-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
				pow((k+hSmall-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) &&
				pow((k-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) ){

				inputStream << "<rect x=\""<< l << "\" y=\""<< k <<"\" width=\""<<wSmall<<"\" height=\""
				<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
			}
		}	
	}
	if(flag==1)
		i+=6*hSmall;
	else
		i+=wSmall;

	for(k=i;k<=radius*2;k+=hSmall){
		for(l=radius-(square_side/2.0);l<=2*radius;l+=wSmall){
			if( pow((k-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
				pow((k+hSmall-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
				pow((k+hSmall-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) &&
				pow((k-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) ){

				inputStream << "<rect x=\""<< l << "\" y=\""<< k <<"\" width=\""<<wSmall<<"\" height=\""
				<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
			}
		}
	}
	if(flag==1){
		temp=hSmall;
		hSmall=wSmall;
		wSmall=temp;
	}
	if(flag==0 && hSmall < wSmall){
		temp=hSmall;
		hSmall=wSmall;
		wSmall=temp;
	}
	
	for(k=square_y+hSmall;k<=2*radius;k+=hSmall){
		for(l=radius-(square_side/2.0);l<=2*radius;l+=wSmall){
				if( pow((k-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
					pow((k+hSmall-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
					pow((k+hSmall-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) &&
					pow((k-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) ){

					inputStream << "<rect x=\""<< l << "\" y=\""<< k <<"\" width=\""<<wSmall<<"\" height=\""
					<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
				}
		}
	}
	for(k=square_y+hSmall_t;k<=radius*2;k+=hSmall){
		for(l=square_x-wSmall;l>=0;l-=wSmall){
			if( pow((k-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
				pow((k+hSmall-radius),2) +  pow((l-radius),2) <= pow(radius,2) &&
				pow((k+hSmall-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) &&
				pow((k-radius),2) +  pow((l+wSmall-radius),2) <= pow(radius,2) ){

				inputStream << "<rect x=\""<< l << "\" y=\""<< k <<"\" width=\""<<wSmall<<"\" height=\""
				<<hSmall<<"\" fill=\"blue\" style=\"fill:blue;stroke:pink;stroke-width:5\"/>" << endl;
			}
		}
	}
	
	if(counter == 0)
		cout<<"I can fit at most "<< counter <<" small shapes into the main container."
		<<"The empty area (red) in container is "<<(PI*pow(radius,2))<<endl;
	else
		cout<<"I can fit at most "<< counter <<" small shapes into the main container."
			<<"The empty area (red) in container is "<<( (PI*pow(radius,2)) - (counter*wSmall*hSmall) )<<endl;

	inputStream <<"</svg>";
}

/*Circle equation.*/
int circle_equation(double x,double y,double radius){
	if( pow(x-radius,2) + pow(y-radius,2) <= pow(radius,2) )
		return 1;
	else
		return 0;
}

/*It starts the center width of the circle and it fills right and left sides seperately.*/
void containerCircleInsideTriangle(double radius,double length,ofstream &inputStream){
	
	double i;
	double y;
	double h_triangle=(length*sqrt(3.0))/2.0;
	int line=0;
	int counter=1;
	containerCircleWriteFile(radius,inputStream); 
	
	y=sqrt(pow(radius,2)-pow(length/2,2))+radius;
	cout<<y;
	y=2*radius-y;

			if(circle_equation(radius,y+h_triangle,radius)==1){
	
				inputStream << "<polygon points=\"" << radius-(length/2) <<","<< y <<" "
					<<radius+(length/2)<<","<<y<<" "
					<< radius << "," << y+((length*sqrt(3))/2)
					<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
	
				if(circle_equation(radius-length,y+h_triangle,radius)==1){
					inputStream << "<polygon points=\"" << radius-(length/2) <<","
							<< y <<" "<<radius<<","<<y+h_triangle
							<<" "<< radius-(length) << ","<< y+h_triangle
							<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
					inputStream << "<polygon points=\"" << radius+(length/2) <<","
							<< y <<" "<<radius<<","<<y+h_triangle
							<<" "<< radius+(length) << ","<< y+h_triangle
							<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
				}
			}
			
	/*For height*/
	for(i=y;i+2*(h_triangle)<=2*radius+h_triangle;i+=((length*sqrt(3.0))/2.0)){
			/*Left sides normal triangle.*/
			while(circle_equation((radius-(length/2))-((static_cast<double>(counter)-1)*length),i+(2.0*h_triangle),radius)==1 &&
				  circle_equation(radius-(static_cast<double>(counter)*length),i+h_triangle,radius)==1){
				
				inputStream << "<polygon points=\"" << radius-((static_cast<double>(counter)-1)*length) <<","
							<< y+(h_triangle*(line+1)) <<" "
							<<radius-(static_cast<double>(counter)*length)<<","<<y+(h_triangle*(line+1))
							<<" "<< radius-(length/2)-((counter-1)*length) << "," 
							<< y+((line+2)*h_triangle)
							<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
				counter++;
			}
			counter=1;
			/*Left sides reverse triangle.*/
			while(circle_equation((radius-(length/2.0))-((static_cast<double>(counter)-1)*length),i+(h_triangle/2.0),radius)==1 &&
				  circle_equation(radius-((static_cast<double>(counter)-1)*length),i+h_triangle,radius)==1 && i!=y){
				inputStream << "<polygon points=\"" << radius-(length/2)-((static_cast<double>(counter)-1)*length)+(length/2.0) <<","
							<< i <<" "<<radius-(static_cast<double>(counter)*length)+(length/2.0)<<","<<y+(h_triangle*(line+1.0))
							<<" "<< radius-((static_cast<double>(counter)-1)*length)+(length/2.0) << "," 
							<< y+(h_triangle*(line+1))
							<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
				counter++;
			}
			counter=1;
			/*Right sides normal triangle.*/
			while(circle_equation((radius+(length/2.0))+((counter-1.0)*length),i+(2.0*h_triangle),radius)==1 &&
				  circle_equation(radius+(counter*length),i+h_triangle,radius)==1){
				
				inputStream << "<polygon points=\"" << radius+((counter-1)*length) 
							<< ","<< y+(h_triangle*(line+1)) <<" "
							<< radius+(counter*length)<<","<<y+(h_triangle*(line+1))
							<< " "<< radius+(length/2)+((counter-1)*length) 
							<< "," << y+((line+2)*h_triangle)
							<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
				counter++;
			}
			counter=1;
			/*Right sides reverse triangle.*/
			while(circle_equation((radius+(length/2.0))+((static_cast<double>(counter)-1.0)*length)+length,i+h_triangle,radius)==1 &&
				  circle_equation(radius+(static_cast<double>(counter)*length),i+h_triangle,radius)==1 && i!=y){
				inputStream << "<polygon points=\"" << radius+(length/2.0)+((static_cast<double>(counter)-1.0)*length)+(length/2.0) <<","
							<< i <<" "<<radius+(static_cast<double>(counter)*length)+(length/2.0)<<","<<y+(h_triangle*(line+1))
							<<" "<< radius+((static_cast<double>(counter)-1.0)*length)+(length/2.0) << "," 
							<< y+(h_triangle*(line+1))
							<< "\" style=\"fill:blue;stroke:pink;stroke-width:2\" />"<<endl;
				counter++;
			}
		counter=1;
		line++;
	}
	inputStream <<"</svg>";
}



