#include <cstdio>
// C 10, 20 是 longlong 
int a[21], k, n;
long long c = 0;

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void dfs(int m, int sum, int idx) {
  if (m == k) {
    c += isPrime(sum);
    return;
  }
  for (int i = idx; i < n; i++) {
    dfs(m + 1, sum + a[i], i + 1);
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  dfs(0, 0, 0);
  printf("%d", c);
  return 0; 
}