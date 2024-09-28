#include<bits/stdc++.h>
using namespace std;using ll=long long;using ld=long double;
using pii=pair<int,int>;
const int M=998244353,g=3;const ll inf=1e17;const double eps=1e-10;
bool trig;
struct NTT
{//998244352=1048576*8*119//或P=1004535809//可多测//ans<M(1e9)
	int bit,bitnum=0;vector<int>rev,w;
	int poww(ll a,int b) { ll ans=1;for(;b;b>>=1,a=a*a%M)if(b&1)(ans*=a)%=M;return ans; }
	int invv(ll a) { return poww(a,M-2); }
	void prew(int n)
	{
		bitnum=0;for(bit=1;bit<=n;bit<<=1)bitnum++;
		rev.resize(bit,0);w.resize(bit,0);w[0]=1;int bs=poww(g,(M-1)/bit);
		for(int i=1;i<bit;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bitnum-1)),w[i]=1ll*w[i-1]*bs%M;
	}
	void _NTT(vector<int>&s,int op)
	{//cur*op:IFFT A/reverse(s+1,s+bit):IFFT B
		for(int i=0;i<bit;i++)if(i<rev[i])swap(s[i],s[rev[i]]);int x,y;
		for(int len=1;len<bit;len<<=1)for(int st=0,cur=0,dst=(len<<1),dc=op*bit/(len<<1)+bit;st<bit;st+=dst,cur=0)
			for(int k=st;k<len+st;k++,cur=(cur+dc)&(bit-1))x=s[k],y=ll(s[k+len])*w[cur]%M,s[k]=(x+y)%M,s[k+len]=(x-y+M)%M;
		if(op==-1) { int inv=poww(bit,M-2);for(int i=0;i<bit;i++)s[i]=ll(s[i])*inv%M; }
	}
	vector<int>mul(vector<int>a,vector<int>b,int l=0)
	{
		int n=a.size(),m=b.size();prew(n+m-1);a.resize(bit,0);b.resize(bit,0);
		_NTT(a,1);_NTT(b,1);for(int i=0;i<bit;i++)a[i]=ll(a[i])*b[i]%M;_NTT(a,-1);a.resize(l?l:n+m-1);return a;
	}
}K;
struct S
{
	int n,la,lb,ca=0,cb=0;
	vector<int>va,vb;string sa,sb;
	void F(bool se) { cout<<(se?"Yes\n":"No\n"); }
	bool cmp(int La,int Ra,int Lb,int Rb)
	{
		if(Ra-La!=Rb-Lb)return 0;
		for(int i=0,d=Ra-La;i<=d;i++)
		{
			if(sa[La+i]!='-'&&sb[Lb+i]!='-'&&sa[La+i]!=sb[Lb+i])return 0;
		}
		return 1;
	}
	void ini()
	{
		cin>>la>>lb>>sa>>sb;
		
		int mi_a=M,ma_a=-M;for(int i=0;i<la;i++)if(sa[i]=='*')mi_a=min(mi_a,i),ma_a=max(ma_a,i);
		int mi_b=M,ma_b=-M;for(int i=0;i<lb;i++)if(sb[i]=='*')mi_b=min(mi_b,i),ma_b=max(ma_b,i);
		//trig=(sa.substr(0,4)=="glgg");
		if(trig)cout<<bool(mi_a^M)<<"|"<<bool(mi_b^M)<<'\n';
		//01
		if(mi_b^M)swap(sa,sb),swap(la,lb),swap(mi_a,mi_b),swap(ma_a,ma_b);
		//00
		if(mi_a==M)return F(cmp(0,la-1,0,lb-1));
		//11
		if(mi_b^M)
		{
			int d1=min(mi_a-0,mi_b-0),d2=min(la-1-ma_a,lb-1-ma_b);
			return F(cmp(0,d1-1,0,d1-1)&&cmp(la-d2,la-1,lb-d2,lb-1));
		}
		//10
		int d1=min(mi_a-0,mi_b-0),d2=min(la-1-ma_a,lb-1-ma_b);if(d1+d2>lb)return F(0);
		if(!(cmp(0,d1-1,0,d1-1)&&cmp(la-d2,la-1,lb-d2,lb-1)))return F(0);
		sa=sa.substr(d1,la-d1-d2);sb=sb.substr(d1,lb-d1-d2);la-=d1+d2,lb-=d1+d2;
		va.resize(la);for(int i=0;i<la;i++)va[i]=ctd(sa[i]);
		vb.resize(lb);for(int i=0;i<lb;i++)vb[i]=ctd(sb[i]);
		if(trig)cout<<"A\n";
		solve();
		
	}
	int ctd(char c) { if(c=='*')return -1;if(c=='-')return 0;return (c-'a'+1)*6+5; }
	int Sol(int La,int Ra,int Lb,int Rb)//return min Rb
	{
		if(trig)cout<<La<<"/"<<Ra<<','<<Lb<<'/'<<Rb<<'\n';
		int da=Ra-La+1,db=Rb-Lb+1;if(!da)return Lb-1;
		vector<vector<int>>a(3,vector<int>(da));
		for(int e=0;e<3;e++)for(int i=0;i<da;i++)
		{
			a[e][i]=1;for(int j=-1;j<=e;j++)(a[e][i]*=va[Ra-i])%=M;
		}
		//for(int i=0;i<da;i++)cout<<sa[Ra-i];cout<<'\n';
		while(1)
		{
			//cout<<"&&\n";
			if(trig)cout<<La<<"_"<<Ra<<','<<Lb<<'_'<<Rb<<'\n';
			if(da>db)return -M;int dd=min(db,da*2+1);
			vector<vector<int>>b(3,vector<int>(dd)),c(3);
			//cout<<"O"<<da<<'/'<<dd<<'/'<<db<<'\n';
			//for(int i=0;i<dd;i++)cout<<sb[Lb+i];cout<<'\n';
			//cout<<"S\n";
			for(int e=0;e<3;e++)for(int i=0;i<dd;i++)
			{
				b[e][i]=1;for(int j=0;j<=e;j++)(b[e][i]*=vb[Lb+i])%=M;
			}
			for(int e=0;e<3;e++)c[e]=K.mul(a[e],b[2-e]);
			int cc=0;
			for(int i=da-1;i<dd;i++)
			{
				ll A=c[0][i],B=c[1][i],C=c[2][i],D=A-B*2+C;
				ll v=(D%M+M)%M;
				if(!v)return Lb+i;//Rb								
				cc++;
			}//cout<<"C\n";
			Lb+=cc;db-=cc;
		}
	}
	void solve()//a:*...*...* b:......
	{
		for(int i=1,lst=0,Lb=0;i<la;i++)if(va[i]==-1)
		{
			int v=Sol(lst+1,i-1,Lb,lb-1);
			if(v==-M)
			{
				return F(0);
			}
			lst=i,Lb=v+1;
		}
		return F(1);
	}
};
void precal() {}
signed main()
{
	//freopen("1.in","r",stdin);
	//cout<<fixed<<setprecision(12);
	ios::sync_with_stdio(0);cin.tie(0);precal();
	int t=1;//cin>>t;
	//clock_t a=clock();
	//while(1) { S SS;SS.ini(); }
	while(t--) { S SS;SS.ini(); }
	//cout<<"Time:"<<double(clock()-a)<<'\n';
}
/*
7 8
ttk-wxx
*tt-l-xx
20 18
bulijiojio-dibuliduo
*li*ji-*ox*i*-du*-

10 10
justmonika
j-stsayori
7 8
ttk-wxx
*tt-l-xx
13 11
asoulwangziji
-soulg*z-y-
7 3
abc*cba
a*c
20 18
bulijiojio-dibuliduo
*li*ji-*ox*i*-du*-

*/