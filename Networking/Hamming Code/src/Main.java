import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter binary data: ");
        String data = sc.nextLine().trim();
        int m = data.length();
        int r = 0;
        while (Math.pow(2, r) < m + r + 1) {
            r++;
        }
        int totalBits = m + r;
        int[] hammingCode = new int[totalBits + 1];
        int j = 0;
        for (int i = 1; i <= totalBits; i++) {
            if ((Math.log(i) / Math.log(2)) % 1 == 0) {
                hammingCode[i] = 0;
            } else {
                hammingCode[i] = data.charAt(j++) - '0';
            }
        }
        for (int i = 0; i < r; i++) {
            int parityPos = (int) Math.pow(2, i);
            int parity = 0;
            for (int k = 1; k <= totalBits; k++) {
                if (((k >> i) & 1) == 1 && k != parityPos) {
                    parity ^= hammingCode[k];
                }
            }
            hammingCode[parityPos] = parity;
        }
        System.out.print("Generated Hamming code: ");
        for (int i = 1; i <= totalBits; i++) {
            System.out.print(hammingCode[i]);
        }
        System.out.print("\n\nEnter received Hamming code: ");
        String received = sc.nextLine().trim();
        int[] receivedCode = new int[totalBits + 1];
        for (int i = 1; i <= totalBits; i++) {
            receivedCode[i] = received.charAt(i - 1) - '0';
        }
        int errorPos = 0;
        for (int i = 0; i < r; i++) {
            int parity = 0;
            for (int k = 1; k <= totalBits; k++) {
                if (((k >> i) & 1) == 1) {
                    parity ^= receivedCode[k];
                }
            }
            if (parity != 0) {
                errorPos += Math.pow(2, i);
            }
        }
        if (errorPos == 0) {
            System.out.println("No error detected in the received code.");
        } else {
            System.out.println("Error detected at position: " + errorPos);
            receivedCode[errorPos] ^= 1;
            System.out.print("Corrected code: ");
            for (int i = 1; i <= totalBits; i++) {
                System.out.print(receivedCode[i]);
            }
        }
        sc.close();
    }
}
