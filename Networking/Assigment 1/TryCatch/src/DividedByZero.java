import java.util.Scanner;

public class DividedByZero {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try{
            System.out.print("Enter the numerator: ");
            int numerator = scanner.nextInt();

            System.out.println("Enter the denominator: ");
            int denominator = scanner.nextInt();

            int result = numerator/denominator;
            System.out.println("The divided by zero is: " + result);

        }catch(ArithmeticException e){
            System.out.println("Cannot divide by zero");
        }
    }
}
