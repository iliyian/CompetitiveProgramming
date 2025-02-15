#include <bits/stdc++.h>
using namespace std;
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <typename T>
void chkmn(T &x, T y) { x = min(x, y); }
typedef long long ll;
int lst;
int main()
{
    int t;
    read(t);
    while (t--) {
int n;
int a[1000020];
int b[1000020];
int c[1000020];
int d[1000020];
map<int, int> mp;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> p;
priority_queue<int> q;
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= n; i++)
        v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    reverse(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        c[a[i]]++;
    for (int i = 1; i <= n; i++)
        c[i] += c[i - 1];
    for (int i = 1; i <= n; i++)
        a[i] = c[a[i] - 1] + (++d[a[i]]);
    int l = 1, r = n;
    while (a[l] == l)
        l++;
    while (a[r] == r)
        r--;
    ll ans = 1LL * n * n;
    std::cerr << l << ' ' << r << '\n';
    int pos = 0;
    lst = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == lst + 1 && p.empty())
            lst++;
        else
            p.push(a[pos = i]);
        while (!p.empty() && p.top() == lst + 1)
        {
            p.pop();
            lst++;
        }
        chkmn(ans, 1LL * pos * pos + (i == r ? 0 : 1LL * (n - lst) * (n - lst)));
    }
    pos = n + 1;
    lst = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == lst - 1 && q.empty())
            lst--;
        else
            q.push(a[pos = i]);
        while (!q.empty() && q.top() == lst - 1)
        {
            q.pop();
            lst--;
        }
        chkmn(ans, 1LL * (n - pos + 1) * (n - pos + 1) + (i == l ? 0 : 1LL * (lst - 1) * (lst - 1)));
    }
    cout << ans << '\n';
    return 0;
}}