#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> cnt;
  int mx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    mx = max(mx, a[i]);
  }
  int t = -1;
  for (int i = 0; i < n; i++) {
    if (!cnt[i]) {
      t = i;
      break;
    }
  }
  set<int> s;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (a[i] < t) {
      s.insert(a[i]);
    }
    if (s.size() == t) {
      ans.push_back(i);
      s.clear();
    }
  }
  if (ans.size() <= 1) {
    cout << -1 << '\n';
    return;
  }
  if (ans.back() < n) {
    int tmp = ans.back();
    ans.pop_back();
    ans.push_back(n);
  }
  cout << ans.size() << '\n';
  cout << 1 << ' ' << ans[0] << '\n';
  for (int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] + 1 << ' ' << ans[i + 1] << '\n';
  }
  // cout << ans.back() - 1 << ' ' << n << '\n';
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