#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string a;
  cin >> a;
  vector<int> m(10);

  auto calc = [&](int x) {
    x = x * 7;
    while (x > 9) {
      int t = x, sum = 0;
      while (t) {
        sum += t % 10;
        t /= 10;
      }
      x = sum;
    }
    return x;
  };

  for (int i = 0; i <= 9; i++) {
    m[i] = calc(i);
    // cout << m[i] << " \n"[i == 9];
  }

  int sum = 0;
  for (int i = a.size() - 1; i >= 0; i -= 2) {
    a[i] = m[a[i] - '0'] + '0';
  }
  for (int i = 0; i < a.size(); i++) {
    sum += a[i] - '0';
  }
  cout << (sum % 8 ? "F" : "T") << '\n';
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