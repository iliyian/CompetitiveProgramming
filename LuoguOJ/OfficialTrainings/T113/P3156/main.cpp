#include <bits/stdc++.h>
using namespace std;

int stus[200001];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> stus[i];
  }
  for (int i = 0 ; i < m; i++) {
    int a;
    cin >> a;
    cout << stus[a] << '\n';
  }
  return 0;
}