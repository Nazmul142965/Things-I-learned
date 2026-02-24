import java.util.Scanner;

public class Eligible {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please enter your age : ");
        int age = Integer.parseInt(scanner.nextLine());

        if(age >= 18){
            System.out.println("Eligible");
        }else{
            System.out.println("Not Eligible");
        }
    }
}
