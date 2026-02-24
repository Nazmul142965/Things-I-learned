import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ConsoleReader {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;

        System.out.println("Enter text. Type 'exit' to quit.");

        try {
            while ((line = reader.readLine()) != null && !line.equalsIgnoreCase("exit")) {
                System.out.println("You entered: " + line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Program terminated.");
    }
}
