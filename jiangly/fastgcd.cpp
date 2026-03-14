int gcd(int a, int b) {
  if (!a | !b) return a + b;
  int az = __builtin_ctzll(a);
  int bz = __builtin_ctzll(b);
  int z = std::min(az, bz);
  a >>= az, b >>= bz;
  while (a != b) {
    int diff = b - a;
    az = __builtin_ctzll(diff);
    b = std::min(a, b), a = std::abs(diff) >> az;
  }
  return a << z;
}