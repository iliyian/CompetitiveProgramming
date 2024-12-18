// date: 2024-08-17 14:22:35
// tag: 莫比乌斯反演

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e5;

std::vector<int> pri, low(N + 1, -1), mo(N + 1);

int calc(int n, int m) {
  int mn = std::min(n, m), ans = 0;
  for (int i = 1, j; i <= mn; i = j + 1) {
    j = std::min(n / (n / i), m / (m / i)); // 二维
    ans += (mo[j] - mo[i - 1]) * (n / i) * (m / j);
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  mo[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (low[i] == -1) {
      low[i] = pri.size();
      pri.push_back(i);
      mo[i] = -1;
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > N) break;
      low[i * pri[j]] = j;
      if (i % pri[j] == 0) {
        mo[i * pri[j]] = 0;
        break;
      }
      mo[i * pri[j]] = -mo[i];
    }
  }

  for (int i = 1; i <= N; i++) {
    mo[i] += mo[i - 1];
  }

  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= std::min(n, m); i++) {
    ans += i * calc(n / i, m / i);
  }
  ans = ans * 2 - n * m;
  std::cout << ans << '\n';

  return 0;
}