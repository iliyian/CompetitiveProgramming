#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  bool f = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (j < i && a) f = false;
    }
  cout << (f ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
}