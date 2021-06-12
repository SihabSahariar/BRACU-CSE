#include<bits/stdc++.h>

using namespace std;

struct birthday
{
    int year;
    int month;
    int date;
};

bool isLessThan(birthday birthdayNodeI , birthday birthdayNodeF)
{
    if(birthdayNodeI.year < birthdayNodeF.year)
        return true;
    else if(birthdayNodeI.month < birthdayNodeF.month && birthdayNodeI.year == birthdayNodeF.year)
        return true;
    else if(birthdayNodeI.date < birthdayNodeF.date && birthdayNodeI.month == birthdayNodeF.month && birthdayNodeI.year == birthdayNodeF.year)
        return true;
    else
        return false;
}

bool isGreaterThan(birthday birthdayNodeI , birthday birthdayNodeF)
{
    if(birthdayNodeI.year > birthdayNodeF.year)
        return true;
    else if(birthdayNodeI.month > birthdayNodeF.month && birthdayNodeI.year == birthdayNodeF.year)
        return true;
    else if(birthdayNodeI.date > birthdayNodeF.date && birthdayNodeI.month == birthdayNodeF.month && birthdayNodeI.year == birthdayNodeF.year)
        return true;
    else
        return false;
}


void quickSort(birthday birthdayNode[] , int f , int l)
{

    int i , j;
    if(f < l)
    {
        i = f+1;
        while (isLessThan(birthdayNode[i] , birthdayNode[f]))
        {
            i++;
        }
        j = l;
        while(isGreaterThan(birthdayNode[j] , birthdayNode[f]))
        {
            j--;
        }
        while(i < j)
        {
            swap(birthdayNode[i] , birthdayNode[j]);
            while (isLessThan(birthdayNode[i] , birthdayNode[f]))
            {
                i++;
            }
            //j = l;
            while(isGreaterThan(birthdayNode[j] , birthdayNode[f]))
            {
                j--;
            }
        }
        swap(birthdayNode[j] , birthdayNode[f]);
        quickSort(birthdayNode , f , j-1);
        quickSort(birthdayNode , j+1 , l);
    }

}

int main()
{
    freopen("quickSortModifiedText.txt" , "r" , stdin);
    int n;
    cin >> n;
    ///input
    cout << "Entered" << endl;
    birthday birthdayNode[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> birthdayNode[i].year >> birthdayNode[i].month >> birthdayNode[i].date;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << birthdayNode[i].year << " " << birthdayNode[i].month << " " << birthdayNode[i].date;
        cout << endl;
    }

    ///quickSort ALgorithm

    quickSort(birthdayNode , 0 , n-1);
    for(int i = 0 ; i < n ; i++)
    {
        cout << birthdayNode[i].year << " " << birthdayNode[i].month << " " << birthdayNode[i].date;
        cout << endl;
    }
}

