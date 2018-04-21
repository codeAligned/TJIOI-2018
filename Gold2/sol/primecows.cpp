#include<iostream>

#include<algorithm>
#include<queue>
#include<ctime>


using namespace std;

int isPrime(int i) { //legitimate way of solving
	if(i == 1 || i == 0)
		return 0;
	int k;
	for(k = 2; k*k <= i; k++) {
		if(i % k == 0)
			return 0;
	}
	return 1;
}

queue<pair<int, int> > q;
int main() {
	int k, N;
	cin >> N;
	q.push(make_pair(2, 1));
	q.push(make_pair(3, 1));
	q.push(make_pair(5, 1));
	q.push(make_pair(7, 1));
	while(!q.empty() && q.front().second < N) { //generates numbers such that 
	           //everything to the left of a given position forms a prime number
		pair<int, int> p = q.front();
		q.pop();
		int p1 = p.first;
		for(k = 0; k < 10; k++) { //checks for every digit
			if(isPrime(10*p1+k)) {
				q.push(make_pair(10*p1+k, p.second + 1));
			}
		}
	}
	int count = 0;
	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int mod = 10;
		int b = 1;
		while(p.first > mod) {
			if(!isPrime(p.first % mod)) {
				b = 0;
				break;
			}
			mod *= 10;
		}
		if(b) {
			count += 1;
		}
	}
	cout << count << endl;
}
