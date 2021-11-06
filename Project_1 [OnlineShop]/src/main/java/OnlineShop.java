/*
Chattarin Muksagul 6213124
Tinh Chaisena 6213199
*/
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class OnlineShop {

    public static void main(String[] args) /*throws FileNotFoundException*/ {
        
        int i=1;
        String FileName = null;
        ArrayList<Product> PL = new ArrayList<Product>();
        
        while(i==1){
            try{
            
                Scanner read = new Scanner(System.in);
                //System.out.println("Products.txt"); //Products.txt
                System.out.println("Input Products File Name : ");
                FileName = read.nextLine();
                Scanner scan = new Scanner(new File(FileName));
                
                while (scan.hasNext()){
                
                    String line = scan.nextLine();
                    String [] buf = line.split(",");
                    
                    if(buf.length != 3){
                        scan.close();
                        throw new Exception("Wrong input file.");
                    }
                    PL.add(new Product(buf[0],Integer.parseInt(buf[1].trim()),Integer.parseInt(buf[2].trim())));
                }
            
                scan.close();
                i=0;

            }catch(IOException e){
                System.out.printf("\nThere's no Products file named \"%s\". Please try again.\n",FileName);
                System.out.println(e + "\n");
            }catch (Exception ex) {
                System.out.println("\nWrong file type. Please input Products file.");
                System.out.println(ex + "\n");
            }
        }
        
        i=1;
        FileName = null;
        ArrayList<Postage> PoL = new ArrayList<Postage>();
        
        while(i==1){
            try{
            
                Scanner read = new Scanner(System.in);
                //System.out.println("postages.txt"); //postages.txt
                System.out.println("Input Postages File Name : ");
                FileName = read.nextLine();
                Scanner scan = new Scanner(new File(FileName));
                
                while (scan.hasNext()){
                    
                    int temp;
                
                    String line = scan.nextLine();
                    String [] buf = line.split(",");

                    if(buf.length != 4 ){
                        scan.close();
                        throw new Exception("Wrong input file.");
                    }
                    
                    if(" inf".equals(buf[2])) temp = (int) Double.POSITIVE_INFINITY;
                    else                temp = Integer.parseInt(buf[2].trim());

                    PoL.add(new Postage(buf[0],Integer.parseInt(buf[1].trim()),temp,Integer.parseInt(buf[3].trim())));
                }
            
                scan.close();
                i=0;

            }catch(IOException e){
                System.out.printf("There's no Postages file named \"%s\". Please try again.\n",FileName);
                System.out.println(e + "\n");
            } catch (Exception ex) {
                System.out.println("\nWrong file type. Please input Postages file.");
                System.out.println(ex + "\n");
            }
        }
        
        i=1;
        FileName = null;
        ArrayList<Customers> CL = new ArrayList<Customers>();
        Customers C[] = new Customers[10];
        
        while(i==1){
            try{
            
                Scanner read = new Scanner(System.in);
                //System.out.println("customers.txt"); //customers.txt
                //System.out.println("customers_errors.txt"); //customers.txt
                System.out.println("Input Customers File Name : ");
                FileName = read.nextLine();
                Scanner scan = new Scanner(new File(FileName));
                
                if(FileName.equals("customers.txt") || FileName.equals("customers_errors.txt")){
                    
                }else{
                    scan.close();
                    throw new FileNotFoundException("Wrong input file.");
                }
                
                while (scan.hasNext()){
                    
                    int[] or = new int[]{0,0,0,0,0} ;
                
                    String line = scan.nextLine();
                    String [] buf = line.split(",");

                    /*if(buf.length != 7 ){
                        scan.close();
                        throw new FileNotFoundException("Wrong input file.");
                    }*/
                    
                    try{
                        int k;
                        if(buf[1].trim().equals("E")||buf[1].trim().equals("R")){
                            for(k=0;k<buf.length-2;k++){
                                or[k] = Integer.parseInt(buf[k+2].trim());
                                if(or[k] < 0)   throw new Exception("Wrong amount of products.");
                                //System.out.printf("%d ",or[k]);
                            }
                            CL.add(new Customers(buf[0],buf[1],or));
                            
                        }else   throw new Exception("Wrong postage type.");
                        
                    }catch (Exception ex) {
                        System.out.println("\nInput line >> " + line);
                        System.out.println("              " + ex + "\n");
                    } 
                }
                
            
                scan.close();
                i=0;

            }catch(IOException e){
                if(e.equals("Wrong input file."))   System.out.println("\nWrong file type. Please input Customers file.");
                else                                System.out.printf("There's no Customers file named \"%s\". Please try again.\n",FileName);
                System.out.println(e + "\n");
            } 
        }
        
        //===========================================================================================
        
        System.out.println("===== Process orders =====");
        for(i=0;i<CL.size();i++){
            System.out.printf("%-25s >>  ",CL.get(i).getName());
            int PostPrice=0,k,j,amount[] = CL.get(i).getOrders();
            
            for(j=0;j<amount.length;j++){
                
                System.out.printf("%s (%2d)   ",PL.get(j).getName(),amount[j]);
                PL.get(j).setTotalSalesInCash(0);
                
                PL.get(j).SalesCalculate(amount[j]);
                CL.get(i).setTotalBill(CL.get(i).getTotalBill() + PL.get(j).getTotalSalesInCash());
                
                PL.get(j).WeightCalculate(amount[j]);
                CL.get(i).setTotalWeight(CL.get(i).getTotalWeight() + PL.get(j).getTotalWeight());
                
                for(k=0;k<PoL.size();k++)
                    if(CL.get(i).getTotalWeight() >= PoL.get(k).getMinWeight() && CL.get(i).getTotalWeight() <= PoL.get(k).getMaxWeight() && CL.get(i).getType().trim().equals(PoL.get(k).getType().trim()))
                        PostPrice = PoL.get(k).PostagePriceCalculate(CL.get(i).getTotalWeight());
                
            }
            System.out.println("");
            System.out.printf("%-25s     products price = %6d\t\ttotal weight = %d\n","",CL.get(i).getTotalBill(),CL.get(i).getTotalWeight());
            System.out.printf("%-25s     postage (%s)    = %6d\t\ttotal bill   = %d\n","",PoL.get(i).getType(),PostPrice,CL.get(i).getTotalBill() + PostPrice);
            //PL.get(i).setTotalProductSales();
            CL.get(i).setTotalBill(CL.get(i).getTotalBill() + PostPrice);
            System.out.println("");
        }
        
        //==============================================================================================
        
        System.out.println("===== Sort customers by total bill =====\n");
        Collections.sort(CL);
        for(i=0;i<CL.size();i++)    System.out.printf("%-25s   bill = %6d\n",CL.get(i).getName(),CL.get(i).getTotalBill());
        System.out.println("");
        
        //==============================================================================================
        
        System.out.println("===== Sort products by total sales in cash =====\n");
        for(i=0;i<PL.size();i++)    PL.get(i).setTotalProductSales();
        Collections.sort(PL);
        for(i=0;i<PL.size();i++)    System.out.printf("%-20s   total sales = %6d B,\t%2d units\n",PL.get(i).getName(),PL.get(i).getTotalProductSales(),PL.get(i).getTotalSalesInUnit());
        
        System.out.println("");
    }
    
}
