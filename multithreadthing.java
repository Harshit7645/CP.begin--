public class multithreadthing extends Thread {
    private int ThreadNumber;
    public multithreadthing(int ThreadNumber)
    {
        this.ThreadNumber = ThreadNumber;
    }
    @Override
    public void run(){
        for(int i=1;i<=5;i++)
        {
            System.out.println(i+" from thread "+ ThreadNumber);
            if(ThreadNumber == 3){
                throw new RuntimeException();
            }
            try{
            Thread.sleep(1000);
            }
            catch (InterruptedException e){
            }
        }
    }
}
