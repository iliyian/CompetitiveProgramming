// date: 2024/02/06 21:13:13
// tag: 谁tmd想得到韦达定理这种初中数学啊艹
// wa#01: 方根的整数检测错了

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> cnt;

void solve() {
  int n;
  cin >> n;
  cnt.clear();
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], cnt[a[i]]++;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    int d = x * x - 4 * y;
    if (d < 0 || (long long)(sqrtl(d)) * (long long)(sqrtl(d)) != d) {
      cout << 0 << ' ';
      continue;
    }
    int x1 = x + sqrt(d), x2 = x - sqrt(d);
    if (x1 % 2 || x2 % 2) {
      cout << 0 << ' ';
      continue;
    }
    if (d == 0) {
      cout << cnt[x1 / 2] * (cnt[x1 / 2] - 1) / 2 << ' ';
    } else {
      cout << cnt[x1 / 2] * cnt[x2 / 2] << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}