#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937_64 rd(std::random_device{}());

  auto check = [&](std::vector<int> &a) {
    if (a.size() % 3) return false;
    std::vector<int> p(a.size());
    std::ranges::iota(p, 0);
    do {
      bool flag = true;
      for (int i = 0; i < a.size(); i += 3) {
        if (a[p[i]] == a[p[i + 1]] && a[p[i + 1]] == a[p[i + 2]]) {
        } else if (a[p[i]] == a[p[i + 1]] - 1 && a[p[i + 1]] == a[p[i + 2]] - 1) {
        } else {
          flag = false;
          break;
        }
      }
      if (flag) {
        return true;
      }
    } while (std::next_permutation(p.begin(), p.end()));
    return false;
  };

  std::ofstream os("d.in");
  int t = 10;
  os << t << '\n';
  for (int i = 1; i <= t; i++) {
    int n = 10000;
    os << n << '\n';
    std::vector<int> a(n);
    for (auto &i : a) i = rd() % 5 + 1;
    for (auto i : a) {
      os << i << ' ';
    }
    os << '\n';
    // int ans = 0;
    // for (int l = 0; l < n; l++) {
    //   for (int r = l; r < n; r++) {
    //     std::vector<int> v;
    //     for (int i = l; i <= r; i++) {
    //       v.push_back(a[i]);
    //     }
    //     if (check(v)) {
    //       ans++;
    //     }
    //   }
    // }
    // os << ans << '\n';
  }
  return 0;
}