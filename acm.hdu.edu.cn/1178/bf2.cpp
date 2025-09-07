#include<bits/stdc++.h>
#define ll long long
#define N 10015
using namespace std;
struct node{
    ll x,y,z;
}a[N];
ll n,k,maxx,maxy;
vector<node> p[N];
ll calc(vector<ll> &s,vector<ll> &sum,ll w)
{
    sum[0]=0;
    for (int i=1;i<=maxx;i++)sum[i]=sum[i-1]+s[i];
    deque<int> q;q.clear();
    ll res=0;
    for (int i=0;i<=maxx;i++)
    {
        while(!q.empty()&&i-q.front()>w)q.pop_front();
        if (!q.empty())res=max(res,sum[i]-sum[q.front()]);
        while(!q.empty()&&sum[i]<=sum[q.back()])q.pop_back();
        q.push_back(i);
    }
    return res;
}
void solve()
{
    maxx=1,maxy=1;
    cin>>n>>k;
    for (int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z,p[i].clear(),maxx=max(maxx,a[i].x),maxy=max(maxy,a[i].y);
    for (int i=1;i<=n;i++)p[a[i].y].push_back(a[i]);
    ll ans=0;
    for (ll h=1;h<=min(k,maxy);h++)
    {
        ll w=k/h;
        
        if (w==0)break;
        if ((h+1)*w<=k)continue;
//        cout<<h<<endl;
        vector<ll> s(maxx+2,0);
        vector<ll> sum(maxx+2,0);
        for (int y=1;y<=h;y++)for (auto x:p[y])s[x.x]+=x.z;
        ans=max(ans,calc(s,sum,w));
        for (int c=1;c<=maxy-h;c++)
        {
            for (auto x:p[c])s[x.x]-=x.z;
            for (auto x:p[c+h])s[x.x]+=x.z;
            ans=max(ans,calc(s,sum,w));
        }
    }
    cout<<ans<<endl;
}
int main()
{
//    freopen("1.in","r",stdin);
    ios::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}