#include<bits/stdc++.h>
using namespace std;

//#define MX 10

int main()
{
    int MX;
    cout << "ENTER N : ";
    cin >> MX;
    int arr[MX];
    for(int i = 0 ; i < MX ; i++)
    {
        arr[i] = rand()%100;
    }
    sort(arr , arr+MX);
    for(int i = 0 ; i < MX ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nEnter key : ";// << endl;
    int key;
    cin >> key;

    int l = 0;
    int h = MX - 1;
    bool found = false;
    int index = -1;

    int iter = 0;
    while(l <= h && !found)
    {
        iter++;
        int m = (int) (h+l)/2;
        if(key < arr[m])
        {
            h = m-1;
            //cout << arr[m] << " ";
        }
        else if(key > arr[m])
        {
            l = m+1;
            //cout << arr[m] << " ";
        }
        else if(key==arr[m])
        {
            found = true;
            index = m;
        }
    }

    if(found)
    {
        cout << "Found at " << index << endl;
        cout << "Iteration Needed " << iter << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    found = false;
    int iter2 = 0;
    index = -1;
    for(int i = 0 ; i <MX ; i++)
    {
        iter2++;
        if(key == arr[i])
        {
            found = true;
            index = i;
            break;
        }
    }
    cout << "\nIN ITERATIVE WAY " << endl;
    if(found)
    {
        cout << "Found at " << index << endl;
        cout << "Iteration Needed " << iter2 << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    cout << "\nDifference is : " << abs(iter2 - iter) << endl;
}
