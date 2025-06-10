#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    cnt += (str[i] == 'H') * (str.size() - i);
  }
  std::cout << (cnt % 2 ? "Alice" : "Bob") << '\n';
}

std::map<int, int> sg;

int work(int x) {
  if (!x) return 0;
  if (sg.count(x)) return sg[x];
  std::set<int> s;
  if (x & 1) s.insert(work(x - 1));
  for (int i = 1; i < 30; i++) {
    if (x >> i & 1) {
      int y = (x ^ (1 << i) ^ (1 << (i - 1)));
      s.insert(work(y));
    }
  }
  int mex = 0;
  while (s.count(mex)) mex++;
  return sg[x] = mex;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  // for (int i = 1; i <= (1 << 10); i++) {
  //   // std::cout << i << ' ' << work(i) << ' ' << __builtin_popcountll(i) << '\n';
  //   // if (work(i) != i % 2) {
  //     std::cerr << i << ' ' << work(i) << ' ';
  //     int cnt = 0;
  //     for (int j = 10; j >= 0; j--) {
  //       // std::cerr << (i >> j & 1);
  //       if (i >> j & 1) {
  //         cnt += j + 1;
  //       }
  //     }
  //     std::cerr << ' ' << cnt << '\n';
      // std::cerr << '\n';
    // }
    // // if (!work(i) && i % 2) {
    //   for (int j = 12; j >= 0; j--) {
    //     std::cout << (i >> j & 1);
    //   }
    //   std::cout << '\n';
    //   // std::cout << i << '\n';
    // } else {
    //   if (work(i) != i % 2) {
    //     std::cout << i << ' ' << work(i) << ' ' << i % 2 << '\n';
    //     for (int j = 12; j >= 0; j--) {
    //       std::cout << (i >> j & 1);
    //     }
    //     std::cout << '\n';
    //   }
    // }
    // std::cout << i << ' ' << work(i) << '\n';
  // }

  while (t--) {
    solve();
  }

  return 0;
}