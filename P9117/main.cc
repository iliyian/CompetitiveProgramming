#include <bits/stdc++.h>
using namespace std;

pair<int, int> row[100010], col[100010];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) row[i] = {0, 0};
    for (int i = 0; i < m; i++) col[i] = {0, 0};
    for (int i = 0; i < q; i++) {
      int opt, x, c;
      scanf("%d %d %d", &opt, &x, &c);
      if (opt) {
        col[x-1] = {c, i+1};
      } else {
        row[x-1] = {c, i+1};
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (row[i].second > col[j].second)
          printf("%d ", row[i].first);
        else
          printf("%d ", col[j].first);
      }
      printf("\n");
    }
  }
  return 0;
}