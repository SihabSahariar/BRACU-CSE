#include<bits/stdc++.h>
using namespace std;
#define MX 100

struct nodes
{
    int source;
    int destination;
    int edgeCost;
};

bool cmp (nodes a , nodes b)
{
    return a.edgeCost < b.edgeCost;
}

int connection[MX][MX];
int parent[MX];

void makeSet(int v)
{
    parent[v] = v;
}

int findParent(int u)
{
    if(u == parent[u])
    {
        return u;
    }
    else
    {
        ///parent[u] = findParent(parent[u]);
        return parent[u] = findParent(parent[u]);
    }
}

void makeUnion(int u , int v)
{
    if(findParent(u) != findParent(v))
    {
        parent[parent[u]] = parent[v];
        ///parent[v] = u;
    }
}

int main()
{
    freopen("prims.txt" , "r" , stdin);
    int vertex , edge;
    cin >> vertex >> edge;
    nodes item[edge];
    for(int i = 0 ; i < edge ; i++)
    {
        cin >> item[i].source >> item[i].destination >> item[i].edgeCost;
    }
    sort(item , item + edge , cmp);

    for(int i = 0 ; i < vertex ; i++)
    {
        makeSet(i);
        ///cout << i << " " << parent[i] << endl;
    }
    cout << "Source\tDest\tCost\n";
    for(int i = 0 ; i < edge ; i++)
    {
        int u = item[i].source;
        int v = item[i].destination;
        int w = item[i].edgeCost;
        if(findParent(u) != findParent(v))
        {
            connection[u][v] = w;
            connection[v][u] = w;
            makeUnion(u , v);
            cout << u <<"\t"<< v <<"\t" << w << endl;
        }
    }

    cout << endl;

    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << connection[i][j] << " ";
        }
        cout << endl;
    }
}
