#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::array<int, 9>> cnt(n + 1);
  // std::array<int, 9> cnt;
  // cnt.fill(0);
  // int cnts[6561] {};
  // std::vector<int> cnts[6561];
  std::vector<std::vector<int>> cnts(6561);
  int p[11] {};
  p[0] = 1;
  for (int j = 0; j < 10; j++) {
    p[j + 1] = p[j] * 3;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  // int realans;
  // std::cin >> realans;
  auto get = [&](int x, int pos) {
    return x / p[pos] % 3;
  };
  int ans = 0;
  // cnts[0] = 1;
  cnts[0].push_back(-1);
  for (int i = 0; i < n; i++) {
    cnt[i + 1] = cnt[i];
    cnt[i + 1][a[i]]++;
    int now = 0;
    for (int j = 8; j >= 1; j--) {
      now = now * 3 + cnt[i + 1][j] % 3;
    }
    for (int j = 0; j < 729; j++) {
      int s = 0;
      auto b = cnt[i + 1];
      int used[9] {};
      int l = 0, r = i - 1, minpos = -1;
      for (int k = 0; k < 6; k++) {
        int val = get(j, k);
        if (val) {
          for (int t = k + 1; t <= k + 3; t++) {
            b[t] -= val;
            used[t]++;
            if (b[t] < 0) {
              goto end;
            }
          }
        }
      }
      while (l <= r) {
        int mid = (l + r) / 2;
        bool flag = true;
        for (int j = 1; j <= 8; j++) { 
          if (cnt[i + 1][j] - cnt[mid][j] < used[j]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          l = mid + 1, minpos = mid;
        } else {
          r = mid - 1;
        }
      }
      for (int k = 8; k >= 1; k--) {
        s = s * 3 + b[k] % 3;
      }
      if (i == 8 && j == 13) {
        // std::cerr << minpos << ' ' << s << '\n';
        // for (auto i : cnts[s]) {
        //   std::cerr << i <<' ';
        // }
        // std::cerr << '\n';
      }
      // ans += cnts[s];
      // if (i == 8 && cnts[s].size()) {
      //   std::cerr << s << '\n';
      // }
      // ans += cnts[s].size();
      ans += std::ranges::upper_bound(cnts[s], minpos) - cnts[s].begin();
      // for (auto j : cnts[s]) {
      //   std::cerr << j + 2 << ' ' << i + 1 << '\n';
      // }
      end:;
    }
    // cnts[now]++;
    cnts[now].push_back(i);
  }
  std::cout << ans << '\n';
  // if (ans != realans) {
  //   std::cout << "WA\n";
  //   for (auto i : a) {
  //     std::cout << i << ' ';
  //   }
  //   std::cout << '\n';
  //   std::cout << ans << ' ' << realans << '\n';
  //   exit(0);
  // }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}