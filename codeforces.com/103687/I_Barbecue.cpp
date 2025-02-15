#include <bits/stdc++.h>
#define int long long

//字符串哈希判断子串是否回文
typedef unsigned long long ull;//自然溢出
namespace str_hash 
{   //从1开始计数
    const int maxn = 2e6 + 7;
    ull base = 100071;//经验值
    ull p[maxn];
    char s[maxn];
    std::unordered_map<ull, ull>rv;
    std::unordered_map<ull, ull>hs;
    int n;
    void init(std::string &str) 
    {
        n = str.length();
        for (int i = 1; i <= n; i++)s[i] = str[i - 1];
        p[0] = 1;
        for (int i = 1; i <= n; i++){  hs[i] = hs[i - 1] * base + s[i];  p[i] = p[i - 1] * base;  }
        for (int i = n; i; --i)  rv[i] = (rv[i + 1] * base + s[i]);
    }
    ull que(ull l, ull r) {  return hs[r] - hs[l - 1] * p[r - l + 1];  }
    ull rev(ull l, ull r) {  return rv[l] - rv[r + 1] * p[r - l + 1];  }
    // rev(L,R) = que(L,R) 说明是回文
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  auto lose = [&]() {
    std::cout << "Budada\n";
  };
  auto win = [&]() {
    std::cout << "Putata\n";
  };
  str_hash::init(str);


  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (str_hash::rev(l, r) == str_hash::que(l, r)) {
      // std::cerr << l << ' ' << r << '\n';
      lose();
      continue;
    }
    if ((r - l + 1) % 2 == 0) {
      lose();
      continue;
    }
    win();
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}