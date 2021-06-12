#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SIZE 100

int adj[SIZE][SIZE];
int colour[SIZE];
int parent[SIZE];
int dis[SIZE];

void bfs(int adj[][SIZE] , int vertex , int startingNode);
void printPath(int startingNode , int endNode);

int main()
{
//    queue <int> q;
//    q.push(1);
//    q.push(2);
//    cout << q.empty() << endl;
//
//    return 0;
    freopen("input.txt" , "r" , stdin);
    int vertex;
    int edge;
    cin >> vertex >> edge;
    cout << "Vertex is : " << vertex <<endl;
    cout << "Edge is : " << edge <<endl;

    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        //cout << "Enter 2 Nodes : ";
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;

    }
    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    bfs(adj , vertex , 0);
    cout << endl;
    printPath(0 , 7);
}

void bfs(int adj[][SIZE] , int vertex , int startingNode)
{
    for(int i = 0 ; i < vertex ; i++)
    {
        if(i!= startingNode)
        {
            colour[i] = WHITE;
            dis[i] = INT_MIN; //Infinity
            parent[i] = -1; // Null
        }
    }

    colour[startingNode] = GRAY;
    dis[startingNode] = 0;
    parent[startingNode] = -1; //Null
    queue <int> bfsQueue;
    bfsQueue.push(startingNode);
    cout << "BFS is : ";
    while(!bfsQueue.empty())
    {
        int u = bfsQueue.front();
        cout << u << " ";
        bfsQueue.pop();
        for(int i = 0 ; i < vertex ; i++)
        {
            if(adj[u][i]!=0)
            {
                int v = i;
                if(colour[v] == WHITE)
                {
                    colour[v] = GRAY;
                    dis[v] = dis[u]+1;
                    parent[v] = u;
                    //cout << "parent of " << v << " is " << parent[v] << endl;
                    bfsQueue.push(v);
                }
            }
        }
        colour[u] = BLACK;
    }

}

void printPath(int startingNode , int endNode)
{
    char path[SIZE];
    int  par = parent[endNode];
    int i = 0;
    path[i++] = endNode+'0';
    path[i++] = ' ';
    while(par != -1)
    {
        path[i++] = par+'0';
        path[i++] = ' ';
        par = parent[par];
        //cout << "par is" << par << endl;
        //if(i==10)
          //  break;
    }
    path[i] = '\0';
    strrev(path);
    cout << "The Path is : " << path << endl;
}

