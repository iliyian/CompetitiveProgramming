#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    if(a.first < b.first) return 1;
    else if(a.second > b.second) return 1;
    return 0;
}


int n, m;
long long a[200010], b[200010], suf[200010], x, y, pos;
pair<long long, long long> c[200010];

int work()
{
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%lld %lld", &x, &y);
        b[x] += y;
    }
    suf[n + 1] = 0;
    for(int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + b[i];
        b[i] = a[i] - suf[i];
        c[n - i + 1] = make_pair(b[i], i);
    }
    sort(c + 1, c + 1 + n, cmp);
    pos = n + 1;
    for(int i = 1; i <= n; i++)
    if(pos > c[i].second)
    {
        a[c[i].second] = c[i].first + suf[pos];
        pos = c[i].second;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int main()
{
  freopen("D.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
        work();
}
