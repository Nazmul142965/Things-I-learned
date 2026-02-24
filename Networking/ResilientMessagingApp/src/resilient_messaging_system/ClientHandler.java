package resilient_messaging_system;

import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Random;

public class ClientHandler extends Thread {
    private final Socket clientSocket;
    private final Random random = new Random();

    public ClientHandler(Socket socket) {
        this.clientSocket = socket;
    }

    @Override
    public void run() {
        try (
                InputStreamReader reader = new InputStreamReader(clientSocket.getInputStream(), StandardCharsets.UTF_8);
                OutputStreamWriter writer = new OutputStreamWriter(clientSocket.getOutputStream(), StandardCharsets.UTF_8)
        ) {
            StringBuilder messageBuilder = new StringBuilder();
            int charCode;
            int length = -1;

            while ((charCode = reader.read()) != -1) {
                char character = (char) charCode;
                if (character == ':') {
                    try {
                        length = Integer.parseInt(messageBuilder.toString());
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Malformed header from client.");
                        return;
                    }
                }
                messageBuilder.append(character);
            }

            if (length != -1) {
                char[] buffer = new char[length];
                int bytesRead = reader.read(buffer, 0, length);
                if (bytesRead == length) {
                    String clientMessage = new String(buffer);
                    System.out.println("Received from client: " + length + ":" + clientMessage);

                    if (random.nextInt(100) < 20) {
                        sendFaultyResponse(writer, clientMessage);
                    } else {
                        sendNormalResponse(writer, clientMessage);
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Communication error with client: " + e.getMessage());
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                // Ignore
            }
        }
    }

    private void sendNormalResponse(Writer writer, String message) throws IOException {
        String response = message.length() + ":" + message;
        writer.write(response);
        writer.flush();
        System.out.println("Sent normal response: " + response);
    }

    private void sendFaultyResponse(Writer writer, String message) throws IOException {
        int faultType = random.nextInt(4);

        switch (faultType) {
            case 0:
                String truncatedContent = message.substring(0, message.length() / 2);
                writer.write(message.length() + ":" + truncatedContent);
                writer.flush();
                System.out.println("Sent FAULTY (Truncated) response.");
                clientSocket.close();
                break;

            case 1:
                String incorrectLengthResponse = (message.length() + 5) + ":" + message;
                writer.write(incorrectLengthResponse);
                writer.flush();
                System.out.println("Sent FAULTY (Incorrect Length) response: " + incorrectLengthResponse);
                break;

            case 2:
                char[] contentChars = message.toCharArray();
                if (contentChars.length > 0) {
                    int randomIndex = random.nextInt(contentChars.length);
                    contentChars[randomIndex] = '@';
                }
                String garbledContent = new String(contentChars);
                String garbledResponse = garbledContent.length() + ":" + garbledContent;
                writer.write(garbledResponse);
                writer.flush();
                System.out.println("Sent FAULTY (Garbled) response: " + garbledResponse);
                break;

            case 3:
                writer.write(message.length() + ":");
                writer.flush();
                System.out.println("Sent FAULTY (Premature Disconnect) response.");
                clientSocket.close();
                break;
        }
    }
}