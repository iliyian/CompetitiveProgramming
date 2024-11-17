#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  if (std::count(str.begin(), str.end(), '1') == 1 && 
  std::count(str.begin(), str.end(), '2') == 2 && 
  std::count(str.begin(), str.end(), '3') == 3
  ) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
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