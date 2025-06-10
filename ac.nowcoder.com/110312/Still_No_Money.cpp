#include <bits/stdc++.h>
#define int long long

std::map<std::array<int, 2>, int> sg;

int work(int x, int k) {
  if (!x || !k) return 0;
  if (sg.count({x, k})) return sg[{x, k}];
  std::set<int> s;
  for (int i = 1; i <= std::min(k, x); i++) {
    s.insert(work(x - i, k - 1));
  }
  int mex = 0;
  while (s.count(mex)) mex++;
  return sg[{x, k}] = mex;
}

void solve() {
  int x, k;
  std::cin >> x >> k;
  if (k % 2 == 1 || k >= x) {
    std::cout << "OC\n";
  } else {
    std::cout << "KP\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int x = 1; x <= 100; x++) {
  //   for (int k = 1; k <= 100; k++) {
  //     std::cout << work(x, k) << " \n"[k == 100];
  //     if (k % 2 == 1 || k >= x) {
  //       assert(work(x, k) > 0);
  //     } else {
  //       if (work(x, k)) {
  //         std::cerr << x << ' ' << k << '\n';
  //       }
  //       // assert(work(x, k) == 0);
  //     }
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}