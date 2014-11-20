package problema2;

import java.util.Scanner;

public class main {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Point a = new Point();
		Point b = new Point();
		Point c = new Point();
		Point d = new Point();
		
		Scanner sc = new Scanner(System.in);
		
		readPoint(a, sc);
		readPoint(b, sc);
		readPoint(c, sc);
		readPoint(d, sc);
		
		if(determinerCalc(a, b, c) < 0 && determinerCalc(a, b, d) < 0) 
		{
			System.out.println("Formeaza poligon");
		}
		else
			if (determinerCalc(a, b, c) > 0 && determinerCalc(a, b, d) > 0) 
			{

				System.out.println("Formeaza poligon");
			}
			else 

				System.out.println("Nu formeaza poligon");
	}
	
	static int determinerCalc(Point a, Point b, Point c){
		
		return ((a.x * b.y * c.z)+(a.y * b.z*c.x)+(b.x*c.y*a.z) - ((c.x*b.y*a.z)+(a.x*b.z*c.y)+(b.x*a.y*c.z)));
	}
	static void readPoint(Point a, Scanner sc) {
		
		System.out.print("Dati coordonatele punctului: \n");
		a.x = sc.nextInt();
		a.y = sc.nextInt();
		a.z = sc.nextInt();
		
	}
}

class Point {
	
	int x, y, z;
}
