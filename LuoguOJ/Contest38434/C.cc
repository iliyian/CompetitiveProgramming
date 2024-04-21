#include <bits/stdc++.h>
using namespace std;

array<int, 200000> a{};
array<int, 100000> temp{};
array<int, 100000> ans{};

const int N = 998244353;

int getMinn(int l, int r) {
  temp.fill(0);
  for (int i = l; i <= r; i++) {
    temp[a[i]]++;
  }
  int maxv = -1;
  for (int i = l; i <= r; i++) {
    int idx = a[i];
    if (temp[idx] > maxv) {
      maxv = temp[idx];
    }
  }
  for (int i = l; i <= r; i++) {
    if (maxv == temp[a[i]]) return a[i];
  }
}

int main() {
  int n, idx = 0;
  cin >> n;
  for (int i = 0; i < n;) {
    int num;
    cin >> num;
    a[idx] = num;
    for (int j = 0; j < num; j++) {
      a[++idx] = j;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n * 2; i++) {
    for (int j = i; j < n * 2; j++) {
      int v = getMinn(i, j);
      cout << "l=" << i << ",r=" << j << ",v=" << v << endl;
      ans += v;
    }
  }
  cout << ans;
  return 0;
}