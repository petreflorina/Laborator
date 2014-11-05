package problema2;

import java.util.Scanner;

public class main {
	
	public static void readPoint(Point a, Scanner sc) {
		
		System.out.print("Dati coordonatele punctului: \n");
		a.x = sc.nextInt();
		a.y = sc.nextInt();
		
	}
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
		
	}
	

}

class Point {
	
	int x, y;
}
