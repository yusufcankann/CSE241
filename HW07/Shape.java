import java.awt.Graphics;

/**
 * 
 * This interface is the basis of every
 * shape classes.
 * 
 * @author Yusuf Can
 *
 */

public interface Shape extends Comparable<Shape>{
	
	/**
	 * Area of shape method.
	 * @return area of shape.
	 */
	public double area();
	
	/**
	 * Perimeter of shape method.
	 * @return perimeter of length
	 */
	public double perimeter();
	
	/**
	 * Increments the coordinates.
	 */
	public void increment();
	
	/**
	 * Decrements the coordinates.
	 */
	public void decrement();
	
	/**
	 * Draws the shape on the graphic object.
	 * @param g graphic object which shape is drawn.
	 */
	public void draw(Graphics g);
	
	/**
	 * Compares shapes by theirs areas.
	 */
	public int compareTo(Shape o);
	
}
