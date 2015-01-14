package problemaSpectacole;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Spectacole {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		List<Spectacol> spectacol = new ArrayList<Spectacol>();
		
		int n=0;
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Dati numarul de spectacole");
		
		n = sc.nextInt();
		
	}

}


class Spectacol{
	int startHr, finishHr;
}