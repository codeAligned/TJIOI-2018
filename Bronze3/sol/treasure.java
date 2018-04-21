import java.lang.*;
import java.util.*;
import java.math.*;
import java.io.*;
public class treasure
{  
   public static void main(String[] args)
   {
      try{
		 Scanner sc = new Scanner(System.in);
      
         int N = sc.nextInt();
         int x = 0;
         int y = 0;
         while(N>0){
         int a = N%4;
         if(a==0){
         y++;
         }
         else if(a==1){
         x++;
         }
         else if(a==2){
         y = y-1;
         }
         else if(a==3){
         x = x-1;
         }
         
         N = N/4;
         }
         String ans = x+", "+y;
         System.out.println(ans);
      }
      catch(Exception e)
      {
         System.out.println(e);
      }
   }
   
}
