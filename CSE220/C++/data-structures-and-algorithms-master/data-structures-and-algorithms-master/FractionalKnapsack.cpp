#include<bits/stdc++.h>
using namespace std;

struct item
{
    int price;
    int weight;
};

bool cmp(item a , item b)
{
    return a.price*b.weight > b.price*a.weight;
}

int main()
{
    freopen("txt.txt" , "r" , stdin);
    int n;
    cout << "Enter N : ";
    cin >> n;
    item arr[n];
    cout << "Enter N Elementes : (price , weight) " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i].price >> arr[i].weight;
    }
    sort(arr , arr+n , cmp);

    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i].price << " " << arr[i].weight << endl;
    }

    int maxWeight;
    cout << "Enter Max Weight "<< endl;
    cin >> maxWeight;

    double profit = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i].weight < maxWeight)
        {
            maxWeight -= arr[i].weight;
            profit += arr[i].price;
            //cout << profit << " " << maxWeight << endl;
        }
        else if(maxWeight != 0)
        {
            profit += arr[i].price * (maxWeight*1.0 / arr[i].weight); // *1.0 to typecast in double
            //cout << profit << " " << maxWeight << endl;
            break;
        }

    }

    cout << "\nProfit Max : " << profit << endl;
}
