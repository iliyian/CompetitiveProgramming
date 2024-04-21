#include <bits/stdc++.h>
#define int long long
#define N 1000000001
#define mod 998244353
using namespace std;

vector<int> pri;
bitset<N> vis;

void solve() {
  int n, m;
  cin >> n >> m;

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  for (int i = 2; i <= N - 1; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p >= N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int prod = 1, n = 0;
  for (int p : pri) {
    if (prod * p >= N) break;
    prod *= p;
    n++;
  }
  cout << n << '\n';
  return 0;

  while (_--) {
    solve();
  }

  return 0;
}