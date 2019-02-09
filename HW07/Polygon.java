
/**
 * Shape class for polygon shapes.
 * @author Yusuf Can
 *
 */
public abstract class Polygon implements Shape {

	
	/**
	 * Simple Constructor.
	 */
	public Polygon(){ }
	
	/**
	 * Inner Class for holding coordinates.
	 * @author Yusuf Can
	 *
	 */
	public class Point2D{
		
		/**
		 * x coordinate.
		 */
		private int x;
		
		/**
		 * y coordinate.
		 */
		private int y;
		
		/**
		 * Simple constructor that sets x and y.
		 * @param x_ x coordinate.
		 * @param y_ y coordinate.
		 */
		public Point2D(int x_,int y_){
			x=x_;
			y=y_;
		}
		
		/**
		 * Simple no parameter constructor. It sets coordinates 0,0.
		 */
		public Point2D(){
			x=0;
			y=0;
		}
		
		/**
		 * Setter method for x coordinate.
		 * @param x_ x coordinate.
		 */
		public void setX(int x_){
			x=x_;
		}
		
		/**
		 * Setter method for y coordinate.
		 * @param y_ y coordinate.
		 */
		public void setY(int y_){
			y=y_;
		}
		
		/**
		 * getter method for x coordinate.
		 * @return returns x coorditane.
		 */
		public int getX(){
			return x;
		}
		
		/**
		 * Getter function for y coordinate.
		 * @return returns y coordinate.
		 */
		public int getY(){
			return y;
		}
	}

}
