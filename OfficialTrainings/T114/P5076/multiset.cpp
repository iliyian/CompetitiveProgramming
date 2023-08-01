// find不能查不存在的

#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main() {
  freopen("data.in", "r", stdin);
  int q;
  cin >> q;
  s.insert(-0x7fffffff);
  s.insert(0x7fffffff);
  for (int i = 0; i < q; i++) {
    int op, x;
    cin >> op >> x;
    switch (op) {
      case 1: {
        auto it = s.lower_bound(x), temp = s.begin();
        int cnt = 0;
        while (temp != it) cnt++, temp++;
        cout << cnt << '\n';
        break;
      } case 2: {
        auto it = s.begin();
        advance(it, x);
        cout << *it << '\n';
        break;
      } case 3: {
        auto it = s.lower_bound(x);
        cout << *--it << '\n';
        break;
      } case 4: {
        auto it = s.upper_bound(x);
        cout << *it << '\n';
        break;
      } case 5: {
        s.insert(x);
        break;
      }
    }
  }
  return 0;
}