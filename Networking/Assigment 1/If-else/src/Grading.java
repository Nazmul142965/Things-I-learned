import java.sql.SQLOutput;
import java.util.Scanner;

public class Grading {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your number : ");
        int num = scanner.nextInt();

        if(num >= 90 && num <= 100) {
            System.out.println("Grade : A");
        }else if(num >= 80 && num <= 89){
            System.out.println("Grade : B");
        }else if(num >= 70  && num <= 79){
            System.out.println("Grade : C");
        }else if(num >= 60 && num <= 69){
            System.out.println("Grade : D");
        }else if(num < 60){
            System.out.println("Grade : F");
        }

    }
}
