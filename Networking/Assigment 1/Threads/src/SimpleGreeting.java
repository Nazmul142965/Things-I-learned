public class SimpleGreeting {
    public static void main(String[] args) {
        GreetingTask task = new GreetingTask();
        Thread t = new Thread(task);
        t.start();
    }
}


class GreetingTask implements Runnable {
    @Override
    public void run() {
        System.out.println("Hello World");
    }
}
