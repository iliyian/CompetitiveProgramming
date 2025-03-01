#include <bits/stdc++.h>
using namespace std;

string str;
int len;
long long n;

void solve(long long pos) {
  if (pos <= len) cout << str[pos - 1];
  else {
    for (int i = 1;; i++) {
      if (len * (1ll << i) >= pos) {
        long long half = (1ll << (i - 1)) * len;
        if (pos == half + 1) {
          solve(half);
        } else {
          solve(pos - 1 - half);
        }
        break;
      }
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> str >> n;
  len = str.size();
  // for (int i = 1; i <= n; i++)
  solve(n);
  return 0;
}