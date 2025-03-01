// date: 2025-02-26 19:04:36
// tag: 他妈的明明二分这么好写，你他妈吃饱了撑的写什么注重细节的双指针啊，草泥马

#include <bits/stdc++.h>
#define int long long

int solve(std::string str) {
  int l = 0;
  int n = str.size();
  while (l < n - l - 1 && str[l] == str[n - l - 1]) l++;
  str = str.substr(l, n - l - l);
  // std::cerr << str << '\n';
  n = str.size();
  l = 0;
  int r = n, ans = -1;
  auto check = [&](int mid) {
    std::vector<int> cnt(200);
    if (mid <= n / 2) {
      for (int i = mid; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
          return false;
        }
      }
      for (int i = 0; i < mid; i++) {
        cnt[str[i]]++;
      }
      for (int i = n - mid; i < n; i++) {
        if (--cnt[str[i]] < 0) {
          // if (mid == 2) {
          //   std::cerr << "qwq" << str[i] << '\n';
          // }
          return false;
        }
      }
      return true;
    }
    for (int i = 0; i < mid; i++) {
      cnt[str[i]]++;
    }
    for (int i = mid; i < n; i++) {
      if (--cnt[str[i]] < 0) {
        return false;
      }
    }
    for (int i : cnt) {
      if (i && i % 2 == 1) {
        return false;
      }
    }
    return true;
  };
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  // std::cout << ans << '\n';
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    int ans = solve(str);
    std::reverse(str.begin(), str.end());
    ans = std::min(ans, solve(str));
    std::cout << ans << '\n';
  }
  return 0;
}