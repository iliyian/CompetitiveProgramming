// date: 2024-07-27 14:57:39
// tag: 搜索

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve(int n) {
  std::vector<int> a(n * (n - 1) / 2 + 1);
  std::multiset<int> s;
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
  }
  auto dfs = [&](auto self, int u, int cnt, std::vector<int> &ans) -> bool {
    if (u == n * (n - 1) / 2 + 1) {
      return true;
    }
    int au = *s.begin() - ans.front();
    bool f = true;

    for (int i = 0; i < cnt; i++) {
      if (s.find(au + ans[i]) == s.end()) {
        return false;
      }
    }

    for (int i = 0; i < cnt; i++) {
      if (s.find(au + ans[i]) == s.end()) {
        return false;
      }

      // 鬼知道为什么不再检查一次会出问题，拍5000组数据大概能复现
      // 有空你可以拍拍看，RE了16,20,22,26这几个点，上面三行删除的话
      s.erase(s.find(au + ans[i]));
    }

    ans.push_back(au);
    if (self(self, u + cnt, cnt + 1, ans)) {
      return true;
    }
    ans.pop_back();

    for (int i = 0; i < cnt; i++) {
      s.insert(au + ans[i]);
    }

    return false;
  };
  std::vector<int> ans;
  for (int i = 1; i <= a[1]; i++) {
    ans.push_back(i);
    bool f = dfs(dfs, 1, 1, ans);
    if (f) {
      for (auto i : ans) {
        std::cout << i << ' ';
      }
      std::cout << '\n';
      return;
    }
    ans.pop_back();
  }
  std::cout << "Impossible\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  while (std::cin >> n) {
    solve(n);
  }

  return 0;
}