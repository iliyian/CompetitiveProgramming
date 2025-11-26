#include <bits/stdc++.h>
// #define int long long

void solve() {
  int n;
  std::cin >> n;
  std::map<std::string, int> cnt, tm;
  std::vector<std::map<std::string, int>> failed(26), unknown(26);
  std::vector<std::tuple<std::string, int, int, std::string>> a(n);
  for (auto &[teamname, _id, time, result] : a) {
    char id;
    std::cin >> teamname >> id >> time >> result;
    _id = id - 'A';
  }
  std::ranges::sort(a, [&](const auto &x, const auto &y) {
    return std::get<2>(x) < std::get<2>(y);
  });
  for (auto &[teamname, id, time, result] : a) {
    if (result == "Accepted") {
      auto x = cnt[teamname];
      if (x >> id & 1 ^ 1) {
        cnt[teamname] |= 1 << id;
        tm[teamname] -= time + failed[id][teamname] * 20;
      }
    } else if (result == "Rejected") {
      if (cnt[teamname] >> id & 1) {
      } else {
        failed[id][teamname]++;
      }
    } else {
      if (!cnt.count(teamname)) {
        cnt[teamname] = 0;
      }
      if (!unknown[id].count(teamname)) {
        unknown[id][teamname] = time;
      }
    }
  }
  std::vector<std::string> ans;
  std::map<std::string, std::pair<int, int>> prv, suf;
  int pcnt = 0, ptm = INT_MAX / 3;

  for (auto &[k, v] : cnt) {
    prv[k] = std::pair{pcnt, ptm};
    int _cnt = __builtin_popcountll(v);
    if (std::tie(pcnt, ptm) < std::tie(_cnt, tm[k])) {
      pcnt = _cnt, ptm = tm[k];
    }
  }
  pcnt = 0, ptm = INT_MAX / 3;
  for (auto &[k, v] : cnt | std::views::reverse) {
    suf[k] = std::pair{pcnt, ptm};
    int _cnt = __builtin_popcountll(v);
    if (std::tie(pcnt, ptm) < std::tie(_cnt, tm[k])) {
      pcnt = _cnt, ptm = tm[k];
    }
  }

  for (auto &[k, v] : cnt) {
    auto mx = std::max(prv[k], suf[k]);
    int pcnt = __builtin_popcountll(v), ptm = tm[k];
    for (int i = 0; i < 26; i++) {
      if (unknown[i].count(k) && v >> i & 1 ^ 1) {
        pcnt++;
        ptm -= unknown[i][k] + failed[i][k] * 20;
      }
    }
    if (std::tie(pcnt, ptm) >= std::tie(mx.first, mx.second)) {
      ans.push_back(k);
    }
  }
  std::ranges::sort(ans);
  for (auto &s : ans) {
    std::cout << s << ' ';
  }
  std::cout << '\n';
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