#include <bits/stdc++.h>
#define int long long
using namespace std;

bitset<1000000005> vis;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  int p;
  cin >> p;
  vector<int> x(p + 1), cnt(n + 1);
  for (int i = 1; i <= p; i++) {
    cin >> x[i];
    vis[x[i]] = true;
    int idx = upper_bound(a.begin() + 1, a.end(), make_pair(x[i], 0x3f3f3f3f3f3f3f3f)) - a.begin() - 1;
    cnt[idx]++;
    if (idx > 1 && a[idx - 1].second == a[idx].first && a[idx].first == x[i]) {
      cnt[idx - 1]++;
    }
  }
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    if (cnt[i] >= 3) {
      cout << "impossible\n";
      return;
    }
    while (cnt[i] < 2 && cnt[i + 1] < 2 && a[i].second == a[i + 1].first && !vis[a[i].second]) {
      vis[a[i].second] = true;
      ans.push_back(a[i].second);
      cnt[i]++, cnt[i + 1]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] < 2) {
      for (int j = a[i].first + 1; j < a[i].second; j++) {
        if (!vis[j]) {
          vis[j] = true;
          ans.push_back(j);
          cnt[i]++;
          break;
        }
      }
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

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}