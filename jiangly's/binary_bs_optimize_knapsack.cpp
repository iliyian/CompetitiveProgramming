std::bitset<N + 1> dp;
dp[0] = 1;
std::vector<int> c(n + 1);
for (int i = 1; i <= mn; i++) {
  c[a[i]]++;
}
for (int i = 1; i <= n; i++) {
  if (c[i]) {
    int x = c[i];
    for (int k = 1; k <= x; k *= 2) {
      dp |= dp << (k * i);
      x -= k;
    }
    dp |= dp << (x * i);
  }
}