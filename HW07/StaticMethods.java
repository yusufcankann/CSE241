import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


/**
 * This class includes some useful static methods.
 * @author Yusuf Can
 *
 */
public class StaticMethods{

	/**
	 * JPanel class for drawAll method.
	 * @author Yusuf Can
	 *
	 */
	public static class DrawAllPanel extends JPanel{
		
		private Shape[] shape;
		
		public DrawAllPanel(Shape[] a_){
			shape=a_;
		}
		public void paintComponent(Graphics g){
			super.paintComponent(g);
			
			for(Shape x:shape){
				x.draw(g);;
			}
		}
	}
	
	
	
	
	/**
	 * It creates an JFrame and JPanel and draw all shapes on it.
	 * @param shapes shapes which will be drawn.
	 */
	public static void drawAll(Shape[] shapes){
		
		final JFrame frame = new JFrame("drawAll()");
		frame.setBounds(1000, 170, 600, 600);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setVisible(true);

		DrawAllPanel panel = new DrawAllPanel(shapes);
		panel.setBounds(10, 10, 580, 580);
		panel.setBackground(Color.pink);
		frame.getContentPane().add(panel);
		
	}
	
	/**
	 * Takes an shape reference array and converts all 
	 * convertible shapes to polygon.
	 * @param shapes shape references
	 * @return polygon vectors.
	 */
	public static Shape[] convertAll(Shape[] shapes){
		int size = shapes.length;
		Shape[] shape = new Shape[size];
		
		for(int i=0;i<size;i++){
			if(shapes[i] instanceof Rectangle){
				PolygonVect temp = new PolygonVect((Rectangle)shapes[i]);
				shape[i] = temp;
			}
			else if(shapes[i] instanceof Circle){
				PolygonVect temp = new PolygonVect((Circle)shapes[i]);
				shape[i] = temp;
			}
			else if(shapes[i] instanceof Triangle){
				PolygonVect temp = new PolygonVect((Triangle)shapes[i]);
				shape[i] = temp;
			}
		}	
		return shape;
	}
	
	/**
	 * Increasingly sorts shapes with respect to their areas.
	 * @param shapes shapes array.
	 */
	public static void sortShapes(Shape[] shapes){
		int size = shapes.length;
		
		for(int j=0;j<size;j++){
			for(int i=0;i<size-1;i++){
				if(shapes[i].area() > shapes[i+1].area()){
					Shape temp = shapes[i];
					shapes[i] = shapes[i+1];
					shapes[i+1] = temp;
				}
			}
		}
	}
	
	
}
