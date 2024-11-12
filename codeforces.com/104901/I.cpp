#include <bits/stdc++.h>
#include <iostream>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::pair<int, int>> ans;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = n; j >= i + 1; j--) {
  //     if (a[j] < a[i]) {
  //       ans.push_back({i, j});
  //       i = j;
  //       break;
  //     }
  //   }
  // }
  int j = 2, pos = 0, cnt = 0;
  for (int i = 1; i <= n; i++) 
  {
    j = std::max(i+1, j);
  //std::cout << i << ' ' << j<<std::endl;
    if (a[i] != i) 
    {
      cnt = 0;
      pos = 0;
      for (; j <= n && cnt < a[i] - i; j++) 
      {
        if (a[j] < a[i]) 
        {
          cnt++;
          pos = j;
        }
      }
      //if(pos == 0) continue;
      ans.push_back({i, pos});
      std::sort(a.begin() + i, a.begin() + pos + 1);
    }
    //for(int k = 1; k <= n; k++) std::cout << a[k] << ' ';
    //std::cout << std::endl;

  }
  std::cout << ans.size() << '\n';
  for (auto [l, r] : ans) {
    std::cout << l << ' ' << r << '\n';
  }
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