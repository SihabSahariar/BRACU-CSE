#include<bits/stdc++.h>
using namespace std;
#define MX 100
int vertex, edge;

struct elements
{
    int startingNode, endingNode, dis;
} nodes[MX];

struct values
{
    int dis;
    int parent;
};

map <int, values> itemList;
int iter = 0;
void setAllVertex(int startingNode);
bool relax(int u, int v, int dis);
bool bellmanFord(int startingNode);

int main()
{
    freopen("BellmanFord2.txt", "r", stdin);
    cin >> vertex >> edge;
    int startingNode,endingNode, disTemp;
    for(int i = 0 ; i< edge ; i++)
    {
        cin >> startingNode >> endingNode >> disTemp;
        nodes[i].startingNode = startingNode;
        nodes[i].endingNode = endingNode;
        nodes[i].dis = disTemp;
    }
    ///cin >> startingNode;
    startingNode = 0;
    if(bellmanFord(startingNode))
    {
        cout << "There is no negative cycle in the graph" << endl;
    }
    else
    {
        cout << "There is a negative cycle in the graph" << endl;
    }
    cout << "Vertex" << "\t\t" << "Distance" << "\t" << "Parent" << endl;
    for(int i = 0 ; i < vertex ; i++)
    {
        values temp = itemList[i];
        cout << i << "\t\t" << temp.dis << "\t\t" << temp.parent << endl;
    }
    cout << "Iteration " << iter << endl;

}

void setAllVertex(int startingNode)
{
    values valuesTemp;
    valuesTemp.dis = 0;
    valuesTemp.parent = startingNode;
    ///cout << startingNode << "\t\t" << valuesTemp.dis << "\t\t" << valuesTemp.parent << endl;
    itemList[startingNode] = valuesTemp;
    for(int i = 0 ; i < vertex ; i++)
    {
        if(i!= startingNode)
        {
            valuesTemp.dis = 1000;
            valuesTemp.parent = -1;
            itemList[i] = valuesTemp;
            ///cout << i << "\t\t" << valuesTemp.dis << "\t\t" << valuesTemp.parent << endl;
        }
    }
}

bool relax(int u, int v, int dis)
{
    values uTemp = itemList[u];
    values vTemp = itemList[v];
    if(vTemp.dis > uTemp.dis + dis)
    {
        vTemp.dis = uTemp.dis + dis;
        vTemp.parent = u;
        itemList[v] = vTemp;
        ///cout << "Update " << v << "\t" << vTemp.dis << "\t" << vTemp.parent << endl;
        return false;///When Updates
    }
    return true; ///No Updates
}

bool bellmanFord(int startingNode)
{
    setAllVertex(startingNode);
    bool check = true;
    ///Vertex - 1 times iterations
    for(int i = 0 ; i < vertex - 1 ; i++)
    {
        check = true;
        bool flag = true;
        for(int i = 0 ; i < edge ; i++)
        {
            check = relax(nodes[i].startingNode, nodes[i].endingNode, nodes[i].dis);
            if(!check)
                flag = false;
        }
        if(flag)
            return flag;

        iter++;

        cout << "Vertex" << "\t\t" << "Distance" << "\t" << "Parent" << endl;
        for(int i = 0 ; i < vertex ; i++)
        {
            values temp = itemList[i];
            cout << i << "\t\t" << temp.dis << "\t\t" << temp.parent << endl;
        }

    }
    check = true;
    ///Last Iteration
    for(int i = 0 ; i < edge ; i++)
    {
        check = relax(nodes[i].startingNode, nodes[i].endingNode, nodes[i].dis);
        if(!check)
            return check;
        //iter++;
    }
    iter++;
    return check;
}
