#include<bits/stdc++.h>
using namespace std;

void hanoi(int n , int i , int j , int k);
void printStack();
int cunt = 0;
stack <int> towerA , towerB , towerC;
void hanoi(int n , stack <int> &towerA , stack <int> &towerB , stack <int> &towerC)
{
    printStack();

//    if(n == 1)
//    {
//        //cout << i << " to " << k << endl;
//        int temp = towerA.top();
//        if(!towerA.empty())
//        {
//            int temp = towerA.top();
//            towerA.pop();
//            towerC.push(temp);
//
//        }
//    }
    if(n > 0)
    {
        cunt++;
        hanoi(n-1 , towerA , towerC , towerB);
        //cout << i << " to " << k << endl;
        if(!towerA.empty())
        {
            int temp = towerA.top();
            towerA.pop();
            towerC.push(temp);

        }
        hanoi(n-1 , towerB , towerA , towerC);
    }
}

void printStack()
{
    stack <int> tempStack;
    cout << endl;
    cout << "ITERATION : " << cunt << endl;
    cout << "\nTowerA : " ;// << endl;
    while(!towerA.empty())
    {
        int temp = towerA.top();
        towerA.pop();
        cout << temp << " ";
        tempStack.push(temp);
    }
    while(!tempStack.empty())
    {
        int temp = tempStack.top();
        towerA.push(temp);
        tempStack.pop();

    }

    cout << "\nTowerB : " ;// << endl;
    while(!towerB.empty())
    {
        int temp = towerB.top();
        towerB.pop();
        cout << temp << " ";
        tempStack.push(temp);
    }
    while(!tempStack.empty())
    {
        int temp = tempStack.top();
        tempStack.pop();
        towerB.push(temp);
    }

    cout << "\nTowerC : " ;// << endl;
    while(!towerC.empty())
    {
        int temp = towerC.top();
        towerC.pop();
        cout << temp << " ";
        tempStack.push(temp);
    }
    while(!tempStack.empty())
    {
        int temp = tempStack.top();
        tempStack.pop();
        towerC.push(temp);
    }

}

int main()
{
    int n;
    cin >> n;
    for(int i = n ; i >= 1 ; i--)
        towerA.push(i);
    hanoi(n , towerA , towerB , towerC);
    cout << "\nNumber of steps " << cunt << endl;
}
