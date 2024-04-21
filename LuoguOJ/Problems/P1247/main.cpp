// 大于小于优先级竟然在异或之上

#include <bits/stdc++.h>
using namespace std;

int a[500000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int k;
  cin >> k;
  int ans = 0;
  for (int i = 0; i < k; i++)
    cin >> a[i], ans ^= a[i];
  if (!ans) {
    cout << "lose";
    return 0;
  }
  for (int i = 0; i < k; i++) {
    if ((ans ^ a[i]) < a[i]) { // 合法性，同时是唯一性，否则对手胜
      cout << (a[i] - (ans ^ a[i])) << ' ' << i + 1 << '\n';
      a[i] ^= ans;
      for (int l = 0; l < k; l++)
        cout << a[l] << ' ';
      return 0;
    }
  }
  return 0;
}