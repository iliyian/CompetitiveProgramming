#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string head = "main";
  int tot = 1;
  std::vector<std::bitset<6000>> g2(6001);
  std::vector<std::vector<int>> g(6001);
  std::map<std::string, int> to;
  to[head] = 1;
  g2[1] = 1;
  std::vector<std::vector<std::string>> cmds(n);
  auto add = [&](int x, int y) {
    // while (g1.size() <= x || g1.size() <= y) g1.push_back({});
    // while (g2.size() <= x || g2.size() <= y) g2.push_back({});
    // g1[x].push_back(y);
    // g2[y].push_back(x);
    g2[y][y] = 1;
    g2[y] |= g2[x];
    g[y].push_back(x);
  };
  int t = n;
  // auto getp = [&](auto self, int x, std::vector<int> &s) -> void {
  //   // s.insert(x);
  //   s.push_back(x);
  //   if (x == 1) return;
  //   for (int y : g2[x]) {
  //     self(self, y, s);
  //   }
  // };
  auto in = [&](std::bitset<6000> &x, std::bitset<6000> &y) {
    return (x | y) == y;
    // for (auto v : x) {
    //   if (!y.count(v)) {
    //     return false;
    //   }
    // }
    // int l = 0, r = 0;
    // while (l < x.size()) {
    //   while (r < y.size() && x[l] != y[r]) r++;
    //   if (r == y.size()) {
    //     return false;
    //   }
    //   l++;
    // }
    // return true;
  };
  std::string tmp;
  // while (t--) {
  //   std::string cmd;
  //   std::cin >> cmd;
  //   if (cmd == "commit" || cmd == "branch" || cmd == "merge" || cmd == "reset" || cmd == "checkout") {
  //     t--;
  //     cmds.push_back({cmd});
  //   } else {
  //     cmds.back().push_back(cmd);
  //   }
  // }
  std::string cmd;
  std::getline(std::cin, tmp);
  for (int i = 0; i < n; i++) {
    std::getline(std::cin, cmd);
    int prv = -1;
    for (int j = 0; j < cmd.size(); j++) {
      if (cmd[j] == ' ') {
        cmds[i].push_back(cmd.substr(prv + 1, j - prv - 1));
        prv = j;
      }
    }
    cmds[i].push_back(cmd.substr(prv + 1, cmd.size() - prv - 1));
    // std::getline(std::cin, cmd);
    // std::stringstream ss;
    // ss << cmd;
    // while (ss >> cmd) {
    //   cmds[i].push_back(cmd);
    // }
  }
  for (auto &cmd : cmds) {
    if (cmd[0] == "commit") {
      int cur = to[head];
      add(cur, ++tot);
      to[head] = tot;
    }
    else if (cmd[0] == "branch") {
      if (cmd[1] == "-d") {
        if (!to.count(cmd[2])) continue;
        to.erase(cmd[2]);
      } else {
        if (cmd.size() == 3) {
          to[cmd[1]] = stoi(cmd[2]);
        } else {
          to[cmd[1]] = to[head];
        }
      }
    }
    else if (cmd[0] == "merge") {
      // std::vector<int> a, b;
      int a = to[head], b = to[cmd[1]];
      // getp(getp, to[head], a);
      // getp(getp, to[cmd[1]], b);
      // std::sort(a.begin(), a.end());
      // std::sort(b.begin(), b.end());
      if (!in(g2[b], g2[a])) {
        if (in(g2[a], g2[b])) {
          to[head] = to[cmd[1]];
        } else {
          int x = ++tot;
          add(to[head], x);
          add(to[cmd[1]], x);
          to[head] = x;
        }
      }
    }
    else if (cmd[0] == "checkout") {
      head = cmd[1];
    }
    else if (cmd[0] == "reset") {
      if (cmd.size() == 2) {
        to[head] = stoi(cmd[1]);
      }
    }
  }
  std::cout << to.size() << '\n';
  for (auto &[k, v] : to) {
    std::cout << k << ' ' << v << '\n';
  }
  std::cout << tot << '\n';
  for (int i = 1; i <= tot; i++) {
    std::cout << g[i].size() << ' ';
    std::sort(g[i].begin(), g[i].end());
    for (auto v : g[i]) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
  }
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