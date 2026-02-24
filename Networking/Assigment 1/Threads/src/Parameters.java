class CountdownTask implements Runnable {
    private String threadName;
    private int startNumber;

    public CountdownTask(String threadName, int startNumber) {
        this.threadName = threadName;
        this.startNumber = startNumber;
    }

    @Override
    public void run() {
        for (int i = startNumber; i > 0; i--) {
            System.out.println(this.threadName + ": " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(this.threadName + " was interrupted.");
            }
        }
    }
}

public class Parameters {
    public static void main(String[] args) {
        CountdownTask task1 = new CountdownTask("Thread A", 5);
        CountdownTask task2 = new CountdownTask("Thread B", 8);

        Thread thread1 = new Thread(task1);
        Thread thread2 = new Thread(task2);

        thread1.start();
        thread2.start();
    }
}
