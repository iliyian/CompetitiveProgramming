#include <bits/stdc++.h>
#define N 100005
using namespace std;

vector<int> pri;
bitset<N> vis, vis2;

void solve() {
  int n;
  cin >> n;
  vis.reset();
  vector<int> a(n + 1);
  for (int i = 0; i * 2 + 1 <= n; i++) {
    vis[i * 2 + 1] = i + 2;
  }
  for (int i = 0; i * 2 + 2 <= n; i++) {
    
  }
  cout << '\n';
}
// 2 6 3 9 4 8 5 10 1 7

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

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

  int _; cin >> _;
  while (_--) solve();
}