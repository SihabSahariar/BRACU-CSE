#include<bits/stdc++.h>
using namespace std;

bool visit[100];
long long f[100];

long long fib(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;

    if(visit[n] == false) visit[n] = true; /// memorise
    else return f[n]; ///state

    return f[n] = fib(n-1) + fib(n-2);
}

int w[] = {10,20,25} , p[] = {25,20,50};
bool visit2[100][1000];
int f2[100][1000];
int K(int pos , int W)
{
    ///if(W < 0) return INT_MIN;
    if(pos == (sizeof(w) / sizeof(int)) ) return 0;

    if(visit2[pos][W] == false) visit2[pos][W] = true;
    else return f2[pos][W];

    if(W - w[pos] >=0)
        return f2[pos][W] = max (K(pos+1 , W-w[pos]) + p[pos] , K(pos +1 , W) );
    else
        return f2[pos][W] = K(pos+1 , W);
}

int main()
{
    ///cout << fib(70) << endl;
    ///cout << sizeof(w) / sizeof(int) << endl; ///count the number of elements in array
    cout << K(0 , 30) << endl; /// K(position , weightMax)
    return 0;
}
