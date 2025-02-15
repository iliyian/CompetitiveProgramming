#include<bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
struct Hash {
    using u64 = unsigned long long;
    u64 base = 13331;
    vector<u64> pow, hash;
    Hash(string &s) {
        s = " " + s;
        int N = s.size();
        pow.resize(N + 1), hash.resize(N + 1);
        pow[0] = 1, hash[0] = 0;
        for (int i = 1; i < s.size(); i ++) {
            pow[i] = pow[i - 1] * base;
            hash[i] = hash[i - 1] * base + s[i];
        }
    }
 
    u64 get(int l, int r) {
        return hash[r] - hash[l - 1] * pow[r - l + 1];
    }
 
    //拼接两个子串
    u64 link(int l1, int r1, int l2, int r2) {
        return get(l1, r1) * pow[r2 - l2 + 1] + get(l2, r2);
    }
 
    bool same(int l1, int r1, int l2, int r2) {
        return get(l1, r1) == get(l2, r2);
    }
 
};
 
void solve() {
 
    string a, b;
    cin >> a >> b;
 
    int k = a.size();
 
    a = a + a;
 
    Hash HashA(a), HashB(b);
 
    set<i64> s;
    for (int i = 0; i + k - 1 < a.size(); i ++) {
        s.insert(HashA.get(i, i + k - 1));
    }
 
    i64 ans = 0;
    for (int i = 0; i + k - 1 < b.size(); i ++) {
        if (s.count(HashB.get(i, i + k - 1)))
            ans ++;
    }
 
    cout << ans << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}