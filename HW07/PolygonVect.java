import java.awt.Graphics;
import java.util.ArrayList;

/**
 * Polygon class which holds the shapes inside a ArrayList.
 * @author Yusuf Can
 * 
 */

public class PolygonVect extends Polygon {

	/**
	 * ArrayList field for 2D points.
	 */
	private ArrayList<Point2D> points = new ArrayList<Point2D>();;
	
	/**
	 * Simple no parameter constructor.
	 */
	public PolygonVect(){ }
	
	/**
	 * Simple constructor that sets inner points.
	 * @param points_ Arraylist of points.
	 */
	public PolygonVect(ArrayList<Point2D> points_){
		for(Point2D i: points_){
			points.add(i);
		}
	}
	
	/**
	 * Conversion constructor for rectangle.
	 * @param rectangle rectangle object
	 */
	public PolygonVect(Rectangle rectangle){
		Point2D[] polygon=new Point2D[4];
		
		for(int i=0;i<4;i++){
			polygon[i]=new Point2D();
		}

		polygon[0].setX((int) rectangle.getX());
		polygon[0].setY((int) rectangle.getY());
		polygon[1].setX( (int) (rectangle.getX()+rectangle.getWidth()) );
		polygon[1].setY( (int) rectangle.getY() );
		polygon[2].setX( (int) (rectangle.getX() + rectangle.getWidth()) );
		polygon[2].setY( (int) (rectangle.getY() + rectangle.getHeight()) );
		polygon[3].setX( (int) rectangle.getX() );
		polygon[3].setY( (int) (rectangle.getY() + rectangle.getHeight()) );
	
		points.add(polygon[0]);
		points.add(polygon[1]);
		points.add(polygon[2]);
		points.add(polygon[3]);
	}
	
	/**
	 * Conversion constructor for circle.
	 * @param circle circle object
	 */
	public PolygonVect(Circle circle){
		double x,y,x_t,y_t;
		double ang =3.6;
		double angle = (ang*Math.PI)/180.; /*I convert the angle to radian.*/
		Point2D[] Polygon2D = new Point2D[100];
		
		for(int i=0;i<100;i++){
			Polygon2D[i] = new Point2D();
		}

		x=circle.getRadius();
		y=0;
		x_t=x;
		y_t=y;

		for(int i=0;i<100;i++){
			Polygon2D[i].setX( (int)( (x_t*Math.cos(angle)-y_t*Math.sin(angle) 
					+ circle.getRadius() + circle.getX() - circle.getRadius()) ) );
			Polygon2D[i].setY( (int) (x_t*Math.sin(angle)+y_t*Math.cos(angle) 
					+ circle.getRadius() + circle.getY() + circle.getRadius())  );
			ang += 3.6;
			angle =  (ang*Math.PI)/180.;
		}
		
		for(Point2D i:Polygon2D)
			points.add(i);
	}
	
	/**
	 * Conversion constructor for triangle.
	 * @param triangle triangle object
	 */
	public PolygonVect(Triangle triangle){
		Point2D[]  polygon=new Point2D[3];
		
		for(int i=0;i<3;i++){
			polygon[i] = new Point2D();
		}
		
		polygon[0].setX( triangle.getX1() );
		polygon[0].setY( triangle.getY1() );
		polygon[1].setX( triangle.getX2() );
		polygon[1].setY( triangle.getY2() );
		polygon[2].setX( triangle.getX3() );
		polygon[2].setY( triangle.getY3() );	
	
		points.add(polygon[0]);
		points.add(polygon[1]);
		points.add(polygon[2]);
	}
	
	@Override
	public double area() {
		int size=points.size();
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=((points.get(i).getX() * points.get(i+1).getY() )-
					(points.get(i).getY() * points.get(i+1).getX() ));
		}
		return Math.abs(sum/2.0);
	}

	@Override
	public double perimeter() {
		int size=points.size();
		double sum=0;
		for(int i=0;i<size-1;i++){
			sum+=(Math.sqrt(Math.pow((points.get(i).getX() - points.get(i+1).getX() ), 2)+ 
					Math.pow( (points.get(i).getY() - points.get(i+1).getY() ), 2)));
		}
		sum+=(Math.sqrt(Math.pow((points.get(0).getX() - points.get(size-1).getX() ), 2)+ 
				Math.pow( (points.get(0).getY() - points.get(size-1).getY() ), 2)));
		return sum;
	}

	@Override
	public void increment() {
		for(int i = 0;i<points.size();i++){
			points.get(i).setX(points.get(i).getX()+1);
			points.get(i).setY(points.get(i).getY()+1);
		}
	}

	@Override
	public void decrement() {
		for(int i = 0;i<points.size();i++){
			points.get(i).setX(points.get(i).getX()-1);
			points.get(i).setY(points.get(i).getY()-1);
		}
	}

	@Override
	public void draw(Graphics g) {
		int[] arrx = new int[points.size()];
		int[] arry = new int[points.size()];
		
		for(int i=0 ; i<points.size();i++){
			arrx[i] = points.get(i).getX();
			arry[i] = points.get(i).getY();
		}
		g.fillPolygon(arrx,arry,points.size());
		g.drawPolygon(arrx,arry,points.size());
	}

	@Override
	public int compareTo(Shape o) {
		if( o.area() == this.area() ) return 1;
		else return 0;
	}
	
	/**
	 * Returns count of points.
	 * @return points count.
	 */
	public int size(){
		return points.size();
	}
	
	/**
	 * Adds points to the inner array list.
	 * @param point 2D point.
	 */
	public void add(Point2D point){
		points.add(point);
	}

}
