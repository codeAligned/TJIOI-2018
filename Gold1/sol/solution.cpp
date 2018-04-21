#include <bits/stdc++.h>
using namespace std;

vector<int> original;

void step_double(vector<int> & v) {
	vector<int> q(v);
	for(int x=0; x<v.size(); x++) {
		v[x] = q[v[x]];
	}
}
void step_single(vector<int> & v) {
	for(int x=0; x<v.size(); x++) {
		v[x] = original[v[x]];
	}
}
void find_ans(vector<int> & v, int k) {
	// Exponentiation by squaring
	stack<int> bits;
	int kp = k;
	while(k > 0) {
		if(k%2 == 0) bits.push(0);
		else bits.push(1);
		k /= 2;
	}
	bits.pop();
	int tmp = 1;
	while(!bits.empty()) {
		step_double(v);
		tmp *= 2;
		if(bits.top() == 1) {
			step_single(v);
			tmp++;
		}
		bits.pop();
	}
	if(kp != tmp) {
		cerr << "SOMETHING WENT WRONG\n";
		cerr << kp << " " << tmp << endl;
	}
}



int main() {
	int n,k;
	cin >> n >> k;
	if(k == 0) {
		for(int x=0; x<n; x++) {
			cout << x << endl;
		}
		return 0;
	}
	vector<int> v(n);
	for(int x=0; x<n; x++) {
		cin >> v[x];
		original.push_back(v[x]);
	}
	find_ans(v, k);
	for(int x=0; x<n; x++) {
		cout << v[x] << endl;
	}
}
