#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), sum(n + 1);
  multiset<int> s;
  s.insert(0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    s.insert(sum[i]);
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, (*s.rbegin()) - sum[i]);
    s.erase(s.find(sum[i]));
  }
  int ans = (mx % mod * qpow(2, k) % mod + sum[n] % mod - mx % mod) % mod;
  cout << (ans + mod) % mod << '\n';
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