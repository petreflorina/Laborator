package backtr;

public class Permutari {

	public static int n;
	public static int vector[];

	public static boolean verif(int pos){
		
		for(int i=0; i<pos;i++){
			if(vector[i] == vector[pos])
				return false;
		}
		return true;
	}
	public static void afisare(){
		
		for(int i=0; i<n;i++){
			System.out.print(vector[i]);
		}
		System.out.println();
	}
	
	public static void back(int pos){
		
		if(pos == n){
			afisare();
		}else {
			for(int i=0; i<n; i++){
			
				vector[pos] = i+1;
				
				if(verif(pos)){
					back(pos+1);
				}
			}
		}
	}
	
	public static void main(String[] args) {
	
		n = 4;
			vector = new int[n];
			back(0);
	}

}
