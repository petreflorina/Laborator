package problemaLunileAnului;
import java.util.*;

//pt fiecare luna  anului sa se citeasca un set de evenimente. 
//adaugare
//modificare
//stergere pentru o anumita luna
//cautarea unui eveniment
//luna cu nr maxim/min de evenimente


public class main {

	static Luna maximNoOfEvents(Set<Luna> luni){

		Iterator it = luni.iterator();
		int maxim = 0;
		Luna lunaNoMaxim=null;
		while(it.hasNext())
		{
			Luna luna =(Luna)it.next();
			if (luna.noOfEvents() >maxim){
				maxim = luna.noOfEvents();
				lunaNoMaxim = luna;
			}
		}
		return lunaNoMaxim;

	}
	static Luna minimNoOfEvents(Set<Luna> luni){

		Iterator it = luni.iterator();
		int minim = 100000;
		Luna lunaNoMinim=null;
		
		while(it.hasNext())
		{
			Luna luna =(Luna)it.next();
			if (luna.noOfEvents() < minim){
				minim = luna.noOfEvents();
				lunaNoMinim = luna;
			}
		}
		return lunaNoMinim;

	}
	
	static Luna findEvent(String event, Set<Luna> luni){
		
		Iterator it = luni.iterator();
		
	
		while(it.hasNext()){
			
			Luna luna = (Luna)it.next();
			if(luna.search(event))
			{
				return luna;
			}
		}
		return null;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Set<Luna> luni = new HashSet<Luna>();
		
		Luna Ianuarie = new Luna(1);
		Luna Februarie = new Luna(2);
		Luna Martie = new Luna(3);
		Luna Aprilie = new Luna(4);
		
		Ianuarie.add("tyy");
		Ianuarie.add("fiesta");
		Martie.add("paste");
		Aprilie.add("craciun");
	
	
		luni.add(Ianuarie);
		luni.add(Februarie);
		luni.add(Martie);
		luni.add(Aprilie);
		
		
		System.out.println("luna "+maximNoOfEvents(luni).ID+" cu numarul de evenimente "+ maximNoOfEvents(luni).noOfEvents());
		
		if(findEvent("craciun2", luni) != null){
		
			System.out.println("luna "+findEvent("craciun2", luni).ID+" are evenimentul craciun");
		}
		else 
			System.out.println("Nu exista eveniment.");
	}

}

class Luna {
	
	public int ID;
	public String nume;
	private Set<String> obj = new HashSet<String>();

	Luna(int ID)
	{
		this.ID = ID;
	}
	
	
	public void add(String event){
		obj.add(event);
	}
	
	public void delete(String event){
		obj.remove(event);
	}
	public void replace(String event, String rework){
		obj.remove(event);
		obj.add(rework);
	}
	public boolean search(String event)
	{
		Iterator it = obj.iterator();
		String s = null;
		
		while(it.hasNext())
		{
			s = (String)it.next();
			if(s.equalsIgnoreCase(event)) return true;
		}
		
		return false;
	}
	public int noOfEvents()
	{
		return obj.size();
	}
}