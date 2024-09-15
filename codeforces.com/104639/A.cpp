#include <bits/stdc++.h>
using namespace std;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("A.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a, b;
  std::set<std::string> vis;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    if (vis.count(str)) {
      continue;
    }
    a.push_back(str);
    vis.insert(str);
  }
  vis.clear();
  for (int i = 1; i <= m; i++) {
    std::string str;
    std::cin >> str;
    if (vis.count(str)) {
      continue;
    }
    b.push_back(str);
    vis.insert(str);
  }
  std::vector<std::string> c;
  int i = 0, j = 0;
  vis.clear();
  while (i < a.size() && j < b.size()) {
    if (a[i] != b[j]) {
      if (!vis.count(a[i])) {
        c.push_back(a[i]);
        vis.insert(a[i]);
      }
      if (!vis.count(b[j])) {
        c.push_back(b[j]);
        vis.insert(b[j]);
      }
      i++, j++;
    } else {
      if (!vis.count(a[i])) {
        c.push_back(a[i]);
        vis.insert(a[i]);
      }
      i++, j++;
    }
  }
  while (i < a.size()) {
    if (!vis.count(a[i])) {
      c.push_back(a[i]);
      vis.insert(a[i]);
    }
    i++;
  }
  while (j < b.size()) {
    if (!vis.count(b[j])) {
      c.push_back(b[j]);
      vis.insert(b[j]);
    }
    j++;
  }
  for (auto &s : c) {
    std::cout << s << '\n';
  }
  return 0;
}