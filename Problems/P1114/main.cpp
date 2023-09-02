#include <bits/stdc++.h>
using namespace std;

map<int, int> l, r;

int main() {
  freopen("data.in", "r", stdin);
  int n, sum1 = 0, sum0 = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum1 += x == 1;
    sum0 += x == 0;
    int t = sum1 - sum0;
    if (l[t] == 0 && t) l[t] = i;
    r[t] = i;
  }
  int ans = -1;
  for (auto i : l)
    ans = max(r[i.first] - i.second, ans);
  cout << ans;
  return 0; 
}