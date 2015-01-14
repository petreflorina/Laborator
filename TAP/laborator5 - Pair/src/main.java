import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;


public class main {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		createSet();
	
		
		Iterator it = luna.iterator();
	
		while(it.hasNext())
		{
			System.out.println(it.next());
		} 
	
		
	}


	static Set<Pair> luna = new HashSet<Pair>();
	
	public static void createSet()
	{
		luna.add(new Pair("Ian", 1));
		luna.add(new Pair("Feb", 2));
		luna.add(new Pair("Mar", 3));
		luna.add(new Pair("Apr", 4));
		luna.add(new Pair("Mai", 5));
		luna.add(new Pair("Iun", 6));
		luna.add(new Pair("Iul", 7));
		luna.add(new Pair("Aug", 8));
		luna.add(new Pair("Sep", 9));
		luna.add(new Pair("Oct", 10));
		luna.add(new Pair("Nov",11));
		luna.add(new Pair("Dec",12));
	}	
}


//enum Luni{Ian,Feb,Mar,Apr,Mai,Iun,Iul,Aug,Sep,Oct,Nov,Dec}

class Pair<S,T>
{
	private final S first;
	private final T second;

	public Pair(S first, T second)
	{
		this.first = first;
		this.second = second;
	}

	public S getFirst()
	{
		return first;
	}

	public T getSecond()
	{
		return second;
	}

	@Override
	public String toString()
	{
		return "("+first+", "+second+")";

	}

}

