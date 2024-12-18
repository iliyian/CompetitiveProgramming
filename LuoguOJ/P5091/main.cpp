// date: 2024/02/03 13:38:27
// tag: 扩展欧拉定理模板
// notice: 注意开 int64，不用考虑gcd(a,m)==1，
// 直接比较b和phi的大小即可，小就再加一个

#include <bits/stdc++.h>
#define int long long
using namespace std;

int euler(int m) {
  int ans = m;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      ans = ans * (i - 1) / i;
      while (m % i == 0) m /= i;
    }
  }
  if (m > 1) ans = ans * (m - 1) / m;
  return ans;
}

int phi;

// (1*100+4*10+9*1)%mod
// 10%mod*10%mod;

void solve() {
  int a, m;
  cin >> a >> m;
  string b;
  cin >> b;
  phi = euler(m);
  int p = 0, ten = 1, cur = 0;
  bool f = false;
  for (int i = b.size() - 1; i >= 0; i--) {
    char ch = b[i];
    if (!f) cur = cur * 10 + ch - '0';
    if (cur >= m) f = true;
    p = (p % phi + ten * (ch - '0') % phi) % phi;
    ten = ten * 10 % phi;
  }

  if (f) p += phi;
  else p = stoi(b);

  int ans = 1;
  while (p) {
    if (p & 1) ans = ans * a % m;
    a = a * a % m;
    p >>= 1;
  }

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> ?_;
  int _ = 1;
  while (_--) solve();
}