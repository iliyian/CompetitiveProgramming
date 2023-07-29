// 带权并查集mini

#include <bits/stdc++.h>
using namespace std;

int pa[2005];

unordered_set<int> s;
vector<pair<int, int>> v;

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
void merge(int x, int y) {pa[find(x)] = find(y);}
// merge x *to* y

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n << 1; i++)
    pa[i] = i;
  for (int i = 0; i < m; i++) {
    char opt;
    int x, y;
    cin >> opt >> x >> y;
    if (opt == 'F') {
      merge(x, y);
    } else {
      merge(x + n, y);
      merge(y + n, x);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += pa[i] == i;
  cout << ans;
  return 0;
}