import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileReaders{
    public static void main(String[] args) {
        try (BufferedReader fileReader = new BufferedReader(new FileReader("my_story.txt"))) {
            String line;
            while ((line = fileReader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }
}