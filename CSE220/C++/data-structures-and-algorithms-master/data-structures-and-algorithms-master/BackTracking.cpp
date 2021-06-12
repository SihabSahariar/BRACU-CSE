#include<bits/stdc++.h>
using namespace std;

bool flag[50];
int n , seq[50];

void permutation(int pos)
{

    if(pos > n)
    {
        for(int i = 1 ; i <= n ; i++)
            cout << seq[i] << " ";
        cout << endl;
        return;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!flag[i])
        {
            flag[i] = true;
            seq[pos] = i;
            permutation(pos+1);
            flag[i] = false;
        }
    }
}

vector <int> v;
set < vector<int> > s;
int arr[50];


void combination(int pos)
{

    if(pos > n)
    {

        for(int i = 1 ; i <= n ; i++)
        {
            //cout << seq[i] << " ";
            v.push_back(seq[i]);

        }
        //for(int i = 0 ; i < v.size() ; i++) cout << v[i] << " ";

        s.insert(v);
        v.clear();

        return;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!flag[i])
        {
            flag[i] = true;
            seq[pos] = arr[i];
            combination(pos+1);
            flag[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    combination(1);
//    vector <int> v2;
//    set< vector <int> >::iterator iter;
    cout << s.size() << endl;
//    for(iter=s.begin(); iter!=s.end(); ++iter);
//    {
//        v2 = *iter;
//        //ii+=1;
//        //cout<<iter<<endl;
//        for(int i = 0 ; i != v2.size() ; i++)
//        {
//            cout << v2[i] << " ";
//        }
//        v2.clear();
//        cout << endl;
//    }

    return 0;
}
