// date: 2024-07-25 16:37:38
// tag: 并查集，观察
// 这是O(n+nlogn)的吗？考虑质因数数量最多为O(logn)
// 显著快于oi-wiki打表前提下的O(sqrt(n/lnn)) ?

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e6)
// using namespace std;

std::vector<int> pri;
std::vector<int> low(N + 1, -1);
std::vector<std::vector<int>> pos(N);
int tot = -1;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n * 2);
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x == 1) {
      ans += n;
    }
    a[i - 1] = a[i + n - 1] = x;
  }

  std::set<int> s;
  for (int i = 1; i < n * 2; i++) {
    int tmp = a[i];
    while (tmp > 1) {
      s.insert(low[tmp]);
      pos[low[tmp]].push_back(i);
      tmp /= pri[low[tmp]];
    }
  }

  std::vector<int> pa(n * 2), siz(n * 2, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) {
      return;
    }
    if (siz[x] > siz[y]) {
      std::swap(x, y);
    }
    pa[x] = y;
    siz[y] += siz[x];
  };

  for (int p : s) {
    auto &v = pos[p];
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 1; i < v.size(); i++) {
      if (v[i] - v[i - 1] <= k) {
        merge(v[i], v[i - 1]);
      }
    }
    v.clear();
  }

  for (int i = 1; i <= n * 2 - 1; i++) {
    if (a[i] > 1) {
      ans += pa[i] == i;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (low[i] == -1) {
      low[i] = ++tot;
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > N) break;
      low[i * pri[j]] = j;
      if (i % pri[j] == 0) break;
    }
  }


  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}