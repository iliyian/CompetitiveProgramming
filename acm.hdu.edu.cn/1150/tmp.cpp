#include <bits/stdc++.h>
using namespace std;

int a=5;

int f();

int main()

{  for(int i=1;i<=3;i++)   cout<<f()<<endl;

    return 0;

}



int f(){

    static int a=2;
    std::cout << a << '\n';

    return a++;

}

