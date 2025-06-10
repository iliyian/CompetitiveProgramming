#include <bits/stdc++.h>
#define int long long

void solve() {
  int m, k;
  std::cin >> m >> k;
  std::vector<std::string> rev(k + 1);
  std::map<std::string, int> mp;
  std::set<std::string> s;
  while (m--) {
    std::string str, name;
    std::cin >> str >> name;
    if (str == "join") {
      if (s.size() == k) {
        std::cout << "full\n";
        continue;
      }
      std::cout << "joined\n";
      for (auto &n : s) {
        mp[n]++;
        rev[mp[n]] = n;
      }
      s.insert(name);
      mp[name] = 0;
      rev[0] = name;
    } else if (str == "exit") {
      int p = mp[name];
      for (auto &n : s) {
        if (mp[n] > p) {
          mp[n]--;
          rev[mp[n]] = n;
        }
      }
      s.erase(name);
      mp.erase(name);
      std::cout << "exited\n";
    } else if (str == "kill") {
      int p = mp[name];
      for (auto &n : s) {
        if (mp[n] < p) {
          mp[n]++;
          rev[mp[n]] = n;
        }
      }
      mp[name] = 0;
      rev[0] = name;
      std::cout << "killed\n";
    } else if (str == "ask") {
      std::cout << mp[name] << '\n';
    } else {
      std::cout << rev[std::stoll(name)] << '\n';
    }
  }
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