#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
// using namespace std;

struct Seg {
  int l, r, v, mx;
};

void solve() {
  int n, w, h;
  std::cin >> n >> w >> h;
  std::vector<int> a(n + 1);
  std::vector<int> vec;
  for (int i = 1; i <= n; i++) {
    
  }
  std::sort(a.begin() + 1, a.end(), [&])
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}