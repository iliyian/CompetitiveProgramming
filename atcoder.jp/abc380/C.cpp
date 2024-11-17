#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int start = 0, end = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '1' && str[i - 1] != '1') {
      cnt++;
      if (cnt == k) {
        start = i;
      }
    }
    if (str[i] != '1' && str[i - 1] == '1' && cnt == k) {
      end = i - 1;
    }
  }
  if (start && !end) end = n;
  int cnt0 = 0;
  int t = start - 1;
  while (t >= 1 && str[t] == '0') t--, cnt0++;
  // std::cout << start << ' ' << end << ' ' << cnt0 << '\n';
  std::shift_left(str.begin() + start - cnt0, str.begin() + end + 1, cnt0);
  for (int i = end; i >= end - cnt0 + 1; i--) str[i] = '0';
  std::cout << str.substr(1, n) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};