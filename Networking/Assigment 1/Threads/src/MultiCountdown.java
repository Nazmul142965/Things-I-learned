public class MultiCountdown {
    public static void main(String[] args) {
        Thread thread1 = new Thread(new Counter("Thread 1", 5));
        Thread thread2 = new Thread(new Counter("Thread 2", 7));

        thread1.start();
        thread2.start();
    }
}


class Counter implements Runnable {
    private String threadName;
    private int startValue;


    public Counter(String threadName, int startValue) {
        this.threadName = threadName;
        this.startValue = startValue;
    }

    @Override
    public void run() {
        for(int i = startValue; i > 0; i--){
            System.out.println(threadName + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}