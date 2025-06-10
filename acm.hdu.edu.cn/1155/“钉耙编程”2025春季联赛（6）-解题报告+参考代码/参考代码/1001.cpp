#include<bits/stdc++.h>

using i64 = long long;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        i64 k, a, b, c;
        std::cin >> k >> a >> b >> c;
        i64 ans = k;
        if (a <= k) ans = std::min(ans, k - a);
        if (b <= k) ans = std::min(ans, k - b);
        if (c <= k) ans = std::min(ans, k - c);
        if (a + b <= k) ans = std::min(ans, k - a - b);
        if (a + c <= k) ans = std::min(ans, k - a - c);
        if (b + c <= k) ans = std::min(ans, k - b - c);
        if (a + b + c <= k) ans = std::min(ans, k - a - b - c);
        std::cout << ans << "\n";
    }
}