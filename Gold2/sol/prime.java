import java.io.*;
import java.util.ArrayDeque;

public class prime {

private static boolean isPrime(int i) { //legitimate way of solving
	if(i == 1 || i == 0)
		return false;
	int k;
	for(k = 2; k*k <= i; k++) {
		if(i % k == 0)
			return false;
	}
	return true;
}

private static ArrayDeque<pair> q = new ArrayDeque<pair>();
public static void main(String[] args) throws IOException {
	int k, N;
	BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
	N = Integer.parseInt(f.readLine());
	q.add(make_pair(2, 1));
	q.add(make_pair(3, 1));
	q.add(make_pair(5, 1));
	q.add(make_pair(7, 1));
	while(!q.isEmpty() && q.peek().second < N) { //generates numbers such that 
	            //everything to the left of a given position forms a prime number
		pair p = q.peek();
  		q.pop();
		int p1 = p.first;
		for(k = 0; k < 10; k++) { //checks for every digit
			if(isPrime(10*p1+k)) {
				q.add(make_pair(10*p1+k, p.second + 1));
			}
		}
	}
	int count = 0;
	while(!q.isEmpty()) {
		pair p = q.peek();
		q.remove();
		int mod = 10;
	   boolean b = true;
		while(p.first > mod) {
			if(!isPrime(p.first % mod)) {
				b = false;
				break;
			}
			mod *= 10;
		}
		if(b) {
			count += 1;
		}
	}
   System.out.println(count);
}

private static pair make_pair(int a, int b) {
	return new pair(a, b);
}

private static class pair {
	int first;
	int second;

	public pair(int a, int b) {
		first = a;
		second = b;
	}
}

}
