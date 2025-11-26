#include <bits/stdc++.h>
#define int long long

std::vector<int> ask(std::vector<int> v) {
  std::cout << "? " << v.size() << ' ';
  for (int i : v) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  int n;
  std::cin >> n;
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ans.push_back(x);
  }
  return ans;
}

void answer(std::vector<int> v) {
  std::cout << "! ";
  for (int i : v) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> vis(n * n + 2), pa(n * n + 2);
  for (int i = 1; i <= n; i++) {
    std::vector<int> v;
    for (int j = 1; j <= n * n + 1; j++) {
      if (!vis[j]) {
        v.push_back(j);
      }
    }
    auto ans = ask(v);
    if (ans.size() >= n + 1) {
      while (ans.size() > n + 1) ans.pop_back();
      answer(ans);
      return;
    }
    for (int j : ans) {
      vis[j] = 1;
    }
    for (int j = 1; j <= n * n + 1; j++) {
      if (!vis[j]) {
        pa[j] = *std::prev(std::ranges::lower_bound(ans, j));
      }
    }
  }
  std::vector<int> ans;
  for (int i = 1; i <= n * n + 1; i++) {
    if (!vis[i]) {
      while (i) {
        ans.push_back(i);
        i = pa[i];
      }
      break;
    }
  }
  std::ranges::reverse(ans);
  answer(ans);
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