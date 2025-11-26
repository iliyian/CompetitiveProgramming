#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s;
  int q;
  std::cin >> s >> q;
  std::vector<int> vl, vr;
  int n = s.size();
  std::vector<int> nxl(n + 1, -1), nxr(n + 1, -1);
  vl.push_back(-1);
  vr.push_back(-1);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      while (!vl.empty()) {
        nxl[vl.back() + 1] = i + 1; vl.pop_back();
      }
    } else {
      while (!vr.empty()) {
        nxr[vr.back() + 1] = i + 1; vr.pop_back();
      }
    }
    vl.push_back(i);
    vr.push_back(i);
  }
  // for (int i = 0; i < n; i++) {
  //   std::cerr << nxl[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cerr << nxr[i] << ' ';
  // }
  // std::cerr << '\n';
  while (q--) {
    std::string t;
    std::cin >> t;
    int j = 0;
    if (t[0] == 'R' && s[0] == 'L') {
      std::cout << "NO\n";
      continue;
    }
    for (int i = 0; i < t.size(); i++) {
      if (t[i] == 'L') {
        j = nxl[j];
      } else {
        j = nxr[j];
      }
      if (j == -1) {
        std::cout << "NO\n";
        goto end;
      }
    }
    // std::cerr << j << ' ' << t.back() << '\n';
    if (s.back() == 'R' && t.back() == 'L' && j != -1) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    end:;
  }
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