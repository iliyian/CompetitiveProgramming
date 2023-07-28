// lower_bound永远应该特殊处理两个边界
// 学会了新stl，multiset
// 也可以用INT_MIN之类的，然后if判断*it是否等于其

#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i >= 1) {
      auto it = s.lower_bound(a);
      if (it == s.end()) ans += abs(*s.rbegin() - a);
      else if (it == s.begin()) ans += abs(*s.begin() - a);
      else {
        int b = *it;
        int c = *(--it);
        ans += min(abs(b - a), abs(c - a));
      }
    } else ans += a;
    s.insert(a);
  }
  cout << ans;
  return 0;
}