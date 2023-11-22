#include <bits/stdc++.h>
#define N 200005
using namespace std;

int pa[N];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
void unite(int x, int y) {pa[find(x)] = find(y);}

vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m, k;
  cin >> n >> m;
  iota(pa, pa + n, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    
  }
  cin >> k;
  return 0;
}