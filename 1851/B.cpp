#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), oi, ei;
  vector<int> odd, even;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2) {
      odd.push_back(a[i]);
      oi.push_back(i);
    } else {
      even.push_back(a[i]);
      ei.push_back(i);
    }
  }
  vector<int> c(n + 1);
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  int idx = 0;
  for (auto i : oi) {
    c[i] = odd[idx++];
  }
  idx = 0;
  for (auto i : ei) {
    c[i] = even[idx++];
  }
  cout << (is_sorted(c.begin() + 1, c.end()) ? "YES" : "NO") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}