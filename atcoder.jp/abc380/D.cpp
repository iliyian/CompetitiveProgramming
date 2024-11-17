#include <bits/stdc++.h>
#include <cctype>
#define int long long
using namespace std;

std::string str;
int cnt = 0, n;
std::vector<int> len(100);

void solve() {
  std::cin >> str;
  int q;
  std::cin >> q;
  n = str.size(), cnt = 0;
  std::fill(len.begin(), len.end(), LLONG_MAX);
  len[0] = n;
  int cur = 0;
  for (int i = 1;; i++, cur++) {
    len[i] = len[i - 1] * 2;
    if (len[i] > 1e18) break;
  }
  while (q--) {
    int x;
    std::cin >> x;
    int nowlen = 0, num = 0;
    for (int i = cur; i >= 0; i--) {
      if (nowlen + len[i] < x) {
        nowlen += len[i];
        num += 1ll << i;
      }
    }
    int t = (x - nowlen + n - 1) % n;
    // std::cout << num << ' ';
    bool f = false;
    for (int i = 62; i >= 2; i--) {
      if (num >> i & 1) {
        num ^= 1ll << i;
        f ^= 1;
      }
    }
    // std::cout << num << '\n';
    std::cout << char(f ^ (num == 1 || num == 2) ? isupper(str[t]) ? tolower(str[t]) : toupper(str[t]) : str[t]) << ' ';
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