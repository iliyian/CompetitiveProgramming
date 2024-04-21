#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int op, len;
    cin >> op >> len;
    if (op == 1) {
      if (s.count(len)) {
        cout << "Already Exist\n";
      } else s.insert(len);
    } else {
      if (s.count(len)) {
        cout << len << '\n';
        s.erase(len);
      } else {
        if (s.empty()) {
          cout << "Empty\n";
        } else {
          // 大于等于和大于，差别不大，通过减法改变不等号方向
          auto l = s.lower_bound(len), r = s.upper_bound(len);
          if (r == s.end()) --r;
          if (l != s.begin()) --l;
          if (len - *l <= *r - len) cout << *l << '\n', s.erase(l);
          else cout << *r << '\n', s.erase(r);
        }
      }
    }
  }
  return 0;
}