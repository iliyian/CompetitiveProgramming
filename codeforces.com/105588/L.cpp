#include <bits/stdc++.h>
#define ll long long
#define N 600011
using namespace std;
ll n, m, a[N], b[N], last, base, tot, j;
void work() {
  for (int k = last + 1; k <= n; k++) {
    if (a[k] <= base + 1)
      last++, base++;
    else
      break;
  }

  return;
}
void solve() {
  tot = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1)
      tot++;
  }
  j = tot + 1, base = tot, last = tot;
  work();
  for (int i = 1; i <= m; i++) {
    if (b[i] <= base) {
      base++;
      work();
      continue;
    }
    while (1) {
      if (j > n) {
        if (tot == 0) {
          cout << "No\n";
        } else {
          b[i]--;
          while (b[i] <= base && i <= n)
            base++, i++, work();
          if (i > n)
            cout << "Yes\n";
          else
            cout << "No\n";
        }
        return;
      }
      b[i]--, j++;
      work();
      if (b[i] <= base) {
        base++;
        work();
        break;
      }
    }
  }
  cout << "Yes\n";
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
