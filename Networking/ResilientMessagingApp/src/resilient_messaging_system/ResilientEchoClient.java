package resilient_messaging_system;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class ResilientEchoClient {
    public static void main(String[] args) {
        String hostname = "localhost";
        int port = 12345;

        try (Scanner consoleScanner = new Scanner(System.in)) {
            while (true) {
                System.out.print("\nEnter a message to send (or 'exit' to quit): ");
                String messageToSend = consoleScanner.nextLine();

                if ("exit".equalsIgnoreCase(messageToSend)) {
                    break;
                }

                try (
                        Socket socket = new Socket(hostname, port);
                        OutputStreamWriter writer = new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8);
                        InputStreamReader reader = new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8)
                ) {
                    String formattedMessage = messageToSend.length() + ":" + messageToSend;
                    writer.write(formattedMessage);
                    writer.flush();
                    System.out.println("Sent: " + formattedMessage);

                    System.out.println("\n--- Server Response ---");
                    readServerResponse(reader);
                    System.out.println("-----------------------");

                } catch (IOException e) {
                    System.out.println("Error: Could not connect to the server or connection lost.");
                }
            }
        }
        System.out.println("Client shutting down.");
    }

    private static void readServerResponse(Reader reader) {
        try {
            StringBuilder lengthBuilder = new StringBuilder();
            int charCode;
            while ((charCode = reader.read()) != -1) {
                char c = (char) charCode;
                if (c == ':') {
                    break;
                }
                lengthBuilder.append(c);
            }

            if (charCode == -1) {
                System.out.println("Error: Connection Lost / Premature Disconnect. No complete header received.");
                return;
            }

            int expectedLength;
            try {
                expectedLength = Integer.parseInt(lengthBuilder.toString());
            } catch (NumberFormatException e) {
                System.out.println("Error: Malformed Message Header. Could not parse length.");
                return;
            }

            char[] contentBuffer = new char[expectedLength];
            int totalCharsRead = 0;
            int charsRead;

            while(totalCharsRead < expectedLength && (charsRead = reader.read(contentBuffer, totalCharsRead, expectedLength - totalCharsRead)) != -1) {
                totalCharsRead += charsRead;
            }

            String receivedContent = new String(contentBuffer, 0, totalCharsRead);

            if (totalCharsRead < expectedLength) {
                System.out.println("Error: Message Truncated or Incomplete.");
                System.out.println("Expected " + expectedLength + " characters, but received " + totalCharsRead + ".");
                System.out.println("Received content: " + receivedContent);
            } else {
                System.out.println("Received successfully: " + receivedContent);
            }

        } catch (SocketException e) {
            System.out.println("Error: Connection Lost / Premature Disconnect. (" + e.getMessage() + ")");
        } catch (IOException e) {
            System.out.println("An I/O error occurred: " + e.getMessage());
        }
    }
}