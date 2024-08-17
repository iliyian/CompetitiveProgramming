// date: 2024-08-16 12:33:16
// tag: 

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e7;

std::vector<int> pri, vis(N + 1), low(N + 1, -1), sg(N + 1);
int idx = -1;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    x ^= sg[a[i]];
  }
  std::cout << (x ? "Alice" : "Bob") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  for (int i = 2; i <= N; i++) {
    if (low[i] == -1) {
      pri.push_back(i);
      low[i] = ++idx;
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > N) break;
      low[i * pri[j]] = j;
      if (i % pri[j] == 0) {
        break;
      }
    }
  }

  sg[1] = 1;
  sg[2] = 0;
  for (int i = 3; i <= N; i++) {
    if (i % 2 == 0) sg[i] = 0;
    else sg[i] = low[i] + 1;
  }

  // for (int i = 1; i <= N; i++) {
  //   std::set<int> s;
  //   if (i > 100) break;
  //   for (int j = 1; j <= i; j++) {
  //     if (std::gcd(i, j) == 1) {
  //       s.insert(sg[i - j]);
  //     }
  //   }
  //   while (s.contains(sg[i])) {
  //     sg[i]++;
  //   }
  //   std::cout << i << ' ' << sg[i] << '\n';
  // }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}