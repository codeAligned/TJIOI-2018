import java.lang.*;
import java.util.*;
import java.math.*;
import java.io.*;
public class treasure
{  
   public static void main(String[] args)
   {
      try{
         BufferedReader f = new BufferedReader ( new FileReader ("treasure.in"));
         PrintWriter out = new PrintWriter ( new BufferedWriter ( new FileWriter ("treasure.out")));
      
         StringTokenizer st = new StringTokenizer(f.readLine());
         int N = Integer.parseInt(st.nextToken());
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
         out.println(ans);
               
                 out.close(); 
      }
      catch(Exception e)
      {
         System.out.println(e);
      }
   }
   
}
