#include<bits/stdc++.h>
using namespace std;
#define MX 100

typedef pair<int , int> PII; /// dest & cost
vector<PII> v[MX];

struct node {
    int u;
    int cost;

    bool operator < (const node &a) const
    {
        return cost > a.cost;
    }

};
priority_queue<node> pq;
int cost[MX];
bool taken[MX];
int vertex , edge;

int prim(int source)
{
    for(int i = 0 ; i < vertex ; i++ )
    {
        cost[i] = INT_MAX;
        taken[i] = false;
    }

    cost[source] = 0;
    node temp;
    temp.u = source;
    temp.cost = 0;
    pq.push(temp);
    int ans = 0;

    while(!pq.empty())
    {

        node current = pq.top();
        pq.pop();

        if(taken[current.u])
        {
            ///already taken
            continue;
        }

        taken[current.u] = true;

        ans += current.cost;



        for(PII i : v[current.u])
        {
            if(taken[i.first])
                {
                    continue;
                }

            if(i.second < cost[i.first])
            {

                node temp2;
                temp2.u = i.first;
                temp2.cost = i.second;
                pq.push(temp2);
                cost[i.first] = i.second;

            }

        }
    }

    return ans;
}


int main()
{
    freopen("prims.txt" , "r" , stdin);

    cin >> vertex >> edge;

    for(int i = 0 ; i < edge ; i++)
    {
        int source;// , dest , cost;
        PII p;
        cin >> source >> p.first >> p.second;

        v[source].push_back(p);
        ///cout << source << p.first << p.second << endl;
    }

//
//    for(int i = 0 ; i < edge ; i++)
//        for(PII V : v[i])
//        {
//            cout << i << " " << V.first << " " << V.second << endl;
//        }

    cout << prim(0) << endl;

}

