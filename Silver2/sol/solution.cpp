#include <bits/stdc++.h>
using namespace std;

int test(int a) {
	int r = 0;
	for(int x=1; x<=a; x++) {
		r += a/x;
	}
	return r;
}

int main() {
	int n,k; cin >> n >> k;
	vector<int> v(n);
	for(int x=0; x<n; x++) {
		cin >> v[x];
	}
	sort(v.begin(), v.end());
	int lo=0, hi=n-1;
	while(lo <= hi) {
		int mid = (lo+hi)/2;
		int t = test(v[mid]);
		if(t > k) {
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	int ans_dist = 2e9;
	int ans = 0;
	if(hi < n) {
		int t = abs(test(v[hi])-k);
		if(t < ans_dist) {
			ans_dist = t;
			ans = v[hi];
		}
	}
	if(lo >= 0) {
		int t = abs(test(v[lo])-k);
		if(t < ans_dist) {
			ans_dist = t;
			ans = v[lo];
		}
	}
	cout << ans;
}


