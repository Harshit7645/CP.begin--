public class multithread extends Thread {
    public static void main(String[] args) {
        for(int i=0;i<5;i++)
        {
            multithreadthing myThing = new multithreadthing(i);
            myThing.start();
            try{
                myThing.join();
            }
            catch (InterruptedException e){
                
            }
        }
    }
}

