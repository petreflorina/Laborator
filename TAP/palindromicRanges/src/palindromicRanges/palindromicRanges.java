package palindromicRanges;

import java.util.Scanner;


public class palindromicRanges {
	
	public static boolean isPalindrom(int target) {
	
		int targetCopy = target, test = 0;
		boolean ok = false;
		
		while (targetCopy > 0)
		{
			test =  test * 10 + targetCopy%10;
			targetCopy /= 10;
		}
		if (target == test) ok = true;
		return ok;
	}
public static void numberOfIntersting(int l, int r){
	
	int numberOfEven = 0;
	
	for(int i=l; i<r; i++)
		for(int j=i+1; j<=r; j++)
		{
			int numberOfPalindroms = 0;
			for(int k=i; k<=j; k++)
				if(isPalindrom(k)) numberOfPalindroms++;
			
			if(isPalindrom(i)) numberOfPalindroms++;
			if(isPalindrom(j)) numberOfPalindroms++;
			
			if(numberOfPalindroms % 2 == 0) numberOfEven++;
		}
	
	System.out.println("Numarul de intervale interesante este: " + numberOfEven);
			
}
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.print("Introduceti numarul de intervale: ");
		int numberIntervals = sc.nextInt();
		
		for(int i=0; i<numberIntervals; i++)
		{
			System.out.print("Introduceti capatul stang al intervalului: ");
			int l = sc.nextInt();
		
			System.out.print("Introduceti capatul drept al intervalului: ");
			int r = sc.nextInt();
			
			numberOfIntersting(l, r);
		}
		sc.close();
	}

}
