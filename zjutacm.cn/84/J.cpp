#include <bits/stdc++.h>
#define int long long

std::vector<int> cur;

int len = 3;
int x = 60;
/*
4
2 5 6 8
3 4 4 10
*/
/*
3
2 7 12
3 4 14
*/
/*
3
1 7 18 
2 3 21
*/

void dfs(int u) {
  if (u == len * 2 + 1) {
    int s1 = 0, x1 = 1, xor1 = 0, s2 = 0, x2 = 1, xor2 = 0;
    std::set<int> st1, st2;
    for (int i = 0; i < len; i++) {
      s1 += cur[i];
      x1 *= cur[i];
      xor1 ^= cur[i];
      st1.insert(cur[i]);
    }
    for (int i = len; i < len * 2; i++) {
      s2 += cur[i];
      x2 *= cur[i];
      xor2 ^= cur[i];
      st2.insert(cur[i]);
    }
    if (s1 == s2 && x1 == x2 && xor1 == xor2 && st1 != st2) {
      for (int i = 0 ; i < len * 2; i++) {
        std::cout << cur[i] << ' ';
        if (i == len - 1) {
          std::cout << '\n';
        }
      }
      exit(0);
    }
    return;
  }
  for (int i = (u == len + 1 ? 1 : cur.empty() ? 1 : cur.back()); i <= x; i++) {
    cur.push_back(i);
    dfs(u + 1);
    cur.pop_back();
  }
}

void solve() {
  // std::cout << 4 << '\n';
  // std::cout << "2 5 6 8\n3 4 4 10\n";
  // std::cout << "3\n2 7 12\n3 4 14\n";
  std::cout << "3\n1 7 18\n2 3 21\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  dfs(1);
  return 0;

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}