import java.awt.Color;
import java.awt.Graphics;
import java.lang.IllegalArgumentException;

/**
 * 
 * A simple Rectangle class that 
 * implements shape methods.
 * 
 * @author Yusuf Can Kan
 *
 */



public class Rectangle implements Shape,Cloneable {

	/**
	 * Width for rectangle.
	 */
	private double width;
	
	/**
	 * Height for rectangle.
	 */
	private double height;
	
	/**
	 * X coordinate.
	 */
	private double x;
	
	/**
	 * Y coordinates.
	 */
	private double y;
	
	/**
	 * The area of rectangles which created so far.
	 */
	private static double total_area=0;
	
	/**
	 * The perimeter of rectangles which created so far.
	 */
	private static double total_perimeter=0;
	
	/**
	 * Simple constructor that sets width,height,x and y coordinates.
	 * @param width_ width of rectangle.
	 * @param height_ height of rectangle.
	 * @param x_ x coordinate of rectangle.
	 * @param y_ y coordinate of rectangle.
	 * @throws IllegalArgumentException throws exception if width and height is smaller than 0.
	 */
	public Rectangle(double width_,double height_,double x_,double y_)
			throws IllegalArgumentException{
		
		if(width_< 0 || height<0 )
			throw new IllegalArgumentException();
		
		width=width_;
		height=height_;
		x=x_;
		y=y_;
		this.increase_total_area();
		this.increase_total_perimeter();
	}
	
	/**
	 * Simple constructor that sets width and height.
	 * @param width_ width of rectangle.
	 * @param height_ height of rectangle.
	 */
	public Rectangle(double width_,double height_){
		this(width_,height_,0,0);
	}
	
	/**
	 * Simple constructor that sets width and height the same value.
	 * @param width_ width and height of the rectangle.
	 */
	public Rectangle(double width_){
		this(width_,width_,0,0);
	}
	
	/**
	 * Simple constructor that sets rectangle lengths 20.
	 */
	public Rectangle(){
		this(20,20,0,0);
	}
	
	/**
	 * Getter method for width.
	 * @return width of rectangle.
	 */
	public double getWidth(){return width;}
	
	/**
	 * Getter method for height.
	 * @return height of rectangle.
	 */
	public double getHeight(){return height;}
	
	/**
	 * Getter method for x coordinates.
	 * @return x coordinates.
	 */
	public double getX() {return x;}
	
	/**
	 * Getter method for y coordinates.
	 * @return y coordinates.
	 */
	public double getY(){return y;}
	
	/**
	 * Setter method for width of rectangle.
	 * @param width_ width of rectangle
	 * @throws IllegalArgumentException throws if width is smaller than 0.
	 */
	public void setWidth(double width_)
			throws IllegalArgumentException{
		if(width_ < 0){
			throw new IllegalArgumentException();
		}
		
		width = width_;
	}
	
	/**
	 * Setter method for height of rectangle.
	 * @param height_ height of rectangle.
	 * @throws IllegalArgumentException throws if height is smaller than 0.
	 */
	public void setHeight(double height_)
			throws IllegalArgumentException{
		if(height_ < 0){
			throw new IllegalArgumentException();
		}
		
		height = height_;
	}
	
	/**
	 * Setter method for x coordinate.
	 * @param x_ x coordinate.
	 * @throws IllegalArgumentException throws if x < 0.
	 */
	public void setX(double x_)
			throws IllegalArgumentException{
		if(x_<0)
			throw new IllegalArgumentException();
		
		x = x_;
	}
	
	/**
	 * Setter method for y coordinates.
	 * @param y_ y coordinate.
	 * @throws IllegalArgumentException throws if y<0.
	 */
	public void setY(double y_)
			throws IllegalArgumentException{
		if(y_<0)
			throw new IllegalArgumentException();
		
		y = y_;
	}
	
	@Override
	public double area() {
		return width*height;
	}

	@Override
	public double perimeter() {
		return 2*width+2*height;
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
		g.setColor(Color.red);
		g.fillRect((int)x, (int)y, (int)width, (int)height);
		g.setColor(Color.black);
		g.drawRect((int)x, (int)y, (int)width, (int)height);
	}

	@Override
	public int compareTo(Shape o) {
		if( o.area() == this.area() ) return 1;
		else return 0;
	}
	
	/**
	 * Increases total area.
	 */
	public void increase_total_area(){
		total_area+= width*height;
	}
	
	/**
	 * Increases total perimeter.
	 */
	public void increase_total_perimeter(){
		total_perimeter += 2*width+2*height;
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
	public Rectangle clone() 
			throws CloneNotSupportedException{ 
		return (Rectangle)super.clone(); 
	}
	
	

}
