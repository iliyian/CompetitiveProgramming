#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int n, q;
  string str;
  cin >> n >> str >> q;
  set<char> s;
  for (int i = 0; i < q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      char c;
      cin >> x >> c;
      s.erase(str[x]);
      s.insert(c);
    } else {
      int l, r;
      cin >> l >> r;
      
    }
  }
}