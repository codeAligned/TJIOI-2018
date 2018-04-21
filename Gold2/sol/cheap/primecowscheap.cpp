#include<iostream>

using namespace std;

int main() {
    int N; cin >> N;
    if(N == 1 || N == 2 ||N == 3) cout <<4 << endl;
    else if(N == 4) cout << 2 << endl;
    else if(N == 6) cout << 1 <<endl;
    else cout << 0 << endl;
}
