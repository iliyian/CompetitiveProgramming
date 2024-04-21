#include <bits/stdc++.h>

int res[5][5] = {
  {0, 0, 1, 1, 0},
  {1, 0, 0, 1, 0},
  {0, 1, 0, 0, 1},
  {0, 0, 1, 0, 1},
  {1, 1, 0, 0, 0}
};

int main() {
  // freopen("data.out", "w", stdout);

  int N, na, nb;
  int a[200], b[200];
  
  scanf("%d %d %d", &N, &na, &nb);
  
  for (int i = 0; i < na; i++)
    scanf("%d", a+i);
  for (int i = 0; i < nb; i++)
    scanf("%d", b+i);

  int aans = 0, bans = 0;
  for (int i = 0; i < N; i++) {
    int an = a[i%na], bn = b[i%nb];
    aans += res[an][bn];
    bans += res[bn][an];
  }

  printf("%d %d", aans, bans);
  return 0;
}

/*
10 5 6
0 1 2 3 4
0 3 4 2 1 0
*/