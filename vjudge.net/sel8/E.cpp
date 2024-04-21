// date: 2023/12/24 16:41:06
// tag: 基本数论，取模性质的运用而已

#include <bits/stdc++.h>
#define N 10000007
using namespace std;

vector<int> pri;
bitset<40001> vis;

void solve() {
  int a, b;
  cin >> a >> b;
  if (b - a == 1) {
    cout << -1 << '\n';
    return;
  }
  int d = b - a, ans = 0x3f3f3f3f;
  vector<int> fac;
  for (int p : pri) {
    if (p * p > d) break;
    if (d % p == 0) fac.push_back(p);
    while (d % p == 0) d /= p;
  }
  if (d > 1) fac.push_back(d);
  for (int o : fac) {
    int k = (o - a % o) % o;
    ans = min(ans, k);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;

  for (int i = 2; i <= 40000; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (auto p : pri) {
      if (i * p > 40000) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  while (_--) solve();
}