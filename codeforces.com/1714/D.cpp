// date: 2024-05-10 17:30:08
// tag: dp，带方案

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string t;
  int n;
  cin >> t >> n;
  int len = t.size();
  t = '#' + t;
  vector<string> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  vector<int> f(len + 1, INT_MAX);
  vector<int> pre(len + 1), whi(len + 1);
  f[0] = 0;
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= n; j++) {
      int siz = s[j].size();
      if (i >= siz && s[j] == t.substr(i - siz + 1, siz)) {
        // f[i] = min(f[i], f[i - siz] + 1);
        for (int k = i - siz + 1; k <= i; k++) {
          if (f[k] > f[i - siz] + 1) {
            pre[k] = i - siz;
            whi[k] = j;
            f[k] = min(f[k], f[i - siz] + 1);
          }
        }
      }
    }
  }
  int cnt = (f[len] == INT_MAX ? -1 : f[len]);
  cout << cnt << '\n';

  if (cnt == -1) return;
  int prv = 0;
  int cur = len;
  while (cur) {
    while (cur < len && pre[cur + 1] == pre[cur]) cur++;
    cout << whi[cur] << ' ' << cur - s[whi[cur]].size() + 1 << '\n';
    cur = pre[cur];
  }
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