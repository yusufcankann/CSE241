import java.awt.Graphics;
import javax.swing.JPanel;



public class DrawPanel extends JPanel {

	int choice =0;
	
	public DrawPanel(){ }
	
	public DrawPanel(int i){
		choice = i;
	}
	
	public void setChoice(int i){
		choice =i;
	}
	
	public void paintComponent(Graphics g){
		
		super.paintComponent(g);
		
		Rectangle rectangle = new Rectangle(500,445);
		Rectangle rectangle1 = new Rectangle(50,90);
		
		Triangle triangle = new Triangle(500);
		Triangle triangle1 = new Triangle(70);
		
		Circle circle = new Circle(230);
		Circle circle1 = new Circle(15);
		
		ComposedShape shape1 = null;
		
		switch(choice){
		case 1:
			 shape1 = new ComposedShape(rectangle,rectangle1);
			 try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 2:
			shape1 = new ComposedShape(rectangle,circle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 3:
			shape1 = new ComposedShape(rectangle,triangle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 4:
			shape1 = new ComposedShape(circle,rectangle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 5:
			shape1 = new ComposedShape(circle,circle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 6:
			shape1 = new ComposedShape(circle,triangle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 7:
			shape1 = new ComposedShape(triangle,rectangle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 8:
			shape1 = new ComposedShape(triangle,circle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		case 9:
			shape1 = new ComposedShape(triangle,triangle1);
			try {
				shape1.optimalFit();
			} catch (CloneNotSupportedException e) {
				System.out.printf("Something went wrong.");
			}
			break;
		}
		
		
		
		if(choice != 0){
			shape1.getContainer().draw(g);
			shape1.draw(g);
		}
		
		
	}
	
	
	
	
}
