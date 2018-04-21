#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> occurences;

string from_vector(vector<int> & v, int start) {
	string s = "";
	for(int x=0; x<v.size(); x++) {
		s += to_string(v[(x+start)%v.size()])+"|";
	}
	return s;
}

int do_step(vector<int> & v, int step_num) {
	int i = step_num % v.size();
	string s = from_vector(v, i);

	// check
	if(occurences.find(s) != occurences.end()) {
		return occurences[s];
	}

	occurences[s] = step_num;

	int tmp = v[i];
	v[i] = 0;
	for(int x=0; x<min(tmp, (int)v.size()); x++) {
		v[(x+i+1)%v.size()]++;
	}
	return -1;
}

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int x=0; x<n; x++) {
		cin >> v[x];
	}
	for(int x=0;; x++) {
		int c = do_step(v, x);
		if(c != -1) {
			cout << x-c << ' ' << c;
			return 0;
		}
	}
}


