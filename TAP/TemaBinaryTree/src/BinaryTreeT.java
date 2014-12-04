import java.util.Scanner;

public class BinaryTreeT {

	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println("Dati numarul de valori.");
		int nr = sc.nextInt();

		System.out.println("Dati valorile.");
		int val = sc.nextInt();

		Binarytree tree = new Binarytree(val);

		for (int i = 0; i < nr; i++) {
			val = sc.nextInt();
			tree.add(val);
		}
		
		System.out.println("Ce valoare doriti sa cautati?");
		val = sc.nextInt();
		
		if(tree.search(val)){
			System.out.println("Exista.");
		}else{
			System.out.println("Nu exista.");
			
		}
		
		tree.afisare();
	}

}

//
// interface PrimaryNode {
//
// public void setInfo(int info);
//
// public int getInfo();
//
// public void setLeft(Node left);
//
// public Node getLeft();
//
// public void setRight(Node right );
//
// public Node getRight();
// }

class Node {

	private int info;
	private Node left;
	private Node right;

	Node(int info) {
		this.info = info;
		right = null;
		left = null;
	}

	public void setInfo(int info) {
		this.info = info;
	}

	public int getInfo() {
		return info;
	}

	public void setLeft(Node left) {
		this.left = left;
	}

	public Node getLeft() {
		return left;
	}

	public void setRight(Node right) {
		this.right = right;
	}

	public Node getRight() {
		return right;
	}

}

class Binarytree {
	private Node root;

	public Binarytree(int data) {
		root = new Node(data);
	}

	public void add(int info) {
		add(info, root);
	}

	public boolean search(int info) {
		return search(info, root);
	}

	public void afisare(){
		System.out.print("Afisare SVD : ");
		SVD(root);
		System.out.println();
		System.out.print("Afisare VSD : ");
		VSD(root);
		System.out.println();
		System.out.print("Afisare SDV : ");
		SDV(root);
		System.out.println();
	}
	private void SVD(Node nod){
		if (nod != null){
			SVD(nod.getLeft());
			System.out.print(nod.getInfo()+" ");
			SVD(nod.getRight());
		}
	}
	
	private void VSD(Node nod){
		if(nod != null){
			System.out.print(nod.getInfo()+" ");
			VSD(nod.getLeft());
			VSD(nod.getRight());
		}
	}
	
	private void SDV(Node nod){
		if( nod != null){
			SDV(nod.getLeft());
			SDV(nod.getRight());
			System.out.print(nod.getInfo()+" ");
		}
	}
	
	private void add(int info, Node nod) {

		// verifica daca info e < nod.info
		if (info < nod.getInfo()) {
			// daca nod.st exista, merg mai departe
			if (nod.getLeft() != null) {
				add(info, nod.getLeft());
			}
			// altfel, creez nodul
			else {
				nod.setLeft(new Node(info));
			}
		} else { // daca info > nod.info, atunci trebuie adaugata in dreapta
			if (info > nod.getInfo()) {
				// daca nod.dr exista, merg mai departe recursiv
				if (nod.getRight() != null) {
					add(info, nod.getRight());
				} else {
					nod.setRight(new Node(info));
				}
			}
		}
	}

	private boolean search(int info, Node nod) {

		if (nod == null)
			return false;

		if (info == nod.getInfo()) {
			return true;
		} else {
			if (info < nod.getInfo()) {
				return search(info, nod.getLeft());
			} else {
				return search(info, nod.getRight());
			}
		}
		
	}

}

