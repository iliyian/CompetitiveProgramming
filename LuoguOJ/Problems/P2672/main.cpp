// date: 2024-03-18 15:49:17
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].second;
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i].first;
  }
  sort(v.begin() + 1, v.end(), greater());
  vector<int> s(n + 1), mx(n + 1), h(n + 2);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + v[i].first;
    mx[i] = max(mx[i - 1], v[i].second);
  }
  for (int i = n; i >= 1; i--) {
    h[i] = max(h[i + 1], v[i].second * 2 + v[i].first);
  }
  for (int i = 1; i <= n; i++) {
    cout << max(s[i] + mx[i] * 2, s[i - 1] + h[i]) << '\n';
  }

  return 0;
}