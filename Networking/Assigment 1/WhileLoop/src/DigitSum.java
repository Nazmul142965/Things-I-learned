import java.util.Scanner;

public class DigitSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int number = scanner.nextInt();
        int sum = 0;


        while (number != 0) {
            int digit = number % 10;
            sum += digit;
            number /= 10;
        }

        System.out.println("The sum of the digits of " + number + " is: " + sum);
        scanner.close();
    }
}
