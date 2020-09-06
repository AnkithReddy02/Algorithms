import java.util.*;
import java.lang.Math;
class Main
{
    long Length(long x)
    {
        if(x==0)
        {
            return 1;
        }
        long count = 0;
        while(x>0)
        {
            count++;
            x = x/10;
        }
        
        return count;
    }
     long  Karastuba(long x,long y)
    {
        if(x<10 && y<10)
        {
            return x*y;
        }
        
        
        long length_x = Length(x);
        long length_y = Length(y);
        
        long length = (Math.max(length_x , length_y)+1 )/2 ;
        
        long x_upperpart = x / (long)(Math.pow(10,length));
        long x_lowerpart = x % (long)(Math.pow(10,length));
        long y_upperpart = y / (long)(Math.pow(10,length));
        long y_lowerpart = y % (long)(Math.pow(10,length));
        
        long A = Karastuba(x_upperpart , y_upperpart);
        long B = Karastuba(x_lowerpart , y_lowerpart);
        long C = Karastuba(x_lowerpart + x_upperpart , y_lowerpart + y_upperpart);
        
        long result = ((long)(Math.pow(10,2*length)) * A )+ ((long)(Math.pow(10,2*length)) * (C-A-B)) + B;
        
        return result;
        
        
    }
    public static void main (String[] args) 
    {
        
        Main obj = new Main();
        
        
        Scanner in  = new Scanner(System.in);
        
        System.out.print("\nEnter First Number : ");
        long n1 = in.nextLong();
        
        System.out.print("\nEnter Second Number : ");
        long n2 = in.nextLong();
        
        long result = obj.Karastuba(n1,n2);
        
        System.out.println("\nThe product of " + n1 + " and " + n2 + " is " + result);
        
        
    }
}
