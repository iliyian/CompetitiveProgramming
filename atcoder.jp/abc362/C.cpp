#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  int mn = 0, mx = 0;

  std::vector<int> ans(n + 1), l(n + 1), r(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
    mn += l[i], mx += r[i];
    sum += l[i];
    ans[i] = l[i];
  }

  if (mn <= 0 && 0 <= mx) {
    std::cout << "Yes\n";
    
    for (int i = 1; i <= n; i++) {
      if (sum < 0) {
        int t = std::min(r[i] - l[i], -sum);
        sum += t;
        ans[i] += t;
      }
      std::cout << ans[i] << ' ';
    }

  } else {
    std::cout << "No\n";
  }

  return 0;
}