#include <bits/stdc++.h>
#define N 1000005
using namespace std;

vector<int> pri;
bitset<4005> vis;

void solve() {
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    for (int p : pri) {
      // if (p * p >= i) break;
      // if (p == 2) continue;
      if (i % p == 0) {
        int a = i / p;
        if (a == 1) continue;
        int b = i - a;
        cout << a << ' ' << b << '\n';
        return;
      }
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  
  for (int i = 2; i <= 4000; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > 4000) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }
  int _; cin >> _;
  while (_--) solve();
}