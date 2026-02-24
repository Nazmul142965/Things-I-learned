import java.util.InputMismatchException;
import java.util.Scanner;

public class InputHandling {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        try{
            System.out.println("Enter An Integer: ");
            int num = input.nextInt();
            System.out.println("Number is: " + num);

        }catch(InputMismatchException e){
            System.out.println("Please enter an integer");
        }
    }
}
