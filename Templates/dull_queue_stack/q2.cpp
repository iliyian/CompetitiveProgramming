// 原来单调队列就是字面意思

#include <bits/stdc++.h>
using namespace std;

int a[1000000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  deque<int> q1, q2, ans1, ans2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (!q1.empty() && q1.front() <= i - k) q1.pop_front();
    while (!q1.empty() && a[q1.back()] >= a[i]) q1.pop_back();
    q1.push_back(i);

    while (!q2.empty() && q2.front() <= i - k) q2.pop_front();
    while (!q2.empty() && a[q2.back()] <= a[i]) q2.pop_back();
    q2.push_back(i);
 
    if (i >= k - 1)
      ans1.push_back(q1.front()), ans2.push_back(q2.front());
  }
  for (auto i : ans1) cout << a[i] << ' ';
  cout << '\n';
  for (auto i : ans2) cout << a[i] << ' ';
  return 0;
}