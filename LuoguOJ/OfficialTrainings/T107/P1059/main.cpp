#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  cout << s.size() << '\n';
  for (auto i : s) {
    cout << i << ' ';
  }
  return 0;
}