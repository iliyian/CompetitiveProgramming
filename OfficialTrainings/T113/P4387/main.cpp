#include <bits/stdc++.h>
using namespace std;

int pushed[100005], poped[100005];

void solve() {
  stack<int> temp;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> pushed[i];
  for (int i = 0; i < n; i++)
    cin >> poped[i];
  int pushcnt = 0, popcnt = 0;
  while (popcnt < n) {
    if (temp.size() && temp.top() == poped[popcnt]) {
      temp.pop(); popcnt++;
    } else if (pushcnt < n) {
      temp.push(pushed[pushcnt++]);
    } else {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  return;
}

int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}