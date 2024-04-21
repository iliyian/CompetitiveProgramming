#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int x;
  vector<int> v;
  while (cin >> x) v.push_back(x);
  sort(v.begin(), v.end());
  if (v.size() < 3) {
    cout << v.back();
    return 0;
  }
  // int prev = 0, cnt = 0, cur = 0, max3 = -1;
  vector<int> temp = v;
  int len = unique(temp.begin(), temp.end()) - temp.begin();
  int max3 = temp[len - 3];
  if (len < 3 || count(v.begin(), v.end(), max3) > 1) cout << v.back();
  else cout << max3;
  return 0;
}