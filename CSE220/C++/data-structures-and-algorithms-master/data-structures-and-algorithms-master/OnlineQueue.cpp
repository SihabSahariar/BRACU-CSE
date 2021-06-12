#include<bits/stdc++.h>
using namespace std;

int n;
int top = -1;
int bottom = -1;

void enQueue(int numberQueue[] , int number);
int deQueue(int numberQueue[] );
void printQueue();

int main()
{

    cout << "Enter N :" << endl;
    cin >> n;
    int numberQueue[n];
    while(true)
    {
        int num;
        cin >> num;
        if(num == -1)
            break;
        enQueue(numberQueue , num);
    }
    while(true)
    {
        int a;
        cout << "Enter Key: ";
        cin >> a;
        if(a==-1)
        {
            break;
        }

        cout << deQueue(numberQueue) << endl;
    }
}

void enQueue(int numberQueue[] , int number)
{
    if(top > n && bottom == -1)
    {
        cout << "Overflow" << endl;
        return;
    }
    else if(top > n)
    {
        top = top%n;
    }

    if(top < bottom)
    {
        if(bottom - top >= 1)
        {
            cout << "Overflow" << endl;
            return;
        }
    }
    numberQueue[++top] = number;
}

int deQueue(int numberQueue[])
{
    if(abs(top - bottom) == 0)
    {
        cout << "Queue is under flow" << endl;
        top = -1;
        bottom = -1;
        return -1;
    }
    return numberQueue[++bottom];
}


void printQueue()
{

}
