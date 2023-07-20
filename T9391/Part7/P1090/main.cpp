// 审题依然关键

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    pq.push(a);
  }
  long long ans = 0;
  while (pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a + b);
  }
  cout << ans;
  return 0;
}