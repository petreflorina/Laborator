package stringSearch;

import java.util.Scanner;


public class stringSearch {

	private static void searchingString(String bossString, String target){
		
		boolean isSubstring = true;
		
		for(int i=0; i<bossString.length(); i++)
			if(bossString.charAt(i) == target.charAt(0))
			{
				int index = i;
				for(int k=1; k<target.length(); k++)
				{	
					index++;
					if(bossString.charAt(index) != target.charAt(k))
					{	
						isSubstring = false;
						break;
					}
				}	
					
			}
		if (isSubstring) System.out.println(target + " este substringu al lui " + bossString); 
			
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("inserati stringurile: ");
		Scanner sc = new Scanner(System.in);

		String S1 = sc.next(), bossString = "", target = "";
		
		String[] motherString = S1.split(",");
		
		bossString = motherString[0];
		System.out.println(bossString);
		
		target = motherString[1];
		System.out.println(target);
		
		searchingString(bossString, target);
		sc.close();
	}

}
