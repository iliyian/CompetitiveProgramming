#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;

  std::vector<int> sum(k + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      char ch;
      std::cin >> ch;
      sum[j] += ch == '1';
    }
  }
  for (int i = 1; i <= k; i++) {
    
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}