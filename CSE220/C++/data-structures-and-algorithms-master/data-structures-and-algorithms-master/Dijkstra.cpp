#include<bits/stdc++.h>
using namespace std;
#define MX 100
#define WHITE 1
#define GRAY 2
#define BLACK 3
int connection[MX][MX] , dis[MX] , parent[MX];
int vertex , edge;

struct node
{
    int currentNode;
    int parent;
    int color;
    int costMin;
    bool operator < (const node& temp) const
    {
        return costMin < temp.costMin;
    }
};
node itemList[MX];
priority_queue<node> queueVertex;

void dijkstra(int startingNode);
void setAll(int startingNode);

int main()
{
    freopen("Dijkstra.txt" , "r" , stdin);
    cin >> vertex >> edge;
    int e1 , e2 , w;

    for(int i = 0 ; i < edge ; i++)
    {
        cin >> e1 >> e2 >> w;
        connection[e1][e2] = w;
    }
    int startingNode = 0;
    dijkstra(startingNode);
    cout << "Vertex\tCost\tParent" << endl;
    for(int i = 0 ; i < vertex ; i++)
    {
        cout << itemList[i].currentNode << "\t" << itemList[i].costMin << "\t" << itemList[i].parent << endl;
    }
}

void dijkstra(int startingNode)
{
    setAll(startingNode);
    queueVertex.push(itemList[startingNode]);
    while(!queueVertex.empty())
    {
        node current = queueVertex.top();
        queueVertex.pop();

        if(current.color == WHITE)
        {
            for(int i = 0 ; i < vertex ; i++)
            {
                if(connection[current.currentNode][i] != 0)
                {
                    if(itemList[i].costMin > current.costMin + connection[current.currentNode][i])
                    {
                        itemList[i].costMin = current.costMin + connection[current.currentNode][i];
                        itemList[i].parent = current.currentNode;
                        queueVertex.push(itemList[i]);
                    }
                }
            }
        }
        itemList[current.currentNode].color = BLACK;

    }
}


void setAll(int startingNode)
{
    dis[startingNode] = 0;
    itemList[startingNode].costMin = 0;
    itemList[startingNode].parent = startingNode;
    itemList[startingNode].color = WHITE;
    for(int i = 0 ; i < vertex ; i++)
    {
        if(i!=startingNode)
        {
            dis[i] = INT_MAX;
            itemList[i].currentNode = i;
            itemList[i].costMin = INT_MAX;
            itemList[i].parent = -1;
            itemList[i].color = WHITE;
        }
    }
}
