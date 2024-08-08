// date: 2024-08-03 15:06:56
// tag: mobius

// 关键在于枚举倍数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> mo(n + 1), vis(n + 1), pri;
  mo[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      mo[i] = -1;
    }
    for (int p : pri) {
      if (i * p > n) break;
      vis[i * p] = true;
      if (i % p == 0) {
        mo[i * p] = 0;
        break;
      }
      mo[i * p] = -mo[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    mo[i] += mo[i - 1];
  }

  auto calc = [&](int t) -> int {
    int ans = 0;
    for (int i = 1, j; i <= t; i = j + 1) {
      j = t / (t / i);
      ans += (t / i) * (t / i) * (mo[j] - mo[i - 1]);
    }
    return ans;
  };

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * calc(n / i);
  }

  ans = (ans - n * (n + 1) / 2) / 2;
  std::cout << ans << '\n';
  return 0;
}