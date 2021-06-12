#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of numbers to sort : ";
    cin >> n;
    int num[n];

    for(int i = 0 ; i < n ; i++)
        num[i] = rand()%1000;

    cout << "The Unsorted Numbers : ";
    for(int i = 0 ; i < n ; i++)
        cout << num[i] << " ";

    cout << endl;

    //Selection Sort Algorithm Starts
    for(int j = n-1 ; j >= 1 ; j--)
    {
        int t = 0;
        for(int k = 1 ; k <= j ; k++)
        {
            if(num[t] < num[k])
            {
                t = k;
            }
        }
        swap (num[j] , num[t]);
    }
    //Selection Sort Algorithm Ends

    cout << "The Sorted Numbers : ";
    for(int i = 0 ; i < n ; i++)
        cout << num[i] << " ";


}

