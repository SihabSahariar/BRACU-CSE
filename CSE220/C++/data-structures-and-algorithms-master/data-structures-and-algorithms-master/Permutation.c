#include <stdio.h>

int flag[50], seq[50] , n ;

void permutation(int pos)
{
    int i ;
    if(pos>n)
    {
        for(i=1;i<=n;i++) printf("%d ",seq[i]);
        puts("");
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            flag[i] = 1 ;
            seq[pos] = i;
            permutation(pos+1);
            flag[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    permutation(1);
    return 0;
}
