#include <bits/stdc++.h>
#define N 100005
using namespace std;

int in[N];
vector<vector<int>> g;
vector<int> c;

void solve() {
  int n;
  cin >> n;
  g.clear();
  g.resize(n + 1);
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    g[i].push_back(a), in[a]++;
  }
  c.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> c[i];

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) cout << i << ' ';
    
  }

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}