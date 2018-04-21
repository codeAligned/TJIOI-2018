#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin >> n >> k;
	vector<double> percents(n);
	for(int x=0; x<n; x++) {
		percents[x] = 1;
	}
	for(int x=0; x<k; x++) {
		for(int y=0; y<n; y++) {
			double percent_change; cin >> percent_change;
			percents[y] *= (100+percent_change)/100.0;
		}
	}
	int c; cin >> c;
	double max_profit = -1e9;
	for(int x=0; x<c; x++) {
		double total = 0;
		double starting_total = 0;
		for(int y=0; y<n; y++) {
			double starting_amount; cin >> starting_amount;
			starting_total += starting_amount;
			total += percents[y] * starting_amount;
		}
		double profit = total - starting_total;
		max_profit = max(max_profit, profit);
	}
	cout << int(round(max_profit)) << endl;
}
