#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

constexpr int N = 2e5;
std::vector<int> pri, vis(N + 1);

int isprime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  int j = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int l = std::max(0ll, i * (pri[j] - 1) + 1);
    int r = i * pri[j];
    while (sum > r) {
      l = std::max(0ll, i * (pri[j] - 1) + 1);
      r = i * pri[j];
      j++;
    }
    auto p = s.lower_bound(l - sum);
    if (p != s.end()) {
      std::cout << *p << ' ';
      sum += *p;
      s.erase(p);
    } else {
      std::cout << *(--s.end()) << ' ';
      sum += *(--s.end());
      s.erase(--s.end());
    }
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

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

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}