import java.awt.Color;
import java.awt.Graphics;
import java.lang.IllegalArgumentException;


/**
 * 
 * A simple Circle class that 
 * implements shape methods.
 * 
 * @author Yusuf Can Kan
 *
 */
public class Circle implements Shape, Cloneable {
	
	/**
	 * radius of circle
	 */
	private double radius;
	
	/**
	 * X coordinates.
	 */
	private double x;
	
	/**
	 * Y coordinates.
	 */
	private double y;
	
	/**
	 * The area of triangles which created so far.
	 */
	private static double total_area=0;
	
	/**
	 * The perimeter of triangles which created so far.
	 */
	private static double total_perimeter=0;
	
	/**
	 * Simple constructor that sets radius.
	 * @param rad radius of circle.
	 */
	public Circle(double rad){
		radius=rad;
		this.increase_total_area();
		this.increase_total_perimeter();
	}
	
	/**
	 * Simple constructor that sets radius to 1.
	 */
	public Circle(){
		radius=1;
		x=0;
		y=0;
		this.increase_total_area();
		this.increase_total_perimeter();
	}
	
	/**
	 * Getter method for radius.
	 * @return returns radius.
	 */
	public double getRadius(){return radius;}
	
	/**
	 * Getter method for x.
	 * @return x coordinate.
	 */
	public double getX(){return x;}
	
	/**
	 * Getter method for y.
	 * @return y coordinates.
	 */
	public double getY(){return y;}

	/**
	 * Setter method for radius.
	 * @param radius_ radius of rectangle.
	 * @throws IllegalArgumentException throws if radius is smaller than 0.
	 */
	public void setRadius(double radius_)
			throws IllegalArgumentException{
		if(radius_ < 0){
			throw new IllegalArgumentException();
		}
		
		radius = radius_;
	}
	
	/**
	 * Setter method for x coordinate.
	 * @param x_ x coordinate.
	 * @throws IllegalArgumentException throws if coordinate is smaller than 0.
	 */
	public void setX(double x_)
			throws IllegalArgumentException{
		if(x_<0)
			throw new IllegalArgumentException();
		
		x = x_;
	}
	
	/**
	 * Setter method for y coordinate.
	 * @param y_ y coordinate.
	 * @throws IllegalArgumentException throws if coordinate is smaller than 0.
	 */
	public void setY(double y_)
			throws IllegalArgumentException{
		if(y_<0)
			throw new IllegalArgumentException();
		
		y = y_;
	}
	
	@Override
	public double area() {
		return radius*radius*(Math.PI);
	}

	@Override
	public double perimeter() {
		return 2*(Math.PI)*radius;
	}

	@Override
	public void increment() {
		x++;
		y++;
	}

	@Override
	public void decrement() {
		if( (x-1) >= 0) x--;
		if( (y-1) >= 0) y--;
	}

	@Override
	public void draw(Graphics g) {
		g.setColor(Color.ORANGE);
		g.fillOval((int)x, (int)y, (int)radius*2 , (int)radius*2);
		g.setColor(Color.black);
		g.drawOval((int)x, (int)y, (int)radius*2 , (int)radius*2);
	}

	@Override
	public int compareTo(Shape o) {
		if( o.area() == this.area() ) return 1;
		else return 0;
	}
	
	/*
	 * Increases total area.
	 */
	public void increase_total_area(){
		total_area+= radius*radius*(Math.PI);
	}
	
	/*
	 * Increases total perimeter.
	 */
	public void increase_total_perimeter(){
		total_perimeter += 2*(Math.PI)*radius;
	}
	
	/**
	 * returns the total area.
	 * @return total area.
	 */
	public double show_total_area(){
		return total_area;
	}
	
	/**
	 * Returns the total perimeter.
	 * @return total perimeter.
	 */
	public double show_total_perimeter(){
		return total_perimeter;
	}
	
	/**
	 * Clone method.
	 */
	public Circle clone() 
			throws CloneNotSupportedException{ 
		return (Circle)super.clone(); 
	}
	

}
