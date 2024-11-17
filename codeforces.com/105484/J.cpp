#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> isfriend(k + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    isfriend[x] = true;
  }
  std::map<std::pair<int, int>, int> mp;
  std::vector<int> cntx(k + 1);
  int prv = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    if (isfriend[a] && !isfriend[b]) {
      cntx[b]++;
    } else if (!isfriend[a] && isfriend[b]) {
      cntx[a]++;
    } else if (isfriend[a] && isfriend[b]) {
      prv++;
    } else {
      if (a == b) {
        cntx[a]++;
      } else {
        mp[{a, b}]++;
      }
    }
  }
  int mx = 0, spmx = 0;

  std::vector<int> id(k + 1);
  std::iota(id.begin(), id.end(),  0);
  std::sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return cntx[x] > cntx[y];
  });
  if (k > 1 && cntx[id[1]] > 0) {
    spmx += cntx[id[1]];
  }
  if (k > 2 && cntx[id[2]] > 0) {
    spmx += cntx[id[2]];
    int x = std::min(id[1], id[2]), y = std::max(id[1], id[2]);
    spmx += mp[{x, y}];
  }
  
  for (auto &[k, v] : mp) {
    // std::cout << k.first << ' ' << k.second << ' ' << v << '\n';
    mx = std::max(mx, v + cntx[k.first] + cntx[k.second]);
  }

  std::cout << std::max(mx, spmx) + prv << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}