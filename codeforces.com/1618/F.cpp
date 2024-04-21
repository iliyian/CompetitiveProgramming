// date: 2024-04-20 13:22:14
// tag: 构造，暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (b & 1 ^ 1) {
    if (a == b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  string as, bs;
  auto convert = [](string &s, int x) {
    bool f = false;
    for (int i = 63; i >= 0; i--) {
      if (x >> i & 1) f = true;
      if (f) s.push_back((x >> i & 1) + '0');
    }
  };
  convert(as, a);
  convert(bs, b);

  auto check = [](string a, const string &b) {
    bool f = false;
    int pos = -1;
    for (int _ = 0; _ < 2; _++) { // for reverse only
      if ((pos = b.find(a)) != string::npos) {
        f = true;
        for (int i = -1;; i--) {
          if (pos + i < 0) break;
          if (b[pos + i] == '0') {
            f = false;
            break;
          }
        }
        if (!f) continue;

        for (int i = 0;; i++) {
          if (pos + a.size() + i >= b.size()) break;
          if (b[pos + a.size() + i] == '0') {
            f = false;
            break;
          }
        }
        if (f) {
          return true;
        }
      }
      reverse(a.begin(), a.end());
    }
    return false;
  };

  as.push_back('1');
  if (check(as, bs)) {
    cout << "YES\n";
    return;
  }
  as.clear();

  while (a & 1 ^ 1) a >>= 1;
  convert(as, a);
  if (check(as, bs)) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  solve();

  return 0;
}