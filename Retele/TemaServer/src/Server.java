import java.io.*;
import java.net.*;

public class Server {

	public static void main(String[] args) throws IOException {

		final int portNumber = 84;

		System.out.println("Creez un server socket cu portul " + portNumber);
		ServerSocket serverSocket = new ServerSocket(portNumber);
		serverSocket.setSoTimeout(1000);

		while (true) {

			Socket socket = null;

			try {

				socket = serverSocket.accept();

				OutputStream os = socket.getOutputStream();
				PrintWriter pw = new PrintWriter(os, true);

				pw.println("Asteptare pachet.");

				BufferedReader br = new BufferedReader(new InputStreamReader(
						socket.getInputStream()));
				String str = br.readLine();

				pw.println("Pachet primit: " + str);
				pw.close();
				socket.close();

			} catch (Exception e) {

			} finally {
				if (socket != null) {
					socket.close();
				}
			}
		}

	}

}
