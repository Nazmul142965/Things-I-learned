package resilient_messaging_system;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class FaultyEchoServer {
    public static void main(String[] args) {
        int port = 12345;
        System.out.println("Faulty Echo Server is running on port " + port);

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress());
                ClientHandler clientHandler = new ClientHandler(clientSocket);
                clientHandler.start();
            }
        } catch (IOException e) {
            System.err.println("Server error: " + e.getMessage());
        }
    }
}