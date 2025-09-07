#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define M 1000000
#define	lc p<<1
#define rc p<<1|1
using namespace std;
int n,a[N];

struct tree{
	int maxn,add,id;
	int l,r;
}t[N<<2];
void update(int p)
{
	t[p].maxn=max(t[lc].maxn,t[rc].maxn); 
	if (t[lc].maxn>=t[rc].maxn)t[p].id=t[lc].id;
	else t[p].id=t[rc].id;
}
void build(int p,int l,int r)
{
	t[p].maxn=t[p].add=0;
	t[p].l=l,t[p].r=r;
	t[p].id=l;
	if (l==r)
	{
		t[p].maxn=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void spread(int p)
{
	t[lc].maxn+=t[p].add;
	t[rc].maxn+=t[p].add;
	t[lc].add+=t[p].add;
	t[rc].add+=t[p].add;
	t[p].add=0;
}
void change(int p,int l,int r,int s)
{
	if (l<=t[p].l&&r>=t[p].r)
	{
		t[p].maxn+=s;
		t[p].add+=s;
		return ;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	if (l<=mid)change(lc,l,r,s);
	if (r>mid) change(rc,l,r,s);
	update(p);
}
pair<int,int> query(int p,int l,int r)
{
	if (l<=t[p].l&&r>=t[p].r)return {t[p].maxn,t[p].id};
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	pair<int,int>val={0,0};
	if (l<=mid)
	{
		pair<int,int>x=query(lc,l,r);
		if (x.first>val.first)val=x;
	}
	if (r>mid){
		pair<int,int>x=query(rc,l,r);
		if (x.first>val.first)val=x;
	}
	return val;
}

vector<int> b[M+5];
vector<pair<int,int>> add[N],del[N];
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	for (int i=1;i<=M;i++)
	{
		if (b[i].size()>=3)
		{
			int t=b[i][b[i].size()-1];
			add[b[i][0]].push_back({b[i][1]+1,t});
			for (int j=1;j<=b[i].size()-2;j++)
			{
				del[b[i][j]].push_back({b[i][j]+1,b[i][j+1]});
			}
		}
		b[i].clear();
	}
	build(1,1,n + 1);
	int	ans,l,r;
	ans=l=r=0;
	for (int i=1;i<=n + 1;i++)
	{
		for (auto [x,y]:add[i])
		{
//			cout<<x<<' '<<y<<' '<<1<<'\n';z
			change(1,x,y,1);
		}
		for (auto [x,y]:del[i])
		{
//			cout<<x<<' '<<y<<' '<<-1<<'\n';
			change(1,x,y,-1);
		}
		pair<int,int> c=query(1,1,n);
		if (c.first>ans)
		{
			ans=c.first;
			l=i+1,r=c.second;
		}
		add[i].clear(),del[i].clear();
	}
	if (ans == 0) {
		std::cout << 0 << '\n';
		std::cout << 2 << ' ' << 3 << '\n';
		return;
	}
	cout<<ans<<'\n';
	cout<<l<<' '<<r<<'\n';
}
int main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
