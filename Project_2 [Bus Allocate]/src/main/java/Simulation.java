/*
Chattarin Muksagul 6213124
Chutiwat Watek 6213195
Tinh Chaisena 6213199
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.CyclicBarrier;

public class Simulation {
    
    public static int enterMaximumSeat(){
        
        Scanner scan;
        int maximumSeat=0;
        boolean loop = true;
        
        while(loop){
            
            try{
                System.out.println(Thread.currentThread().getName() + " >> Enter max seats  : ");
                scan = new Scanner(System.in);
                maximumSeat = scan.nextInt();
                if(maximumSeat <= 0)    throw new Exception("Wrong amoint of maximum seats.");
                else                    loop = false;
            }catch(Exception e){
                System.out.println("\n" + e + " Please try another input.\n");
            }
            
        }
        
        return maximumSeat;
        
    }
    
    public static int enterCheckpoint(){
        
        Scanner scan;
        int checkpoint=0;
        boolean loop = true;
        
        while(loop){
            
            try{
                System.out.println(Thread.currentThread().getName() + " >> Enter checkpoint  : ");
                scan = new Scanner(System.in);
                checkpoint = scan.nextInt();
                if(checkpoint <= 0)     throw new Exception("Wrong amoint of checkpoint.");
                else                    loop = false;
            }catch(Exception e){
                System.out.println("\n" + e + " Please try another input.\n");
            }
            
        }
        
        return checkpoint;
        
    }

    public static void main(String[] args) {
        
        int MaxSeat = enterMaximumSeat();
        int Checkpoint = enterCheckpoint();
        
        BusLine AirportBL   =   new BusLine("A",MaxSeat);
        BusLine CityBL      =   new BusLine("C",MaxSeat);
        
        ArrayList<TicketCounter> TCL = new ArrayList<>();
        CyclicBarrier finish = new CyclicBarrier(3);
        
        for(int i=1; i<=3; i++){
            
            try{
                
                //System.out.println("T" + i + ".txt");
                Scanner textFile = new Scanner(new File("T" + i + ".txt") );
                TCL.add(new TicketCounter("T"+i,AirportBL,CityBL,textFile,Checkpoint));
                TCL.get(i-1).setCyclicBarrier(finish);
                
            }catch(Exception e){
                System.out.println(e + ". \nThe text files are required to execute the program.\n");
                System.exit(0);
            }
            
        }
        
        for(TicketCounter n : TCL)  n.start();
        try{
            for(TicketCounter n : TCL)  n.join();
        }catch (InterruptedException e) { }
        
        System.out.println("\n" + Thread.currentThread().getName() + " >> ========== AIRPORT BOUND ==========");
        AirportBL.printSummaryReport();
        System.out.println("\n" + Thread.currentThread().getName() + " >> ==========   CITY BOUND  ==========");
        CityBL.printSummaryReport();
        
    }
    
}
