import java.util.Scanner;

public class NumberGuessing {
    public static void main(String[] args) {
        int secretNumber = 5;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number to be guessed between 1 and 10: ");
        int guessNumber;

        while(true){
            guessNumber = scanner.nextInt();
            if(guessNumber < secretNumber){
                System.out.println("Too low!");
            }else if(guessNumber > secretNumber){
                System.out.println("Too high!");
            }else {
                System.out.println("Correct!");
                break;
            }
        }
    }
}
