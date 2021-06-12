#include<bits/stdc++.h>
using namespace std;
#define MX 100

struct Edge
{
    int u;
    int v;
    int w;
};

bool operator < (Edge lhs, Edge rhs)
{
    return lhs.w < rhs.w;
}

bool cmp(const Edge &lhs, const Edge &rhs)
{
    if(lhs.u != rhs.u)
        return lhs.u < rhs.u;
    else
        return lhs.w < rhs.w;
}

int parent[MX];
bool taken[MX];
vector<Edge> E;

int findParent(int u)
{
    if(parent[u] == u) return u;
    else return parent[u] = findParent(parent[u]);
}


int kruskal()
{
    sort(E.begin(), E.end());

    int sz = E.size();

    int ans = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        if(findParent(E[i].u) != findParent(E[i].v))
        {
            //union
            parent[parent[E[i].u]] = parent[E[i].v];
            taken[i] = true;
            ans+=E[i].w;
        }
    }
    return ans;
}

int kruskal2()
{
    sort(E.begin(), E.end(), cmp);

    int sz = E.size();

    for(int i = 0 ; i < 100 ; i++)
    {
        parent[i] = i;
    }
    int ans = 0;

    for(int i = 0 ; i < sz ; i++)
    {

        //union
        if(!taken[i])
        {
            if(!(i < sz && E[i].u == E[i+1].u))
            {
                continue;
            }
            else
            {
                ans+=E[i].w;
            }

        }
        else
        {
            ans+=E[i].w;
        }

    }
    return ans;
}

int main()
{
    freopen("text.txt", "r", stdin);
    int vertex, edge;
    cin >> vertex >> edge;
    for(int i = 0 ; i < 100 ; i++)
    {
        parent[i] = i;
    }
    for(int i = 0 ; i < edge ; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        E.push_back(e);
    }
    cout << "1st MST" << endl;
    cout << "Cost " << kruskal() << endl;
    cout << endl;
    cout << "2nd MST" << endl;
    cout << "Cost " << kruskal2() << endl;
}

