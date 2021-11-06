
public class Postage {
    private final String type;
    private final int minWeight,maxWeight,rate;
    public Postage(String t,int minW,int maxW,int r){
        type = t;
        minWeight = minW;
        maxWeight = maxW;
        rate = r;
    }
    public String getType()     {   return type;    }
    public int getMinWeight()   {   return minWeight;  }
    public int getMaxWeight()   {   return maxWeight;  }
    public int PostagePriceCalculate(int weight)    {   return rate;    }
}
