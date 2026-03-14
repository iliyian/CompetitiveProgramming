#include <bits/stdc++.h>

typedef long long int64;
typedef long double db;

std::mt19937 Rand(time(0));
// std::mt19937 Rand(4);

const db eps=1e-8L,pi=acos(-1L);

template<typename T>
struct point{

  using type=T;
  
  type x,y;
  
  point():x(),y(){}
  point(type _x,type _y):x(_x),y(_y){}

  friend point operator+(const point &a,const point &b){return point(a.x+b.x,a.y+b.y);}
  friend point operator-(const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}
  friend point operator*(const point &a,const type &b){return point(a.x*b,a.y*b);}
  friend point operator*(const type &a,const point &b){return point(a*b.x,a*b.y);}
  friend point operator/(const point &a,const type &b){return point(a.x/b,a.y/b);}
  friend type operator*(const point &a,const point &b){return a.x*b.x+a.y*b.y;}
  friend type operator%(const point &a,const point &b){return a.x*b.y-a.y*b.x;}

  type mod2()const{return x*x+y*y;}
  type mod()const{return sqrtl(mod2());}

  point norm()const{return point(-y,x);}

};

template<typename T>
struct line{

  using type=T;

  point<type> s,t;

  line():s(),t(){}
  line(const point<type> &_s,const point<type> &_t):s(_s),t(_t){}

  point<type> vec()const{return t-s;}

};

template<typename type>
point<type> Cross(const line<type> &m,const line<type> &n){
  return m.s+n.vec()%(m.s-n.s)/(m.vec()%n.vec())*m.vec();
}

template<typename T>
struct circle{
  
  using type=T;

  point<type> o;
  type r;

  circle():o(),r(){}
  circle(const point<type> &_o):o(_o),r(){}
  circle(const point<type> &_o,type _r):o(_o),r(_r){}
  
  circle(
    const point<type> &a,
    const point<type> &b
  ):o((a+b)/2),r((a-b).mod()/2){}

  circle(
    const point<type> &a,
    const point<type> &b,
    const point<type> &c
  ){
    auto u=(a+b)/2;
    auto m=line(u,u+(a-b).norm());
    auto v=(b+c)/2;
    auto n=line(v,v+(b-c).norm());
    o=Cross(m,n);
    r=(a-o).mod();
  }

  bool In(const point<type> &p)const{
    return (p-o).mod2()<=r*r+eps;
  }

  type area()const{return pi*r*r;}
  type len()const{return 2*pi*r;}

};

db Area(const std::vector<point<int64>> &a){
  db res=0;
  for (int i=0;i<(int)a.size();++i){
    int j=(i+1)%(int)a.size();
    res+=a[i]%a[j];
  }
  return res/2;
}

// #define debug

circle<db> MinCircle(const std::vector<point<int64>> &_a){
  int n=_a.size();
  std::vector<point<db>> a(n);
  for (int i=0;i<n;++i){
    auto [x,y]=_a[i];
    a[i]=point<db>(x,y);
  }
  std::shuffle(a.begin(),a.end(),Rand);
  circle<db> res(a[0],0);
  #ifdef debug
  if (n==3){
    std::cerr<<" order : \n";
    std::cerr<<a[0].x<<' '<<a[0].y<<'\n';
    std::cerr<<a[1].x<<' '<<a[1].y<<'\n';
    std::cerr<<a[2].x<<' '<<a[2].y<<'\n';
    std::cerr<<'\n';
  }
  #endif
  for (int i=1;i<n;++i){
    if (res.In(a[i])) continue;
    #ifdef debug
    if (n==3){
      std::cerr<<" now : "<<i<<'\n';
    }
    #endif
    res=circle<db>(a[i],0);
    for (int j=0;j<i;++j){
      if (res.In(a[j])) continue;
      res=circle(a[i],a[j]);
      #ifdef debug
      if (n==3){
        std::cerr<<'\n';
        std::cerr<<" start checking\n";
        std::cerr<<' '<<a[i].x<<' '<<a[i].y<<'\n';
        std::cerr<<' '<<a[j].x<<' '<<a[j].y<<'\n';
        std::cerr<<' '<<res.o.x<<' '<<res.o.y<<' '<<res.r<<'\n';
        std::cerr<<'\n';
      }
      #endif
      for (int k=0;k<j;++k){
        if (res.In(a[k])) continue;
        res=circle(a[i],a[j],a[k]);
      }
    }
  }
  #ifdef debug
  if (n==3){
    exit(0);
  }
  #endif
  return res;
}

void work(){
  int n;
  std::cin>>n;
  std::vector<point<int64>> a(n);
  for (auto &[x,y]:a)
    std::cin>>x>>y;
  db v=Area(a);
  auto o=MinCircle(a);
  // std::cout<<o.r<<" : ";
  std::cout<<(o.area()-v)/o.len()<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cerr<<std::fixed<<std::setprecision(6);
  std::cout<<std::fixed<<std::setprecision(6);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}