#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), b(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] % k;
    if (b[i] == 0) {
      b[i] = k;
    }
  }
  iota(id.begin() + 1, id.end(), 1);
  stable_sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return b[x] > b[y];
  });
  for (int i = 1; i <= n; i++) {
    cout << id[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}