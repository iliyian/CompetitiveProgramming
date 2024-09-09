// date: 2024-09-08 22:21:15
// tag: 转线性基

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9 + 7;

std::vector<int> p(31);

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void insert(int x) {
  for (int i = 30; i >= 0; i--) {
    if (x >> i & 1) {
      if (p[i]) {
        x ^= p[i];
      } else {
        p[i] = x;
        return;
      }
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("C.in", "r", stdin);
  int n;
  std::cin >> n;

  std::vector<int> pri, minp(101, -1);
  for (int i = 2; i <= 100; i++) {
    if (minp[i] == -1) {
      minp[i] = pri.size();
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > 100) break;
      minp[i * pri[j]] = j;
      if (i % pri[j] == 0) break;
    }
  }

  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    int res = 0;
    for (int j = 0; pri[j] <= x; j++) {
      if (x % pri[j] == 0) {
        int cnt = 0, t = x;
        while (t % pri[j] == 0) {
          cnt ^= 1;
          t /= pri[j];
        }
        res ^= cnt << j;
      }
    }
    insert(res);
  }
  for (int i = 30; i >= 0; i--) {
    if (p[i]) {
      n--;
    }
  }
  std::cout << qpow(2, n) - 1 << '\n';
  return 0;
}