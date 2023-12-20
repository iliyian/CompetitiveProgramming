#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a[2];

void dfs(int cur) {
  bool f = false;
  for (int i = 0; i < n; i++) {
    if (a[cur][i] && a[cur ^ 1][i]) {
      int t = a[cur ^ 1][i];
      a[cur][i]--, a[cur ^ 1][i] = 0;
      f = true;
      dfs(cur ^ 1);
      a[cur][i]++, a[cur ^ 1][i] = t;
    }
  }
  if (!f) {
    
  }
}

void solve() {
  cin >> n;
  a[0].clear(), a[1].clear();
  a[0].resize(n), a[1].resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[0][i];
  for (int i = 0; i < n; i++)
    cin >> a[1][i];
  dfs(0);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E1.in", "r", stdin);
  freopen("E1.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}