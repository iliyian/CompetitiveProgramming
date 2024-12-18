// date: 2024-07-16 13:21:44
// tag: 堆

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int cur = 0;
int n, m, q, u, v, t;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::cin >> n >> m >> q >> u >> v >> t;

  std::vector<int> a(n + 1);
  std::queue<int> qa, qb, qc;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  sort(a.begin() + 1, a.end(), std::greater<int>());
  for (int i = 1; i <= n; i++) {
    qa.push(a[i]);
  }

  auto pop = [&]() {
    int len = LLONG_MIN;
    if (!qa.empty()) len = std::max(len, qa.front());
    if (!qb.empty()) len = std::max(len, qb.front());
    if (!qc.empty()) len = std::max(len, qc.front());

    if (len == qa.front()) qa.pop();
    else if (len == qb.front()) qb.pop();
    else if (len == qc.front()) qc.pop();

    return len;
  };

  for (int i = 1; i <= m; i++) {
    int len = pop();

    len += cur * q;

    if (i % t == 0) {
      std::cout << len << ' ';
    }

    int l = len * u / v;
    int r = len - l;

    cur++;

    qb.push(l - cur * q);
    qc.push(r - cur * q);
  }

  std::cout << '\n';
  
  int tm = 0;
  for (int i = 1; i <= n + m; i++) {
    int len = pop();
    if (i % t == 0) {
      std::cout << len + cur * q << ' ';
    }
  }

  return 0;
}