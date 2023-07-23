#include <bits/stdc++.h>
using namespace std;

int tracks[10010];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tracks[i];
  }
  bool f;
  int ans = 0;
  do {
    f = true;
    for (int i = 0; i < n - 1; i++) {
      if (tracks[i] > tracks[i + 1]) {
        swap(tracks[i], tracks[i + 1]);
        f = false;
        ans++;
      }
    }
  } while (!f);
  cout << ans;
  return 0;
}