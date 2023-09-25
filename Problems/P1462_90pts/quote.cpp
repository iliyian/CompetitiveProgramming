#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int xx=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx;
}
int n,m,num,head[10010],fi[10010],b,ans;
bool ju[10010];
struct edge{
	int to;
	int nxt;
	int dis;
}ed[1000010];
struct node{
	int xh;
	int hf;
	int hp;
	friend bool operator < (node x,node y)
	{
		return x.hf>y.hf;
	}
}dl[10010];
void add(int st,int to,int dis)
{
	num++;
	ed[num].dis=dis;
	ed[num].nxt=head[st];
	head[st]=num;
	ed[num].to=to;
	return ;
}
void dfs()
{
	int x=max(fi[1],fi[n]);
	for(int i=1;i<=n;++i) dl[i].xh=i,dl[i].hp=0,dl[i].hf=x;
	dl[1].hp=b;
	priority_queue <node> q;
	q.push(dl[1]);
	while(!q.empty())
	{
		node cur=q.top();
		q.pop();
		int st=cur.xh;
		for(int i=head[st];i;i=ed[i].nxt)
		{
			int to=ed[i].to;
			int xl=cur.hp-ed[i].dis;
			int co=max(cur.hf,fi[to]);
			if(xl<=0) continue;
			if(xl<=dl[to].hp&&co>=dl[to].hf) continue;//交的时候这里写错了，不过还能过，可能是数据水，也可能这句没啥用
			if(to==n) 
			{
				ans=co;
				return ;
			}
			dl[to].hp=xl;
			dl[to].hf=co;
			q.push(dl[to]); 
		}
	}
}
int main()
{
  freopen("data.in", "r", stdin);
	n=read();
	m=read();
	b=read();
	for(int i=1;i<=n;++i) fi[i]=read();
	for(int i=1;i<=m;++i)
	{
		int x=read();
		int y=read();
		int z=read();
		add(x,y,z);
		add(y,x,z);
	}
	dfs();
	if(ans==0) cout<<"AFK";
	else cout<<ans;
	return 0;
}