#include <bits/stdc++.h>
using namespace std;

set<string> names;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  string name;
  for (int i = 0; i < n; i++) {
    cin >> name;
    names.insert(name);
  }
  for (int i = 0; i < m; i++) {
    cin >> name;
    names.erase(name);
  }
  for (int i = 0; i < l; i++) {
    cin >> name;
    names.insert(name);
  }
  for (auto n : names) {
    cout << n << '\n';
  }
  return 0;
}