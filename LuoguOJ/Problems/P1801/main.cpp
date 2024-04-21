// complex

#include <bits/stdc++.h>
using namespace std;

priority_queue<int> qmax;
priority_queue<int, vector<int>, greater<int>> qmin;
int a[200001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  int prev = 1;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    for (int j = prev; j <= u; j++) {
      qmax.push(a[j]);
      qmin.push(qmax.top());
      qmax.pop();
    }
    prev = u + 1;
    cout << qmin.top() << '\n';
    qmax.push(qmin.top());
    qmin.pop();
  }
  return 0;
}