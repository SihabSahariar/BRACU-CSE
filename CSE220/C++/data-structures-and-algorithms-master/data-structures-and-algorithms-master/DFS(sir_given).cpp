#include "stdio.h"
#include "queue"
#include "iostream"
#define maxSize 100
#define inf 9999
#define white 0
#define gray 1
#define black 2

using namespace std;

int color[maxSize];
int parent[maxSize];
int time,v,e;
int discoverTime[maxSize], finishingTime[maxSize];
int comp = 0;
int cycle = 0;
struct something
{
    int index;
    int finishingTime;
    string str;
};

struct something abc[maxSize];



void dfsVisit(int grid[maxSize][maxSize], int u){
    int i,j;
    color[u] = gray;
    discoverTime[u] = ++time;
    for(i=0; i<v; i++){
        if(grid[u][i]!=0){
            if(color[i]==white){
                parent[i]=u;
                dfsVisit(grid, i);
                //cout << "Here " << endl;
            }
            if(color[i]==black)//checks if the componant has a cycle
                cycle++;
        }
    }
    color[u] = black;
    finishingTime[u]=++time;
    printf("%d\t", u);

}

void dfs(int grid[maxSize][maxSize]){
    //initialization
    int i,j;

    for(i=0; i<v; i++){
        parent[i]=-1;
        color[i]=white;
    }
    time=0;
    for(i=0; i<v; i++){
        if(color[i] == white){
            dfsVisit(grid, i);
            //cout << "Called " << endl;
            comp++;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    abc[0].str = "Socks";
    abc[1].str = "Shoes";
    abc[2].str = "Shorts";
    abc[3].str = "Pants";
    abc[4].str = "Belt";
    abc[5].str = "Jacket";
    abc[6].str = "Shirt";
    abc[7].str = "Tie";
    abc[8].str = "Watch";
    int grid[maxSize][maxSize];
    int i,j,x,y;

    printf("Enter number of vertex: ");
    scanf("%d",&v);
    printf("Enter number of edge: ");
    scanf("%d",&e);

    //input
    for(i=0; i<v; i++)
        for(j=0; j<v; j++)
            grid[i][j]=0;

    printf("Enter edges (u v): ");
    for(i=0; i<e; i++){
        scanf("%d %d",&x,&y);
        grid[x][y]=1;
        //grid[y][x]=1; // becomes undirected if comment out
    }

    //output
    printf("\nInput Graph:\n");
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            printf("%d\t",grid[i][j]);
        }
        printf("\n");
    }

    printf("\n\nDFS\n");
    dfs(grid);

    printf("\n\n");

    //cout << "Number Of Connected Componant " << comp << endl;
    //cout << "Number Of Cycle " << cycle << endl;
    //cout << "Number Of Tree " << comp - cycle << endl;

    for(int i = 0 ; i < 9 ; i++)
    {
        //cout << finishingTime[i] << " "; //<< endl;
        abc[i].index = i;
        abc[i].finishingTime = finishingTime[i];
    }

    for(int i = 0 ; i < v ; i++)
    {
        for(int j = i ; j< v ; j++)
        {
            if(abc[i].finishingTime < abc[j].finishingTime)
            {
                something temp = abc[i];
                abc[i] = abc[j];
                abc[j] = temp;
                //cout << abc[j].index << " ";
            }
        }
    }
    for(int i = 0 ; i< v ; i++)
        cout << abc[i].str << " ";
    return 0;
}


