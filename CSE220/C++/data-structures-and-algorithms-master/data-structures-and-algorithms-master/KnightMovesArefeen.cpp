#include <iostream>
#include <cstdio>
#include <stack>
#include<queue>

#define loop(a) for(int i = 0; i<(a) ; i++)
#define loop2(b) for(int j = 0 ; j<(b) ; j++)

#define tree -2
#define knight 2
#define home 1
#define white -1
#define gray 0
#define black 1
using namespace std;

int v , e , t , x , y , kx , ky , hx , hy;
int grid[100][100];
int d[100][100];
int visited[100][100] , map[100][100];


int moveX[] = {-1,-1,1,1,-2,-2,2,2};
int moveY[] = {2,-2,2,-2,1,-1,1,-1};

queue <pair <int , int> > q;

void bfs(pair <int , int> root);
bool movePossible(int x,int x1 ,int y ,int y1 );

int main()
{
	freopen("knight.txt" , "r" , stdin);

	cout << "Enter the dimensions of grid : " ;
	cin >> v >> e;
	cout << " " << v <<" " << e << endl;

	cout << "Enter the number of the trees: ";
	cin >> t;
	cout << " " << t;

	cout << endl;

	loop(v)
		loop2(e)
			grid[i][j] = 0;

	cout << endl << "Trees are: \n" << endl;

	loop(t)
	{
		cin >> x >> y;
		cout <<"\t" << x << "\t" << y << endl;
		grid[x][y] = tree;
		visited[x][y] = tree;
	}

	cout << "\nEnter Knight's position: ";
	cin >> kx >> ky;
	cout << " " << kx << " " << ky << endl;

	if(kx > v-1 || kx < 0 || ky > e-1 || ky < 0) { cout << "\nKnight out of the board!\n\n" ; return 0; }
	else	grid[kx][ky] = knight;


	cout << "\nEnter Home position: ";
	cin >> hx >> hy;
	cout << " " << hx << " " << hy << endl ;

	if(hx > v-1 || hx < 0 || hy > e-1 || hy < 0) { cout << "\nHome out of the board!\n\n" ; return 0; }
	else	grid[hx][hy] = home;

	cout << endl <<"     ";
			for(int k = 0; k <= e*8 ; k++)
				cout << "_" ;
	cout << endl;

	loop(v)
	{
		loop2(e)
			{
				if(grid[i][j] == tree) cout << "\ttree";
				else if(grid[i][j] == 0) cout << "\t" << grid[i][j];
				else if(grid[i][j] == knight) cout << "\tKNIGHT";
				else if(grid[i][j] == home) cout << "\tHOME";
			}
			cout << endl <<"     ";

			for(int k = 0; k <= e*8 ; k++)
				cout << "_" ;
			cout << endl;
	}

	pair <int , int> root = make_pair(kx , ky);

	bfs(root);

	return 0;
}


void bfs(pair <int , int> root)
{
	int x, y , move = 0;
	bool found = false;
	pair<int , int> parent[v][e];
	pair <int , int > p ;

	loop(v)
		loop2(e)
		{
			visited[i][j] = white;
			parent[i][j] = make_pair(-1 , -1);
			map[i][j] = 0;
		}

	q.push(root);
	pair<int , int> temp = root;

	visited[temp.first][temp.second] = gray;
	d[temp.first][temp.second] = 0;


	while(!q.empty())
	{
		temp = q.front(); q.pop();
		x = temp.first;
		y = temp.second;

		//if( x == hx && y == hy) break;


		loop(8)
			if( movePossible( x, moveX[i] , y , moveY[i] ) )
			{
				if (visited[ x+moveX[i] ][ y+moveY[i] ] == white)
				{
					visited[ x+moveX[i] ][ y+moveY[i] ] = gray;
					d[ x+moveX[i] ][ y+moveY[i] ] = d[x][y] + 1 ;
					parent[ x+moveX[i] ] [ y+moveY[i] ] = make_pair(x,y);
					q.push(make_pair(x+moveX[i] , y+moveY[i]));
				}
			}
			visited[x][y] = black;
	}



	if(d[hx][hy] == 0) cout << endl << "No - Knight can't reach home!" << endl;
	else
	{
		cout << endl << "Yes - Knight can reach home in " << d[hx][hy] << " steps! " << endl;

		cout << endl << "The path is: " << endl;

		p = make_pair(hx , hy);
		stack <pair <int , int> > s;

		while(p.first != -1 && p.second != -1)
		{
			s.push(p);
			p = parent[p.first][p.second];
		}

		while (!s.empty())
		{
			p = s.top(); s.pop();
			cout << "\t\t" << p.first << "\t" << p.second << endl;
			map[p.first][p.second] = move;

			move++;
		}

		cout << endl << endl;
	}

	cout << "Movement Map: " << endl << endl;
	map[kx][ky] = -1;

	loop(v)
	{
		loop2(e)
		{
			if(map[i][j] == -1) cout << "\tM:0";
			else if (map[i][j] !=0 ) cout<< "\tM:" << map[i][j];
			else cout << "\t" << map[i][j];
		}
		cout << endl << endl;
	}


}

bool movePossible(int x , int x1 , int y , int y1 )
{
	if ( x+x1 < 0 || x+x1 > v-1 || y+y1 < 0 || y+y1 > e-1 ) return false;
	else if (grid[x+x1][y+y1] != tree) return true;
	else return false;
}
