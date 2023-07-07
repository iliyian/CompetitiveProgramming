#include <cstdio>
#include <cstring>

const int S = 300;
int c[S], d[S];
int n, l, step = 0;
char s[S];

inline void add() {
  for (int i = 0; i < l; i++)
    d[l-1-i] = c[i];
  l += 2;
  for (int i = 0; i < l; i++) {
    c[i] += d[i];
    if (c[i] >= n) c[i+1]++, c[i]-=n;
  }
  while (!c[l-1]) l--;
}

inline bool pd() {
  for (int i = 0; i < l; i++)
    if (c[i] != c[l-1-i]) return false;
  return true;
}

int main() {
  scanf("%d %s", &n, s);
  l = strlen(s);
  for (int i = 0; i < l; i++) {
    if (s[i] >= '0' && s[i] <= '9') c[i] = s[i] - '0';
    else c[i] = s[i] - 'A' + 10;
  }
  while(!pd()) {
    step++;
    if (step > 30) break;
    add();
  }
  if (step <= 30) printf("STEP=%d\n", step);
  else printf("Impossible!");
  return 0;
}