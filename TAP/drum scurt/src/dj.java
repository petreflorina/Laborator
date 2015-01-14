public class dj {

	public static int drumuri[][], d[], v[], intermediar[];
	public static int n = 5, m = 6;

	public static void init(int sursa) {

		for (int i = 0; i < n; i++) {
			d[i] = drumuri[sursa][i];
			v[i] = 0;

			if (d[i] < 100) {
				intermediar[i] = sursa;
			} else {
				intermediar[i] = 0;
			}
		}
	}

	public static void main(String[] args) {

		drumuri = new int[m][m];
		d = new int[n];
		v = new int[n];
		intermediar = new int[n];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++) {
				if (i == j)
					drumuri[i][j] = 0;
				else {
					drumuri[i][j] = 100;
				}
			}

		drumuri[0][1] = 5;
		drumuri[0][2] = 1;
		drumuri[0][3] = 4;
		drumuri[1][2] = 3;
		drumuri[1][3] = 7;
		drumuri[1][4] = 2;
		drumuri[1][0] = 5;
		drumuri[2][0] = 2;
		drumuri[2][3] = 1;
		drumuri[3][0] = 4;
		drumuri[2][1] = 3;
		drumuri[3][1] = 7;
		drumuri[3][4] = 1;
		drumuri[4][1] = 2;
		
		
		int sursa = 0;
		init(sursa);
		
		d[sursa] = 0;
		v[sursa] = 1;
		int k = 0;

		for (int i = 0; i < n; i++) {
			int minim = 100;

			for (int j = 0; j < n; j++) {
				if (v[j] != 1 && d[j] < minim) {
					minim = d[j];
					k = j;
				}
			}
			
			v[k] = 1;

			for (int j = 0; j < n; j++) {
				if (v[j] != 1 && d[k] + drumuri[k][j] < d[j]) {
					d[j] = d[k] + drumuri[k][j];
					intermediar[j] = k;

				}
			}
		}
		int nod=4;
		
		while(nod != sursa){
			System.out.print(nod+" ");
			nod = intermediar[nod];

			//System.out.print(nod+" ");
		}
	}

}
