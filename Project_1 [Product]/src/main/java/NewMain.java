/*
Chattarin Muksagul 6213124
Tinh Chaisena 6213199
*/

import java.io.*;
import java.util.*;

class NewMain  
{
  public static void main(String[] args)  
  {
	String infile = "prices.txt";
	String outfile = "output.txt";
        
	try 
        {
	  Scanner scan  = new Scanner(new File(infile));
	  PrintWriter write = new PrintWriter(outfile);
          
          System.out.printf("  Product  \t   Price before VAT \t   VAT \t       Net Price\n");
          System.out.printf("===============================================================\n");
        
          write.printf("  Product  \t   Price before VAT \t   VAT \t       Net Price\r\n");
          write.printf("===============================================================\r\n");

	  while (scan.hasNext()) 
          {							
	    String prod	  = scan.next();
	    int price = scan.nextInt();
            double a,b;
            // Use \r\n when writing to file
            System.out.printf("%s    \t\t %.2f   \t  %.2f   \t %.2f \n", prod, a = price/1.07, b = a*0.07, a+b);
            write.printf("%s    \t\t %.2f   \t  %.2f   \t %.2f \r\n", prod, a = price/1.07, b = a*0.07, a+b);
	  }
          
	  scan.close();
	  write.close();
	}
	catch(Exception e) {
	  System.err.println("An error occurs. End program.");
	  System.exit(-1);
	}
  }
}