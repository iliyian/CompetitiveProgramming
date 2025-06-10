// date: 2025-03-16 12:57:02
// tag: 什么严谨的时间复杂度分析，什么set::erase的神奇用法。子序列的前缀性的性质

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> s(n + 1);
  int len = 0;
  std::vector<std::vector<int>> rev(200);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    std::reverse(s[i].begin(), s[i].end());
    len += s[i].size();
    rev[s[i].back()].push_back(i);
  }
  std::string t;
  std::cin >> t;
  // if (n == 99000) {
  //   std::cout << t << '\n';
  //   return;
  // }
  std::reverse(t.begin(), t.end());
  std::string ans;
  int prvlen = len;
  std::set<int> alive;
  for (int i = 0; i < n; i++) alive.insert(i);
  while (len) {
    // std::cerr << len << '\n';
    bool f = false;
    // for (int i = 0; i < n; i++) {
    //   std::cerr << s[i] << ' ';
    // }
    // std::cerr << t << '\n';

    // auto nxtalive = alive;
    for (char i = 'a'; i <= 'z'; i++) {
      if (!rev[i].empty() && t.back() != i) {
        std::vector<int> tmp;
        for (auto j : rev[i]) {
          s[j].pop_back();
          len--;
          if (!s[j].empty()) {
            if (s[j].back() == i) {
              tmp.push_back(j);
            } else {
              rev[s[j].back()].push_back(j);
            }
          } else {
            alive.erase(j);
          }
        }
        ans.push_back(i);
        rev[i].clear();
        for (auto j : tmp) {
          rev[i].push_back(j);
        }
        f = true;
        break;
      }
    }

    // for (int i = 0; i < n; i++) {
    //   if (!s[i].empty() && t.back() != s[i].back()) {
    //     std::vector<int> tmp;
    //     char x = s[i].back();
    //     std::cerr << x << '\n';
    //     ans.push_back(x);
    //     assert(!rev[x].empty());
    //     for (auto j : rev[x]) {
    //       // std::cerr << j << '\n';
    //       s[j].pop_back();
    //       len--;
    //       if (!s[j].empty()) {
    //         if (s[j].back() == x) {
    //           tmp.push_back(j);
    //         } else {
    //           rev[s[j].back()].push_back(j);
    //         }
    //       }
    //     }
    //     rev[x].clear();
    //     for (auto j : tmp) {
    //       rev[x].push_back(j);
    //     }
    //     f = true;
    //     break;
    //   }
    // }
    // for (char i = 'a'; i <= 'z'; i++) {
    //   for (int j = 0; j < n; j++) {
    //     if (s[j].empty()) continue;
    //     if (s[j].back() == i && t.back() != i) {
    //       f = true;
    //       ans.push_back(i);
    //       for (int k = 0; k < n; k++) {
    //         if (!s[k].empty() && s[k].back() == i) {
    //           s[k].pop_back();
    //         }
    //       }
    //       break;
    //     }
    //   }
    //   if (f) {
    //     break;
    //   }
    // }
    if (!f) {
      rev[t.back()].clear();
      // for (int i = 0; i < n; i++) {
      for (auto it = alive.begin(); it != alive.end();) {
        int i = *it;
        if (!s[i].empty()) {
          s[i].pop_back(), len--;
          if (!s[i].empty()) {
            // std::cerr << s[i].back() << '\n';
            rev[s[i].back()].push_back(i);
          } else {
            it = alive.erase(it);
            continue;
          }
        }
        it++;
      }
      ans.push_back(t.back());
      t.pop_back();
      // if (n == 99000) {
      //   std::cout << len << ' ';
      // }
    }
    // alive = nxtalive;

    // if (n == 99000) {
    //   std::cout << len << ' ';
    // }
    // assert(prvlen != len);
    // prvlen = len;
  }
  if (t.empty()) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}