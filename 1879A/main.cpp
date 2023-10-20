#include <bits/stdc++.h>
using namespace std;

int s[101], e[101];

struct Node {
  int s, e, idx;
  bool operator < (const Node &b) {
    if (s == b.s) return e > b.e;
    return s > b.s;
  }
} nodes[101];

void solve() {
  int n, S, E;
  cin >> n;
  if (n) cin >> S >> E;
  else {
    cout << -1 << '\n';
    return;
  }
  bool f = true;
  for (int i = 1; i < n; i++) {
    int s, e;
    cin >> s >> e;
    if (s >= S && e >= E) {
      f = false;
    }
  }
  cout << (f ? S : -1) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}