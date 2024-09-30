// date: 2023/12/11
// wa@01: 不能自作聪明得给pair排序
// tag: greedy

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  multiset<int> ls, rs;
  for (int i = 0; i < n; i++) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    if (op == '+') ls.insert(l), rs.insert(r);
    else ls.erase(ls.find(l)), rs.erase(rs.find(r));
    cout << (ls.size() >= 2 && *rs.begin() < *ls.rbegin() ? "YES" : "NO") << '\n';
  }
}