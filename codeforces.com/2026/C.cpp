#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int ans = (n + 1) * n / 2;
  int prv = 0;
  std::vector<int> vis(n + 1);
  std::queue<int> q;
  for (int i = n; i >= 1; i--) {
    if (str[i] == '0') {
      if (!q.empty()) {
        ans -= q.front(); q.pop();
      }
    } else {
      q.push(i);
    }
  }
  int t = q.size();
  for (int i = 0; i < t / 2; i++) {
    ans -= q.front(); q.pop();
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}