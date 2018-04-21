#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long> edges[1000005];
int vis[1000005];

void dfs(long n) {
   vis[n]=1;
   for (int i=0; i<edges[n].size(); i++) {
      long child = edges[n].at(i);
      if (vis[child]==0)
         dfs(child);
   }
}
int main() {
   ofstream fout ("bridges.out");
   ifstream fin ("bridges.in");
   long N, M;
   fin >> N >> M;
   for (int i=0; i<M; i++) {
      long n1, n2;
      fin >> n1 >> n2;
      edges[n1-1].push_back(n2-1);
      edges[n2-1].push_back(n1-1);
   }
   long components = 0;
   for (int i=0; i<N; i++) {
      if (vis[i]==0) {
         dfs(i);
         components++;   
      }
   }
   fout << components-1 << '\n';
}