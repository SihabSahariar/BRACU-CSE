#include<bits/stdc++.h>
using namespace std;
#define MX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

bool connection[MX][MX];
int vertex , edge;
int timeCount;
struct topologicalStructure
{
    ///int nodeNumber;
    string nodeName;
    int discoverTime;
    int finishingTime;
    int colour;
    int parent;

};
topologicalStructure topologicalItem[MX];
map <string , int> itemList;

void dfs();
void dfsVisit(int u);


int main()
{
    freopen("inputTopologicalSort.txt" , "r" , stdin);
    ///cout << "Enter Vertex & Edge : ";
    cin >> vertex >> edge;
    cout << "Vertex is : " << vertex <<endl;
    cout << "Edge is : " << edge <<endl;

    for(int i = 0 ; i < vertex ; i++)
    {
        cin >> topologicalItem[i].nodeName;
        itemList[topologicalItem[i].nodeName] = i;
        ///topologicalItem[i].nodeNumber = i;
    }
    string edge1;
    string edge2;

    ///Connection Create & Print
    for(int i = 0 ; i < edge ; i++)
    {
        cin >> edge1 >> edge2;

        connection[itemList[edge1]][itemList[edge2]] = true;
        ///connection[itemList[edge2]][itemList[edge1]] = true;
        ///cout << edge1 << " " << itemList[edge1] << " " << edge2 << " " << itemList[edge2] << endl;
    }
    dfs();
}


void dfs()
{
    for(int i=0 ; i < vertex ; i++)
    {
        topologicalItem[i].parent = -1;
        topologicalItem[i].colour = WHITE;
    }
    timeCount=0;
    for(int i=0 ; i < vertex ; i++)
    {
        if(topologicalItem[i].colour == WHITE)
        {
            dfsVisit(i);
        }
    }
}

void dfsVisit(int u)
{
    topologicalItem[u].colour = GRAY;
    topologicalItem[u].discoverTime = ++timeCount;

    for(int i=0 ; i < vertex ; i++)
    {
        if(connection[u][i] == true)
        {
            ///cout << "u is " << u << " i is " << i << endl;
            if(topologicalItem[i].colour == WHITE)
            {
                topologicalItem[i].parent = u;
                dfsVisit(i);
            }
        }
    }
    topologicalItem[u].colour = BLACK;
    topologicalItem[u].finishingTime = ++timeCount;
    cout << topologicalItem[u].nodeName << "\t";
}
