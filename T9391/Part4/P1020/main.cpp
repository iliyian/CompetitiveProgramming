// 真tmd奇妙

#include <bits/stdc++.h>
using namespace std;

int a[100001], len = 0, l1[100001], l2[100001];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  while (cin >> a[len++]);
  int len1 = 0, len2 = 0;
  for (int i = 0; i < len; i++) {
    if (l1[len1] >= a[i]) l1[++len1] = a[i];
    else *upper_bound(l1, l1 + len1, a[i], greater<int>()) = a[i];
    if (l2[len2] < a[i]) l2[++len2] = a[i];
    else *lower_bound(l2, l2 + len2, a[i]) = a[i];
  }
  cout << len1 << '\n' << len2;
  return 0;
}