// date: 2024/01/28 08:17:51
// tag: tmd, 最后几秒竟然改对了代码，但是来不及交了，恨啊，我忽略了n啊艹

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  string str;
  cin >> str;
  vector<int> cnt(26);
  int v = 1;
  string ans;
  for (int i = 0; i < m; i++) {
    cnt[str[i] - 'a']++;
    bool f = true;
    for (int j = 0; j < k; j++) {
      if (!cnt[j]) {
        f = false;
        break;
      }
    }
    if (f) {
      v++;
      ans.push_back(str[i]);
      fill(cnt.begin(), cnt.end(), 0);
    }
  }
  if (v <= n) {
    cout << "NO\n";
    cout << ans;
    for (int i = 0; i < k; i++)
      if (!cnt[i]) {
        for (int j = 0; j < n - v + 1; j++) {
          cout << char(i + 'a');
        }
          cout << '\n';
          return;
      }
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}