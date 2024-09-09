#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b;
std::vector<int> ans;

bool work(int cur) {
  if (cur > b) return false;
  if (cur == b) return true;
  ans.push_back(cur * 2);
  if (work(cur * 2)) return true;
  ans.pop_back();
  ans.push_back(cur * 10 + 1);
  if (work(cur * 10 + 1)) return true;
  ans.pop_back();
  return false;
}

void solve() {
  std::cin >> a >> b;
  ans.push_back(a);
  bool f = work(a);
  if (f) {
    std::cout << "YES\n" << ans.size() << '\n';
    for (auto i : ans) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "NO\n";
  }
}

signed main() {
  freopen("N.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}