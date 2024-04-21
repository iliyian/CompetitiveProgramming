#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x, k;
  cin >> n >> x >> k;
  vector<int> ans;
  int cur = 0;
  for (int i = 0; n > 0; i++) {
    int cnt = 0;
    while (cur < k && n) {
      cur += x;
      cnt++;
      n--;
    }
    if (cur < k) {
      break;
    } else {
      cur -= k;
      ans.push_back(cnt);
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}