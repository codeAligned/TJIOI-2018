#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int maxN = 1e4;
struct segTree {
    vector<int> v;
    static const int size = 7*maxN;
    int c;
    int(*op)(int,int);
    segTree() {}
    segTree(int(*op)(int,int), int c) : v(size, c), c(c), op(op) {}

    void upd(int idx, int num, int currLo=0, int currHi=maxN+5, int pos=1) {
        if(currLo>idx || currHi<idx) return;
        if(currLo>=idx && currHi<=idx) {
			v[pos] = num;
            return;
        }
        int mid = (currLo+currHi)/2;
        upd(idx, num, currLo, mid, pos*2);
        upd(idx, num, mid+1, currHi, pos*2+1);
        v[pos] = op(v[pos*2], v[pos*2+1]);
    }
    int query(int lo, int hi, int currLo=0, int currHi=maxN+5, int pos=1) {
        if(currLo>hi || currHi<lo) return (int)c;
        if(currLo>=lo && currHi<=hi) {
            return v[pos];
        }
        int mid = (currLo + currHi)/2;
        return op(
                    query(lo, hi, currLo, mid, pos*2),
                    query(lo, hi, mid+1, currHi, pos*2+1)
        );

    }
};

int min1(int i, int j) {return min(i,j);}
int max1(int i, int j) {return max(i,j);}

int sieve[1005];
int ans[10005];
int a[10005];

int main() {
	ios_base::sync_with_stdio(0); // faster input/output
	for(int x=0; x<10005; x++) {
		ans[x] = -1;
	}

	int N; cin >> N;
	for(int x=0; x<N; x++) {
		cin >> a[x];
	}

	int Q; cin >> Q;
	vector< tuple<int,int,int> > inp(Q);

	for(int x=0; x<Q; x++) {
		char type; cin >> type;
		if(type == 'C') {
			int i, v; cin >> i >> v;
			inp[x] = make_tuple(-1, i, v);
		} else {
			int i, j, v; cin >> i >> j >> v;
			inp[x] = make_tuple(i, j, v);
		}
	}


	// find prime numbers <= 1000
	for(int x=2; x<=1000; x++) {
		if(sieve[x]) continue;
		for(int y=x*2; y<=1000; y+=x) {
			sieve[y] = 1; // y is not prime
		}
	}

	for(int x=2; x<=1000; x++) {
		if(sieve[x]) continue;
		segTree tree(max1, -(int)2e9);

		for(int y=0; y<N; y++) {
			if(a[y] % x == 0) {
				tree.upd(y, a[y]);
			}
		}

		// x is prime
		for(int q=0; q<Q; q++) {
			tuple<int,int,int> query = inp[q];
			if(get<0>(query) == -1) { // type == 'C'
				int i = get<1>(query);
				int v = get<2>(query);
				if(v % x == 0) {
					tree.upd(i, v);
				} else {
					tree.upd(i, -1);
				}
			} else { // type == 'F'
				int i = get<0>(query);
				int j = get<1>(query);
				int v = get<2>(query);
				if(v % x == 0) {
					int max_val = tree.query(i, j);
					ans[q] = max(ans[q], max_val);
				}
			}
		}
	}
	for(int q=0; q<Q; q++) {
		if(get<0>(inp[q]) != -1) {
			cout << ans[q] << endl;
		}
	}
}
