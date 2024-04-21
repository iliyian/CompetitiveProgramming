// date: 2023/12/4
// tag: kinds of find laws

#include <bits/stdc++.h>
using namespace std;

string a[10][10];
char c[10][10];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
  map<char, int> m;
  for (int i = 2; i <= n; i++) {
    int ans = 0;
    for (int j = 2; j <= n; j++)
      ans += a[i][j].size() == 2;
    m[a[i][1].front()] = ans;
  }
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++) {
      int sum = a[i][j].size() == 1 ? m[a[i][j].front()] : m[a[i][j].front()] * (n - 1) + m[a[i][j].back()];
      if (m[a[i][1].front()] + m[a[1][j].front()] != sum) {
        cout << "ERROR!";
        return 0;
      }
    }
  for (int i = 2; i <= n; i++)
    cout << a[1][i] << '=' << m[a[1][i].front()] << " \n"[i == n];
  cout << n - 1;
}