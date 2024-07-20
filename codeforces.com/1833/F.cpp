// date: 2024-07-19 11:46:23
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  std::sort(a.begin() + 1, a.end());
  a.erase(std::unique(a.begin() + 1, a.end()), a.end());

  std::vector<int> mul(n + 1);
  mul[0] = 1;
  for (int i = 1; i <= n; i++) {
    mul[i] = mul[i - 1] * cnt[a[i]] % mod;
  }

  int ans = 0;
  n = a.size() - 1;
  for (int l = 1; l <= n - m + 1; l++) {
    int r = l + m - 1;
    if (a[r] - a[l] >= m) continue;
    ans += mul[r] * inv(mul[l - 1]) % mod;
    ans %= mod;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}