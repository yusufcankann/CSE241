import java.awt.Graphics;

/**
 * ComposedShape class that takes 2 shape and composes them.
 * @author Yusuf Can
 *
 */
public class ComposedShape implements Shape {
	
	/**
	 * Inner shapes.
	 */
	private Shape[] shapes;
	
	/**
	 * size of inner shapes.
	 */
	private int size=0;
	
	/**
	 * container shape.
	 */
	private Shape container;
	
	/**
	 * inner shape.
	 */
	private Shape inner;
	
	/**
	 * Simple constructer.
	 */
	public ComposedShape() {
		shapes = null;
		container = null;
		inner = null;
	}
	
	/**
	 * Simple constructer that sets inner and container shapes.
	 * @param container_ container shape.
	 * @param inner_ inner shape.
	 */
	public ComposedShape(Shape container_,Shape inner_){
		shapes=null;
		container = container_;
		inner = inner_;
	}
	
	/**
	 * Getter method for inner shapes.
	 * @return inner shapes.
	 */
	public Shape[] getShapes(){ return shapes; }
	
	/**
	 * Getter method for inner shapes count.
	 * @return inner shapes count.
	 */
	public int getSize(){ return size; }
	
	/**
	 * Getter method for container shape.
	 * @return container shape.
	 */
	public Shape getContainer(){ return container; }
	
	/**
	 * Getter method for inner shape.
	 * @return inner shape.
	 */
	public Shape getInner() { return inner; }
	
	/**
	 * Setter method for conainer shape.
	 * @param container_ container shape.
	 */
	public void setContainer(Shape container_){
		container = container_;
	}
	
	/**
	 * Setter method for inner shape.
	 * @param inner_ inner shape.
	 */
	public void setInner(Shape inner_){
		inner = inner_;
	}
	
	@Override
	public double area()
			throws NullPointerException{
		double sum = 0;
		if(shapes == null)
			throw new NullPointerException();
		
		for(int i=0;i<size;i++)
			sum+= shapes[i].area();
		
		return sum;
	}

	@Override
	public double perimeter()
			throws NullPointerException{
		double sum = 0;
		if(shapes == null)
			throw new NullPointerException();
		
		for(int i=0;i<size;i++)
			sum+= shapes[i].perimeter();
		
		return sum;
	}

	@Override
	public void increment()
			throws NullPointerException{
		if(shapes == null)
			throw new NullPointerException();
		
		for(int i=0;i<size;i++)
			shapes[i].increment();
	}

	@Override
	public void decrement() 
			throws NullPointerException{
		if(shapes == null)
			throw new NullPointerException();
		
		for(int i=0;i<size;i++)
			shapes[i].decrement();
	}

	@Override
	public void draw(Graphics g) 
			throws NullPointerException{
		if(shapes == null)
			throw new NullPointerException();
		
		for(int i=0;i<size;i++){
			shapes[i].draw(g);
		}
	}

	@Override
	public int compareTo(Shape o) {
		if( o.area() == this.area() ) return 1;
		else return 0;
	}
	
	/**
	 * Adds element to the inner shapes array.
	 * @param shape_ element which is goint to be added.
	 * @throws CloneNotSupportedException Clone method exception.
	 */
	public void add(Shape shape_) throws CloneNotSupportedException{
		if(shapes == null){
			if(shape_ instanceof Circle){
				shapes = new Circle[1];
				shapes[0] = ((Circle) shape_).clone();
			}
			else if(shape_ instanceof Rectangle){
				shapes = new Rectangle[1];
				shapes[0] = ((Rectangle) shape_).clone();
			}
			else if(shape_ instanceof Triangle){
				shapes = new Triangle[1];
				shapes[0] = ((Triangle) shape_).clone();
			}
		}
		else{
			if(shapes[0] instanceof Circle){
				Circle[] temp = new Circle[size];
				for(int i=0;i<size;i++){
					temp[i] = ((Circle)shapes[i]).clone();
				}
				
				shapes = new Circle[size+1];
				
				for(int i=0;i<size;i++){
					shapes[i] = temp[i];
				}
				shapes[size] = ((Circle)shape_).clone();
			}
			else if(shapes[0] instanceof Rectangle){
				Rectangle[] temp = new Rectangle[size];
				for(int i=0;i<size;i++){
					temp[i] = ((Rectangle)shapes[i]).clone();
				}
				
				shapes = new Rectangle[size+1];
				
				for(int i=0;i<size;i++){
					shapes[i] = temp[i];
				}
				shapes[size] = ((Rectangle)shape_).clone();
			}
			else if(shapes[0] instanceof Triangle){
				Triangle[] temp = new Triangle[size];
				for(int i=0;i<size;i++){
					temp[i] = ((Triangle)shapes[i]).clone();
				}
				
				shapes = new Triangle[size+1];
				
				for(int i=0;i<size;i++){
					shapes[i] = temp[i];
				}
				shapes[size] = ((Triangle)shape_).clone();
			}
			
		}
		size++;
	}
	
	/**
	 * Clears all inner shapes.
	 */
	public void clear(){
		shapes = null;
	}
	
	/**
	 * It controls the given points are inside the circle or not.
	 * @param x x coordinate of point.
	 * @param y y coordinate of point.
	 * @param radius radius of circle.
	 * @return returns if is inside 1 , is not 0.
	 */
	public int circle_equation(double x,double y,double radius){
		if( Math.pow(x-radius,2) + Math.pow(y-radius,2) <= Math.pow(radius,2) )
			return 1;
		else
			return 0;
	}
	
	
	
	/**
	 * Calculates the inner shapes for Container rectangle, Inner rectangle.
	 * @param r_container container shape.
	 * @param r_inside inner shape.
	 * @throws CloneNotSupportedException clone function exception.
	 */
	public void RectangleRectangle(Rectangle r_container,Rectangle r_inside) 
			throws CloneNotSupportedException{
		int i = 0,j = 0,k = 0,l = 0;
		Rectangle rec;
		
		
		for(i=0; i+(r_inside.getHeight()) <= r_container.getHeight() ; i+=r_inside.getHeight() ){
			for(j=0; j+ (r_inside.getWidth() ) <= r_container.getWidth() ; j+=(r_inside.getWidth() )){
				rec = new Rectangle(); 
				rec.setX(j);
				rec.setY(i);
				rec.setWidth( r_inside.getWidth() );
				rec.setHeight( r_inside.getHeight() );
				this.add(rec);
				rec.increase_total_area();
				rec.increase_total_perimeter();
			}	
		}
		/*After that it controls the bottom,top,right and left sides and fills the gaps.*/
		if(i+(r_inside.getHeight()) > r_container.getHeight() && (r_container.getHeight() - i) >= r_inside.getWidth() && r_container.getWidth() >= r_inside.getHeight() ){
			for(k=i;k+ (r_inside.getWidth()) <= r_container.getHeight() ; k+=(r_inside.getWidth() ) ){
				for(l=0;l+r_inside.getHeight()<=r_container.getWidth();l+=r_inside.getHeight()){
					rec = new Rectangle();	
					rec.setX(l);
					rec.setY(k);
					rec.setWidth( r_inside.getHeight() );
					rec.setHeight( r_inside.getWidth() );
					this.add(rec);
					rec.increase_total_area();
					rec.increase_total_perimeter();
				}
			}
		}
		if( (j+r_inside.getWidth() > r_container.getWidth()) && ((r_container.getWidth() - j)) >= r_inside.getHeight() && r_container.getHeight() >= r_inside.getWidth() ) {
			for(k=0;k+r_inside.getWidth() <= r_container.getHeight() ;k+=r_inside.getWidth()){
				for(l=j ; (l+r_inside.getHeight()) <= r_container.getWidth() ;l+=r_inside.getHeight()){
					rec = new Rectangle();	
					rec.setX(l);
					rec.setY(k);
					rec.setWidth( r_inside.getHeight() );
					rec.setHeight( r_inside.getWidth() );
					this.add(rec);
					rec.increase_total_area();
					rec.increase_total_perimeter();
				}
			}
		}
	}
	
	/**
	 * Calculates the inner shapes for Container rectangle, Inner circle.
	 * @param r_container container shape.
	 * @param c_inside inner shape.
	 * @throws CloneNotSupportedException clone function exception.
	 */
	public void RectangleCircle(Rectangle r_container,Circle c_inside)
			throws CloneNotSupportedException{
	
		((Rectangle)container).setX(c_inside.getRadius());
		((Rectangle)container).setY(c_inside.getRadius());
		double i,j;
		int line=1;
		int condition1=0,condition2=0;
	
		Circle circle;		
	
		/*First it calculates the most efficient way.
		  There is 2 way which is one under the other or cross way.*/
		for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+((c_inside.getRadius())*(Math.sqrt(3)))){
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
			for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+(c_inside.getRadius()*(Math.sqrt(3)))){
				for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
					circle= new Circle();	 
					if(j==c_inside.getRadius() && line %2 == 0)
						j+=c_inside.getRadius();

					 circle.setRadius(c_inside.getRadius());
					 circle.setX(j);
					 circle.setY(i);
					 this.add(circle);
					 circle.increase_total_area();
					 circle.increase_total_perimeter();
				}
				line++;
			}	
		}
		else{/*It applies the one under the other condition.*/
			for(i=c_inside.getRadius();(i+c_inside.getRadius())<=r_container.getHeight();i=i+(c_inside.getRadius()*2)){
				for(j=c_inside.getRadius();(j+c_inside.getRadius())<=r_container.getWidth();j=j+(c_inside.getRadius()*2)){
					circle= new Circle();	 
					 circle.setRadius(c_inside.getRadius());
					 circle.setX(j);
					 circle.setY(i);
					 this.add(circle);
					 circle.increase_total_area();
					 circle.increase_total_perimeter();
				}
			}
		}

	}
	
	/**
	 * Calculates the inner shapes for Container rectangle, Inner triangle.
	 * @param r_container container shape.
	 * @param t_inside inner shape.
	 * @throws CloneNotSupportedException clone function exception.
	 */
	public void RectangleTriangle(Rectangle r_container,Triangle t_inside)
			throws CloneNotSupportedException{
	
		double i,j;
		Triangle triangle;

/*It calculates and after that it adds small shape to the vector.*/
		for(i=0 ; (i+ ((t_inside.getLength()*(Math.sqrt(3)))/2) ) <= r_container.getHeight() ; i+= (t_inside.getLength()*(Math.sqrt(3))/2) ){
			for(j=0; (j+ (t_inside.getLength()) ) <= r_container.getWidth() ; j+=t_inside.getLength() ){
				triangle = new Triangle();		 
				triangle.setLength(t_inside.getLength());
				triangle.setX1((int) j);
				triangle.setY1((int) i);
				triangle.setX2((int) (j+t_inside.getLength()));
				triangle.setY2((int) i);
				triangle.setX3( (int) (j+(t_inside.getLength()/2)));
				triangle.setY3( (int) (t_inside.getLength()*((Math.sqrt(3))/2)+i) );
				this.add(triangle);
				triangle.increase_total_area();
				triangle.increase_total_perimeter();
				/*Reverse triangle calculation.*/
				if( ( j+(t_inside.getLength()/2)+(t_inside.getLength()) ) <= r_container.getWidth()){
					triangle = new Triangle();		 
					triangle.setLength(t_inside.getLength());
					triangle.setX1((int) (j+t_inside.getLength()));
					triangle.setY1((int) i);
					triangle.setX2((int) (j+t_inside.getLength()/2));
					triangle.setY2((int) (i+t_inside.getLength()*((Math.sqrt(3))/2)));
					triangle.setX3( (int) (j+t_inside.getLength()+(t_inside.getLength()/2)) );
					triangle.setY3( (int) (t_inside.getLength()*((Math.sqrt(3))/2)+i) );
					this.add(triangle);
					triangle.increase_total_area();
					triangle.increase_total_perimeter();
					}
				}
		}
	}
	
	/**
	 * Calculates the inner shapes for Container circle, Inner rectangle.
	 * @param c_container container shape.
	 * @param r_inside inner shape.
	 * @throws CloneNotSupportedException clone function exception.
	 */
	public void CircleRectangle(Circle c_container,Rectangle r_inside)
			throws CloneNotSupportedException{
		
		double i,j,k,l;
		double square_side=(Math.sqrt(2.0))*c_container.getRadius();
		double square_x,square_y;
		double temp;
		double hSmall_t;
		int flag=0;
		hSmall_t=r_inside.getHeight();
		
		Rectangle rec = null;

		square_y=c_container.getRadius()-(square_side/2.0);
		square_x=square_y;


		for(i=square_y;i+r_inside.getHeight()<=square_side;i+=r_inside.getHeight()){
			for(j=square_x;j<=square_side+r_inside.getWidth();j+=r_inside.getWidth()){
				if(Math.pow((i-c_container.getRadius()),2) +  Math.pow((j+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) ) {
					rec=new Rectangle();		 
					rec.setWidth(r_inside.getWidth());
					rec.setHeight(r_inside.getHeight());
					rec.setX(j);
					rec.setY(i);
					this.add(rec);
					rec.increase_total_area();
					rec.increase_total_perimeter();
	            }
			}
		}
	/*
		After here the function changes width and height and it controls the empty areas for filling the gap.
		When it change width and height it finds the empty area more.
	*/
		/*It controls the empty areas.*/
		if(r_inside.getHeight() > r_inside.getWidth()){
			temp=rec.getHeight();
			rec.setHeight(r_inside.getWidth());
			rec.setWidth(temp);
			flag=1;
		}
	/*It fills the empty areas.*/
		for(k=square_y-r_inside.getHeight();k>=0;k-=r_inside.getHeight()){
			for(l=square_x+r_inside.getWidth();l<=2*c_container.getRadius();l+=r_inside.getWidth()){
				rec=new Rectangle();		 
				if( Math.pow((k-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) + Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) ){
				
					rec.setWidth(r_inside.getWidth());
					rec.setHeight(r_inside.getHeight());
					rec.setX(l);
					rec.setY(k);
					this.add(rec);
					rec.increase_total_area();
					rec.increase_total_perimeter();
				}
			}	
		}
		if(flag==1)
			i+=6* rec.getHeight();
		else
			i+=rec.getWidth();

		for(k=i;k<=c_container.getRadius()*2;k+=r_inside.getHeight()){
			for(l=c_container.getRadius()-(square_side/2.0);l<=2*c_container.getRadius();l+=r_inside.getWidth()){
				rec=new Rectangle();		 
				if( Math.pow((k-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) ){

					rec.setWidth(r_inside.getWidth());
					rec.setHeight(r_inside.getHeight());
					rec.setX(l);
					rec.setY(k);
					this.add(rec);
					rec.increase_total_area();
					rec.increase_total_perimeter();
				}
			}
		}
		if(flag==1){
			temp=r_inside.getHeight();
			rec.setHeight(r_inside.getWidth());
			rec.setWidth(temp);
		}
		if(flag==0 && r_inside.getHeight() < r_inside.getWidth()){
			temp=r_inside.getHeight();
			rec.setHeight(r_inside.getWidth());
			rec.setWidth(temp);
		}

		for(k=square_y+r_inside.getHeight();k<=2*c_container.getRadius();k+=r_inside.getHeight()){
			for(l=c_container.getRadius()-(square_side/2.0);l<=2*c_container.getRadius();l+=r_inside.getWidth()){
					rec=new Rectangle();		 
					if( Math.pow((k-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
						Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
						Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
						Math.pow((k-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) ){

						rec.setWidth(r_inside.getWidth());
						rec.setHeight(r_inside.getHeight());
						rec.setX(l);
						rec.setY(k);
						this.add(rec);
						rec.increase_total_area();
						rec.increase_total_perimeter();
					}
			}
		}
		for(k=square_y+hSmall_t;k<=c_container.getRadius()*2;k+=r_inside.getHeight()){
			for(l=square_x-r_inside.getWidth();l>=0;l-=r_inside.getWidth()){
				rec=new Rectangle();		 
				if( Math.pow((k-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k+r_inside.getHeight()-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) &&
					Math.pow((k-c_container.getRadius()),2) +  Math.pow((l+r_inside.getWidth()-c_container.getRadius()),2) <= Math.pow(c_container.getRadius(),2) ){

					rec.setWidth(r_inside.getWidth());
					rec.setHeight(r_inside.getHeight());
					rec.setX(l);
					rec.setY(k);
					this.add(rec);
					rec.increase_total_area();
					rec.increase_total_perimeter();
				}
			}
		}
	}
	
	/**
	 * Calculates the inner shapes for Container circle, Inner circle.
	 * @param c_container container shape.
	 * @param c_inside inner shape.
	 * @throws CloneNotSupportedException clone function exception.
	 */
	public void CircleCircle(Circle c_container,Circle c_inside)
			throws CloneNotSupportedException{
		
		((Circle)c_container).setX(c_inside.getRadius());
		((Circle)c_container).setY(c_inside.getRadius());
		double angle;
		double anglee;
		double i,j;
		double x,y;/*Coordinates of circles.*/
		double x_t,y_t;/*For temprary coordinates.*/
		int number_of_circle;
		int counter=0;
		double sradius_temp,radius_temp;
		Circle circle;

		/*COSINUS THEOREM C^2 = A^2+B^2+2AB*COS*/
		angle= Math.acos(1.0 - ( Math.pow( (2.0*c_inside.getRadius()) , 2.0 ) ) / (2.0* Math.pow( (c_container.getRadius()-c_inside.getRadius()),2.0 )) );
		anglee= (angle*180.0) / Math.PI;
		number_of_circle = (int) (360/anglee);


		x=c_container.getRadius();
		y=c_inside.getRadius();
		radius_temp=c_container.getRadius();
		sradius_temp=c_inside.getRadius();
		/*First it add circle to most external part after that it comes to center of circle. */
		for(i=sradius_temp;i+sradius_temp*3<=(c_container.getRadius()+2*c_inside.getRadius());i+=sradius_temp*2){
			for(j=0;j<=number_of_circle-(1);j++){
				circle= new Circle();		 
				x_t=x-c_container.getRadius();
				y_t=y-c_container.getRadius();
			/*Rotation formules*/
				x=x_t*(Math.cos(angle))-y_t*(Math.sin(angle));
				y=x_t*(Math.sin(angle))+y_t*(Math.cos(angle));

				x+=c_container.getRadius();
				y+=c_container.getRadius();	

				 circle.setX(x);
				 circle.setY(y);
				 circle.setRadius(c_inside.getRadius());
				this.add(circle);
				 circle.increase_total_area();
				 circle.increase_total_perimeter();
			}
			/*This part does the same calculations for other interior part.*/
			radius_temp-=2*(c_inside.getRadius());
			counter++;
			x=c_container.getRadius();
			y=c_inside.getRadius()+(2*counter*c_inside.getRadius());
			angle= Math.acos(1.0 - ( Math.pow( (2.0*c_inside.getRadius()) , 2.0 ) ) / (2.0* Math.pow( (radius_temp-c_inside.getRadius()),2.0 )) );
			anglee= (angle*180.0) / Math.PI;
			number_of_circle = (int) (360/anglee);
		}

		if(c_inside.getRadius()*2 == c_container.getRadius()){
			circle= new Circle();		 
			 circle.setX(c_container.getRadius());
			 circle.setY(c_container.getRadius()-c_inside.getRadius());
			 circle.setRadius(c_inside.getRadius());
			this.add(circle);
			circle.increase_total_area();
			circle.increase_total_perimeter();
		}

		if( c_container.getRadius()- (i-c_inside.getRadius()) > c_inside.getRadius()){
			circle= new Circle();		 
			 circle.setX(c_container.getRadius());
			 circle.setY(c_container.getRadius());
			 circle.setRadius(c_inside.getRadius());
			this.add(circle);
			circle.increase_total_area();
			circle.increase_total_perimeter();
		}
	}
	
	/**
	 * Calculates the inner shapes for Container circle, Inner triangle.
	 * @param c_container container shape.
	 * @param t_inside inner shape.
	 * @throws CloneNotSupportedException clone function exception.
	 */
	public void CircleTriangle(Circle c_container,Triangle t_inside)
			throws CloneNotSupportedException{
	

		double i;
		double y;
		double h_triangle=(t_inside.getLength()*(Math.sqrt(3.0)))/2.0;
		int line=0;
		int counter=1;
		

		Triangle triangle;

	/*First it calculates the y coordinate because i started the filling the gaps from center and with reverse radius.*/
		y=Math.sqrt(Math.pow(c_container.getRadius(),2)-Math.pow(t_inside.getLength()/2,2))+c_container.getRadius();
		y=2*c_container.getRadius()-y;
	/*It controls the situations with circle equation formules.*/
		if(circle_equation(c_container.getRadius(),y+h_triangle,c_container.getRadius())==1){
			triangle = new Triangle();		 
			triangle.setLength(t_inside.getLength());
			triangle.setX1((int) (c_container.getRadius()-(t_inside.getLength()/2)));
			triangle.setY1((int) y);
			triangle.setX2((int) (c_container.getRadius()+(t_inside.getLength()/2)));
			triangle.setY2((int) y);
			triangle.setX3( (int) c_container.getRadius());
			triangle.setY3( (int) (y+((t_inside.getLength()*Math.sqrt(3))/2)) );
			this.add(triangle );
			triangle.increase_total_area();
			triangle.increase_total_perimeter();

			if(circle_equation(c_container.getRadius()-t_inside.getLength(),y+h_triangle,c_container.getRadius())==1){
				triangle = new Triangle();		 
				triangle.setLength(t_inside.getLength());
				triangle.setX1((int) (c_container.getRadius()-(t_inside.getLength()/2)));
				triangle.setY1((int) y);
				triangle.setX2((int) c_container.getRadius());
				triangle.setY2((int) (y+h_triangle));
				triangle.setX3((int) (c_container.getRadius()-(t_inside.getLength())));
				triangle.setY3((int) (y+h_triangle));
				this.add(triangle );
				triangle.increase_total_area();
				triangle.increase_total_perimeter();

				triangle = new Triangle();		 
				triangle.setLength(t_inside.getLength());
				triangle.setX1((int) (c_container.getRadius()+(t_inside.getLength()/2)));
				triangle.setY1((int) y);
				triangle.setX2((int) c_container.getRadius());
				triangle.setY2((int) (y+h_triangle));
				triangle.setX3((int) (c_container.getRadius()+t_inside.getLength()));
				triangle.setY3((int) (y+h_triangle));
				this.add(triangle );
				triangle.increase_total_area();
				triangle.increase_total_perimeter();
			}
		}
		/*For height*/
		for(i=y;i+2*(h_triangle)<=2*c_container.getRadius()+h_triangle;i+=((t_inside.getLength()*Math.sqrt(3.0))/2.0)){
				/*Left sides normal triangle.*/
			while(circle_equation((c_container.getRadius()-(t_inside.getLength()/2))-(((double)(counter)-1)*t_inside.getLength()),i+(2.0*h_triangle),c_container.getRadius())==1 &&
				  circle_equation(c_container.getRadius()-((double)(counter)*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1){
					triangle = new Triangle();		 
					triangle.setLength(t_inside.getLength());
					triangle.setX1((int) (c_container.getRadius()-(((double)(counter)-1)*t_inside.getLength())));
					triangle.setY1((int) (y+(h_triangle*(line+1))));
					triangle.setX2((int) (c_container.getRadius()-((double)(counter)*t_inside.getLength())));
					triangle.setY2((int) (y+(h_triangle*(line+1))));
					triangle.setX3((int) (c_container.getRadius()-(t_inside.getLength()/2)-((counter-1)*t_inside.getLength())));
					triangle.setY3((int) (y+((line+2)*h_triangle)));
					this.add(triangle );
					//triangle.increase_total_area();
					//triangle.increase_perimeter();

					counter++;
				}
				counter=1;
				/*Left sides reverse triangle.*/
				while(circle_equation((c_container.getRadius()-(t_inside.getLength()/2.0))-(((double)(counter)-1)*t_inside.getLength()),i+(h_triangle/2.0),c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()-(((double)(counter)-1)*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1 && i!=y){
					triangle = new Triangle();		 
					triangle.setLength(t_inside.getLength());
					triangle.setX1((int) (c_container.getRadius()-(t_inside.getLength()/2)
					-(((double)(counter)-1)*t_inside.getLength())+(t_inside.getLength()/2.0)));
					triangle.setY1((int) i);

					triangle.setX2((int) (c_container.getRadius()-
					((double)(counter)*t_inside.getLength())+(t_inside.getLength()/2.0)));

					triangle.setY2((int) (y+(h_triangle*(line+1.0))));

					triangle.setX3((int) (c_container.getRadius()-
					(((double)(counter)-1)*t_inside.getLength())+(t_inside.getLength()/2.0)));

					triangle.setY3((int) (y+(h_triangle*(line+1))));
					this.add(triangle);
					counter++;
					triangle.increase_total_area();
					triangle.increase_total_perimeter();
				}
				counter=1;
				/*Right sides normal triangle.*/
				while(circle_equation((c_container.getRadius()+(t_inside.getLength()/2.0))+((counter-1.0)*t_inside.getLength()),i+(2.0*h_triangle),c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()+(counter*t_inside.getLength()),i+h_triangle,c_container.getRadius())==1){
				triangle = new Triangle();		 
				triangle.setLength(t_inside.getLength());
				triangle.setX1((int) (c_container.getRadius()+((counter-1)*t_inside.getLength())));
				triangle.setY1((int) (y+(h_triangle*(line+1))));
				triangle.setX2((int) (c_container.getRadius()+(counter*t_inside.getLength())));
				triangle.setY2((int) (y+(h_triangle*(line+1))));
				triangle.setX3((int) (c_container.getRadius()+(t_inside.getLength()/2)+((counter-1)*t_inside.getLength())) );
				triangle.setY3((int) (y+((line+2)*h_triangle)));
				this.add(triangle);
				triangle.increase_total_area();
				triangle.increase_total_perimeter();


					counter++;
				}

				counter=1;
				/*Right sides reverse triangle.*/
				while(circle_equation((c_container.getRadius()+(t_inside.getLength()/2.0))+(((double)(counter)-1.0)*t_inside.getLength())+
					t_inside.getLength(),i+h_triangle,c_container.getRadius())==1 &&
					  circle_equation(c_container.getRadius()+((double)(counter)*t_inside.getLength()),
						i+h_triangle,c_container.getRadius())==1 && i!=y){
					triangle = new Triangle();		 
					triangle.setLength(t_inside.getLength());
					triangle.setX1((int) (c_container.getRadius()+(t_inside.getLength()/2.0)+
						(((double)(counter)-1.0)*t_inside.getLength())+(t_inside.getLength()/2.0)));
					triangle.setY1((int) i);
					triangle.setX2((int) (c_container.getRadius()+((double)(counter)*t_inside.getLength())+(t_inside.getLength()/2.0)));
					triangle.setY2((int) (y+(h_triangle*(line+1))));
					triangle.setX3((int) (c_container.getRadius()+(((double)(counter)-1.0)*t_inside.getLength())+(t_inside.getLength()/2.0)));
					triangle.setY3((int) (y+(h_triangle*(line+1))));
					this.add(triangle);
					triangle.increase_total_area();
					triangle.increase_total_perimeter();

					counter++;
				}
			counter=1;
			line++;
		}
		
		
	}
		
		
		
		
		
		
		
		/**
		 * Calculates the inner shapes for Container triangle, Inner rectangle.
		 * @param t_container container shape.
		 * @param r_inside inner shape.
		 * @throws CloneNotSupportedException clone function exception.
		 */
		public void TriangleRectangle(Triangle t_container,Rectangle r_inside)
				throws CloneNotSupportedException{
			

			double i,j;
			int temp;
			double line=0;
			double horizontal,vertical;
			double lineHorizontalLong;
			Rectangle rec;
		
			if(r_inside.getHeight() > r_inside.getWidth()){
				temp=(int) r_inside.getWidth();
				r_inside.setWidth(r_inside.getHeight());
				r_inside.setHeight(temp);
			}
			/*It calculates the first coordinate to put.*/
			vertical = (r_inside.getWidth())/(2.0/(Math.sqrt(3.0)));
			horizontal = (t_container.getLength()/2.0) - (r_inside.getWidth()/2.0); 

			lineHorizontalLong= (( ( ((line*r_inside.getHeight()) + ((r_inside.getWidth()/2)*Math.sqrt(3.0))) ) /Math.sqrt(3.0) ) *2) +horizontal;
			/*After that it calculates the other points with geometric calculations.*/
			for(i=vertical; (i+r_inside.getHeight()) <= t_container.getLength()*(Math.sqrt(3.0)/2.0);i+=r_inside.getHeight()){
				for(j=horizontal; (j+r_inside.getWidth()) <= (lineHorizontalLong);j+=r_inside.getWidth()){
					rec=new Rectangle();		 
					rec.setWidth(r_inside.getWidth());
					rec.setHeight(r_inside.getHeight());
					rec.setX(j);
					rec.setY(i);
					this.add(  rec );
					rec.increase_total_area();
					rec.increase_total_perimeter();
				}
				line++;
				horizontal -=(r_inside.getHeight()/Math.sqrt(3.0));
				lineHorizontalLong= (( ( ((line*r_inside.getHeight()) + ((r_inside.getWidth()/2)*Math.sqrt(3.0))) ) /Math.sqrt(3.0) ) *2) +horizontal;
			}
			
		}
		
		
		/**
		 * Calculates the inner shapes for Container triangle, Inner circle.
		 * @param t_container container shape.
		 * @param c_inside inner shape.
		 * @throws CloneNotSupportedException clone function exception.
		 */
		public void TriangleCircle(Triangle t_container,Circle c_inside)
				throws CloneNotSupportedException{ 
		
			
			((Triangle)t_container).setX1((int) (t_container.getX1() + c_inside.getRadius()));
			((Triangle)t_container).setY1((int) (t_container.getY1() + c_inside.getRadius()));
			((Triangle)t_container).setX2((int) (t_container.getX2() + c_inside.getRadius()));
			((Triangle)t_container).setY2((int) (t_container.getY2() + c_inside.getRadius()));
			((Triangle)t_container).setX3((int) (t_container.getX3() + c_inside.getRadius()));
			((Triangle)t_container).setY3((int) (t_container.getY3() + c_inside.getRadius()));
			
			
			double i,j;
			double linePoint = t_container.getLength()/2.0;
			int line=1,linecounter=1;
			Circle circle;
		

			/*It prints the circles with a spesific pattern.
				First it places the top and after that it goes to the bottom.*/
			for(i=2*c_inside.getRadius();(i+c_inside.getRadius())<=t_container.getLength()*(Math.sqrt(3.0)/2.0);i=i+(c_inside.getRadius()*Math.sqrt(3))){
				for(j=linePoint;linecounter<=line;j=j+(c_inside.getRadius()*2)){
				
					circle= new Circle();		 
				
					 circle.setRadius(c_inside.getRadius());
					 circle.setRadius(c_inside.getRadius());
					 circle.setX(j);
					 circle.setY(i);
	
					this.add(circle);
					 circle.increase_total_area();
					 circle.increase_total_perimeter();
				
					linecounter++;
				}
				line++;
				linecounter=1;
				linePoint-=c_inside.getRadius();
			}
		
		}
		
		/**
		 * Calculates the inner shapes for Container triangle, Inner triangle.
		 * @param t_container container shape.
		 * @param t_inside inner shape.
		 * @throws CloneNotSupportedException clone function exception.
		 */
		public void TriangleTriangle(Triangle t_container,Triangle t_inside)
				throws CloneNotSupportedException{ 
			double i,j;
			double line=1.0;
			double linePoint = t_container.getLength()/2.0;
			Triangle triangle;

			/*It prints the triangles inside a triangle. It decreases the row width every 
			  line and it prints one normal one reverse triangle.*/
			for(i=0; i+((t_inside.getLength()*Math.sqrt(3.0))/2.0) <= ( (t_container.getLength() * Math.sqrt(3.0))/2.0 ) ; i+= ((t_inside.getLength()*Math.sqrt(3.0))/2.0)){
				for(j=linePoint ; j <=((linePoint)+((line-1)*t_inside.getLength())) ; j+= t_inside.getLength()){
				triangle = new Triangle();	 
				triangle.setLength(t_inside.getLength());
				triangle.setX1((int) j);
				triangle.setY1((int) i);
				triangle.setX2((int) (j-(t_inside.getLength()/2.0)));
				triangle.setY2((int) (i+t_inside.getLength()*(Math.sqrt(3.0)/2.0)));
				triangle.setX3( (int) (j+(t_inside.getLength()/2.0)));
				triangle.setY3( (int) (i+t_inside.getLength()*(Math.sqrt(3.0)/2.0)) );
				this.add(triangle);
				triangle.increase_total_area();
				triangle.increase_total_perimeter();

				if(line != 1 && j !=((linePoint)+((line-1)*t_inside.getLength()))){
						triangle = new Triangle();		 
						triangle.setLength(t_inside.getLength());
						triangle.setX1((int) j);
						triangle.setY1((int) i);
						triangle.setX2((int) (j+t_inside.getLength()));
						triangle.setY2((int) i);
						triangle.setX3( (int) (j+(t_inside.getLength()/2.0)) );
						triangle.setY3( (int) (i+t_inside.getLength()*(Math.sqrt(3.0)/2.0)) );
						this.add(triangle);
						triangle.increase_total_area();
						triangle.increase_total_perimeter();
					}
				}
				linePoint-=t_inside.getLength()/2.0;
				line++;
			}
			
		}
		
		/**
		 * It calculates the inner shapes for the composedshape fields.
		 * @throws CloneNotSupportedException Clone method exception.
		 */
		public void optimalFit() 
				throws CloneNotSupportedException{
			
			
			if(inner instanceof Rectangle && container instanceof Rectangle){
				this.RectangleRectangle((Rectangle)container,(Rectangle)inner);
			}
			else if(inner instanceof Rectangle && container instanceof Circle){
				this.CircleRectangle((Circle)container,(Rectangle)inner);
			}
			else if(inner instanceof Rectangle && container instanceof Triangle){
				this.TriangleRectangle((Triangle)container,(Rectangle)inner);
			}
			else if(inner instanceof Circle && container instanceof Rectangle){
				this.RectangleCircle((Rectangle)container,(Circle)inner);
			}
			else if(inner instanceof Circle && container instanceof Circle){
				this.CircleCircle((Circle)container,(Circle)inner);
			}
			else if(inner instanceof Circle && container instanceof Triangle){
				this.TriangleCircle((Triangle)container,(Circle)inner);
			}
			else if(inner instanceof Triangle && container instanceof Rectangle){
				this.RectangleTriangle((Rectangle)container,(Triangle)inner);
			}
			else if(inner instanceof Triangle && container instanceof Circle){
				this.CircleTriangle((Circle)container,(Triangle)inner);
			}
			else if(inner instanceof Triangle && container instanceof Triangle){
				this.TriangleTriangle((Triangle)container,(Triangle)inner);
			}
			
			
			
			
		}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}















