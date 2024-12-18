// date: 2024-08-17 14:38:42
// tag: 莫比乌斯反演，数论分块

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 4e6 + 1;

std::vector<int> low(N + 1, -1), pri, mo(N + 1);

int calc(int n) {
  int ans = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    ans += (mo[j] - mo[i - 1]) * (n / i) * (n / j);
  }
  return ans;
}

void solve(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * calc(n / i);
  }
  ans = (ans - n * (n + 1) / 2) / 2;
  std::cout << ans << '\n';
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

  int n;
  while (std::cin >> n && n) {
    solve(n);
  }

  return 0;
}