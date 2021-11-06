
public class Customers implements Comparable<Customers>{
    private final String name;
    private final String type;
    private final int[] orders;
    private int totalBill=0;
    private int totalWeight=0;
    public Customers(String na,String t,int[] or){
        name = na;
        type = t;
        orders = or;
    }
    public String getName()         {   return name;    }
    public int[] getOrders()        {   return orders;  }
    public String getType()         {   return type;    }
    public int getTotalBill()       {   return totalBill;}
    public void setTotalBill(int total)       {   totalBill = total;    }
    public int getTotalWeight()       {   return totalWeight;}
    public void setTotalWeight(int total)       {   totalWeight = total;    }
    
    public int  compareTo(Customers other)         { 
            if(this.totalBill < other.totalBill)            return 1;
            else                                            return -1;
        }
    
}
