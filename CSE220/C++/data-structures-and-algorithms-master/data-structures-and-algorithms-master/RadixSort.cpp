#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};

void enqueQueue(node *header , int data);
int dequeQueue(node *header);
void printList(node *header);

int maxiNumber(node *header);
int maxiDigit(int num);
//int a = 0;
int main()
{

    node *header;
    header = (node * ) malloc(sizeof(node)); //

    node *q[10];
    for(int i = 0 ; i < 10 ; i++)
    {
        q[i] = (node * ) malloc(sizeof(node));
        q[i] -> data = INT_MIN;
        q[i] -> link = NULL;
    }

    if(header == NULL)
    {
        cout << "Memory not available" << endl;
        return 0;
    }

    header ->data = INT_MIN;
    header ->link = NULL;

    cout << "Enter N :";
    int n;
    cin >> n;
    for(int i = 0 ; i< n ; i++)
    {
        int number = rand()%1000;
        enqueQueue(header , number);
        //cout << number << endl;
    }
    printList(header);
    int mx = maxiNumber(header);
    int mxDigit = maxiDigit(mx);
    //cout << mx << endl;
    //cout << mxDigit << endl;

    for(int i = 1 ; i<= mxDigit ; i++)
    {
        int data = 0;
        while(true)
        {
            data = dequeQueue(header);
            if(data == -1)
                break;
            int data2 = data;
            for(int j = 1 ; j<i ; j++)
                data2/=10;
            data2 = data2%10;
            enqueQueue(q[data2] , data);
            //printList(q[data2]);
        }
        for(int k = 0 ; k < 10 ; k++)
        {
            while(true)
            {
                int data = dequeQueue(q[k]);
                if(data == -1)
                    break;
                enqueQueue(header , data);
            }
        }
    }
    printList(header);


    return 0;
}

void enqueQueue(node *header , int data)
{
    node *ptr = header;
    while(ptr ->link != NULL)
    {
        ptr = ptr -> link;
    }
    node *newNode = (node * ) malloc(sizeof(struct node)); //
    if(newNode == NULL)
    {
        cout << "No New Memory left" << endl;
    }
    else
    {
        newNode -> data = data;
        newNode -> link = ptr -> link;
        ptr -> link = newNode;
    }
}

int dequeQueue(node *header)
{
    if(header -> link == NULL)
    {
        //cout << "The Queue Is Underflow" << a++ << endl;
        return -1;
    }
    node *ptr = header -> link;
    int data = ptr -> data;
    header -> link = ptr -> link;
    free(ptr);
    return data;
}

void printList(node *header)
{
    if(header -> link == NULL)
    {
        cout << "The Queue Is Empty" << endl;
        return;
    }
    node *ptr = header ->link;
    while(ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
    cout << endl;
}

int maxiNumber(node *header)
{
    node *ptr = header -> link;
    int mx = ptr -> data;
    while(ptr->link!= NULL)
    {
        ptr = ptr -> link;
        if(mx < ptr ->data)
            mx = ptr ->data;
    }
    return mx;
}
int maxiDigit(int num)
{
    int digit = 0;
    if(num==0)
        return 1;

    while(num!=0)
    {
        num /= 10;
        digit++;
    }
    return digit;
}


