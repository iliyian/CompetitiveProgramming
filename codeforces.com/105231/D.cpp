// date: 2024-07-01 20:48:35
// tag: gcd与lcm，模拟

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e6)
#define mod 998244353
// using namespace std;

std::vector<int> pri;
std::bitset<N + 1> vis;

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
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::pair<int, int>> f;
  std::vector<int> pri;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        int cur = 0;
        while (a[i] % j == 0) a[i] /= j, cur++;
        f.push_back({j, cur});
        pri.push_back(j);
      }
    }
    if (a[i] > 1) {
      f.push_back({a[i], 1});
      pri.push_back(a[i]);
    }
  }
  auto cmp = [&](const std::pair<int, int> &x, const std::pair<int, int> &y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
  };
  std::sort(f.begin(), f.end(), cmp);
  std::sort(pri.begin(), pri.end());
  pri.erase(unique(pri.begin(), pri.end()), pri.end());

  std::set<int> raw_pointers;
  for (int i = 0; i < pri.size(); i++) {
    raw_pointers.insert(lower_bound(f.begin(), f.end(), std::pair{pri[i], 0}, std::less<std::pair<int, int>>()) - f.begin());
  }
  std::set<int> pointers = raw_pointers;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::set<int> rm;
    int res = 1;
    for (auto j : pointers) {
      res = res * qpow(f[j].first, f[j].second) % mod;
      if (j == f.size() - 1 || raw_pointers.count(j + 1)) {
        rm.insert(j);
      }
    }
    for (auto j : rm) {
      pointers.erase(j);
    }
    std::set<int> nxt;
    for (auto j : pointers) {
      nxt.insert(j + 1);
    }
    pointers = nxt;
    ans = (ans + res) % mod;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}