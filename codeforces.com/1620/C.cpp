// date: 2024-04-21 15:01:12
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  string str;
  cin >> str;
  vector<int> a;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'a') {
      if (cnt) {
        a.push_back(cnt);
        cnt = 0;
      }
    }
    if (str[i] == '*') {
      cnt++;
    }
  }
  if (cnt) {
    a.push_back(cnt);
  }
  if (a.empty()) {
    cout << str << '\n';
    return;
  }
  for (auto &i : a) {
    i = i * k + 1;
  }

  vector<int> mul(a.size());
  vector<int> ans(a.size(), 0);
  int mx = -1;
  x--;
  for (int i = a.size() - 1; i >= 0; i--) {
    __int128 t = (__int128)(i + 1 < a.size() ? mul[i + 1] : 1) * a[i];
    if (t > x) {
      mx = i;
      break;
    }
    mul[i] = t;
  }

  for (int i = mx; i < a.size() - 1; i++) {
    ans[i] = x / mul[i + 1];
    x -= ans[i] * mul[i + 1];
  }
  ans.back() = x;

  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '*') {
      assert(idx < ans.size());
      for (int j = 0; j < ans[idx]; j++) {
        cout << 'b';
      }
      idx++;
      while (str[i] == '*') ++i;
      i--;
    } else {
      cout << str[i];
    }
  }
  assert(idx == ans.size());
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}