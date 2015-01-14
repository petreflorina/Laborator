import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;

public class Client {

    public static void main(String[] args) throws IOException {

        final String host = "localhost";
        final int portNumber = 84;

        System.out.println("Creez socket la '" + host + "' la portul "
                + portNumber);

        for (int i = 0; i < getPachete().length; i++) {

            Socket socket = new Socket();
            socket.connect(new InetSocketAddress(host, portNumber), 1000);

            BufferedReader br = new BufferedReader(new InputStreamReader(
                    socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            System.out.println("server:" + br.readLine());

            String userInput = ((String[]) getPachete())[i] + '0';

            while (true) {
                try {
                    out.println(userInput);
                    String s = br.readLine();

                    if(s != null) {
                        System.out.println("server:" + s);
                        break;
                    }
                } catch (Exception e) {

                }
            }
            socket.close();
        }
    }

    public static String[] getPachete() {

        return new String[]{"pachet1", "pachet2", "pachet3"};
    }

}
