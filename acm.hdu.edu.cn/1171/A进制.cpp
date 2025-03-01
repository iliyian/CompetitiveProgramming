// date: 2025-03-01 14:41:23
// tag: 进制转换完全可以不用vector，频繁申请和释放真的很耗时，哎卡常

#include <bits/stdc++.h>
#define int long long

constexpr int N = 30000;

void solve() {
  int n, A, x;
  std::cin >> n >> A >> x;
  std::vector<std::bitset<N + 1>> f(n + 1);
  f[0][x] = 1;
  auto opt = [&](int x, int y, int op) {
    // 下面这段注释的是个大常数的做法
    // 甚至用stack也不行，这常数要求很小
    // 哎 base


    // std::vector<int> vx, vy;
    // std::stack<int> vx, vy;
    // while (x) {
    //   // vx.push_back(x % A);
    //   vx.push(x % A);
    //   x /= A;
    // }
    // while (y) {
    //   // vy.push_back(y % A);
    //   vy.push(y % A);
    //   y /= A;
    // }
    // while (vx.size() < vy.size()) vx.push(0);
    // while (vy.size() < vx.size()) vy.push(0);
    // int ans = 0;
    // while (!vx.empty()) {
    //   ans = ans * A + (op == 1 ? std::min(vx.top(), vy.top()) : op == 2 ? std::max(vx.top(), vy.top()) : (vx.top() + vy.top()) % A);
    //   vx.pop();
    //   vy.pop();
    // }
    // return ans;
    
    int ans = 0, t = 1;
    while (x || y) {
      ans = ans + t * (op == 1 ? std::min(x % A, y % A) : op == 2 ? std::max(x % A, y % A) : (x % A + y % A) % A);
      x /= A, y /= A;
      t *= A;
    }
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    int y;
    std::cin >> y;
    for (int j = 0; j <= N; j++) {
      if (f[i - 1][j]) {
        f[i][opt(j, y, 1)] = 1;
        f[i][opt(j, y, 2)] = 1;
        f[i][opt(j, y, 3)] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (f[n][i]) {
      ans += i;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}