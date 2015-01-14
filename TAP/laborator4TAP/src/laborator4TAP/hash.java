package laborator4TAP;
import java.util.*;
public class hash {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Set<String> obj = new HashSet<String>();
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Dati nr de nume:");
		int n = sc.nextInt(); 
		System.out.println("Dati numele:");
	
		String s = null;
		for(int i=0; i<n; i++)
		{
			obj.add(sc.next());
		}
		
		Iterator it = obj.iterator();
		int maxLength = 0;
		String a=null;
		while(it.hasNext())
		{
			a = (String)it.next();
			if(a.length() > maxLength) 
				{
					s = a;
					maxLength = a.length();
				}
		}
		
		System.out.print(s+ " "+ maxLength);
		
		

		sc.close();
	}
	

}
