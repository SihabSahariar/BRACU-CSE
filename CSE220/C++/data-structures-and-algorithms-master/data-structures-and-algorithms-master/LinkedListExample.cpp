#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *link;
};

void deleteFront(struct node *header)
{
    struct node *ptr = header -> link;
    header -> link = ptr -> link;
    free(ptr);
}
void deleteLast(struct node *header)
{
    struct node *ptr = header;
    while(ptr ->link -> link !=NULL)
    {
        ptr = ptr -> link;
    }
    free(ptr ->link);
    ptr -> link = NULL;
}
void insertFront(struct node *header , int data)
{
    struct node *newNode = (node * ) malloc(sizeof(struct node)); // malloc functions returns a void type pointer that's why we have to typecast it.
    if(newNode == NULL)
    {
        cout << "No New Memory left" << endl;
    }
    else
    {
        newNode -> data = data;
        newNode -> link = header -> link;
        header -> link = newNode;
    }
}


void insertLast(struct node *header , int data)
{
    struct node *ptr = header;
    while(ptr ->link !=NULL)
    {
        ptr = ptr -> link;
    }
    struct node *newNode = (node * ) malloc(sizeof(struct node)); // malloc functions returns a void type pointer that's why we have to typecast it.
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

void printList( struct node *header)
{
    struct node *ptr = header ->link;
    while(ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> link;
    }
}
int main()
{
    struct node *header;
    header = (node * ) malloc(sizeof(struct node)); // malloc functions returns a void type pointer that's why we have to typecast it.

    if(header == NULL)
    {
        cout << "Memory not available" << endl;
    }
    else
    {
        header ->data = INT_MIN;
        header ->link = NULL;

        insertFront(header , 10);
        insertFront(header , 5);
        insertFront(header , 20);

        printList(header);
    }

    int number;
    cout << "\nInsert a number" << endl;

    cin >> number ;
    insertLast(header , number);
    printList(header);
    cout << endl;
    deleteFront(header);
    printList(header);

    cout << endl;
    deleteLast(header);
    printList(header);


}
