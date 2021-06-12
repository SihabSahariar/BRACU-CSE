#include <bits/stdc++.h>
using namespace std;

map < vector <int> , int> check ;

int flag[50] , arr[50] , n ;
vector <int> seq ;

void permutation(int pos)
{
    int i ;
    if(pos>n)
    {
        if(check[seq]!=0) return ;
        check[seq] = 1;
        for(i=0;i<n;i++) printf("%d ",seq[i]);
        puts("");
        return ;
    }
    for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            flag[i] = 1 ;
            seq.push_back(arr[i]);
            permutation(pos+1);
            seq.pop_back();
            flag[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin >> arr[i];
    permutation(1);
    return 0;
}
