// date: 2024-07-27 13:34:01
// tag: SB树

#include <bits/stdc++.h>

double D, error;
bool f = false;
int N, M, ansn = 0, ansm = 1;

void dfs(int a, int b, int c, int d) {
  int n = a + c, m = b + d;
  double e = (double)n / m - D;
  if (n > N || m > M) {
    return;
  }
  if (std::abs(e) == error) {
    f = true;
  } else if (std::abs(e) < error) {
    error = std::abs(e);    
    f = false;
    ansn = n, ansm = m;
    if (!error) return;
  }
  if (e > 0) {
    dfs(a, b, n, m);
  } else {
    dfs(n, m, c, d);
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::cin >> N >> M >> D;
  error = D;

  dfs(0, 1, 1, 0);
  if (f) {
    std::cout << "TOO MANY\n";
    return 0;
  }
  std::cout << std::format("{}/{}", ansn, ansm) << '\n';
}