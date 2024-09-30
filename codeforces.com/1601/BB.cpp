#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 4e5 + 10;
const int Max = MaxN << 5;
const int inf = 0x3f3f3f3f;

struct edge
{
    int next, to, dis;
} e[Max];

int head[Max], a[MaxN], b[MaxN];
int n, m, cnt, dis[Max], vis[Max], pre[Max];

void add_edge(int u, int v, int d)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
};

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

struct SegmentTree
{
    int cnt, idx[Max];
    void build(int id, int l, int r)
    {
        if(l == r) 
            return (void) (idx[id] = l + n + 1);
        idx[id] = ++cnt; int mid = (l + r) >> 1;
        build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
        if(idx[id << 1]) add_edge(idx[id], idx[id << 1], 0);
        if(idx[id << 1 | 1]) add_edge(idx[id], idx[id << 1 | 1], 0);
    }
    void modify(int id, int l, int r, int ql, int qr, int u)
    {
        if(ql > r || l > qr) return;
        if(ql <= l && r <= qr) 
            return add_edge(u, idx[id], 1);
        int mid = (l + r) >> 1;
        modify(id << 1, l, mid, ql, qr, u);
        modify(id << 1 | 1, mid + 1, r, ql, qr, u);
    }
} T;

void bfs()
{
    std::deque<int> q;
    dis[n] = 0, q.push_back(n);
    while(!q.empty())
    {
        int u = q.front(); q.pop_front();
        if(vis[u]) continue; vis[u] = 1;
        for(int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if(dis[v] > dis[u] + e[i].dis)
            {
                dis[v] = dis[u] + e[i].dis;
                if(!vis[v])
                {
                    if(e[i].dis) q.push_back(v);
                    else q.push_front(v); pre[v] = u;
                }
            }
        }
    }
}

signed main()
{   
  freopen("B.in", "r", stdin);
  freopen("BB.out", "w", stdout);
    int now = 0;
    n = read(), T.cnt = 2 * n + 1, memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read();
    for(int i = 0; i <= n; i++)
        add_edge(i + n + 1, i + b[i], 0);
    T.build(1, 0, n);
    for(int i = 1; i <= n; i++)
        T.modify(1, 0, n, i - a[i], i, i);
    bfs(), printf("%d\n", dis[0] == inf ? -1 : dis[0]);
    if(dis[0] != inf)
    {
        std::vector<int> path;
        while(now != n) 
        {
            if(n + 1 <= now && now <= 2 * n + 1) 
                path.push_back(now - n - 1);
            now = pre[now];
        }
        std::reverse(path.begin(), path.end());
        for(auto x : path) printf("%d ", x);
    }
    return 0;
}