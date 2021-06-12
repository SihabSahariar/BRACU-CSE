#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SIZE 100


int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

int row , col;
int tree;

struct cordinate
{
    int x;
    int y;
};

struct datatype
{
    cordinate myCordinate;
    bool isTree;
    int colour;
    int dis;
    cordinate parent;
};

cordinate knightPosition;
cordinate knightHome;
datatype knightBoard[SIZE][SIZE];


void bfs(cordinate knightPosition);
void printPath(cordinate knightPosition, cordinate knightHome);

int main()
{

    freopen("KnightReturns.txt" , "r" , stdin);

    cout << "Enter Dimensions of Grid : ";
    cin >> row >> col;
    cout << endl;

    cout << "Enter Number of Trees: ";
    cin >> tree;
    cout << endl;

    cout << "Enter position of Trees: " << endl;
    for(int i = 0 ; i< tree ; i++)
    {
        int xTree;
        int yTree;
        cin >> xTree >> yTree;
        knightBoard[xTree][yTree].isTree = true;
    }

    cout << "Enter Knight's Position: ";
    cin >> knightPosition.x >> knightPosition.y;
    cout << endl;

    cout << "Enter Home Position: ";
    cin >> knightHome.x >> knightHome.y;
    cout << endl;

    bfs(knightPosition);
    printPath(knightPosition , knightHome);
}


void bfs(cordinate knightPosition)
{
    if(knightPosition.x < 0 && knightPosition.x >= row && knightPosition.y < 0 && knightPosition.y >= col)
    {
        cout << "There Is No Path From Knight to Home" << endl;
        return;
    }
    else if(knightHome.x < 0 && knightHome.x >= row && knightHome.y < 0 && knightHome.y >= col)
    {
        cout << "There Is No Path From Knight to Home" << endl;
        return;
    }

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            knightBoard[i][j].myCordinate.x = i;
            knightBoard[i][j].myCordinate.y = j;
            if(i != knightPosition.x && j != knightPosition.y)
            {
                if(!knightBoard[i][j].isTree)
                {
                    knightBoard[i][j].colour = WHITE;
                    knightBoard[i][j].dis = INT_MIN;
                    knightBoard[i][j].parent.x = -1;
                    knightBoard[i][j].parent.y = -1;
                }
            }
        }
    }

    knightBoard[knightPosition.x][knightPosition.y].colour = GRAY;
    knightBoard[knightPosition.x][knightPosition.y].dis = 0;
    knightBoard[knightPosition.x][knightPosition.y].parent.x = -1;
    knightBoard[knightPosition.x][knightPosition.y].parent.y = -1;
    knightBoard[knightPosition.x][knightPosition.y].myCordinate = knightPosition;

    queue <datatype> bfsQueue;
    bfsQueue.push(knightBoard[knightPosition.x][knightPosition.y]);
    //cout << "BFS is : ";
    while(!bfsQueue.empty())
    {
        datatype u = bfsQueue.front();
        bfsQueue.pop();
        //cout << u.myCordinate.x << " " << u.myCordinate.y << endl;
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = u.myCordinate.x + dx[i];
            int y = u.myCordinate.y + dy[i];
            //cout << "Previous " << x << " " << y << endl;
            if(!knightBoard[x][y].isTree && x >=0 && x < row && y >=0 && y < col)
            {
                if(knightBoard[x][y].colour == WHITE)
                {
                    //cout << "Present " << x << " " << y << endl;
                    knightBoard[x][y].colour = GRAY;
                    knightBoard[x][y].dis = u.dis+1;
                    knightBoard[x][y].parent = u.myCordinate;
                    bfsQueue.push(knightBoard[x][y]);
                }
            }
        }
        u.colour = BLACK;
    }

}

void printPath(cordinate knightPosition, cordinate knightHome)
{
    int moves = 0;
    stack <cordinate> pathCordinate;
    cordinate par = knightBoard[knightHome.x][knightHome.y].parent;
    while(par.x != -1 && par.y !=-1)
    {
        pathCordinate.push(par);
        par = knightBoard[par.x][par.y].parent;
        moves++;
    }
    cout << endl;
    if(moves != 0)
    {
        cout << "Yes the knight can reach home with " << moves << " steps" << endl;
        cout << "The Steps are : " << endl;
        while(!pathCordinate.empty())
        {
            cordinate temp = pathCordinate.top();
            pathCordinate.pop();
            cout << temp.x << " " << temp.y << endl;
        }
    }
    else
        cout << "There Is No Path From Knight to Home" << endl;
}

