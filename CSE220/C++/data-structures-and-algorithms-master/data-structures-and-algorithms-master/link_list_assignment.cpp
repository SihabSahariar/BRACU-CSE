#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
} *header;

///insert functions
void insertFront(node *header, int data);
void printList(node *header);
void insertLast(node *header, int data);
void insertValue(node *header, int insertAfter, int data);
void insertAtIndex(node *header, int insetIndex, int data);

///update functions
void updateFront(int data);
void updateLast(int data);
void updateMiddle(int updateValue, int data);
void updateAtIndex(int updateIndex, int data);

///delete functions
void deleteFront(node *header);
void deleteLast(node *header);
void deleteMiddle(int deleteValue);
void deleteAtIndex(int deleteIndex);

///search function
int searchValue(int data);

///functions for insert, delete, update, search operations
void insertOptions();
void deleteOptions();
void updateOptions();
void searchOptions();

///populating the linked list with dummy data
void populateLinkWithDemo(int n);

int main()
{
    int n;
    cout << "Enter Linked List initial size: ";
    cin >> n;
    populateLinkWithDemo(n);

    while(1)
    {
        cout << "******************************************************" << endl;
        cout << "Current List:" << endl;
        printList(header);

        cout << "\nOptions:\n" << endl;
        cout << "1. Insert\n2. Update\n3. Delete\n4. Search\n5. Exit\n" << endl;
        int choice;
        cout << "Enter  your choice:  " ;
        cin >> choice;

        switch(choice)
        {
        case 1:
            insertOptions();
            break;
        case 2:
            updateOptions();
            break;
        case 3:
            deleteOptions();
            break;
        case 4:
            searchOptions();
            break;
        case 5:
            cout << "\nExiting..." <<endl;
            exit(0);
        default:
            cout << "\nInvalid choice. Please Enter correct option.\n" << endl;
            break;
        }
    }
    return 0;
}

void printList(node *header)
{
    node *ptr = header->link;
    while(ptr != NULL)
    {
        printf("\t%d\n", ptr->data);
        ptr = ptr->link;
    }
}

///insert options and functions
void insertOptions()
{
    bool insertExit = false;
    int data, value;
    cout << "\nInsert Options:\n\n" ;
    while(!insertExit)
    {
        cout << "1. Insert at First\n2. Insert at Last\n3. Insert after a value\n4. Insert at an index\n5. Back\n" << endl;
        int insertChoice;
        cout << "Enter  your choice:  " ;
        cin >> insertChoice;

        switch(insertChoice)
        {
        case 1:
            cout << "Enter data: " ;
            cin >> data;
            insertFront(header, data);
            cout << "\n***\tData inserted \t***\n" << endl;
            insertExit = true;
            break;
        case 2:
            cout << "Enter data: " ;
            cin >> data;
            insertLast(header, data);
            cout << "\n***\tData inserted \t***\n" << endl;
            insertExit = true;
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter data: " ;
            cin >> data;
            insertValue(header, value, data);
            cout << "\n***\tData inserted \t***\n" << endl;
            insertExit = true;
            break;
        case 4:
            cout << "Enter index: ";
            cin >> value;
            cout << "Enter data: " ;
            cin >> data;
            insertAtIndex(header, value, data);
            cout << "\n***\tData inserted \t***\n" << endl;
            insertExit = true;
            break;
        case 5:
            insertExit = true;
            break;
        default:
            cout << "Invalid choice. Please Enter correct option:\n" << endl;
            break;
        }
    }
}

void insertFront(node *header, int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        cout << "Memory not available" << endl;
    }
    else
    {
        newNode->data = data;
        newNode->link = header->link;
        header->link = newNode;
    }
}

void insertLast(node *header, int data)
{
    node *ptr = header->link;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        cout << "Memory not available" << endl;
    }
    else
    {
        newNode->data = data;
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
}

void insertValue(node *header, int insetAfter, int data)
{
    node *ptr = header->link;
    bool found = false;
    while(ptr != NULL)
    {
        if(ptr->data == insetAfter)
        {
            found = true;
            break;
        }
        ptr = ptr->link;
    }

    if(found)
    {
        node *newNode = (node*)malloc(sizeof(node));
        if(newNode == NULL)
        {
            cout << "Memory not available" << endl;
        }
        else
        {
            newNode->data = data;
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    }
    else
    {
        cout << "\nElement not found and data could not be inserted" << endl;
    }
}

void insertAtIndex(node *header, int insetIndex, int data)
{
    node *ptr = header->link;
    bool found = false;
    int i = 0;
    while(ptr != NULL)
    {
        if(i == (insetIndex-1))
        {
            found = true;
            break;
        }
        i++;
        ptr = ptr->link;
    }

    if(found)
    {
        node *newNode = (node*)malloc(sizeof(node));
        if(newNode == NULL)
        {
            cout << "Memory not available" << endl;
        }
        else
        {
            newNode->data = data;
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    }
    else
    {
        cout << "\nIndex not found and data could not be inserted" << endl;
    }
}

///delete options and functions
void deleteOptions()
{
    bool deleteExit = false;
    int data, value;
    cout << "\nDelete Options:\n\n" ;
    while(!deleteExit)
    {
        cout << "1. Delete from First\n2. Delete from Last\n3. Delete a value\n4. Delete at an index\n5. Back\n" << endl;
        int deleteChoice;
        cout << "Enter  your choice:  " ;
        cin >> deleteChoice;

        switch(deleteChoice)
        {
        case 1:
            deleteFront(header);
            deleteExit = true;
            break;
        case 2:
            deleteLast(header);
            deleteExit = true;
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            deleteMiddle(value);
            deleteExit = true;
            break;
        case 4:
            cout << "Enter index: ";
            cin >> value;
            deleteAtIndex(value);
            deleteExit = true;
            break;
        case 5:
            deleteExit = true;
            break;
        default:
            cout << "Invalid choice. Please Enter correct option:\n" << endl;
            break;
        }
    }
}

void deleteFront(node *header)
{
    cout << "\nDo you want to delete from front?\n1.yes\n2.no" << endl;
    int deleteData;
    cin >> deleteData;
    if(deleteData == 1)
    {
        if(header->link == NULL)
        {
            printf("The list is empty");
        }
        else
        {
            node *ptr = header->link;

            header->link = ptr->link;

            free(ptr);
        }
        cout << "\n***\tData deleted \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData not deleted \t***\n" << endl;
    }
}

void deleteLast(node *header)
{
    cout << "\nDo you want to delete from last?\n1.yes\n2.no" << endl;
    int deleteData;
    cin >> deleteData;
    if(deleteData == 1)
    {
        node *ptr = header;
        while(ptr->link->link != NULL)
        {
            ptr = ptr->link;
        }
        free(ptr->link);
        ptr->link = NULL;
        cout << "\n***\tData deleted \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData not deleted \t***\n" << endl;
    }
}

void deleteMiddle(int deleteValue)
{
    cout << "\nDo you want to delete the value?\n1.yes\n2.no" << endl;
    int deleteData;
    bool found = false;
    cin >> deleteData;
    if(deleteData == 1)
    {
        node *ptr = header->link;
        node *ptr2 = header;
        while(ptr != NULL)
        {
            if(ptr->data == deleteValue)
            {
                found = true;
                break;
            }
            ptr2 = ptr;
            ptr = ptr->link;
        }
        if(found)
        {
            ptr2->link = ptr->link;
            free(ptr);
        }
        cout << "\n***\tData deleted \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData not deleted \t***\n" << endl;
    }
}

void deleteAtIndex(int deleteIndex)
{
    cout << "\nDo you want to delete the index?\n1.yes\n2.no" << endl;
    int deleteData, i = 0;
    bool found = false;
    cin >> deleteData;
    if(deleteData == 1)
    {
        node *ptr = header->link;
        node *ptr2 = header;
        while(ptr != NULL)
        {
            if(i == deleteIndex)
            {
                found = true;
                break;
            }
            i++;
            ptr2 = ptr;
            ptr = ptr->link;
        }
        if(found)
        {
            ptr2->link = ptr->link;
            free(ptr);
        }
        cout << "\n***\tData deleted \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData not deleted \t***\n" << endl;
    }
}

///update options and functions
void updateOptions()
{
    bool updateFinish = false;
    int data, value;
    while(!updateFinish)
    {
        cout << "\nUpdate options: \n" << endl;
        cout << "1. Update at first\n2. Update at last\n3. Update a value\n4. Update value at an position\n5. Back\n" << endl;
        int updateChoice;
        cout << "Enter  your choice:  " ;
        cin >> updateChoice;

        switch(updateChoice)
        {
        case 1:
            cout << "Enter data: " ;
            cin >> data;
            updateFront(data);
            cout << "\n***\tData updated \t***\n" << endl;
            updateFinish = true;
            break;
        case 2:
            cout << "Enter data: " ;
            cin >> data;
            updateLast(data);
            cout << "\n***\tData updated \t***\n" << endl;
            updateFinish = true;
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter data: " ;
            cin >> data;
            updateMiddle(value, data);
            updateFinish = true;
            break;
        case 4:
            cout << "Enter position: ";
            cin >> value;
            cout << "Enter data: " ;
            cin >> data;
            updateAtIndex(value, data);
            updateFinish = true;
            break;
        case 5:
            updateFinish = true;
            break;
        default:
            cout << "Invalid choice. Please Enter correct option:\n" << endl;
            break;
        }
    }
}

void updateFront(int data)
{
    node *ptr = header->link;

    ptr->data = data;
}

void updateLast(int data)
{
    node *ptr = header->link;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->data = data;

}

void updateMiddle(int updateValue, int data)
{
    node *ptr = header->link;
    bool found = false;
    while(ptr != NULL)
    {
        if(ptr->data == updateValue)
        {
            found = true;
            break;
        }
        ptr = ptr->link;
    }
    if(found)
    {
        ptr->data = data;
        cout << "\n***\tData updated \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData could not be updated. \t***\n" << endl;
    }
}

void updateAtIndex(int updateIndex, int data)
{
    node *ptr = header->link;
    bool found = false;
    int i = 0;
    while(ptr != NULL)
    {
        if(i == (updateIndex-1))
        {
            found = true;
            break;
        }
        i++;
        ptr = ptr->link;
    }
    if(found)
    {
        ptr->data = data;
        cout << "\n***\tData updated \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData could not be updated. \t***\n" << endl;
    }
}

///search options and functions
void searchOptions()
{
    cout << "\nEnter value to search: " ;
    int searchData;
    cin >> searchData;

    int pos = searchValue(searchData);
    if(pos != -1)
    {
        cout << "\n***\tValue found in position: " << pos+1 << " \t***\n" << endl;
    }
    else
    {
        cout << "\n***\tData not found. \t***\n" << endl;
    }
}

int searchValue(int data)
{
    node *ptr = header->link;
    bool found = false;
    int i = 0;
    while(ptr != NULL)
    {
        if(ptr->data == data)
        {
            found = true;
            break;
        }
        i++;
        ptr = ptr->link;
    }
    if(found)
    {
        return i;
    }
    return -1;
}

///populating the linked list with dummy data
void populateLinkWithDemo(int n)
{
    header = (node*)malloc(sizeof(node));
    if(header == NULL)
    {
        cout << "Memory not available" << endl;
    }
    else
    {
        header->data = INT_MIN;
        header->link = NULL;
        for(int i = 0 ; i < n ; i++)
        {
            insertFront(header, rand()%1000);
        }
    }
}
