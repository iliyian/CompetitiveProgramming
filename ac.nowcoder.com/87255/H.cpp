#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int n;
  std::cin >> n;
  
  std::map<std::string, std::vector<std::string>> m;

  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    int c;
    std::cin >> c;
    for (int j = 0; j < c; j++) {
      std::string x;
      std::cin >> x;
      m[str].push_back(x);
    }
  }

  std::cout << m.size() << '\n';
  for (auto [k, v] : m) {
    std::cout << k << ' ';

    std::vector<std::string> a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
      bool f = true;
      for (int j = 0; j < v.size(); j++) {
        if (j == i || v[j].size() < v[i].size()) continue;
        if (v[j].substr(v[j].size() - v[i].size(), v[i].size()) == v[i]) {
          f = false;
          break;
        }
        // auto pos = v[j].find(v[i], v[j].size() - v[i].size() - 1);
        // if (pos == v[j].size() - v[i].size()) {
        //   f = false;
        //   break;
        // }
      }
      if (f) {
        a.push_back(v[i]);
      }
    }

    // std::sort(a.begin(), a.end(), [&](const std::string &x, const std::string &y) {
    //   for (int i = 0; i < std::min(x.size(), y.size()); i++) {
    //     if (x[i] != y[i]) {
    //       return x[i] < y[i];
    //     }
    //   }
    //   return x.size() < y.size();
    // });
    std::sort(a.begin(), a.end());
    std::cout << a.size() << ' ';
    for (auto i : a) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}