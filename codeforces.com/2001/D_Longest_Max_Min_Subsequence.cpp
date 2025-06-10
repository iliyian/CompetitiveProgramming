// date: 2025-03-21 14:41:23
// tag: 一种神奇的变种单调栈，奇数位尽可能大，偶数位尽可能小，只要模仿普通单调栈即可，加上可能同时pop两个的操作即可

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), lst(n + 1), ins(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    lst[a[i]] = i;
  }
  std::vector<int> v;
  auto check2 = [&](int i) {
    return lst[a[v[v.size() - 1]]] > i && lst[a[v[v.size() - 2]]] > i;
  };
  auto check1 = [&](int i) {
    return lst[a[v[v.size() - 1]]] > i;
  };
  for (int i = 1; i <= n; i++) {
    if (!ins[a[i]]) {
      while (v.size() >= 1 && check1(i) && (v.size() % 2 ? a[v.back()] < a[i] : a[v.back()] > a[i])) {
        ins[a[v.back()]] = false;
        v.pop_back();
      }
      while (v.size() >= 2 && check2(i) && (v.size() % 2 ? a[v[v.size() - 2]] > a[i] : a[v[v.size() - 2]] < a[i])) {
        ins[a[v.back()]] = false;
        v.pop_back();
        ins[a[v.back()]] = false;
        v.pop_back();
      }
      ins[a[i]] = 1;
      v.push_back(i);
      // std::cerr << i << ": ";
      // for (auto i : v) {
      //   std::cerr << a[i] << ' ';
      // }
      // std::cerr << '\n';
    }
  }
  std::cout << v.size() << '\n';
  for (int i : v) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}