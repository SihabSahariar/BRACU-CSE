// BFS means Breadth First Search
// BFS works for undirected graph
// BFS finds a shortest path from one node to another node in a graph
// Time complexity O(V+E)
// V -> vertex E -> edge

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define mx 10000
struct node
{
    int u,w;
};

bool graph[mx+10][mx+10];
bool visit[mx+10];

int BFS(int source,int destination)
{
    queue <node> Q;
    node obj;
    obj.u=source;
    obj.w=0;

    Q.push(obj);
    visit[source]=true;

    while(Q.size()!=0)
    {
        obj = Q.front();
        Q.pop();
        int u = obj.u , w = obj.w;
        if(u==destination) return w;

        for(int i=0;i<=mx;i++)
        {
            if(graph[u][i]==true&&visit[i]==false)
            {
                visit[i]=true;
                obj.u=i;obj.w=w+1;
                Q.push(obj);
            }
        }
    }

    return -1; // There are no such paths exist between source and destination
}
int main()
{
    int N,M; // N is the numbers of junctions and M is the number of roads

    scanf("%d%d",&N,&M);
    for(int i=0;i<=mx;i++) for(int j=0;j<=mx;j++) graph[i][j] = false ;

    while(M--)
    {
        int u , v ; // There is a road between junctions u and v
        scanf("%d%d",&u,&v);
        graph[u][v]= graph[v][u] = true;
    }

    int x , y ; // Find the shortest path from junction x to junction y
    scanf("%d%d",&x,&y);

    printf("%d\n",BFS(x,y));

    return 0;
}
