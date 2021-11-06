/*
Chattarin Muksagul 6213124
Chutiwat Watek 6213195
Tinh Chaisena 6213199
*/

import java.util.ArrayList;

public class BusLine {
    
    private String destination;
    private int maximumSeat;
    private ArrayList<Bus>  BusList;
    private int BusNumber = 0;
    
    public BusLine(String d,int ms){
        destination = d;
        maximumSeat = ms;
        BusList = new ArrayList<>();
    }
    
    public void addBus(String name){
        Bus b = new Bus(name);
        BusList.add(b);
    }
    
    public synchronized void allocateBus(int transaction, String TourName, int passengers){
        
        if(BusList.size() == 0) addBus(destination + BusNumber);
        
        while(passengers != 0){
            
            if(passengers <= maximumSeat - BusList.get(BusNumber).getCurPassengers()){
                
                System.out.printf("%s >> Transaction %2d : %-40s (%2d seats) bus %s \n",Thread.currentThread().getName(),transaction,TourName,passengers,BusList.get(BusNumber).getBusName());
                BusList.get(BusNumber).addGroup(TourName, passengers);
                BusList.get(BusNumber).fillTheBus(passengers);
                passengers = 0;
                
            }else{
                
                passengers -= (maximumSeat - BusList.get(BusNumber).getCurPassengers());
                
                if(maximumSeat - BusList.get(BusNumber).getCurPassengers() != 0){
                    System.out.printf("%s >> Transaction %2d : %-40s (%2d seats) bus %s \n",Thread.currentThread().getName(),transaction,TourName,(maximumSeat - BusList.get(BusNumber).getCurPassengers()),BusList.get(BusNumber).getBusName());
                    BusList.get(BusNumber).addGroup(TourName, maximumSeat - BusList.get(BusNumber).getCurPassengers());
                    BusList.get(BusNumber).fillTheBus(maximumSeat - BusList.get(BusNumber).getCurPassengers());
                }
                
                BusNumber++;
                addBus(destination + BusNumber);
                
            }
            
        }
        
    }
    
    public void CheckPointReport(){
        
        System.out.print(Thread.currentThread().getName() + " >> " + BusList.size());
        
        if(destination.equals("A")) System.out.print(" airport-bound ");
        else                        System.out.print(" city-bound ");
        
        if(BusList.size() > 1)  System.out.print("buses have been allocated. \n");
        else                    System.out.print("bus has been allocated. \n");
    }
    
    public void printSummaryReport(){
        for(int i=0; i<BusList.size(); i++){
            BusList.get(i).printGroup();
        }
    }
    
}

class Bus{
    private String BusName;
    private int passengers;
    private ArrayList<Group> GL;
    
    public Bus(String name){
        BusName = name;
        passengers = 0;
        GL = new ArrayList<>();
    }
    
    public String getBusName()      {   return BusName;     }
    
    public int getCurPassengers()   {   return passengers;  }
    
    public void fillTheBus(int n)   {   passengers += n;    }
    
    public void addGroup(String name, int p){
        Group g = new Group(name,p);
        GL.add(g);
    }
    
    public void printGroup(){
        
        int i=0;
        System.out.printf("%s >> %-3s : ",Thread.currentThread().getName(),BusName);
        for(Group g : GL){
            if(i++ > 0)   System.out.print(", ");
            System.out.printf("%-30s (%-2d seats) ",g.getGroupName(),g.getGroupMember());
        }
        System.out.println();
    }
    
}

class Group{
    private String GroupName;
    private int member;
    
    public Group(String name, int m){
        GroupName = name;
        member = m;
    }
    
    public String getGroupName()    {   return GroupName;   }
    
    public int getGroupMember()     {   return member;      }
    
}