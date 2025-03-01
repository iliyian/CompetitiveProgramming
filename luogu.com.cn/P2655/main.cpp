// date: 2024-03-19 13:32:41
// tag: 模拟

#include <bits/stdc++.h>
#include <format>
#define int long long
using namespace std;

void solve() {
  int len, y, mon, d, h, minu, s;
  cin >> len >> y >> mon >> d >> h >> minu >> s;
  int t = (1ll << len - 1) - 1;
  s += t;
  if (s >= 60) {
    minu += s / 60;
    s %= 60;
  }
  if (minu >= 60) {
    h += minu / 60;
    minu %= 60;
  }
  if (h >= 24) {
    d += h / 24;
    h %= 24;
  }
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  auto isLeap = [&](int n) {
    return (n % 4 == 0 && n % 100) || n % 400 == 0;
  };
  auto getDays = [&](int y, int m) {
    return isLeap(y) && m == 2 ? 29 : days[m];
  };

  while (d > getDays(y, mon)) {
    d -= getDays(y, mon);
    mon++;
    if (mon == 13) {
      mon = 1, y++;
    }
  }

  cout << format("{} {} {} {} {} {}", y, mon, d, h, minu, s) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}