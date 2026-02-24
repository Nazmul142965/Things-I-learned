import java.util.Scanner;

public class InputBuffer {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("--- Part A: nextInt() followed by nextLine() ---");
        System.out.print("Enter an integer: ");
        int number = scanner.nextInt();
        System.out.print("Enter a line of text: ");
        String line = scanner.nextLine();
        System.out.println("Integer read: " + number);
        System.out.println("Line read: '" + line + "' (Notice it's empty)");
        System.out.println();

        System.out.println("--- Part B: nextLine() and parsing ---");
        System.out.print("Enter an integer: ");
        int number2 = Integer.parseInt(scanner.nextLine());
        System.out.print("Enter a line of text: ");
        String line2 = scanner.nextLine();
        System.out.println("Integer read: " + number2);
        System.out.println("Line read: '" + line2 + "' (This works as expected)");

        scanner.close();
    }
}