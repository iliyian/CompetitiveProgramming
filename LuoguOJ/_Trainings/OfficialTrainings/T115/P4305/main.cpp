#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
  int T;
  cin >> T;
  while (T--) {
    s.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (!s.count(a)) {
        cout << a << ' ';
        s.insert(a);
      }
    }
    cout << '\n';
  }
  return 0;
}