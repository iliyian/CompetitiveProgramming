// date: 2024-06-08 00:03:50
// tag: 筛

#include <bits/stdc++.h>
#define int long long
#define N ((int)3.2e4)
using namespace std;

vector<int> pri;
bitset<N + 1> vis;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int p : pri) {
    for (int i = 1; i <= n; i++) {
      if (a[i] % p == 0) {
        
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}