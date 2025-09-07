#include <bits/stdc++.h>
#define ll long long
#define N 1500
using namespace std;
int n, a[N][N], f[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> f[i];
  for (int x = 1; x <= n; x++) {
    vector<int> ban, need, s;
    vector<pair<int, bool>> allow;
    for (int i = 1; i <= n; i++)
      if (f[i] == x)
        ban.push_back(i);
      else if (f[i] > x)
        need.push_back(i);
      else if (f[i] < x)
        allow.push_back({i, 0});
    //        cout<<x<<' '<<need.size()<<' '<<allow.size()<<endl;
    if (need.size() == 0)
      continue;
    for (int i = 0; i < need.size(); i++) {
      if (i + 1 == need.size()) {
        s.push_back(need[i]);
        break;
      }
      int X = need[i], Y = need[i + 1];
      if (a[X][Y] == 0) {
        a[X][Y] = x;
        a[Y][X] = x;
        i++;
      } else
        s.push_back(X);
    }
    //        cout<<x<<'!'<<endl;
    for (int i = 0; i < s.size(); i++) {
      bool flag = 1;
      for (int j = 0; j < allow.size(); j++)
        if (allow[j].second == 0 && flag) {
          int X = s[i], Y = allow[j].first;
          if (a[X][Y] == 0)
            a[X][Y] = a[Y][X] = x, allow[j].second = 1, flag = 0;
        }
      if (flag) {
        for (int j = 0; j < need.size(); j++)
          if (a[s[i]][need[j]] == 0) {
            a[s[i]][need[j]] = x;
            a[need[j]][s[i]] = x;
            flag = 0;
            break;
          }
        if (flag && &a[s[i]][s[i]] == 0)
          a[s[i]][s[i]] = x;
      }
    }
    //        for (int i=1;i<=n;i++)
    //        {
    //            for (int j=1;j<=n;j++)
    //            {
    //                printf("%d ",a[i][j]);
    //            }
    //            printf("\n");
    //        }
    //        printf("\n");
    //        cout<<x<<"!!"<<endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", a[i][j]);
      a[i][j] = 0;
    }
    printf("\n");
  }
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}