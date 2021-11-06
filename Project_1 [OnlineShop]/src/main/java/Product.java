
public class Product implements Comparable<Product>{
    private final String name;
    private final int price, weight;
    private int totalSalesInCash=0,totalSalesInUnit=0;
    private int totalWeight;
    private int totalProductSales;
    public Product(String na,int p,int w){
        name = na;
        price = p;
        weight = w;
    }
    public String getName()             {   return name;    }
    public int getTotalSalesInCash()    {   return totalSalesInCash;    }
    public int getTotalSalesInUnit()    {   return totalSalesInUnit;    }
    public void setTotalSalesInCash(int m)      {   totalSalesInCash = m;   }
    public void SalesCalculate(int amount)   {
        totalSalesInCash += amount*price ;
        totalSalesInUnit += amount;
    }
    public int getTotalWeight()              {   return totalWeight;  }
    public void WeightCalculate(int amount)   { totalWeight = amount*weight ;   }
    
    public void setTotalProductSales()    {   totalProductSales = totalSalesInUnit * price;   }
    public int getTotalProductSales()          {   return totalProductSales;}
    
    public int  compareTo(Product other)         { 
            Product cur = (Product) other; 
            if(this.totalProductSales < other.totalProductSales)      return 1;
            else                                                    return -1;
        }
}
