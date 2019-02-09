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
namespace MyShape{
	/*Constructors*/
	ComposedShape::ComposedShape():Shape(),container(nullptr),inner(nullptr)
	{ }
	ComposedShape::ComposedShape(Shape &container,Shape &inside):Shape(),
								container(&container),inner(&inside)
	{ }

	ComposedShape::ComposedShape(vector<Shape*> shapee)
								:Shape(){
		container=nullptr;
		inner=nullptr;
		for(auto i : shapee){
			shape.push_back(i);
		}	
	}

	ComposedShape::ComposedShape(vector<Shape*> shapee,Shape &containerr,Shape &innerr):Shape(){
		container=(&containerr);
		inner=(&innerr);
		for(auto i : shapee){
			shape.push_back(i);
		}	

	}

	/*copy constructor*/
	ComposedShape::ComposedShape(const ComposedShape &cs){
		for(auto a : shape){
			delete a;
		}
		shape.clear();

		Rectangle *rectangle;
		Circle *circle;
		Triangle *triangle;
	
		for(Shape *a: cs.getVector() ){
			rectangle=dynamic_cast<Rectangle*>(a);
			if(rectangle != nullptr){
				rectangle=new Rectangle;
				(*rectangle)=*(dynamic_cast<Rectangle*>(a));	
				shape.push_back(rectangle);
			}
		
			circle=dynamic_cast<Circle*>(a);
			if(circle != nullptr){
				circle = new Circle;
				(*circle)=*(dynamic_cast<Circle*>(a));	
				shape.push_back(circle);
			}

			triangle=dynamic_cast<Triangle*>(a);
			if(triangle != nullptr){
				triangle = new Triangle;
				(*triangle)=*(dynamic_cast<Triangle*>(a));	
				shape.push_back(triangle);
			}
		}
		/*I didn't delete the container and inner pointer because they deleted 
		  automatically by Rectangle,Triangle or circle destructor at the end of the program.*/	
		if(cs.getContainer() != container){
			rectangle=dynamic_cast<Rectangle*>(cs.getContainer());
			if(rectangle != nullptr){
				rectangle = new Rectangle;
				(*rectangle) =*(dynamic_cast<Rectangle*>( cs.getContainer()));	
				container = rectangle;
			}

			circle=dynamic_cast<Circle*>(cs.getContainer());
			if(circle != nullptr){
				circle = new Circle;
				(*circle) =*(dynamic_cast<Circle*>( cs.getContainer()));	
				container = circle;
			}

			triangle=dynamic_cast<Triangle*>(cs.getContainer());
			if(triangle != nullptr){
				triangle = new Triangle;
				(*triangle) =*(dynamic_cast<Triangle*>( cs.getContainer()));	
				container = triangle;
			}
		}	
		if(cs.getInner() != inner){
			rectangle=dynamic_cast<Rectangle*>(cs.getInner());
			if(rectangle != nullptr){
				rectangle = new Rectangle;
				(*rectangle) =*(dynamic_cast<Rectangle*>( cs.getInner()));	
				inner = rectangle;
			}

			circle=dynamic_cast<Circle*>(cs.getInner());
			if(circle != nullptr){
				circle = new Circle;
				(*circle) =*(dynamic_cast<Circle*>( cs.getInner()));	
				inner = circle;
			}
		
			triangle=dynamic_cast<Triangle*>(cs.getInner());
			if(triangle != nullptr){
				triangle = new Triangle;
				(*triangle) =*(dynamic_cast<Triangle*>( cs.getInner()));	
				inner = triangle;
			}
		}	
	}
	/*Assignemnt operator. Here i used downcasting.*/
	ComposedShape ComposedShape::operator=(ComposedShape &cs)throw(){
		for(auto a : shape){
			delete a;
		}
		shape.clear();

		Rectangle *rectangle;
		Circle *circle;
		Triangle *triangle;
	
		for(Shape *a: cs.getVector() ){
			rectangle=dynamic_cast<Rectangle*>(a);
			if(rectangle != nullptr){
				rectangle=new Rectangle;
				(*rectangle)=*(dynamic_cast<Rectangle*>(a));	
				shape.push_back(rectangle);
			}
	
			circle=dynamic_cast<Circle*>(a);
			if(circle != nullptr){
				circle = new Circle;
				(*circle)=*(dynamic_cast<Circle*>(a));	
				shape.push_back(circle);
			}
	
			triangle=dynamic_cast<Triangle*>(a);
			if(triangle != nullptr){
				triangle = new Triangle;
				(*triangle)=*(dynamic_cast<Triangle*>(a));	
				shape.push_back(triangle);
			}
			}
		/*I didn't delete the container and inner pointer because they deleted 
		  automatically by Rectangle,Triangle or circle destructor at the end of the program.*/	
		if(cs.getContainer() != container){
			rectangle=dynamic_cast<Rectangle*>(cs.getContainer());
			if(rectangle != nullptr){
				rectangle = new Rectangle;
				(*rectangle) =*(dynamic_cast<Rectangle*>( cs.getContainer()));	
				container = rectangle;
			}
		
		circle=dynamic_cast<Circle*>(cs.getContainer());
		if(circle != nullptr){
			circle = new Circle;
			(*circle) =*(dynamic_cast<Circle*>( cs.getContainer()));	
			container = circle;
			}

			triangle=dynamic_cast<Triangle*>(cs.getContainer());
			if(triangle != nullptr){
				triangle = new Triangle;
				(*triangle) =*(dynamic_cast<Triangle*>( cs.getContainer()));	
				container = triangle;
			}
		}	
		/*It controls the inner shapes equal or not. It not it assignes new one.*/
		if(cs.getInner() != inner){
			rectangle=dynamic_cast<Rectangle*>(cs.getInner());
			if(rectangle != nullptr){
				rectangle = new Rectangle;
				(*rectangle) =*(dynamic_cast<Rectangle*>( cs.getInner()));	
				inner = rectangle;
			}

			circle=dynamic_cast<Circle*>(cs.getInner());
			if(circle != nullptr){
				circle = new Circle;
				(*circle) =*(dynamic_cast<Circle*>( cs.getInner()));	
				inner = circle;
			}

			triangle=dynamic_cast<Triangle*>(cs.getInner());
			if(triangle != nullptr){
				triangle = new Triangle;
				(*triangle) =*(dynamic_cast<Triangle*>( cs.getInner()));	
				inner = triangle;
			}
		}	
		return *this;
	}

	double ComposedShape::area()const throw(){
		double sum=0;
		for(unsigned int i=0;i<shape.size();i++){
			sum=sum+ ( shape[i]->area() );
		}
		return sum;
	}
	double ComposedShape::perimeter()const throw(){
		double sum=0;
		for(unsigned int i=0;i<shape.size();i++){
			sum+=shape[i]->perimeter();
		}
		return sum;
	}

	Shape& ComposedShape::operator++() throw(){
		for(unsigned int i=0;i<shape.size();i++){
			(*shape[i])++;
		}
		return *this;
	}

	/*!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!
	*
	*	If you use this operator you have 
	*	to delete return adress manually!!!!!!!!!
	*
	*/
	Shape& ComposedShape::operator++(int IgnoreMe) throw(){
		ComposedShape *cs = new ComposedShape;
		*cs = (*this);
		for(unsigned int i=0;i<shape.size();i++){
			(*shape[i])++;
		}
		return *cs;
	}
	Shape& ComposedShape::operator--() throw(){
		for(unsigned int i=0;i<shape.size();i++){
			(*shape[i])--;
		}
		return *this;
	}
	/*!!!!!!!!!!!!!!!!!WARNING!!!!!!!!!!!!!!!!!
	*
	*	If you use this operator you have 
	*	to delete return adress manually!!!!!!!!!
	*
	*/
	Shape& ComposedShape::operator--(int IgnoreMe) throw(){
		ComposedShape *cs = new ComposedShape(*this);
		for(unsigned int i=0;i<shape.size();i++){
			(*shape[i])--;
		}
		return *cs;
	
	}

	Shape* ComposedShape::operator[](int index)throw(ExceptionError1){
		try{
			if(index<0)
				throw ExceptionError1(-1.);
	
			return (shape[index]);
		}
		catch(ExceptionError1 a){
			cout<<endl<<"Invalid Index!!"<<endl;
		}
		return (shape[index]);
	}

	const Shape* ComposedShape::operator[](int index)const throw(ExceptionError1){

		try{
			if(index<0)
				throw ExceptionError1(-1.);
	
			return (shape[index]);
		}
		catch(ExceptionError1 a){
			cout<<endl<<"Invalid Index!!"<<endl;
		}
		return (shape[index]);
	}

	/*These are draws the container shape in the svg file.*/
	void ComposedShape::DrawContainerRectangle(ostream &inputStream)const throw() {
		inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<(*(static_cast<Rectangle*>(container))).getWidth()<<"\" height=\""
			<<(*(static_cast<Rectangle*>(container))).getHeight()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"100%\" height=\"100%\" fill=\"red\" />" << endl;
	}
	void ComposedShape::DrawContainerTriangle(ostream &inputStream)const throw(){
		inputStream << "<svg version=\"1.1\" " << endl
			<<" baseProfile=\"full\" " << endl
			<< " width=\""<<(*(static_cast<Triangle*>(container))).getLength()<<"\" height=\""
			<<(*(static_cast<Triangle*>(container))).getLength()<<"\" " << endl
			<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl 	
			<< " <polygon points=\"" << (*(static_cast<Triangle*>(container))).getLength()/2 << ",0 0,"
			<<(*(static_cast<Triangle*>(container))).getLength()*(sqrt(3)/2)<<" "
			<< (*(static_cast<Triangle*>(container))).getLength() << "," 
			<< (*(static_cast<Triangle*>(container))).getLength()*(sqrt(3)/2) 
			<< "\" fill=\"red\"/> " << endl;
	}
	void ComposedShape::DrawContainerCircle(ostream &inputStream)const throw(){
		inputStream << "<svg version=\"1.1\" " << endl
				<<" baseProfile=\"full\" " << endl
				<< " width=\""<<(*(static_cast<Circle*>(container))).getRadius()*2<<"\" height=\""
				<<(*(static_cast<Circle*>(container))).getRadius()*2<<"\" " << endl
				<< " xmlns=\"http://www.w3.org/2000/svg\">" << endl
				<< " <circle cx=\""<<(*(static_cast<Circle*>(container))).getRadius()
				<<"\" cy=\""<<(*(static_cast<Circle*>(container))).getRadius()<<"\" r=\""
				<<(*(static_cast<Circle*>(container))).getRadius()
				<<"\" fill=\"red\" /> " << endl;
	}

	/*In here i used downcasting.*/
	ostream& operator<<(ostream &outputStream,ComposedShape &composed){
		Shape *temp = composed.getContainer();
		Rectangle *rectangle;
		Circle *circle;
		Triangle *triangle;

		rectangle=dynamic_cast<Rectangle*>(temp);
		if(rectangle != nullptr)
			composed.DrawContainerRectangle(outputStream);
	
		circle=dynamic_cast<Circle*>(temp);
		if(circle != nullptr)
			composed.DrawContainerCircle(outputStream);

		triangle=dynamic_cast<Triangle*>(temp);
		if(triangle != nullptr)
			composed.DrawContainerTriangle(outputStream);

		for(int i=0;i<composed.getVectorSize();i++)
			composed[i]->draw(outputStream);
	
		outputStream<<"</svg>";
		return outputStream;

	}

	/*getters*/
	int ComposedShape::getVectorSize()const throw(){
		return shape.size();
	}

	vector<Shape*> ComposedShape::getVector()const throw(){
		return shape;
	}

	Shape* ComposedShape::getContainer()const throw(){
		return container;
	}
	Shape* ComposedShape::getInner()const throw(){
		return inner;
	}

	void ComposedShape::draw(ostream &outputStream)throw(){
		outputStream<<(*this);
	}

	ComposedShape::~ComposedShape(){	

			for(auto a:shape)
				delete a;
	
		/*I didn't delete the container and inner pointer because they deleted 
		  automatically by Rectangle,Triangle or circle destructor at the end of the program.*/	
	}

	Shape* ComposedShape::operator+=(Shape *shapee)throw(){
		shape.push_back(shapee);
			return shape[getVectorSize()];
	}











	/*-----------------------------------------------OPTIMAL FIT FUNCTİON OVERLOADS----------------------------------------------------*/
	/*Overloaded optimal fit functions for each cases.*/


		void ComposedShape::optimalFit(Rectangle r_container,Rectangle r_inside)throw(){
			int i,j,k,l;
			auto counter=0;
			Rectangle *rec;

		/*It calculates and adds small shapes to the vector*/

			for(i=0; i+(r_inside.getHeight()) <= r_container.getHeight() ; i+=r_inside.getHeight() ){
				for(j=0; j+ (r_inside.getWidth() ) <= r_container.getWidth() ; j+=(r_inside.getWidth() )){
					rec = new Rectangle; 
					rec->setX(j);
					rec->setY(i);
					rec->setWidth( r_inside.getWidth() );
					rec->setHeight( r_inside.getHeight() );
					shape.push_back(rec);
					counter++;
					//rec.increase_total_area();
					//rec.increase_perimeter();
				
				}	
			}
			/*After that it controls the bottom,top,right and left sides and fills the gaps.*/
			if(i+(r_inside.getHeight()) > r_container.getHeight() && (r_container.getHeight() - i) >= r_inside.getWidth() && r_container.getWidth() >= r_inside.getHeight() ){
				for(k=i;k+ (r_inside.getWidth()) <= r_container.getHeight() ; k+=(r_inside.getWidth() ) ){
					for(l=0;l+r_inside.getHeight()<=r_container.getWidth();l+=r_inside.getHeight()){
						rec = new Rectangle;	
						rec->setX(l);
						rec->setY(k);
						rec->setWidth( r_inside.getHeight() );
						rec->setHeight( r_inside.getWidth() );
						shape.push_back(rec);
						counter++;
						//rec.increase_total_area();
						//rec.increase_perimeter();
					}
				}
			}
			if( (j+r_inside.getWidth() > r_container.getWidth()) && ((r_container.getWidth() - j)) >= (r_inside.getHeight() && r_container.getHeight() >= r_inside.getWidth() ) ){
				for(k=0;k+r_inside.getWidth() <= r_container.getHeight() ;k+=r_inside.getWidth()){
					for(l=j ; (l+r_inside.getHeight()) <= r_container.getWidth() ;l+=r_inside.getHeight()){
						rec = new Rectangle;	
						rec->setX(l);
						rec->setY(k);
						rec->setWidth( r_inside.getHeight() );
						rec->setHeight( r_inside.getWidth() );
						shape.push_back(rec);
						counter++;
						//rec.increase_total_area();
						//rec.increase_perimeter();
					}
				}
			}
		}

		void ComposedShape::optimalFit(Rectangle r_container,Circle c_inside)throw(){
			int i,j;
			auto line=1;
			auto condition1=0,condition2=0;
			decltype(c_inside) fitC;
		
			Circle *circle;		
		
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
						circle= new Circle;	 
						if(j==c_inside.getRadius() && line %2 == 0)
							j+=c_inside.getRadius();

						 circle->setRadius(c_inside.getRadius());
						 circle->setX(j);
						 circle->setY(i);
						shape.push_back(circle);
						 //circle.increase_total_area();
						 //circle.increase_perimeter();
					}
					line++;
				}	
			}
			else{/*It applies the one under the other condition.*/
				for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+(c_inside.getRadius()*2)){
					for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
						circle= new Circle;	 
						 circle->setRadius(c_inside.getRadius());
						 circle->setX(j);
						 circle->setY(i);
						 shape.push_back(circle);
						 //circle.increase_total_area();
						 //circle.increase_perimeter();
					}
				}
			}
		}

		void ComposedShape::optimalFit(Rectangle r_container,Triangle t_inside)throw(){
			double i,j;
			auto line = 1;
			auto counter=0;
			decltype(t_inside) fitT;

			Triangle *triangle;

	/*It calculates and after that it adds small shape to the vector.*/
			for(i=0 ; (i+ ((t_inside.getLength()*sqrt(3.0))/2.0) ) <= r_container.getHeight() ; i+= (t_inside.getLength()*sqrt(3.0)/2.0) ){
				for(j=0; (j+ (t_inside.getLength()) ) <= r_container.getWidth() ; j+=t_inside.getLength() ){
					triangle = new Triangle;		 
					triangle->setLength(t_inside.getLength());
					triangle->setX1(j);
					triangle->setY1(i);
					triangle->setX2(j+t_inside.getLength());
					triangle->setY2(i);
					triangle->setX3( j+(t_inside.getLength()/2));
					triangle->setY3( t_inside.getLength()*(sqrt(3)/2)+i );
					shape.push_back(triangle);
					//triangle.increase_total_area();
					//triangle.increase_perimeter();
					/*Reverse triangle calculation.*/
					if( ( j+(t_inside.getLength()/2)+(t_inside.getLength()) ) <= r_container.getWidth()){
						triangle = new Triangle;		 
						triangle->setLength(t_inside.getLength());
						triangle->setX1(j+t_inside.getLength());
						triangle->setY1(i);
						triangle->setX2(j+t_inside.getLength()/2);
						triangle->setY2(i+t_inside.getLength()*(sqrt(3)/2));
						triangle->setX3( j+t_inside.getLength()+(t_inside.getLength()/2) );
						triangle->setY3( t_inside.getLength()*(sqrt(3)/2)+i );
						shape.push_back(triangle);
						////triangle.increase_total_area();
						////triangle.increase_perimeter();

							counter++;
						}
					counter++;
					}
				line++;
			}

		}
	
		void ComposedShape::optimalFit(Circle c_container,Rectangle r_inside)throw(){
			double i,j,k,l;
			double square_side=sqrt(2.0)*c_container.getRadius();
			double square_x,square_y;
			double temp;
			double hSmall_t;
			int flag=0;
			auto counter=0;
			hSmall_t=r_inside.getHeight();
			decltype(r_inside) fitR;
			Rectangle *rec;

			square_y=c_container.getRadius()-(square_side/2.0);
			square_x=square_y;


			for(i=square_y;i+r_inside.getHeight()<=square_side;i+=r_inside.getHeight()){
				for(j=square_x;j<=square_side+r_inside.getWidth();j+=r_inside.getWidth()){
					if(pow((i-c_container.getRadius()),2) +  pow((j+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ) {
						rec=new Rectangle;		 
						rec->setWidth(r_inside.getWidth());
						rec->setHeight(r_inside.getHeight());
						rec->setX(j);
						rec->setY(i);
						shape.push_back(rec);
						counter++;
						//rec.increase_total_area();
						//rec.increase_perimeter();
		            }
				}
			}
		/*
			After here the function changes width and height and it controls the empty areas for filling the gap.
			When it change width and height it finds the empty area more.
		*/
			/*It controls the empty areas.*/
			if(r_inside.getHeight() > r_inside.getWidth()){
				temp=rec->getHeight();
				rec->setHeight(r_inside.getWidth());
				rec->setWidth(temp);
				flag=1;
			}
		/*It fills the empty areas.*/
			for(k=square_y-r_inside.getHeight();k>=0;k-=r_inside.getHeight()){
				for(l=square_x+r_inside.getWidth();l<=2*c_container.getRadius();l+=r_inside.getWidth()){
					rec=new Rectangle;		 
					if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){
					
						rec->setWidth(r_inside.getWidth());
						rec->setHeight(r_inside.getHeight());
						rec->setX(l);
						rec->setY(k);
						shape.push_back(rec);
						//rec.increase_total_area();
						//rec.increase_perimeter();
					}
				}	
			}
			if(flag==1)
				i+=6* rec->getHeight();
			else
				i+=rec->getWidth();

			for(k=i;k<=c_container.getRadius()*2;k+=r_inside.getHeight()){
				for(l=c_container.getRadius()-(square_side/2.0);l<=2*c_container.getRadius();l+=r_inside.getWidth()){
					rec=new Rectangle;		 
					if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){

						rec->setWidth(r_inside.getWidth());
						rec->setHeight(r_inside.getHeight());
						rec->setX(l);
						rec->setY(k);
						shape.push_back(rec);
						//rec.increase_total_area();
						//rec.increase_perimeter();
					}
				}
			}
			if(flag==1){
				temp=r_inside.getHeight();
				rec->setHeight(r_inside.getWidth());
				rec->setWidth(temp);
			}
			if(flag==0 && r_inside.getHeight() < r_inside.getWidth()){
				temp=r_inside.getHeight();
				rec->setHeight(r_inside.getWidth());
				rec->setWidth(temp);
			}
	
			for(k=square_y+r_inside.getHeight();k<=2*c_container.getRadius();k+=r_inside.getHeight()){
				for(l=c_container.getRadius()-(square_side/2.0);l<=2*c_container.getRadius();l+=r_inside.getWidth()){
						rec=new Rectangle;		 
						if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
							pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
							pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
							pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){

							rec->setWidth(r_inside.getWidth());
							rec->setHeight(r_inside.getHeight());
							rec->setX(l);
							rec->setY(k);
							shape.push_back(rec);
							//rec.increase_total_area();
							//rec.increase_perimeter();
						}
				}
			}
			for(k=square_y+hSmall_t;k<=c_container.getRadius()*2;k+=r_inside.getHeight()){
				for(l=square_x-r_inside.getWidth();l>=0;l-=r_inside.getWidth()){
					rec=new Rectangle;		 
					if( pow((k-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) &&
						pow((k-c_container.getRadius()),2) +  pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= pow(c_container.getRadius(),2) ){

						rec->setWidth(r_inside.getWidth());
						rec->setHeight(r_inside.getHeight());
						rec->setX(l);
						rec->setY(k);
						shape.push_back(rec);
						//rec.increase_total_area();
						//rec.increase_perimeter();
					}
				}
			}

		}

		void ComposedShape::optimalFit(Circle c_container,Circle c_inside)throw(){
	
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
		
			Circle *circle;

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
					circle= new Circle;		 
					x_t=x-c_container.getRadius();
					y_t=y-c_container.getRadius();
				/*Rotation formules*/
					x=x_t*cos(angle)-y_t*sin(angle);
					y=x_t*sin(angle)+y_t*cos(angle);
	
					x+=c_container.getRadius();
					y+=c_container.getRadius();	
	
					 circle->setX(x);
					 circle->setY(y);
					 circle->setRadius(c_inside.getRadius());
					shape.push_back(circle);
					 //circle.increase_total_area();
					 //circle.increase_perimeter();

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
				circle= new Circle;		 
				 circle->setX(c_container.getRadius());
				 circle->setY(c_container.getRadius()-c_inside.getRadius());
				 circle->setRadius(c_inside.getRadius());
				shape.push_back(circle);
				counter_circle=2;
				 //circle.increase_total_area();
				 //circle.increase_perimeter();
			}
	
			if( c_container.getRadius()- (i-c_inside.getRadius()) > c_inside.getRadius()){
				circle= new Circle;		 
				 circle->setX(c_container.getRadius());
				 circle->setY(c_container.getRadius());
				 circle->setRadius(c_inside.getRadius());
				shape.push_back(circle);
				counter_circle++;
				 //circle.increase_total_area();
				 //circle.increase_perimeter();
			}

		
		}

		void ComposedShape::optimalFit(Circle c_container,Triangle t_inside)throw(){

			double i;
			double y;
			double h_triangle=(t_inside.getLength()*sqrt(3.0))/2.0;
			int line=0;
			auto counter=1;
			decltype(t_inside) fitT;

			Triangle *triangle;

		/*First it calculates the y coordinate because i started the filling the gaps from center and with reverse radius.*/
			y=sqrt(pow(c_container.getRadius(),2)-pow(t_inside.getLength()/2,2))+c_container.getRadius();
			y=2*c_container.getRadius()-y;
		/*It controls the situations with circle equation formules.*/
			if(circle_equation(c_container.getRadius(),y+h_triangle,c_container.getRadius())==1){
				triangle = new Triangle;		 
				triangle->setLength(t_inside.getLength());
				triangle->setX1(c_container.getRadius()-(t_inside.getLength()/2));
				triangle->setY1(y);
				triangle->setX2(c_container.getRadius()+(t_inside.getLength()/2));
				triangle->setY2(y);
				triangle->setX3( c_container.getRadius());
				triangle->setY3( y+((t_inside.getLength()*sqrt(3))/2) );
				shape.push_back(triangle );
				//triangle.increase_total_area();
				//triangle.increase_perimeter();
	
				if(circle_equation(c_container.getRadius()-t_inside.getLength(),y+h_triangle,c_container.getRadius())==1){
					triangle = new Triangle;		 
					triangle->setLength(t_inside.getLength());
					triangle->setX1(c_container.getRadius()-(t_inside.getLength()/2));
					triangle->setY1(y);
					triangle->setX2(c_container.getRadius());
					triangle->setY2(y+h_triangle);
					triangle->setX3(c_container.getRadius()-(t_inside.getLength()));
					triangle->setY3(y+h_triangle);
					shape.push_back(triangle );
					//triangle.increase_total_area();
					//triangle.increase_perimeter();
	
					triangle = new Triangle;		 
					triangle->setLength(t_inside.getLength());
					triangle->setX1(c_container.getRadius()+(t_inside.getLength()/2));
					triangle->setY1(y);
					triangle->setX2(c_container.getRadius());
					triangle->setY2(y+h_triangle);
					triangle->setX3(c_container.getRadius()+t_inside.getLength());
					triangle->setY3(y+h_triangle);
					shape.push_back(triangle );
					//triangle.increase_total_area();
					//triangle.increase_perimeter();
				}
			}
			/*For height*/
			for(i=y;i+2*(h_triangle)<=2*c_container.getRadius()+h_triangle;i+=((t_inside.getLength()*sqrt(3.0))/2.0)){
					/*Left sides normal triangle.*/
				while(circle_equation((c_container.getRadius()-(t_inside.getLength()/2))-((static_cast<double>(counter)-1)*t_inside.getLength()),i+(2.0*h_triangle),c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()-(static_cast<double>(counter)*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1){
						triangle = new Triangle;		 
						triangle->setLength(t_inside.getLength());
						triangle->setX1(c_container.getRadius()-((static_cast<double>(counter)-1)*t_inside.getLength()));
						triangle->setY1(y+(h_triangle*(line+1)));
						triangle->setX2(c_container.getRadius()-(static_cast<double>(counter)*t_inside.getLength()));
						triangle->setY2(y+(h_triangle*(line+1)));
						triangle->setX3(c_container.getRadius()-(t_inside.getLength()/2)-((counter-1)*t_inside.getLength()));
						triangle->setY3(y+((line+2)*h_triangle));
						shape.push_back(triangle );
						//triangle.increase_total_area();
						//triangle.increase_perimeter();

						counter++;
					}
					counter=1;
					/*Left sides reverse triangle.*/
					while(circle_equation((c_container.getRadius()-(t_inside.getLength()/2.0))-((static_cast<double>(counter)-1)*t_inside.getLength()),i+(h_triangle/2.0),c_container.getRadius())==1 &&
						  circle_equation(c_container.getRadius()-((static_cast<double>(counter)-1)*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1 && i!=y){
						triangle = new Triangle;		 
						triangle->setLength(t_inside.getLength());
						triangle->setX1(c_container.getRadius()-(t_inside.getLength()/2)
						-((static_cast<double>(counter)-1)*t_inside.getLength())+(t_inside.getLength()/2.0));
						triangle->setY1(i);

						triangle->setX2(c_container.getRadius()-
						(static_cast<double>(counter)*t_inside.getLength())+(t_inside.getLength()/2.0));

						triangle->setY2(y+(h_triangle*(line+1.0)));

						triangle->setX3(c_container.getRadius()-
						((static_cast<double>(counter)-1)*t_inside.getLength())+(t_inside.getLength()/2.0));

						triangle->setY3(y+(h_triangle*(line+1)));
						shape.push_back(triangle);
						counter++;
						//triangle.increase_total_area();
						//triangle.increase_perimeter();
					}
					counter=1;
					/*Right sides normal triangle.*/
					while(circle_equation((c_container.getRadius()+(t_inside.getLength()/2.0))+((counter-1.0)*t_inside.getLength()),i+(2.0*h_triangle),c_container.getRadius())==1 &&
						  circle_equation(c_container.getRadius()+(counter*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1){
					triangle = new Triangle;		 
					triangle->setLength(t_inside.getLength());
					triangle->setX1(c_container.getRadius()+((counter-1)*t_inside.getLength()));
					triangle->setY1(y+(h_triangle*(line+1)));
					triangle->setX2(c_container.getRadius()+(counter*t_inside.getLength()));
					triangle->setY2(y+(h_triangle*(line+1)));
					triangle->setX3(c_container.getRadius()+(t_inside.getLength()/2)+((counter-1)*t_inside.getLength()) );
					triangle->setY3(y+((line+2)*h_triangle));
					shape.push_back(triangle);
					//triangle.increase_total_area();
					//triangle.increase_perimeter();


						counter++;
					}

					counter=1;
					/*Right sides reverse triangle.*/
					while(circle_equation((c_container.getRadius()+(t_inside.getLength()/2.0))+((static_cast<double>(counter)-1.0)*t_inside.getLength())+
						t_inside.getLength(),i+h_triangle,c_container.getRadius())==1 &&
						  circle_equation(c_container.getRadius()+(static_cast<double>(counter)*t_inside.getLength()),
							i+h_triangle,c_container.getRadius())==1 && i!=y){
						triangle = new Triangle;		 
						triangle->setLength(t_inside.getLength());
						triangle->setX1(c_container.getRadius()+(t_inside.getLength()/2.0)+
							((static_cast<double>(counter)-1.0)*t_inside.getLength())+(t_inside.getLength()/2.0));
						triangle->setY1(i);
						triangle->setX2(c_container.getRadius()+(static_cast<double>(counter)*t_inside.getLength())+(t_inside.getLength()/2.0));
						triangle->setY2(y+(h_triangle*(line+1)));
						triangle->setX3(c_container.getRadius()+((static_cast<double>(counter)-1.0)*t_inside.getLength())+(t_inside.getLength()/2.0));
						triangle->setY3(y+(h_triangle*(line+1)));
						shape.push_back(triangle);
						//triangle.increase_total_area();
						//triangle.increase_perimeter();

						counter++;
					}
				counter=1;
				line++;
			}


		}

		void ComposedShape::optimalFit(Triangle t_container,Rectangle r_inside)throw(){
	
			double i,j;
			int temp;
			double line=0;
			double horizontal,vertical;
			double lineHorizontalLong;
			auto counter=0;
			decltype(r_inside) fitR;
		
			Rectangle *rec;
		
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
					rec=new Rectangle;		 
					rec->setWidth(r_inside.getWidth());
					rec->setHeight(r_inside.getHeight());
					rec->setX(j);
					rec->setY(i);
					shape.push_back(  rec );
					counter++;
					//rec.increase_total_area();
					//rec.increase_perimeter();
				}
				line++;
				horizontal -=(r_inside.getHeight()/sqrt(3.0));
				lineHorizontalLong= (( ( ((line*r_inside.getHeight()) + ((r_inside.getWidth()/2)*sqrt(3.0))) ) /sqrt(3.0) ) *2) +horizontal;
			}
		}

		void ComposedShape::optimalFit(Triangle t_container,Circle c_inside)throw(){
			double i,j;
			double linePoint = t_container.getLength()/2.0;
			int line=1,linecounter=1;
			auto counter=0;
			decltype(c_inside) fitC;
		
			Circle *circle;
		

			/*It prints the circles with a spesific pattern.
				First it places the top and after that it goes to the bottom.*/
			for(i=2*c_inside.getRadius();(i+c_inside.getRadius())<=t_container.getLength()*(sqrt(3.0)/2.0);i=i+(c_inside.getRadius()*sqrt(3))){
				for(j=linePoint;linecounter<=line;j=j+(c_inside.getRadius()*2)){
				
					circle= new Circle;		 
				
					 circle->setRadius(c_inside.getRadius());
					 circle->setRadius(c_inside.getRadius());
					 circle->setX(j);
					 circle->setY(i);
	
					shape.push_back(circle);
					 //circle.increase_total_area();
					 //circle.increase_perimeter();
				
					counter++;
					linecounter++;
				}
				line++;
				linecounter=1;
				linePoint-=c_inside.getRadius();
			}
		
		}

		void ComposedShape::optimalFit(Triangle t_container,Triangle t_inside)throw(){
			double i,j;
			double line=1.0;
			double linePoint = t_container.getLength()/2.0;
			auto counter=0;
			decltype(t_inside) fitT;
		
			Triangle *triangle;

			/*It prints the triangles inside a triangle. It decreases the row width every 
			  line and it prints one normal one reverse triangle.*/
			for(i=0; i+((t_inside.getLength()*sqrt(3.0))/2.0) <= ( (t_container.getLength() * sqrt(3.0))/2.0 ) ; i+= ((t_inside.getLength()*sqrt(3.0))/2.0)){
				for(j=linePoint ; j <=((linePoint)+((line-1)*t_inside.getLength())) ; j+= t_inside.getLength()){
				triangle = new Triangle;	 
				triangle->setLength(t_inside.getLength());
				triangle->setX1(j);
				triangle->setY1(i);
				triangle->setX2(j-(t_inside.getLength()/2.0));
				triangle->setY2(i+t_inside.getLength()*(sqrt(3.0)/2.0));
				triangle->setX3( j+(t_inside.getLength()/2.0));
				triangle->setY3( i+t_inside.getLength()*(sqrt(3.0)/2.0) );
				shape.push_back(triangle);
				//triangle.increase_total_area();
				//triangle.increase_perimeter();

				counter++;
					if(line != 1 && j !=((linePoint)+((line-1)*t_inside.getLength()))){
						triangle = new Triangle;		 
						triangle->setLength(t_inside.getLength());
						triangle->setX1(j);
						triangle->setY1(i);
						triangle->setX2(j+t_inside.getLength());
						triangle->setY2(i);
						triangle->setX3( j+(t_inside.getLength()/2.0) );
						triangle->setY3( i+t_inside.getLength()*(sqrt(3.0)/2.0) );
						shape.push_back(triangle);
						//triangle.increase_total_area();
						//triangle.increase_perimeter();
					}
				}
				linePoint-=t_inside.getLength()/2.0;
				line++;
			}
	}
	void ComposedShape::optimalFit()throw(){
		Rectangle *rectangle_c, *rectangle_i;
		Circle *circle_c, *circle_i;
		Triangle *triangle_c, *triangle_i;

		rectangle_c=dynamic_cast<Rectangle*>(container);
		circle_c=dynamic_cast<Circle*>(container);
		triangle_c=dynamic_cast<Triangle*>(container);
	
		rectangle_i=dynamic_cast<Rectangle*>(inner);
		circle_i=dynamic_cast<Circle*>(inner);
		triangle_i=dynamic_cast<Triangle*>(inner);

		if(rectangle_c != nullptr && rectangle_i != nullptr)
			optimalFit(*rectangle_c,*rectangle_i);
		else if(rectangle_c != nullptr && circle_i != nullptr)
			optimalFit(*rectangle_c,*circle_i);
		else if(rectangle_c != nullptr && triangle_i != nullptr)
			optimalFit(*rectangle_c,*triangle_i);
		else if(circle_c != nullptr && rectangle_i != nullptr)
			optimalFit(*circle_c,*rectangle_i);
		else if(circle_c != nullptr && circle_i != nullptr)
			optimalFit(*circle_c,*circle_i);
		else if(circle_c != nullptr && triangle_i != nullptr)
			optimalFit(*circle_c,*triangle_i);
		else if(triangle_c != nullptr && rectangle_i != nullptr)
			optimalFit(*triangle_c,*rectangle_i);
		else if(triangle_c != nullptr && circle_i != nullptr)
			optimalFit(*triangle_c,*circle_i);
		else if(triangle_c != nullptr && triangle_i != nullptr)
			optimalFit(*triangle_c,*triangle_i);

	}

}


















