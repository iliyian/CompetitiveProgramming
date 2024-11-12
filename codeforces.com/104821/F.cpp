#include <bits/stdc++.h>
// #define int long long

int a[100010], b[100010], cover_last[100010], cover_first[100010], first, second, pos;
std::vector<int> p[100010];

void solve() {
  int n, m, k;
  std::cin >> n >> m;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for(int i = 1; i<= n; i++)
  {
    int x;
    std::cin >> x;
    p[i].resize(x + 2);
    // std::cin >> p[i][0]
    p[i][0] = x;
    for(int j = 1; j <= p[i][0]; j++)
    {
      std::cin >> p[i][j];
      a[p[i][j]] = i;
    }
  }

  for(int i = 1; i<= n; i++)
  {
    cover_last[i] = 0;
    cover_first[i] = n + 1;
  }

  for(int i = 1; i<= n; i++)
  {
    for(int j = 1; j <= p[i][0]; j++)
    {
      if(a[p[i][j]] == i) cover_last[i] = std::max(cover_last[i], b[p[i][j]]);
      else cover_first[i] = std::min(cover_first[i], a[p[i][j]]);
      b[p[i][j]] = i;
    }
  }
  bool flag = 0;
  for(int i = 1; i<= n; i++)
  {
    if(cover_last[i] + 1 != cover_first[i] - 1)
    {
      flag = 1;
      if(cover_last[i] + 1 != i)pos = cover_last[i] + 1;
      else pos = cover_first[i] - 1;
      second = i;
      break;
    }
  }
  if(flag)
  {
    std::cout << "Yes\n";
    for(int i = second; i < pos; i++)
    {
      std::swap(a[i], a[i + 1]);
    }
    for(int i = 1; i <= n; i++)
    {
      if(i < second || i >pos)
        std::cout<<i<<' ';
      else
      if(i < pos) std::cout<<i+1<<' ';
      else std::cout << second<< ' ';
    }
    
    std::cout << '\n';
  }
  else
  {
    std::cout << "No\n";
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}