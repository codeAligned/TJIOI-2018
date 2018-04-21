import java.util.*;


public class max_noncoprime {
   static int n;
   int l;
   int r;
   int m;
   max_noncoprime left;
   max_noncoprime right;
   void update(int i, int v) {
      if (i<l || i>r) 
         return;
      if (l!=r) {
         left.update(i,v);
         right.update(i,v);
         m=Math.max(left.m,right.m);
      } 
      else {
         m=v;
      }
   }
   int query(int min, int max) {
      if (l>max || r<min) 
         return -1;
      if (l==r) 
         return m;
      return Math.max(left.query(min,max),right.query(min,max));
   }
   static max_noncoprime makeTree(int l, int r) {
      max_noncoprime nn=new max_noncoprime();
      nn.l=l;
      nn.r=r;
      if (l!=r) {
         nn.left=makeTree(l,(l+r)/2);
         nn.right=makeTree((l+r)/2+1,r);
      }
      nn.m=-1;
      return nn;
   } 
   public static void main(String[] arggg) {
      Scanner sc=new Scanner(System.in);
      n=sc.nextInt();
      int[] arr=new int[n];
      max_noncoprime[] segs=new max_noncoprime[170];
      int[] primes=new int[170];
      segs[0]=makeTree(0,n-1);
      primes[0]=2;
      int pr=1;
      for (int i=3; i<1008; i+=2) {
         boolean valid=true;
         for (int k=1; k<pr; k++) {
            if (i%primes[k]==0) {
               valid=false;
               break;
            }
            if (primes[k]*primes[k]>=i) 
               break;
         }
         if (valid) {
            primes[pr]=i;
            segs[pr]=makeTree(0,n-1);
            pr++;
         }
      }
      for (int i=0; i<n; i++) {
         int imp=sc.nextInt();
         arr[i]=imp;
         int cp=imp;
         for (int k=0; k<pr; k++) {
            if (imp%primes[k]==0) {
               segs[k].update(i,cp);
               imp=imp/primes[k];
            }           
         }
      }
      int Q=sc.nextInt();
      for (int qn=0; qn<Q; qn++) {
         if (sc.next().charAt(0)=='C') {
            int ind=sc.nextInt();
            int v=sc.nextInt();
            int imp=arr[ind];
            for (int k=0; k<pr; k++) {
               if (imp%primes[k]==0) {
                  segs[k].update(ind,-1);
                  imp=imp/primes[k];
               }
            }
            imp=v;
            for (int k=0; k<pr; k++) {
               if (imp%primes[k]==0) {
                  segs[k].update(ind,v);
                  imp=imp/primes[k];
               }
            }
         } 
         else {
            int l=sc.nextInt();
            int r=sc.nextInt();
            int v=sc.nextInt();
            int imp=v;
            int max=-1;
            for (int k=0; k<pr; k++) {
               if (imp%primes[k]==0) {
                  max=Math.max(max,segs[k].query(l,r));
                  imp=imp/primes[k];
               }
            }
            System.out.println(max);
         }
      }
   }
}