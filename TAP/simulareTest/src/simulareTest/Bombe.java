package simulareTest;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Bombe {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int n, k;
		
		List<Bomba> listaBombe = new ArrayList<Bomba>();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Dati numarul de bombe.");
		n = sc.nextInt();
		
		System.out.println("Dati coordonatele punctelor, precum si raza acestora.");
		
		for(int i=0; i<n; i++)
		{
			Bomba bomba = new Bomba();
			bomba.x = sc.nextInt();
			bomba.y = sc.nextInt();
			bomba.r = sc.nextInt();
			bomba.index = i;
			listaBombe.add(bomba);
		}
		
		System.out.println("Dati indicele primei bombe care explodeaza.");
		
		k = sc.nextInt();
		
		List<Bomba> bombeExplodeaza = new ArrayList<Bomba>();
		
		bombeExplodeaza.add(listaBombe.get(k));
		listaBombe.get(k).ok = true;
		
		for(int j=0; j<bombeExplodeaza.size(); j++)
		{
		
			for(int i=0; i<listaBombe.size(); i++)
				{
				if ( listaBombe.get(i).index != bombeExplodeaza.get(j).index)
				{
					if (twoPointsDistance(bombeExplodeaza.get(j), listaBombe.get(i)) < bombeExplodeaza.get(j).r * bombeExplodeaza.get(j).r)
					{
						if(!listaBombe.get(i).ok)
						{
							bombeExplodeaza.add(listaBombe.get(i));
							listaBombe.get(i).ok = true;
						}
						
					}
				}
			}
		
		}
		
		System.out.println(listaBombe.size() - bombeExplodeaza.size());
	}
	
 static int twoPointsDistance(Bomba a, Bomba b)
 {
	 int distance = 0;
	 
	 distance = ( b.x - a.x)*( b.x - a.x) + (b.y - a.y)*(b.y - a.y);
	 
	 return distance;
 }

}

class Bomba {
	
	public int x,y,r, index;
	boolean ok = false;
}