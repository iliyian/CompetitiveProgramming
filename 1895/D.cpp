#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  vector<array<int, 2>> t = {{-1, -1}};
  auto add = [&](int x) {
    int v = 0;
    for (int i = 30; i >= 0; i--) {
      int j = (x >> i) & 1;
      if (t[v][j] == -1) {
        t[v][j] = t.size();
        t.push_back({-1, -1});
      }
      v = t[v][j];
    }
  };
  auto get = [&](int x) {
    int v = 0;
    for (int i = 30; i >= 0; i--) {
      int j = (x >> i) & 1;
      if (t[v][j ^ 1] != -1) {
        j ^= 1;
      }
      x ^= (j << i);
      v = t[v][j];
    }
    return x;
  };
  for (auto i : a) add(i);
  for (int i = 0; i < n; i++) {
    if (get(i) == n - 1) {
      for (auto j : a) {
        cout << (i ^ j) << ' ';
      }
      cout << '\n';
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}