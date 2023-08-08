#include<bits/stdc++.h>
#define IL inline
#define RI register int
IL void in(int &x)
{
	int f=1;x=0;char s=getchar();
	while(s>'9' or s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s>='0' and s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}
int n,k,f[100008],tot;
bool init[1000008];
long long ans;
struct cod{int u,v,w;}edge[100008];
IL int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
IL bool ccp(const cod&a,const cod&b){return a.w>b.w;}
int main(void)
{
  freopen("data.in", "r", stdin);
  freopen("ans.out", "w", stdout);
	in(n),in(k);
	for(RI i=1;i<=n;i++)f[i]=i;//一定要初始化!
	for(RI i=1,x;i<=k;i++)in(x),init[x]=true;
	for(RI i=1;i<=n-1;i++)
		in(edge[i].u),in(edge[i].v),in(edge[i].w),ans+=edge[i].w;
	std::sort(edge+1,edge+n,ccp);//从大到小sort.
	for(RI i=1;i<=n-1;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u),fv=find(v);
		if(init[fu] and init[fv])continue;
		f[fu]=fv;
		ans-=w;//减去边
		if(init[fu])init[fv]=true;
		else if(init[fv])init[fu]=true;
	}
	printf("%lld",ans);
}
