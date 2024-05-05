// date: 2024-05-05 11:48:29
// tag: 构造，树

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int s = -1, cnt = 0;
  bool f = false;
  for (int i = 0; i < n; i++) {
    if (str[i] == '1' && s == -1) {
      s = i;
    }
    cnt += str[i] - '0';
    if (str[i] == '0') {
      f = true;
    }
  }
  if (cnt & 1 || !cnt) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (!f) {
    for (int i = 1; i < n; i++) {
      cout << 1 << ' ' << i + 1 << '\n';
    }
    return;
  }

  auto nxt = [&](int x) {
    return (x + 1) % n;
  };
  auto prv = [&](int x) {
    return (x - 1 + n) % n;
  };
  int rt = nxt(s);
  while (str[rt] == '1') rt = nxt(rt);

  for (int i = nxt(rt); i != rt; i = nxt(i)) {
    if (str[prv(i)] == '0') cout << prv(i) + 1 << ' ' << i + 1 << '\n';
    else cout << rt + 1 << ' ' << i + 1 << '\n';
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