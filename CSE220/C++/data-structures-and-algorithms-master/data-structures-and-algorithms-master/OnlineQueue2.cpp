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

int main()
{

    node *header;
    header = (node * ) malloc(sizeof(node)); //

    if(header == NULL)
    {
        cout << "Memory not available" << endl;
        return 0;
    }

    header ->data = INT_MIN;
    header ->link = header;

    cout << "Enter N :";
    int n;
    cin >> n;
    for(int i = 0 ; i< n ; i++)
    {
        int number = rand()%1000;
        enqueQueue(header , number);
        cout << number << endl;
    }

    printList(header);
    int a = dequeQueue(header);
    int b = dequeQueue(header);
    cout << a << " " << b << endl;
    return 0;
}

void enqueQueue(node *header , int data)
{
    node *ptr = header;
    while(ptr ->link != header)
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
    if(header -> link == header)
    {
        cout << "The Queue Is Underflow" << endl;
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
    if(header -> link == header)
    {
        cout << "The Queue Is Empty" << endl;
        return;
    }
    node *ptr = header ->link;
    while(ptr != header)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
    cout << endl;
}
