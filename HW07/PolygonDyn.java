import java.awt.Color;
import java.awt.Graphics;

/**
 * Polygon class which holds the shapes inside a vector.
 * @author Yusuf Can
 * 
 */

public class PolygonDyn extends Polygon {

	/**
	 * Polygon2D class array wich holds 2D points.
	 */
	private Point2D[] points=null;
	
	/**
	 * points array used size.
	 */
	private int used=0;
	
	/**
	 * points array capacity.
	 */
	private int capacity=0;
	
	/**
	 * Simple no parameter constructor.
	 */
	public PolygonDyn(){ }
	
	/**
	 * Simple constructor that takes Point2D array and sets it.
	 * @param points_ Point2D class array.
	 */
	public PolygonDyn(Point2D[] points_){
		capacity = points_.length;
		used = capacity;
		
		points = new Point2D[capacity];
		
		for(int i=0;i<used;i++){
			points[i] = points_[i];
		}
	}
	/**
	 * Conversion constructor that converts rectangle to polygon.
	 * @param rectangle rectangle object
	 */
	public PolygonDyn(Rectangle rectangle){
		
		points = new Point2D[4];
		
		for(int i=0;i<4;i++){
			points[i] = new Point2D();
		}
		
		points[0].setX((int) rectangle.getX());
		points[0].setY((int) rectangle.getY());
		points[1].setX( (int) (rectangle.getX()+rectangle.getWidth()) );
		points[1].setY( (int) rectangle.getY() );
		points[2].setX( (int) (rectangle.getX() + rectangle.getWidth()) );
		points[2].setY( (int) (rectangle.getY() + rectangle.getHeight()) );
		points[3].setX( (int) rectangle.getX() );
		points[3].setY( (int) (rectangle.getY() + rectangle.getHeight()) );
		used=4;
		capacity=4;
	}
	/**
	 * Conversion constructor that converts triangle to polygon.
	 * @param triangle triangle object
	 */
	public PolygonDyn(Triangle triangle){
		points = new Point2D[3];
		
		for(int i=0;i<3;i++){
			points[i]=new Point2D();
		}
		
		points[0].setX( triangle.getX1() );
		points[0].setY( triangle.getY1() );
		points[1].setX( triangle.getX2() );
		points[1].setY( triangle.getY2() );
		points[2].setX( triangle.getX3() );
		points[2].setY( triangle.getY3() );	
		used=3;
		capacity=3;
		
	}
	
	/**
	 * Conversion constructor that converts circle to polygon with 100 points.
	 * @param circle circle object
	 */
	public PolygonDyn(Circle circle){
		double x,y,x_t,y_t;
		double ang =3.6;
		double angle = (ang*Math.PI)/180.; /*I convert the angle to radian.*/
		points = new Point2D[100];
		
		for(int i=0;i<100;i++){
			points[i] = new Point2D();
		}
		
		x=circle.getRadius();
		y=0;
		x_t=x;
		y_t=y;

		for(int i=0;i<100;i++){
			
			points[i].setX( (int) (x_t*Math.cos(angle)-y_t*Math.sin(angle) + circle.getRadius() 
							+ circle.getX() - circle.getRadius())  );
			
			points[i].setY( (int) (x_t*Math.sin(angle)+y_t*Math.cos(angle) + circle.getRadius() 
							+ circle.getY() + circle.getRadius())  );
			ang += 3.6;
			angle =  (ang*Math.PI)/180.;
		}
	
		used=100;
		capacity=100;
	}
	
	/**
	 * Getter function for array capacity.
	 * @return capacity.
	 */
	public int getCapacity(){
		return capacity;
	}
	
	/**
	 * Getter function for array used.
	 * @return used array size.
	 */
	public int getUsed(){
		return used;
	}
	
	/**
	 * Getter function for points.
	 * @return Point2D array.
	 */
	public Point2D[] getPoints(){
		return points;
	}
	
	@Override
	public double area() {
		int size=capacity;
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=((points[i].getX() * points[i+1].getY() )-
					(points[i].getY() * points[i+1].getX() ));
		}
		return Math.abs(sum/2.0);
	}

	@Override
	public double perimeter() {
		int size=capacity;
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=(Math.sqrt(Math.pow((points[i].getX() - points[i+1].getX() ), 2)
					+ Math.pow( (points[i].getY() - points[i+1].getY() ), 2)));
		}
		sum+=(Math.sqrt(Math.pow((points[0].getX() - points[size-1].getX() ), 2)+ 
				Math.pow( (points[0].getY() - points[size-1].getY() ), 2)));
		return sum;
	}

	@Override
	public void draw(Graphics g) {
		int[] arrx = new int[used];
		int[] arry = new int[used];
		
		for(int i=0 ; i<used;i++){
			arrx[i] = points[i].getX();
			arry[i] = points[i].getY();
		}
		g.setColor(Color.GRAY);
		g.fillPolygon(arrx,arry,used);
		g.drawPolygon(arrx,arry,used);
	}

	@Override
	public int compareTo(Shape o) {
		if( o.area() == this.area() ) return 1;
		else return 0;
	}

	@Override
	public void increment(){
		for(int i = 0;i<used;i++){
			points[i].setX(points[i].getX()+1);
			points[i].setY(points[i].getY()+1);
		}
	}

	@Override
	public void decrement() {
		for(int i = 0;i<used;i++){
			points[i].setX(points[i].getX()-1);
			points[i].setY(points[i].getY()-1);
		}
	}
	
	/**
	 * Adds points to the inner points array.
	 * @param point 2D points array.
	 */
	public void add(Point2D point){
		if(used==0){
			points = new Point2D[1];
			points[0].setX(point.getX());
			points[0].setY(point.getY());
			
			capacity=1;
			used=1;
		}
		else{
			Point2D[] a=new Point2D[capacity];
			
			for(int i=0;i<capacity;i++)
				a[i]=points[i];
			
			points = new Point2D[capacity+1];
			
			for(int i=0;i<capacity;i++)
				points[i]=a[i];
			
			points[capacity]=point;
			
			used++;
			capacity++;
		}
	}

}
