#include<bits/stdc++.h>
using namespace std;using ll=long long;using pii=pair<int,int>;
const int M=998244353,Lim=5e4;const ll inf=1e17;
struct S
{
	int n;
	void ini()
	{
		cin>>n;vector<vector<int>>res;
		//ȡ[l,r],����(l+r)*(r-l+1)=n*2
		//��(r-l+1)=x,y=l+r=n*2/x,��b=(y+x-1)/2,a=(y-x+1)/2
		//ö��x,�ж��Ƿ�:(y=n*2/xΪ������ & x<y & x,y��ż��һ��)����
		//x<y,���xֻ��ö�ٵ�sqrt(n);��Ȼl��x�������ݼ�
		for(int x=2;x<=Lim;x++)if(n*2%x==0)
		{
			int y=n*2/x;if((y-x+1)%2)continue;
			int b=(y+x-1)/2,a=(y-x+1)/2;if(a<1)continue;
			vector<int>v;for(int i=a;i<=b;i++)v.push_back(i);res.push_back(v);
		}
		cout<<res.size()<<'\n';
		for(auto&k:res) { for(auto&kk:k)cout<<kk<<' ';cout<<'\n'; }
	}
	void solve()
	{

	}
};
void precal() {}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);precal();
	int t=1;//cin>>t;
	while(t--) { S SS;SS.ini();SS.solve(); }
}