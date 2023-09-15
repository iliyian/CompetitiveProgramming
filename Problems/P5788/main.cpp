// 存下标的单调栈太妙了
// 为什么下标从 1 开始？

#include <bits/stdc++.h>
using namespace std;

int f[3000000], a[3000000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  stack<int> s, ans;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && a[s.top()] <= a[i]) s.pop();
    ans.push(s.empty() ? 0 : s.top() + 1);
    s.push(i);
  }
  while (!ans.empty())
    cout << ans.top() << ' ', ans.pop();
  return 0;
}