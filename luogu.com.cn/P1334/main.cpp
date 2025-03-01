#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }
  long long ans = 0;
  while (q.size() >= 2) {
    int a = q.top(); q.pop();
    int b = q.top(); q.pop();
    ans += a + b;
    q.push(a + b);
  }
  cout << ans;
  return 0;
}