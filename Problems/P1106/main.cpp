#include <bits/stdc++.h>
using namespace std;

int in[300];

string a;

void add(int &n) {
  ++n;
  while (!n) ++n;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int k;
  cin >> a >> k;
  for (int i = 0; i < k; i++) {
    int len = a.size();
    for (int i = 0; i < len; i++) {
      if (a[i] > a[i + 1]) {
        for (int j = i; j < len; j++)
          a[j] = a[j + 1];
        len--;
        break;
      }
    }
  }
  bool f = false;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] && a[i] != '0') f = true;
    if (a[i] && f) cout << a[i];
  }
  if (!f) cout << 0;
  return 0;
}