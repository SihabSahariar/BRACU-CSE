#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};

void pushStack(node *header , int data);
void printList(node *header);
int popStack(node *header);


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
        pushStack(header , number);
        cout << number << endl;
    }
    printList(header);
    int a = popStack(header);
    int b = popStack(header);
    cout << a << " " << b << endl;
    return 0;
}

void pushStack(node *header , int data)
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


int popStack(node *header)
{
    if(header -> link == header)
    {
        cout << "The Stack Is Underflow" << endl;
        return -1;
    }
    else
    {
        node *ptr = header;
        while(ptr ->link -> link !=header)
        {
            ptr = ptr->link;
        }
        int data = ptr->link->data;
        free(ptr ->link);
        ptr -> link = header;
        return data;
    }
}

void printList(node *header)
{
    if(header -> link == header)
    {
        cout << "The Stack Is Empty" << endl;
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

