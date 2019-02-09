import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;



public class main_161044007 {
	
	public static void main(String[] args){

		
		
		/*************************************************************GUI CODES************************************************************/
		final JFrame frame = new JFrame("draw() - optimalfit() ");
		frame.setBounds(120, 170, 800, 550);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setVisible(true);
		
		final DrawPanel panel = new DrawPanel();
		panel.setBounds(10, 10, 580, 480);
		panel.setBackground(Color.pink);
		frame.getContentPane().add(panel);
		
		/*A button that prints Rectangle-Rectangle combination on the GUI.*/
		JButton btn1 = new JButton("Rectangle Rectangle");
		btn1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(1);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn1.setBounds(600, 20, 190, 23);
		frame.getContentPane().add(btn1); // button reference copied
		
		
		/*A button that prints Rectangle-Circle combination on the GUI.*/
		JButton btn2 = new JButton("Rectangle Circle");
		btn2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(2);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn2.setBounds(600, 50, 190, 23);
		frame.getContentPane().add(btn2); // button reference copied
		
		
		/*A button that prints Rectangle-Triangle combination on the GUI.*/
		JButton btn3 = new JButton("Rectangle 	Triangle");
		btn3.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(3);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn3.setBounds(600, 80, 190, 23);
		frame.getContentPane().add(btn3); // button reference copied
		
		
		/*A button that prints Circle-Rectangle combination on the GUI.*/
		JButton btn4 = new JButton("Circle Rectange");
		btn4.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(4);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn4.setBounds(600,110, 190, 23);
		frame.getContentPane().add(btn4); // button reference copied
		
		/*A button that prints Circle-Circle combination on the GUI.*/
		JButton btn5 = new JButton("Circle Circle");
		btn5.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(5);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn5.setBounds(600,140, 190, 23);
		frame.getContentPane().add(btn5); // button reference copied
		
		/*A button that prints Circle-Triangle combination on the GUI.*/
		JButton btn6 = new JButton("Circle Triangle");
		btn6.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(6);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn6.setBounds(600,170, 190, 23);
		frame.getContentPane().add(btn6); // button reference copied
		
		
		/*A button that prints Triangle-Rectangle combination on the GUI.*/
		JButton btn7 = new JButton("Triangle Rectangle");
		btn7.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(7);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn7.setBounds(600,200, 190, 23);
		frame.getContentPane().add(btn7);
		
		/*A button that prints Triangle-Circle combination on the GUI.*/
		JButton btn8 = new JButton("Triangle Circle");
		btn8.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(8);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn8.setBounds(600,230, 190, 23);
		frame.getContentPane().add(btn8);
		
		
		/*A button that prints Triangle-Triangle combination on the GUI.*/
		JButton btn9 = new JButton("Triangle Triangle");
		btn9.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				panel.setChoice(9);
				Graphics g = panel.getGraphics();
				panel.setBackground(Color.pink);
				panel.paintComponent(g);
			}
		});

		btn9.setBounds(600,260, 190, 23);
		frame.getContentPane().add(btn9); // button reference copied

		/*A button which clears the screen.*/
		JButton btnClear = new JButton("Clear");
		btnClear.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.pink); // from now on, use white color
				g.fillRect(0, 0, 800, 500); 
				panel.paintComponents(g); // the panel will change when THIS function is executed
			}
		});
	
		btnClear.setBounds(600, 460, 190, 23);
		frame.getContentPane().add(btnClear);
		/*******************************************************************************************************************/
		
		
		
		
		
		
		
		
		
		/************************************TEST CODES (DRIVER)************************************************************/
		
		
		
		
		
		
		
/*Rectangle*/
		System.out.printf("\n\n\n---Rectangle----");
		Rectangle rec1 = new Rectangle(100,100,10,10);
		Rectangle rec2 = new Rectangle(300,300);
		Rectangle rec3 = new Rectangle(30);
		Rectangle rec4 = new Rectangle();
		
		
		rec1.setWidth(200);
		rec1.setHeight(200);
		rec1.setX(20);
		rec1.setX(20);
		
		
		rec3.setX(20);
		
		System.out.printf("\nRectangle width=%f.2",rec1.getWidth());
		System.out.printf("\nRectangle height=%f.2",rec1.getHeight());
		System.out.printf("\nRectangle x=%.2f",rec1.getX());
		System.out.printf("\nRectangle y=%.2f",rec1.getY());
		
		System.out.printf("\nRectangle area: %f.2",rec1.area());
		System.out.printf("\nRectangle perimeter: %f.2",rec1.perimeter());
		System.out.printf("\nRectangle.increment()");
		rec1.increment();
		System.out.printf("\nRectangle x=%f.2",rec1.getX());
		System.out.printf("\nRectangle y=%f.2",rec1.getY());
		System.out.printf("\nRectangle.decrement()");
		rec1.decrement();
		System.out.printf("\nRectangle x=%f.2",rec1.getX());
		System.out.printf("\nRectangle y=%f.2",rec1.getY());
		
		System.out.printf("\nCompateTO;");
		System.out.printf("\n%d",rec1.compareTo(rec2));		
		rec2.setWidth(200);
		rec2.setHeight(200);
		System.out.printf("\n%d",rec1.compareTo(rec2));	
		
		
		
		System.out.printf("\nshow_total_area()");
		System.out.printf("\n%.2f",rec1.show_total_area());
		System.out.printf("\nshow_total_perimeter()");
		System.out.printf("\n%.2f",rec1.show_total_perimeter());
		System.out.printf("\nincrease_total_area()");
		rec1.increase_total_area();
		System.out.printf("\nincreaseTotalPerimeter()");
		rec1.increase_total_perimeter();
		System.out.printf("\nshow_total_area()");
		System.out.printf("\n%.2f",rec1.show_total_area());
		System.out.printf("\nshow_total_perimeter()");
		System.out.printf("\n%.2f",rec1.show_total_perimeter());
		
		System.out.printf("\nClone;(redo)");
		try {
			rec4 = rec1.clone();
		} catch (CloneNotSupportedException e) {
			System.out.printf("\nError");
		}
		System.out.printf("\nAreas: %.2f-%.2f",rec4.area(),rec1.area());
	
/*Circle*/
		System.out.printf("\n\n\n---Circle---");
		Circle circ1=new Circle(100);
		Circle circ2=new Circle();
		
		circ1.setX(100);
		circ1.setY(300);
		circ1.setRadius(300);
		
		System.out.printf("\nradius %f \nx coordinate:%.2f \ny coordinate:%.2f",
				circ1.getRadius(),
				circ1.getX(),
				circ1.getY());
		
		System.out.printf("\nArea:%.2f",circ1.area());
		System.out.printf("\nPerimeter:%.2f",circ1.perimeter());
		
		System.out.printf("\nincrement();");	
		circ1.increment();
		System.out.printf("\nx coordinate:%.2f \ny coordinate:%.2f",
				circ1.getX(),
				circ1.getY());
		System.out.printf("\ndecrement();");	
		circ1.decrement();
		System.out.printf("\nx coordinate:%.2f \ny coordinate:%.2f",
				circ1.getX(),
				circ1.getY());
		
		System.out.printf("\nCompareTo();");
		System.out.printf("\n%d",circ1.compareTo(circ2));
		circ2.setRadius(300);
		System.out.printf("\n%d",circ1.compareTo(circ2));
		
		
		System.out.printf("\nshow_total_area()");
		System.out.printf("\n%.2f",circ1.show_total_area());
		System.out.printf("\nshow_total_perimeter()");
		System.out.printf("\n%.2f",circ1.show_total_perimeter());
		System.out.printf("\nincrease_total_area()");
		circ1.increase_total_area();
		System.out.printf("\nincreaseTotalPerimeter()");
		circ1.increase_total_perimeter();
		System.out.printf("\nshow_total_area()");
		System.out.printf("\n%.2f",circ1.show_total_area());
		System.out.printf("\nshow_total_perimeter()");
		System.out.printf("\n%.2f",circ1.show_total_perimeter());
		
		
		System.out.printf("\nClone;(Examine the code)");
		try {
			circ2 = circ1.clone();
		} catch (CloneNotSupportedException e) {
			System.out.printf("\nError");
		}
		System.out.printf("\nAreas: %.2f-%.2f",circ2.area(),circ1.area());
		
		
		
		
/*Triangle*/
		System.out.printf("\n\n\n---Triangle---");
		
		
		Triangle tri1 = new Triangle(10);
		Triangle tri2 = new Triangle();
		
		java.awt.Polygon polygon = tri1.getPolygon();
		
		int[] arr1 = tri1.getArrayX();
		int[] arr2 = tri1.getArrayY();
		
		System.out.printf("\ngetArrayX() - getArrayY();");
		System.out.printf("\nX: %d %d %d - Y: %d %d %d",
				arr1[0],arr1[1],arr1[2],
				arr2[0],arr2[1],arr2[2]);	
		
		System.out.printf("\ngetLenth():");
		System.out.printf("\n%f",tri1.getLength());
		
		System.out.printf("\ngetX1():%d \ngetX1():%d \ngetX1():%d " +
				"\ngetY1():%d \ngetY2():%d \ngetY3():%d",
				tri1.getX1(),tri1.getX2(),tri1.getX3(),
				tri1.getY1(),tri1.getY2(),tri1.getY3());
		
		
		System.out.printf("\n\nsetPolygon()\n\n");
		tri1.setPolygon(polygon);
		
		System.out.printf("\nsetX1(1) \nsetX1(2) \nsetX1(3) " +
				"\nsetY1(4) \nsetY2(5) \nsetY3(6)");
		tri1.setX1(1);
		tri1.setX2(2);
		tri1.setX3(3);
		tri1.setY1(4);
		tri1.setY2(5);
		tri1.setY3(6);
		
		System.out.printf("\ngetX1():%d \ngetX1():%d \ngetX1():%d " +
				"\ngetY1():%d \ngetY2():%d \ngetY3():%d",
				tri1.getX1(),tri1.getX2(),tri1.getX3(),
				tri1.getY1(),tri1.getY2(),tri1.getY3());
		
		System.out.printf("\n\narea():%f",tri1.area());
		System.out.printf("\nperimeter():%f",tri1.perimeter());
		
		System.out.printf("\nincrement()");
		tri1.increment();
		System.out.printf("\nx1:%d,y1:%d",tri1.getX1(),tri1.getY1());
		System.out.printf("\ndecrement()");
		tri1.decrement();
		System.out.printf("\nx1:%d,y1:%d",tri1.getX1(),tri1.getY1());
		
		System.out.printf("\nCompareTo();");
		tri2.setLength(100);
		System.out.printf("\n%d",tri1.compareTo(tri2));
		tri2.setLength(10);
		System.out.printf("\n%d",tri1.compareTo(tri2));
		
		
		System.out.printf("\nshow_total_area()");
		System.out.printf("\n%.2f",tri1.show_total_area());
		System.out.printf("\nshow_total_perimeter()");
		System.out.printf("\n%.2f",tri1.show_total_perimeter());
		System.out.printf("\nincrease_total_area()");
		tri1.increase_total_area();
		System.out.printf("\nincreaseTotalPerimeter()");
		tri1.increase_total_perimeter();
		System.out.printf("\nshow_total_area()");
		System.out.printf("\n%.2f",tri1.show_total_area());
		System.out.printf("\nshow_total_perimeter()");
		System.out.printf("\n%.2f",tri1.show_total_perimeter());
		
		
		System.out.printf("\nClone;(Examine the code)");
		try {
			tri2 = tri1.clone();
		} catch (CloneNotSupportedException e) {
			System.out.printf("\nError");
		}
		System.out.printf("\nAreas: %.2f-%.2f",tri2.area(),tri1.area());
		
		
		
		
/*ComposedShape*/
		System.out.printf("\n\n\n---ComposedShape---");
		
		Rectangle rectangle = new Rectangle(500,445);
		Rectangle rectangle1 = new Rectangle(50,90);
		
		Triangle triangle = new Triangle(500);
		Triangle triangle1 = new Triangle(70);
		
		Circle circle = new Circle(230);
		Circle circle1 = new Circle(15);
	
		ComposedShape composed0 = new ComposedShape();
		ComposedShape composed1 = new ComposedShape(rectangle,rectangle1);
		ComposedShape composed2 = new ComposedShape(rectangle,circle1);
		ComposedShape composed3 = new ComposedShape(rectangle,triangle1);
		ComposedShape composed4 = new ComposedShape(circle,rectangle1);
		ComposedShape composed5 = new ComposedShape(circle,circle1);
		ComposedShape composed6 = new ComposedShape(circle,triangle1);
		ComposedShape composed7 = new ComposedShape(triangle,rectangle1);
		ComposedShape composed8 = new ComposedShape(triangle,circle1);
		ComposedShape composed9 = new ComposedShape(triangle,triangle1);
		
		/*!!!!!!!!!!!!!!!!1IMPORTANT NOTE!!!!!!!!!!!!!!!!!!!!!!
		 * 
		 * This part tests above function. Besides that i tested this function
		 * inside the GUI.
		 * 
		 * 
		 * RectangleRectangle()
		 * RectangleCircle()
		 * RectangleTriangle()
		 * CircleRectangle()
		 * CircleCircle()
		 * CircleTriangle()
		 * TriangleRectangle()
		 * TriangleCircle()
		 * TriagleTriangle()
		 * 
		 * */
		try {
			composed1.optimalFit();
			composed2.optimalFit();
			composed3.optimalFit();
			composed4.optimalFit();
			composed5.optimalFit();
			composed6.optimalFit();
			composed7.optimalFit();
			composed8.optimalFit();
			composed9.optimalFit();
		} catch (CloneNotSupportedException e) {
			System.out.printf("\n\nSomething Went Wrong!!");
		}
		
		System.out.printf("\nComposed.getShapes()");
		Shape[] shapes = composed1.getShapes();
		System.out.printf("\nshapeslength():%d",shapes.length);
		System.out.printf("\ncomposed.getSize():%d",composed1.getSize());
		
		
		Rectangle recc1=(Rectangle) composed1.getContainer();
		Rectangle recc2=(Rectangle) composed1.getInner();
		
		
		composed1.setContainer(rec1);
		composed1.setInner(rec2);
		
		System.out.printf("\nComposed area:%.2f",composed1.area());
		System.out.printf("\nComposed perimeter:%.2f",composed1.perimeter());
		
		System.out.printf("\nComposedShape.increment()");
		composed1.increment();
		System.out.printf("\nComposedShape.decrement()");
		composed1.decrement();
		
		System.out.printf("\nComposed.add(shape)");
		try {
			composed1.add(recc1);
		} catch (CloneNotSupportedException e) {
			System.out.printf("\nSomethicg went wrong");
		}
		
		System.out.printf("\ncomposedShape.clear()");
		composed1.clear();
		
		System.out.printf("\ncircle_equation():%d",composed1.circle_equation(10, 15, 100));
		
		
/*PolygonDyn*/
		System.out.printf("\n\n\n---PolygonDyn---");
		
		PolygonDyn dyn1 = new PolygonDyn();
		PolygonDyn dyn2 = new PolygonDyn(rec1);
		PolygonDyn dyn3 = new PolygonDyn(tri1);
		PolygonDyn dyn4 = new PolygonDyn(circ1);
		
		System.out.printf("\ngetCapacity:%d Used:%d",
				dyn2.getCapacity(),dyn2.getUsed());
		
		System.out.printf("\ngetPoints");
		Polygon.Point2D[] point = dyn2.getPoints();
		
		System.out.printf("\narea():%.2f",dyn2.area());
		System.out.printf("\narea():%.2f",dyn2.perimeter());
		
		System.out.printf("\nCompareTo():%d",dyn3.compareTo(dyn4));
		PolygonDyn dyn5 = new PolygonDyn(tri1);
		System.out.printf("\nCompareTo():%d",dyn3.compareTo(dyn5));
		
		System.out.printf("\nIncrement()");
		dyn5.increment();
		System.out.printf("\nDecrement()");
		dyn4.decrement();
		
		
		System.out.printf("\n\nUsed:%d",dyn4.getUsed());
		System.out.printf("\nAdd()");
		dyn4.add(point[2]);
		System.out.printf("\nUsed:%d",dyn4.getUsed());

/*Point2D*/
		System.out.printf("\n\n\n---Point2D---");
		
		System.out.printf("\ngetx:%d , gety:%d",point[1].getX(),point[1].getY());
		System.out.printf("\nsetX(100),setY(100)");
		point[1].setX(100);
		point[1].setY(100);
		System.out.printf("\ngetx:%d , gety:%d",point[1].getX(),point[1].getY());
		
/*PolygonVect*/
		System.out.printf("\n\n\n---PolygonVect---");
		
		ArrayList<Polygon.Point2D> points = new ArrayList<Polygon.Point2D>();;
		points.add(point[0]);
		points.add(point[1]);
		points.add(point[2]);
		
		
		PolygonVect vec1 = new PolygonVect();
		PolygonVect vec2 = new PolygonVect(points);
		PolygonVect vec3 = new PolygonVect(rec1);
		PolygonVect vec4 = new PolygonVect(tri1);
		PolygonVect vec5 = new PolygonVect(circ1);
		
		System.out.printf("\narea():%.2f",vec2.area());
		System.out.printf("\narea():%.2f",vec2.perimeter());
		
		System.out.printf("\nCompareTo():%d",vec3.compareTo(vec4));
		PolygonVect vec6 = new PolygonVect(rec1);
		System.out.printf("\nCompareTo():%d",vec3.compareTo(vec6));
		
		System.out.printf("\nIncrement()");
		vec4.increment();
		System.out.printf("\nDecrement()");
		vec4.decrement();
		
		
		System.out.printf("\n\nsize():%d",vec1.size());
		System.out.printf("\nAdd()");
		vec1.add(point[0]);
		System.out.printf("\nsize():%d",vec1.size());
		
		
		
	
	/*Draw All function.*/
		Shape[] shapess = new Shape[5];
		

		Triangle triangle_ = new Triangle(300);
		Rectangle rectangle_ = new Rectangle(150,180);
		Circle circle_ = new Circle(120);
/**/	Triangle triangle11_ = new Triangle(500);
		

		circle_.setX(300);
		circle_.setY(300);
		Rectangle rectangle1_ = new Rectangle(150,200);
		rectangle_.setX(360);
		
		PolygonDyn plydyn = new PolygonDyn(rectangle1_);
		PolygonVect polygonvec = new PolygonVect(triangle11_);

		shapess[0] = triangle_;
		shapess[1] = rectangle_;
		shapess[2] = circle_;
		shapess[3] = plydyn;
		shapess[4] = polygonvec;

		
		System.out.printf("\ndrawAll();");
		StaticMethods.drawAll(shapess);
		
		
		/*SortShapes()*/
		System.out.printf("\n\n\n Areas;\n");
		
		for(int i=0;i<4;i++){
			System.out.printf(" %f ",shapess[i].area());
		}
		
		StaticMethods.sortShapes(shapess);
		
		System.out.printf("\n After StaticMethods.sortShapes();");
		
		System.out.printf("\n Areas;\n");
		
		for(int i=0;i<4;i++){
			System.out.printf(" %f ",shapess[i].area());
		}
		
		/*convertAll()*/
			
		shapes = StaticMethods.convertAll(shapess);
		
		if(shapes[0] instanceof PolygonVect){
			System.out.printf("\nArray converted to polygon succesfully");
		}
		
		
		
		
		/*EXCEPTIONS*/
		
		System.out.printf("\n----Exceptions----");
		
		try{
			Rectangle rec5 = new Rectangle(-10,-20,30,30);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		try{
			rec1.setWidth(-120);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		try{
			rec1.setHeight(-120);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		try{
			rec1.setX(-120);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		try{
			rec1.setY(-120);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		
		try{
			circ1.setRadius(-100);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		try{
			circ1.setX(-100);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
		
		try{
			circ1.setY(-100);
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}
	
		
		try{
			int[] arrt1=new int[4];
			tri1.setArrayX(arrt1);	
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Parameter.");
		}
		
		try{
			int[] arrt1=new int[4];
			tri1.setArrayY(arrt1);	
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Parameter.");
		}
		
		try{
			tri1.setLength(-100);	
		}catch(IllegalArgumentException e){
			System.out.printf("\nInvalid Input.");
		}

		
		try{
			composed0.area();
		}catch(NullPointerException e){
			System.out.printf("\nInner shapes is empty.");
		}
		
		try{
			composed0.perimeter();
		}catch(NullPointerException e){
			System.out.printf("\nInner shapes is empty.");
		}
		
		try{
			composed0.increment();
		}catch(NullPointerException e){
			System.out.printf("\nInner shapes is empty.");
		}
		
		try{
			composed0.decrement();
		}catch(NullPointerException e){
			System.out.printf("\nInner shapes is empty.");
		}
		
		try{
			Graphics g = null;
			composed0.draw(g);
		}catch(NullPointerException e){
			System.out.printf("\nInner shapes is empty.");
		}
		
		
	}
}
