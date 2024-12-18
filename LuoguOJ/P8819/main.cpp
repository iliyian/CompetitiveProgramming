// date: 2024-08-16 15:12:40
// tag: 随机权值和维护的多重集合哈希，图论，内向基环树森林

#include <bits/stdc++.h>
#define int long long
// using namespace std;

std::mt19937 rd(std::random_device{}());

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> w(n + 1);
  int sum = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    w[i] = rd();
    sum += w[i];
  }
  std::vector<int> g(n + 1), in(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[y] += w[x];
    in[y] += w[x];
    cur += w[x];
  }
  int q;
  std::cin >> q;
  while (q--) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> y;
      in[y] -= w[x];
      cur -= w[x];
    } else if (op == 2) {
      std::cin >> x;
      cur -= in[x];
      in[x] = 0;
    } else if (op == 3) {
      std::cin >> x >> y;
      in[y] += w[x];
      cur += w[x];
    } else {
      std::cin >> x;
      cur += g[x] - in[x];
      in[x] = g[x];
    }
    std::cout << "NO\n";
  }

  return 0;
}