#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MX 100

int vertex;
int edge;
bool connection[MX][MX];
bool connectionReverse[MX][MX];
int colour[MX];
int parent[MX];
///int finishingTime[MX];
///int discoverTime[MX];
///int timeCount = 0;
int compCount = 0;
stack <int> finishedNodeStack;
set <int> st;
int maxNodes;
int minNodes = INT_MAX;
void dfs();
void dfsVisit(int u);
void dfsVisitReverse(int u);


int main()
{
    freopen("inputConnected.txt" , "r" , stdin);

    cin >> vertex >> edge;
    cout << "Vertex is : " << vertex <<endl;
    cout << "Edge is : " << edge <<endl;

    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        //cout << "Enter 2 Nodes : ";
        cin >> node1 >> node2;
        connection[node1][node2] = true;
        connectionReverse[node2][node1] = true;

    }

    dfs();
    cout  << endl;
    for(int i = 0 ; i < vertex ; i++)
    {
        colour[i] = WHITE;
        parent[i] = -1;
    }
    ///timeCount = 0;

    while(!finishedNodeStack.empty())
    {
        int u = finishedNodeStack.top();
        finishedNodeStack.pop();
        if(colour[u] == WHITE)
        {
            compCount++;
            cout << "Componant Number " << compCount << " : ";
            dfsVisitReverse(u);
            if(st.size() > maxNodes)
            {
                maxNodes = st.size();
            }
            if(st.size() < minNodes)
            {
                minNodes = st.size();
            }
            set <int> :: iterator it;

            for(it = st.begin() ; it != st.end() ; it++)
            {
                cout << *it << " ";
            }

            st.clear();

            cout << endl;
        }

    }

    cout << "Maximum Length : " << maxNodes << endl;
    cout << "Minimum Length : " << minNodes << endl;


}


void dfs()
{
    for(int i = 0 ; i < vertex ; i++)
    {
        colour[i] = WHITE;
        parent[i] = -1;
    }
    ///timeCount = 0;
    cout << "DFS is ";
    for(int i = 0 ; i<vertex ; i++)
    {
        if(colour[i] == WHITE)
        {
            dfsVisit(i);
        }
    }
}

void dfsVisit(int u)
{
    colour[u] = GRAY;
    ///discoverTime[u] = ++timeCount;
    for(int i = 0 ; i<vertex ; i++)
    {
        if(connection[u][i] == true)
        {
            int v = i;
            if(colour[v] == WHITE)
            {
                parent[v] = u;
                dfsVisit(v);
            }
        }
    }
    colour[u] = BLACK;
    ///finishingTime[u] = ++timeCount;
    cout << u << " ";
    finishedNodeStack.push(u);

}


void dfsVisitReverse(int u)
{


    colour[u] = GRAY;

    ///discoverTime[u] = ++timeCount;
    for(int i = 0 ; i < vertex ; i++)
    {
        if(connectionReverse[u][i] == true)
        {
            int v = i;
            if(colour[v] == WHITE)
            {
                parent[v] = u;
                dfsVisitReverse(v);
            }
        }
    }
    colour[u] = BLACK;
    ///cout << u << " ";
    st.insert(u);
    ///finishingTime[u] = ++timeCount;
    ///cout << u << " ";
    ///finishedNodeStack.push(u);

}
