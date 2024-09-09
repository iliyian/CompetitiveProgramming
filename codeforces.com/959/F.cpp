// date: 2024-09-08 23:32:56
// tag: 线性基构造，子集异或值查询查询

#include <bits/stdc++.h>
#define int long long
using namespace std;

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

std::vector<int> d(31);
int tot = 0;

void insert(int x) {
  for (int i = 30; i >= 0; i--) {
    if (x >> i & 1) {
      if (d[i]) {
        x ^= d[i];
      } else {
        d[i] = x;
        tot++;
        return;
      }
    }
  }
}

bool find(int x) {
  for (int i = 30; i >= 0; i--) {
    if (x >> i & 1) {
      if (d[i]) {
        x ^= d[i];
      } else {
        return false;
      }
    }
  }
  return true;
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::array<int, 3>> ask(q + 1);
  std::vector<int> ans(q + 1);
  for (int i = 1; i <= q; i++) {
    std::cin >> ask[i][0] >> ask[i][1];
    ask[i][2] = i;
  }
  std::sort(ask.begin() + 1, ask.end());
  int cur = 1;
  for (int i = 1; i <= q; i++) {
    auto &[l, x, id] = ask[i];
    while (cur <= l) {
      insert(a[cur++]);
    }
    if (find(x)) {
      ans[id] = qpow(2, l - tot);  
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}