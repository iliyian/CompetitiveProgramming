#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = -1;
  int tot = 0;
  auto ask = [&](int x, int sl, int sr) {
    std::cout << "? " << x << ' ' << sr - sl + 1 << ' ';
    for (int i = sl; i <= sr; i++) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
  };
  auto solve = [&](this auto &&self, int l, int r, std::vector<int> dou, std::vector<int> sin) {
    // std::cerr << "debug: " << l << ' ' << r << '\n';
    // for (int i : dou) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    // for (int i : sin) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    if (l == r) {
      ans = dou.front();
      return;
    }
    int mid = (l + r) / 2;
    std::vector<int> lsin, ldou, rsin, rdou;
    for (int i : sin) {
      int ans = ask(i, l, mid);
      if (ans) {
        lsin.push_back(i);
      } else {
        rsin.push_back(i);
      }
    }
    for (int i : dou) {
      int ansl = ask(i, l, mid), ansr = ask(i, mid + 1, r);
      if (ansl && ansr) {
        lsin.push_back(i), rsin.push_back(i);
      } else if (ansl) {
        ldou.push_back(i);
      } else {
        assert(ansr);
        rdou.push_back(i);
      }
    }
    int llen = lsin.size() + ldou.size() * 2, rlen = rsin.size() + rdou.size() * 2;
    if (llen % 2 != (mid - l + 1) % 2) {
      self(l, mid, ldou, lsin);
    } else {
      self(mid + 1, r, rdou, rsin);
    }
  };
  std::vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  solve(1, n * 2 - 1, v, {});
  std::cout << "! " << ans << std::endl;
  // std::cout << "queried " << tot << '\n';
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