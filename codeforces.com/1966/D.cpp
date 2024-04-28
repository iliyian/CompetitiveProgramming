#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  for (int i = 1; i <= n; i <<= 1) {
    if (__lg(i) != __lg(k)) {
      ans.push_back(i);
    }
  }
  ans.push_back(k - (1 << __lg(k)));
  ans.push_back(k + 1);
  ans.push_back(k + 1 + (1 << __lg(k))); // request at k bit
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}