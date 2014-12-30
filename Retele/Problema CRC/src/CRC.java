import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

///010111001
///1101
///result = 101

public class CRC {

	static List<Boolean> code = new ArrayList<Boolean>();
	static List<Boolean> generator = new ArrayList<Boolean>();
	static List<Boolean> reserve = new ArrayList<Boolean>();
	static int lastPositionCode = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String c = "010111001";
		String g = "1101";

		read(c, code);
		read(g, generator);
		addZero(code, generator);
		write(code);
		System.out
				.println("Apasati 1 pentru codificare sau 2 pentru decodificare.");

		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		System.out.print("CRC-ul este: ");
		division();
	}

	public static void division() {

		int reserveSize = 4, parameterReserve = 4;
		lastPositionCode = 3;
		for (int i = 0; i < reserveSize; i++) {
			reserve.add(code.get(i));
		}

		while (lastPositionCode < code.size()) {

			parameterReserve = addXor(reserveSize);
			fillReserve(parameterReserve, reserveSize);
		}
		write(reserve, reserveSize - 1);
	}

	public static void fillReserve(int parameterReserve, int reserveSize) {

		// /daca reserve-ul nu este complet, il compeltez
		if (parameterReserve < reserveSize) {
			for (int i = parameterReserve; i < reserveSize; i++) {
				lastPositionCode++;
				if (lastPositionCode < code.size()) {
					reserve.set(i, code.get(lastPositionCode));
				}
			}

		}
	}

	public static int addXor(int reserveSize) {

		int parameterReserve = 0;

		boolean found = false;
		// /verific daca primele caractere sunt 0, pana la intalnirea primului
		// 1, apoi introduc ce ramane din xor in reserve

		for (int i = 0; i < reserveSize; i++) {

			if (xor(reserve.get(i), generator.get(i))) {

				found = true;
			}
			if (found) {
				reserve.set(parameterReserve,
						xor(reserve.get(i), generator.get(i)));
				parameterReserve++;
			}
		}
		return parameterReserve;
	}

	public static void addZero(List<Boolean> receiver, List<Boolean> sender) {

		for (int i = 0; i < sender.size(); i++) {
			if (sender.get(i) == true) {
				receiver.add(false);
			}
		}
	}

	public static void write(List<Boolean> list) {

		write(list, list.size());
	}

	public static void write(List<Boolean> list, int size) {

		for (int i = 0; i < Math.min(list.size(), size); i++) {

			if (list.get(i) == true) {
				System.out.print('1' + " ");
			} else {
				System.out.print('0' + " ");
			}
		}
		System.out.println();
	}

	public static void read(String s, List<Boolean> list) {

		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1')
				list.add(i, true);
			else if (s.charAt(i) == '0') {
				list.add(i, false);
			}
		}

	}

	public static boolean xor(boolean x, boolean y) {

		return x ^ y;

	}

}