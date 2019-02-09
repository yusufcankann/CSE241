import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;
import java.lang.IllegalArgumentException;
import java.lang.NullPointerException;


/**
 * 
 * A simple Triangle class that 
 * implements shape methods.
 * 
 * @author Yusuf Can
 *
 */


public class Triangle implements Shape,Cloneable {

	/**
	 * A polygon for drawing shapes.
	 */
	private Polygon polygon;
	
	/**
	 * Side length for triangle.
	 */
	private double length;
	
	/**
	 * X coordinates.
	 */
	private int[] arrx = null;
	
	/**
	 * y coordinates.
	 */
	private int[] arry = null;
	
	/**
	 * The area of triangles which created so far.
	 */
	private static double total_area=0;
	
	/**
	 * The perimeter of triangles which created so far.
	 */
	private static double total_perimeter=0;
	
	/**
	 * 
	 * Simple constructor that
	 * sets all points by given length.
	 * 
	 * @param length_ length side of triangle
	 */
	public Triangle(double length_){
		length = length_;
		arrx = new int[3];
		arry = new int[3];
		
		arrx[0] =  0;
		arry[0] = (int)(( length_* (Math.sqrt(3)) ) / 2);
		arrx[1] = (int)(length_/2);
		arry[1] = 0;
		arrx[2] = (int)length_;
		arry[2] = (int)((length_*(Math.sqrt(3)))/2) ;

		polygon = new Polygon(arrx,arry,3);
		
		this.increase_total_area();
		this.increase_total_perimeter();
	}
	
	/**
	 * No parameter constructor which sets length 10
	 * and sets points.
	 */
	public Triangle(){
		this(10);
	}
	
	/**
	 * Getter method for polygon object.
	 * @return polygon object
	 */
	public Polygon getPolygon(){return polygon;}
	
	/**
	 * Getter method for x coordinates.
	 * @return x coordinates.
	 */
	public int[] getArrayX(){return arrx;}
	
	/**
	 * Getter method for y coordinates.
	 * @return y coordinates.
	 */
	public int[] getArrayY(){return arry;}
	
	/**
	 * Getter method for length.
	 * @return length of triangle.
	 */
	public double getLength(){return length;}
	
	/**
	 * Getter method for first x coordinate.
	 * @return X coordinate.
	 */
	public int getX1(){ return arrx[0]; }
	
	/**
	 * Getter method for second x coordinate.
	 * @return X coordinate.
	 */
	public int getX2(){ return arrx[1]; }
	
	/**
	 * Getter method for third x coordinate.
	 * @return X coordinate.
	 */
	public int getX3(){ return arrx[2]; }
	
	/**
	 * Getter method for first y coordinate.
	 * @return Y coordinate.
	 */
	public int getY1(){ return arry[0]; }
	
	/**
	 * Getter method for second y coordinate.
	 * @return Y coordinate.
	 */
	public int getY2(){ return arry[1]; }
	
	/**
	 * Getter method for third y coordinate.
	 * @return Y coordinate.
	 */
	public int getY3(){ return arry[2]; }
	
	
	
	/**
	 * Setter method for polygon.
	 * @param polygon_ polygon references.
	 */
	public void setPolygon(Polygon polygon_){
		polygon=polygon_;
	}
	
	/**
	 * Setter method for x coordinates.
	 * @param arrx_ integer array for x coordinates.
	 * @throws IllegalArgumentException if length of array different than 3 it throws this exception.
	 */
	public void setArrayX(int[] arrx_)
			throws IllegalArgumentException{
		if( (arrx_.length) != 3){
			throw new IllegalArgumentException();
		}
		
		arrx=new int[3];
		arrx[0]=arrx_[0];
		arrx[1]=arrx_[1];
		arrx[2]=arrx_[2];
				
	}
	
	/**
	 * Setter method for y coordinates.
	 * @param arry_ integer array for t coordinates.
	 * @throws IllegalArgumentException if length of array different than 3 it throws this exception.
	 */
	public void setArrayY(int[] arry_)
			throws IllegalArgumentException{
		if( (arry_.length) != 3){
			throw new IllegalArgumentException();
		}
		
		arry=new int[3];
		arry[0]=arry_[0];
		arry[1]=arry_[1];
		arry[2]=arry_[2];
				
	}
	
	/**
	 * Setter method for triangle length.
	 * @param length_ length of triangle
	 * @throws IllegalArgumentException if length negative , throws exception.
	 */
	public void setLength(double length_)
			throws IllegalArgumentException{
		if(length_ <= 0){
			throw new IllegalArgumentException();
		}
		
		length = length_;
		
		arrx[0] =  0;
		arry[0] = (int)(( length_* (Math.sqrt(3)) ) / 2);
		arrx[1] = (int)(length_/2);
		arry[1] = 0;
		arrx[2] = (int)length_;
		arry[2] = (int)((length_*(Math.sqrt(3)))/2) ;
	}
	
	/**
	 * Setter method for x coordinates.
	 * @param x1 x coordinate.
	 */
	public void setX1(int x1){
		arrx[0]=x1;
	}
	
	/**
	 * Setter method for x coordinates.
	 * @param x2 x coordinate.
	 */
	public void setX2(int x2){
		arrx[1]=x2;
	}
	
	/**
	 * Setter method for x coordinates.
	 * @param x3 x coordinate.
	 */
	public void setX3(int x3){
		arrx[2]=x3;
	}
	
	/**
	 * Setter method for y coordinate.
	 * @param y1 y coordinate.
	 */
	public void setY1(int y1){
		arry[0]=y1;
	}
	
	/**
	 * Setter method for y coordinate.
	 * @param y2 y coordinate
	 */
	public void setY2(int y2){
		arry[1]=y2;
	}
	
	/**
	 * Setter method for y coordinate.
	 * @param y3 y coordinate.
	 */
	public void setY3(int y3){
		arry[2]=y3;
	}
	
	@Override
	public double area() {
		return ( (length*length*(Math.sqrt(3)))/4 );
	}

	@Override
	public double perimeter() {
		return length*3;
	}

	@Override
	public void increment()
			throws NullPointerException{
		if(arrx == null || arry == null){
			throw new NullPointerException();
		}
		
		for(int i=0;i<3;i++){
			arrx[i]++;
			arry[i]++;
		}

	}

	@Override
	public void decrement()
			throws NullPointerException{
		
		if(arrx == null || arry == null){
			throw new NullPointerException();
		}
		
		for(int i=0;i<3;i++){
			if( (arrx[i]-1) >= 0)
				arrx[i]--;
			if( (arry[i]-1) >= 0)
				arry[i]--;
		}

	}

	@Override
	public void draw(Graphics g) {
		g.setColor(Color.magenta);
		g.fillPolygon(arrx,arry,3);
		g.setColor(Color.black);
		g.drawPolygon(arrx,arry,3);
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
		total_area+= ( (length*length*(Math.sqrt(3)))/4 );
	}
	
	/**
	 * Increases total perimeter.
	 */
	public void increase_total_perimeter(){
		total_perimeter += length*3;
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
	public Triangle clone() 
			throws CloneNotSupportedException{ 
		Triangle t = (Triangle)super.clone(); 
		
		int[] arrayx = new int[3];
		int[] arrayy = new int[3];
		
		for(int i=0;i<3;i++){
			arrayx[i] = arrx[i];
			arrayy[i] = arry[i];
		}
		
		t.setArrayX(arrayx);
		t.setArrayY(arrayy);
		
		return t;
	}

}
