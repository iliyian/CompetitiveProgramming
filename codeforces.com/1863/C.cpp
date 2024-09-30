// date: 2024/01/31 13:32:51
// tag: wa#01: 没考虑循环取不到mex,即mex为最大的数+1的情况
// 模拟即可，模拟着模拟着就找到规律了，然后模拟即可...

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  deque<int> a(n);
  set<int> s;
  for (int i = 0; i < n; i++)
    cin >> a[i], s.insert(a[i]);
  int mex = -1;
  for (int i = 0; i <= *s.rbegin(); i++)
    if (s.find(i) == s.end()) {
      mex = i;
      break;
    }
  if (mex == -1) mex = *s.rbegin() + 1;
  a.push_front(mex);
  int t = k % (n + 1), l = -1;
  if (t == 0) l = 1;
  else if (t == 1) l = 0;
  else l = n + 2 - t;
  for (int i = l; i < l + n; i++)
    cout << a[i % (n + 1)] << " \n"[i == l + n - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}