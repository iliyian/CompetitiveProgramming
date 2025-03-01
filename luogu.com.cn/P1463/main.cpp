// date: 2024-07-27 16:54:17
// tag: 打表，筛法

#include <bits/stdc++.h>

int dict[] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160, 2882880, 3603600, 4324320, 6486480, 7207200, 8648640, 10810800, 14414400, 17297280, 21621600, 32432400, 36756720, 43243200, 61261200, 73513440, 110270160, 122522400, 147026880, 183783600, 245044800, 294053760, 367567200, 551350800, 698377680, 735134400, 1102701600, 1396755360, 2095133040};

int main() {
  int n;
  std::cin >> n;
  for (int i = 0;; i++) {
    if (dict[i] > n) {
      std::cout << dict[i - 1] << '\n';
      return 0;
    }
  }
}
/*
#include <bits/stdc++.h>
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.out", "w", stdout);

  const int N = 1e7;
  std::vector<int> d(N + 1), num(N + 1), vis(N + 1), pri, low(N + 1, -1);
  d[1] = 1;
  int tot = -1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      d[i] = 2;
      num[i] = 1;
      low[i] = ++tot;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      low[i * p] = tot;
      if (i % p == 0) {
        num[i * p] = num[i] + 1;
        d[i * p] = d[i] / num[i * p] * (num[i * p] + 1);
        break;
      }
      num[i * p] = 1;
      d[i * p] = d[i] * 2;
    }
  }
  std::vector<std::pair<int, int>> pre;
  for (int i = 1; i <= N; i++) {
    if (d[i] > d[i - 1]) {
      pre.push_back({i, d[i]});
      // std::cout << i << ' ' << d[i] << '\n';
    }
    d[i] = std::max(d[i - 1], d[i]);
  }
  num.clear();
  vis.clear();

  auto get = [&](int x) {
    int cnt = 0;
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        cnt += (i * i == x ? 1 : 2);
      }
    }
    return cnt;
  };

  // int inc = 12252240;
  int inc = 720720;
  for (int i = pre.back().first; i <= 2.1e9; i += inc) {
    auto x = get(i);
    if (x > pre.back().second) {
      pre.push_back({i, x});
    }
  }
  for (auto [x, y] : pre) {
    std::cout << x << ", ";
  }

  return 0;
}
*/