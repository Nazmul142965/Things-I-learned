import java.util.Scanner;

public class PNZ {
    public static void main(String[] args) {
        Scanner scanner  =  new Scanner(System.in);
        System.out.print("Enter an Integer : ");
        int number = scanner.nextInt();

        if(number>0){
            System.out.println("Positive");
        } else if (number<0) {
            System.out.println("Negative");
        } else  {
            System.out.println("Zero");
        }
    }
}
