#include <bits/stdc++.h>
using namespace std;

struct Node {
  int l, r;
  bool operator < (const Node &b) const {
    if (l == b.l) return r < b.r;
    return l < b.l;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  multiset<Node> s;
  while (t--) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    if (op == '+') s.insert({l, r});
    else s.erase(s.find({l, r}));
    if (s.size() < 2) {
      cout << "NO\n";
      continue;
    }
    int minr = s.begin()->r, maxl = s.rbegin()->l;
    if (minr >= maxl) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}