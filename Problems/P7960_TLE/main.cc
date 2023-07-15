#include <bits/stdc++.h>
const int N = int(1e7) + 10;

bool vis[N+1];

bool check(int n) {
  while (n) {
    if (n % 10 == 7) return true;
    n /= 10;
  }
  return false;
}

int read() {
  int n = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    n = n * 10 + ch - '0';
    ch = getchar();
  } 
  return n;
}

void write(int n) {
  if (n > 9) write(n / 10);
  putchar(n % 10 + '0');
}

int main() {
  freopen("P7960_8.in", "r", stdin);
  freopen("data.out", "w", stdout);
  
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= N; i++) {
    if (vis[i]) continue;
    if (check(i))
      for (int j = 1; i * j <= N; j++) vis[i * j] = 1;
  }

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int a = read();
    if (vis[a]) putchar('-'), putchar('1'), putchar('\n');
    else for (int j = a+1; j <= N; j++)
      if (!vis[j]) {
        write(j);
        putchar('\n');
        break;
      }
  }

  return 0;
}