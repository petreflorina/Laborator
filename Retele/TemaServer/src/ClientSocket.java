import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;

public class ClientSocket {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		final String host = "gazda";
		final int portNumber = 84;

		System.out.println("Creez socket la '" + host + "' la portul "
				+ portNumber);
		Socket socket = new Socket();// host, portNumber);
		
		while (true) {
			
			socket.connect(new InetSocketAddress(host, portNumber), 1000);
			
			for (int i = 0; i < getPachete().length; i++) {

			BufferedReader br = new BufferedReader(new InputStreamReader(
					socket.getInputStream()));
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

			System.out.println("server:" + br.readLine());

			// BufferedReader userInputBR = new BufferedReader(new
			// InputStreamReader(System.in));

			
				String userInput = ((String[]) getPachete())[i];// userInputBR.readLine();

				out.println(userInput);

				System.out.println("server:" + br.readLine());

				if ("exit".equalsIgnoreCase(userInput)) {
					socket.close();
					break;
				}
			}
		}

	}

	public static String[] getPachete() {

		return new String[] { "pachet1", "pachet2", "pachet3" };
	}

}
