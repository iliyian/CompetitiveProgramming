#include <bits/stdc++.h>
using namespace std;
struct S {
  int n, res = 1;
  map<int, vector<int>> mp;
  vector<int> stk, pos, lc;
  int h = 0, c = 0;
  void solve() {
    cin >> n;
    stk.resize(n + 2, -1);
    stk[0] = 0;
    lc = pos = stk;
    for (int i = 1, l, r; i <= n; i++)
      cin >> l >> r, mp[l].push_back(i), mp[r + 1].push_back(-i);
    for (auto &k : mp) {
      for (auto &x : k.second) {
        if (x > 0)
          stk[++h] = x, pos[x] = h, c++;
        else {
          int &p = pos[-x];
          stk[p] = -1;
          p = -1;
          c--;
        }
      }
      while (stk[h] == -1)
        h--;
      int x = stk[h];
      res += (lc[x] != c);
      lc[x] = c;
      // ���㱾����ͬ���ҽ���h,c����ͬ
    }
    cout << res << '\n';
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  S SS;
  SS.solve();
}