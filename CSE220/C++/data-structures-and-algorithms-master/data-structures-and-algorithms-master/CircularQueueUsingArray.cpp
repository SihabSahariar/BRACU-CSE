#include<bits/stdc++.h>
using namespace std;

int n;
int top = -1;
int rare = -1;

void enQueue(int numberQueue[] , int number);
int deQueue(int numberQueue[] );
void printQueue(int numberQueue[] );

int main()
{

    cout << "Enter N :" << endl;
    cin >> n;
    int numberQueue[n];
    while(true)
    {
        cout << "Enter Option 0 to enqueue 1 to dequeue and 2 to printQueue : " ;
        int option;
        cin >> option;
        if(option == 0)
        {
            int num;
            cin >> num;
            enQueue(numberQueue , num);
        }
        else if(option == 1)
        {
            cout << deQueue(numberQueue) << endl;
        }
        else if(option == 2)
        {
            printQueue(numberQueue);
        }

        //cout << "Rare " << rare << " top "<<top << endl;
    }

}

void enQueue(int numberQueue[] , int number)
{

    if(top >= n-1 && rare == -1)
    {
        cout << "Queue is Over Flow" << endl;
        return;
    }
    else if(top >= n -1)
        top = -1;
    if(top == rare && top != -1)
    {
        cout << "Queue is Over Flow" << endl;
        return;
    }
    numberQueue[++top] = number;
}

int deQueue(int numberQueue[])
{
    if(top == n-1 && rare == n-1)
    {
        cout << "Under Flow" << endl;
        top = -1;
        rare = -1;
        return -1;
    }
    else if(top == -1 && rare == -1)
    {
        cout << "Under Flow" << endl;
        return -1;
    }
    else if(rare < top && rare+1 == top)
    {
        int a = rare;
        top = -1;
        rare = -1;
        return numberQueue[a+1];
    }
    else if(top == rare+1 && rare != -1)
    {
        //cout << "Under Flow Rare " << rare << " top "<<top << endl;
        cout << "Under Flow" << endl;
        top = -1;
        rare = -1;
        return -1;
    }
    if(rare >= n -1)
        rare = -1;

    return numberQueue[++rare];
}


void printQueue(int numberQueue[] )
{
    if(rare < top)
    {
        for(int i = rare+1 ; i< top+1 ; i++)
            cout << numberQueue[i] << " ";
        cout << endl;
    }
    else
    {
        for(int i = rare + 1 ; i<n ; i++)
            cout << numberQueue[i] << " ";
        for(int i = 0 ; i< top+1 ; i++)
            cout << numberQueue[i] << " ";
        cout << endl;
    }
}

