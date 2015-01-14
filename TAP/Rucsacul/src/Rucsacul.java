import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Rucsacul {

	public static void main(String[] args) {
		
		int nr=0, g=0;
		List<Rucsac> rucsac = new ArrayList<Rucsac>();
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Dati greutatea maxima.");
		g = sc.nextInt();
		System.out.println("Dati numarul de rucsacuri.");
		nr = sc.nextInt();
		
		System.out.println("Dati greutatea si profitul fiecarui rucsac.");
		for(int i=0; i<nr; i++)
		{
			Rucsac rux = new Rucsac();
			
			rux.greutate = sc.nextInt();
			rux.profit = sc.nextInt();
			rucsac.add(rux);
		}
		
		sort(rucsac);
		solv(g,rucsac);
		
		sc.close();
	}
	
	static void solv(int g, List<Rucsac> rucsac){
		int maxProfit= 0, i=0;
		
		while(g>0 && i<rucsac.size())
		{
				
				if(g-rucsac.get(i).greutate >= 0)
				{
					maxProfit += rucsac.get(i).profit;
					g-=rucsac.get(i).greutate;
					
				}
				i++;
			
		}
		System.out.println("Profitul maxim este: "+maxProfit);

	}
	
	
	static void write( List<Rucsac> rucsac){
		for(int i=0; i<rucsac.size(); i++){
			System.out.println(i+" "+rucsac.get(i).greutate+" "+rucsac.get(i).profit);
		}
	}
	static void swap(List<Rucsac> rucsac,int i, int j){
		
		Rucsac aux = new Rucsac();
		aux = rucsac.get(i);
		
		rucsac.set(i, rucsac.get(j));
		rucsac.set(j, aux);
	
	}
	
	static void sort(List<Rucsac> rucsac){
		
		for(int i=0; i<rucsac.size()-1; i++){
			for(int j=i+1; j <rucsac.size(); j++){
				if(rucsac.get(i).profit < rucsac.get(j).profit)
				{
					
					swap(rucsac,i,j);
				}
				else
					if(rucsac.get(i).profit == rucsac.get(j).profit)
					{
						if(rucsac.get(i).greutate > rucsac.get(j).greutate){
							swap(rucsac,i,j);
								
						}
					}
			}
		}
	}

}

class Rucsac {
	public int greutate, profit;
}
