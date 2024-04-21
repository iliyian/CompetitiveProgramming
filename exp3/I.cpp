#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("I.in", "r", stdin);
  int n;
  while (cin >> n) {
    stack<int> s;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int cur = 1, i = 1;
    while (i <= n) {
      s.push(i);
      ans.push_back(i << 1 | 1);
      i++;
      while (!s.empty() && s.top() == a[cur]) {
        ans.push_back(s.top() << 1);
        s.pop();
        cur++;
      }
    }
    if (!s.empty()) {
      cout << "NO\n";
      continue;
    } else cout << "YES\n";
    for (auto i : ans)
      cout << (i & 1 ? "push" : "pop") << ' ' << (i >> 1) << '\n';
  }
}