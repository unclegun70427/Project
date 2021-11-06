/*
Chattarin Muksagul 6213124
Chutiwat Watek 6213195
Tinh Chaisena 6213199
*/

import java.io.File;
import java.util.Scanner;
import java.util.concurrent.CyclicBarrier;

public class TicketCounter extends Thread {
    
    private BusLine AirportBL,CityBL;
    private Scanner scan;
    private int checkpoint;
    private int order;
    protected  CyclicBarrier	cfinish;
    private static int check;
    
    public void setCyclicBarrier(CyclicBarrier f)	{ cfinish = f; }
    
    public TicketCounter(String name, BusLine ABL, BusLine CBL, Scanner TextFile, int cp){
        super(name);
        AirportBL = ABL;
        CityBL = CBL;
        scan = TextFile;
        checkpoint = cp;
        order = 1;
        check = 0;
    }
    
    public void run(){
        
        while(scan.hasNext()){
            
            try{
                
                String line = scan.nextLine();
                String [] buf = line.split(",");
                if(buf.length != 4) throw new Exception("Wrong amount of data. ");
                
                //---------------------------------------------------------------------------------------------------
                
                try{
                    
                    int Transaction = Integer.parseInt(buf[0].trim());
                    String TourName = buf[1].trim();
                    int Passengers = Integer.parseInt(buf[2].trim());
                    String Destination = buf[3].toUpperCase().trim();
                    
                    if(Transaction < 1) throw new Exception("Invalid transaction number");
                    if(Transaction != order)    throw new Exception("Incorrect transaction ordered");
                    if(Passengers < 1)  throw new Exception("Invalid amount of passenger");
                    
                    try { cfinish.await(); } catch (Exception e) { }
                    
                    if(Transaction == checkpoint && check == 0)   {
                        check++;
                        System.out.println();
                        AirportBL.CheckPointReport();
                        //try { cfinish.await(); } catch (Exception e) { }
                        CityBL.CheckPointReport();
                        System.out.println();
                    }
                    
                    try { cfinish.await(); } catch (Exception e) { }
                    
                    if(Destination.equals("A"))         AirportBL.allocateBus(Transaction, TourName, Passengers);
                    else if(Destination.equals("C"))    CityBL.allocateBus(Transaction, TourName, Passengers);
                    else                                throw new Exception("Invalid kind of destination");
                    
                }catch(Exception e){
                    System.out.println("\n" + e + ". \nline : " + line + "\n");
                }finally{
                    order++;
                }
                
                //--------------------------------------------------------------------------------------------------
                
            }catch(Exception e){
                System.out.println(e + "\n");
            }
            
        }
        
    }
    
}
