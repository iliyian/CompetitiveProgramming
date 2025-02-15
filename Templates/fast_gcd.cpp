int gcd(int a, int b) {
    if (!a || !b) return a + b;
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int z = min(az, bz);
    a >>= az;
    b >>= bz;
    while (a != b) {
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = min(a, b);
        a = abs(diff) >> az;
    }
    return a << z;
}
