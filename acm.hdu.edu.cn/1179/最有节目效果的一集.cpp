#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define N 3005
#define M 1500000
using namespace std;
struct node{
    int x,y;
    int a,b;
    bool flag;
}b[100005];
struct team{
    int win,s;
    string Name;
    int x;
		friend bool operator<(team x, team y) {
			
    if (x.win==y.win)
    {
        if (x.s==y.s)return x.Name<y.Name;
        return x.s>y.s;
    }
    else return x.win>y.win;
		}
}g[N];
int maxn=0;
int get(int x,int y,unordered_map<int ,int> &f)
{
    int z=x*N+y;
    if (!f[z])
    {
        f[z]=++maxn;
        return maxn;
    }
    return f[z];
}
bool cmp(team x,team y)
{
    if (x.win==y.win)
    {
        if (x.s==y.s)return x.Name<y.Name;
        return x.s>y.s;
    }
    else return x.win>y.win;
}
int n,k,cnt,pos[N],win[N],s[N],tot;
string Name[N];
deque<int> head[100005];
tree<team, null_type, less<team>, rb_tree_tag, tree_order_statistics_node_update> t[4];

node read(unordered_map<string,int> &a)
{
    char ch;
    string st;
    for (int i=1;i<=4;i++)cin>>st;
    st.erase(st.size()-1);
//    cout<<st<<endl;
    node x;
    x.x=a[st];
    for (int i=1;i<=8;i++)cin>>st;
    x.y=a[st];
    cin>>st>>x.a>>ch>>x.b>>ch;
    if (x.x>x.y)swap(x.x,x.y),swap(x.a,x.b);
    return x;
}
void add(node x)
{
	t[pos[x.x]].erase({win[x.x],s[x.x],Name[x.x],x.x});
	t[pos[x.y]].erase({win[x.y],s[x.y],Name[x.y],x.y});
    if (x.a>x.b)win[x.x]++;
    else win[x.y]++;
    s[x.x]+=x.a-x.b,s[x.y]+=x.b-x.a;
	t[pos[x.x]].insert({win[x.x],s[x.x],Name[x.x],x.x});
	t[pos[x.y]].insert({win[x.y],s[x.y],Name[x.y],x.y});
}
void del(node x)
{
	t[pos[x.x]].erase({win[x.x],s[x.x],Name[x.x],x.x});
	t[pos[x.y]].erase({win[x.y],s[x.y],Name[x.y],x.y});
    if (x.a>x.b)win[x.x]--;
    else win[x.y]--;
    s[x.x]-=x.a-x.b,s[x.y]-=x.b-x.a;
	t[pos[x.x]].insert({win[x.x],s[x.x],Name[x.x],x.x});
	t[pos[x.y]].insert({win[x.y],s[x.y],Name[x.y],x.y});
}

void solve()
{
    unordered_map<string,int> a;
    unordered_map<int,int> f;
    vector<int> p[4];
		t[1].clear(),t[2].clear(),t[3].clear();
//    f.clear();
//    a.clear();
    for (int i=0;i<=maxn;i++)head[i].clear();
    maxn=0;
    cnt=0;
    cin>>n>>k;
    for (int i=1;i<=3*n;i++)
    {
        win[i]=s[i]=0;
        for (int j=1;j<=6;j++)
        {
            string st;
            cin>>st;
            a[st]=i;
            if (j==1)Name[i]=st;
        }
        int x;
        cin>>x;
        pos[i]=x;
        p[x].push_back(i);
    }
		for (int i=1;i<=3*n;i++)t[pos[i]].insert({0,0,Name[i],i});

    while(k--)
    {
        int op;
        
        cin>>op;
        if (op==1)
        {
            node x=read(a);
            //判断在不在同一组
//            cout<<x.x<<' '<<x.y<<' '<<x.a<<' '<<x.b<<endl;
            x.flag=1;
            b[++cnt]=x;
            if (pos[x.x]!=pos[x.y]||x.x==x.y)
            {
                b[cnt].flag=0;
//                cout<<"!"<<endl;
                continue;
            }
            int id=get(x.x,x.y,f);
            head[id].push_back(cnt);
            if (head[id].size()==1)
			{
				add(x);
			}
            else b[cnt].flag=0;
            
        }
        if (op==2)
        {
            int x;
            cin>>x;
            if (b[x].flag==0)continue;
            del(b[x]);
            int id=get(b[x].x,b[x].y,f);
            b[head[id].front()].flag=0;
            head[id].pop_front();
            if (head[id].size()>0)
            {
                add(b[head[id].front()]);
                b[head[id].front()].flag=1;
            }
        }
        if (op==3)
        {
            int x;
            cin>>x;
            cout<<t[pos[x]].order_of_key({win[x],s[x],Name[x],x})+1<<endl;
//            for (int i=0;i<p[pos[x]].size();i++)
//            {
//                int id=p[pos[x]][i];-=
//                g[++tot].win=win[id];
//                g[tot].s=s[id];
//                g[tot].Name=Name[id];
//                g[tot].x=id;
////                cout<<id<<' '<<win[id]<<' '<<s[id]<<' '<<Name[id]<<endl;
//            }
//            sort(g+1,g+tot+1,cmp);
//            for (int i=1;i<=tot;i++)
//            {
//                if (x==g[i].x)
//                {
//                    printf("%d\n",i);
//                    break;
//                }
//            }
        }
    }
    return ;
}
int main()
{
//    freopen("11.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
