#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int num = 0;
	for(int x=0; x<(s.size()/2-1); x++) {
		int corresponding = s.size()-x-1;
		if(s[x] != s[corresponding]) {
			num++;
		}
	}
	cout << num;
}
