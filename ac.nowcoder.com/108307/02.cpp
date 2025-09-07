#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define P 1000000007
using namespace std;
int n;
std::vector<int> a(N);
struct E{
	int x,y,z;
};
std::vector<E> edge(N);
struct node{
	ll x,y,z,X,Z,x_p;
};
std::vector<node> val(N);
ll power(ll a,ll b)
{
	ll s=1;
	for (;b;b>>=1)
	{
		if (b&1)s=s*a%P;
		a=a*a%P;
	}
	return s;
}
void dfs(int u)
{
	if (val[edge[u].x].x==0)dfs(edge[u].x);
	if (val[edge[u].y].x==0)dfs(edge[u].y);
	node &x=val[edge[u].x],&y=val[edge[u].y];
	node &z=val[u];
	if (x.z==0&&y.z==0)
	{
		if (edge[u].z==1)
		{
			z.x=x.x,z.z=y.x;
			z.X=x.X,z.Z=y.X;
			z.x_p=x.x_p;
		}
		else if (edge[u].z==2) 
		{
			z.x=(x.x+y.x)%P;
			z.X=x.X*y.X;
			z.x_p=(x.x_p+y.x_p)%(P-1);
		}
		else {
			z.x=(x.x*y.x)%P;
			z.X=power(x.X,y.x_p);
			z.x_p=(x.x_p*y.x_p)%(P-1);
		}
	}
	else if (x.z==0)
	{
		if (edge[u].z==1)
		{
			z.x=x.x;
			z.X=x.X;
			z.x_p=x.x_p;
			z.y=y.x*y.y%P,
			z.z=y.z;
			z.Z=y.Z;
		}
		else if(edge[u].z==2)
		{
			z.x=(x.x+y.x)%P;
			z.X=(x.X*y.X)%P;
			z.x_p=(x.x_p+y.x_p)%(P-1);
			z.y=y.y;
			z.z=y.z;
			z.Z=y.Z;
		}
		else {
			z.x=(x.x*y.x)%P;
			z.X=power(x.X,y.x_p);
			z.x_p=(x.x_p*y.x_p)%(P-1);
			z.y=y.y;
			z.z=y.z;
			z.Z=y.Z;
		}
	}
	else if (y.z==0)
	{
		if (edge[u].z==1)
		{
			z.x=x.x;
			z.X=x.X;
			z.x_p=x.x_p;
			z.y=x.y*x.Z%P;
			z.z=y.x;
			z.Z=y.X;
		}
		else if (edge[u].z==2){
			z.x=x.x;
			z.X=x.X;
			z.x_p=x.x_p;
			z.y=x.y;
			z.z=(x.z+y.x)%P;
			z.Z=(x.Z*y.X)%P;
		}
		else{
			z.x=x.x;
			z.X=x.X;
			z.x_p=x.x_p;
			z.y=x.y;
			z.z=(x.z*y.x)%P;
			z.Z=power(x.Z,y.x_p);
		}
	}
	else {
		if (edge[u].z==1||edge[u].z==2){
			z.x=x.x;
			z.X=x.X;
			z.x_p=x.x_p;
			z.y=x.y*x.Z%P*y.X%P*y.y%P;
			z.z=y.z;
			z.Z=y.Z;
		}
		else {
			z.x=x.x;
			z.X=x.X;
			z.x_p=x.x_p;
			z.y=x.y*power(x.Z,y.x_p)%P*y.y%P;
			z.z=y.z;
			z.Z=y.Z;
		}
	}
	a[u]=z.x*z.y%P*z.Z%P;
	return ;
}
void solve()
{
	cin>>n;
	char ch;
	for (int i=1;i<=n;i++)
	{
		val[i]={0,1,0,1,1,0};
		cin>>ch;
		if (ch=='N')cin>>a[i],val[i].x=val[i].x_p=a[i],val[i].X=power(2,a[i]);
		else {
			cin>>edge[i].x>>edge[i].y;
			if (ch=='<')edge[i].z=1;
			if (ch=='+')edge[i].z=2;
			if (ch=='*')edge[i].z=3;
		}
	}
	for (int i=1;i<=n;i++)if (!a[i])dfs(i);
	for (int i=1;i<=n;i++)cout<<a[i]<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
