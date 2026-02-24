public class ArrayIndex {
    public static void main(String[] args) {
        int[] myArray = new int[5];

        try {
            System.out.println("Accessing element at index 10...");
            int element = myArray[10];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Array index is out of bounds.");
        }
    }
}
