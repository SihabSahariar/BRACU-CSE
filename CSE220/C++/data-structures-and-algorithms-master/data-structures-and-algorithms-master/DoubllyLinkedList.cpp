#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *fLink;
    node *bLink;
};



void insertFront(node *header , int data);
void insertLast(node *header , int data);
void insertAt(node *header , int data , int index);
void insertBeforeValue(node *header , int data , int value);
void insertAfterValue(node *header , int data , int value);

void updateFront(node *header , int data);
void updateLast(node *header , int data);
void updateAt(node *header , int data , int index);
void updateValue(node *header , int data , int value);

void deleteFront(node *header);
void deleteLast(node *header);
void deleteAt(node *header , int index);
void deleteValue(node *header , int value);

void printList(node *header);
int searchIndexOfValue(node *header , int data);
void freeAll(node *header);

int optionList();
int optionListForAll();
void insertOperation(node *header , int insertOption);
void updateOperation(node *header , int updateOption);
void deleteOperation(node *header , int deleteOption);

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
    header ->fLink = NULL;
    header ->bLink = NULL;


    cout << "Enter N :";
    int n;
    cin >> n;
    for(int i = 0 ; i< n ; i++)
    {
        int number = rand()%1000;
        insertLast(header , number);
    }


    while(true)
    {
        cout << "\nCurrent List : ";
        printList(header);

        int option = optionList();

        if(option == 1)
        {
            cout << "Insert Operations : " << endl;
            int insertOption = optionListForAll();
            insertOperation(header , insertOption);
        }
        else if(option == 2)
        {
            cout << "Update Operations : " << endl;
            int updateOption = optionListForAll();
            updateOperation(header , updateOption);
        }
        else if(option == 3)
        {
            cout << "Delete Operations : " << endl;
            int deleteOption = optionListForAll();
            deleteOperation(header , deleteOption);
        }
        else if(option == 4)
        {
            cout << "Enter Value : ";
            int value;
            cin >> value;
            int index = searchIndexOfValue(header , value);
            if(index == -1)
                cout << "Invalid Data" << endl;
            else
                cout << value << " is at index " << index << endl;
        }
        else if(option == 5)
        {
            freeAll(header);
            return 0;
        }
        else
            cout << "Invalid Option" << endl;

    }

}


void insertFront(node *header , int data)
{
    node *newNode = (node * ) malloc(sizeof(struct node)); //
    if(newNode == NULL)
    {
        cout << "No New Memory left" << endl;
    }
    else
    {
        newNode -> data = data;
        newNode -> fLink = header -> fLink;
        header -> fLink = newNode;
        newNode -> bLink = header;
    }
}


void insertLast(node *header , int data)
{
    node *ptr = header;
    while(ptr ->fLink !=NULL)
    {
        ptr = ptr -> fLink;
    }
    node *newNode = (node * ) malloc(sizeof(struct node)); //
    if(newNode == NULL)
    {
        cout << "No New Memory left" << endl;
    }
    else
    {
        newNode -> data = data;
        newNode -> fLink = ptr -> fLink;
        ptr -> fLink = newNode;
        newNode -> bLink = ptr;
    }
}

void insertAt(node *header , int data , int index)
{
    node *ptr = header;
    int indexCheck = -1;

    while(indexCheck < index - 1 && ptr -> fLink != NULL)
    {
        indexCheck++;
        ptr = ptr -> fLink;
    }
    if(indexCheck +1 != index)
    {
        cout << "Invalid Index Or Data" << endl;
        return;
    }

    node *newNode = (node * ) malloc(sizeof(struct node)); //
    if(newNode == NULL)
    {
        cout << "No New Memory left" << endl;
    }
    else
    {
        newNode -> data = data;
        newNode ->bLink = ptr;
        newNode -> fLink = ptr -> fLink;
        ptr -> fLink -> bLink = newNode;
        ptr -> fLink = newNode;
    }

}

void insertBeforeValue(node *header , int data , int value)
{
    int index = searchIndexOfValue(header , value);
    insertAt(header , data , index);
}



void updateFront(node *header , int data)
{
    if(header -> fLink == NULL)
        return;
    header -> fLink -> data = data;
}


void updateLast(node *header , int data)
{
    if(header -> fLink == NULL)
        return;
    node *ptr = header;
    while(ptr ->fLink !=NULL)
    {
        ptr = ptr -> fLink;
    }
    ptr -> data = data;
}

void updateAt(node *header , int data , int index)
{
    if(header -> fLink == NULL)
        return;
    node *ptr = header;
    int indexCheck = -1;


    while(indexCheck < index - 1 && ptr -> fLink != NULL)
    {
        indexCheck++;
        ptr = ptr -> fLink;
    }
    if(indexCheck +1 != index)
    {
        cout << "Invalid Index Or Data" << endl;
        return;
    }

    ptr -> fLink -> data = data;

}

void updateValue(node *header , int data , int value)
{
    if(header -> fLink == NULL)
        return;
    int index = searchIndexOfValue(header , value);
    updateAt(header , data , index);
}




void deleteFront(node *header)
{
    if(header -> fLink == NULL)
        return;
    node *ptr = header -> fLink;
    header -> fLink = ptr -> fLink;
    ptr -> fLink -> bLink = ptr -> bLink;
    free(ptr);
}

void deleteLast(node *header)
{
    if(header -> fLink == NULL)
        return;
    node *ptr = header;
    while(ptr ->fLink -> fLink !=NULL)
    {
        ptr = ptr -> fLink;
    }
    free(ptr ->fLink);
    ptr -> fLink = NULL;
}

void deleteAt(node *header , int index)
{
    if(header -> fLink == NULL)
        return;
    node *ptr = header;
    int indexCheck = -1;

    while(indexCheck < index - 1 && ptr -> fLink != NULL)
    {
        indexCheck++;
        ptr = ptr -> fLink;
    }
    if(indexCheck +1 != index)
    {
        cout << "Invalid Index Or Data" << endl;
        return;
    }

    node *temp = ptr -> fLink -> fLink;
    free(ptr -> fLink);
    ptr -> fLink = temp;
    temp -> bLink = ptr;
}

void deleteValue(node *header , int value)
{
    if(header -> fLink == NULL)
        return;
    int index = searchIndexOfValue(header , value);

    deleteAt(header , index);
}


void printList(node *header)
{
    node *ptr = header ->fLink;
    if(header ->fLink == NULL)
    {
        cout << "The List is Empty" << endl;
        return;
    }
    while(ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> fLink;
    }
    cout << endl;
}

int searchIndexOfValue(node *header , int data)
{
    node *ptr = header ->fLink;
    int index = 0;

    while(ptr -> data != data && ptr -> fLink != NULL)
    {
        index++;
        ptr = ptr -> fLink;
    }
    if(ptr -> data == data)
        return index;
    else
        return -1;
}



void freeAll(node *header)
{
    node *ptr = header;
    node *ptr2 = header -> fLink;

    while(ptr2 -> fLink != NULL)
    {
        free(ptr);
        ptr = ptr2;
        ptr2 = ptr2 -> fLink;
    }
    free(ptr2);
}

int optionList()
{
    cout << endl;
    cout <<"THESE ARE THE OPTIONS TO EDIT THE CURRENT DOUBLLY LINKED LIST" << endl;
    cout << "1 : Insert" << endl;
    cout << "2 : Update" << endl;
    cout << "3 : Delete" << endl;
    cout << "4 : Search" << endl;
    cout << "5 : Exit" << endl;

    cout << "Enter Option : ";
    int option;
    cin >> option;
    cout << endl;
    return option;
}

int optionListForAll()
{
    cout << "1 : Front" << endl;
    cout << "2 : Last" << endl;
    cout << "3 : At Index" << endl;
    cout << "4 : Value" << endl;
    cout << "Enter Option : ";
    int option;
    cin >> option;
    return option;
}

void insertOperation(node *header , int insertOption)
{

    if(insertOption == 1)
    {
        int data;
        cout << "Enter Data : ";
        cin >> data;
        insertFront(header , data);
    }
    else if(insertOption == 2)
    {
        int data;
        cout << "Enter Data : ";
        cin >> data;
        insertLast(header , data);
    }
    else if(insertOption == 3)
    {
        int data , index;
        cout << "Enter Data and Index : ";
        cin >> data >> index;
        insertAt(header , data , index);

    }
    else if(insertOption == 4)
    {
        int data , value;
        cout << "Enter Data and Value : ";
        cin >> data >> value;
        insertBeforeValue(header , data , value);
    }
    else
        cout << "Invalid Insert Option" << endl;
}

void updateOperation(node *header , int updateOption)
{

    if(updateOption == 1)
    {
        int data;
        cout << "Enter Data : ";
        cin >> data;
        updateFront(header , data);
    }
    else if(updateOption == 2)
    {
        int data;
        cout << "Enter Data : ";
        cin >> data;
        updateLast(header , data);
    }
    else if(updateOption == 3)
    {
        int data , index;
        cout << "Enter Data and Index : ";
        cin >> data >> index;
        updateAt(header , data , index);

    }
    else if(updateOption == 4)
    {
        int data , value;
        cout << "Enter Data and Value : ";
        cin >> data >> value;
        updateValue(header , data , value);
    }
    else
        cout << "Invalid Update Option" << endl;
}

void deleteOperation(node *header , int deleteOption)
{

    if(deleteOption == 1)
    {
        deleteFront(header);
    }
    else if(deleteOption == 2)
    {
        deleteLast(header);
    }
    else if(deleteOption == 3)
    {
        int index;
        cout << "Enter Index : ";
        cin >> index;
        deleteAt(header , index);

    }
    else if(deleteOption == 4)
    {
        int value;
        cout << "Enter Value : ";
        cin >> value;
        deleteValue(header , value);
    }
    else
        cout << "Invalid Update Option" << endl;
}

void insertAfterValue(node *header , int data , int value)
{
    node *ptr = header->fLink;
    while(ptr->data != value)
    {
        ptr = ptr->fLink;
    }

    node *newNode = (node * ) malloc(sizeof(struct node)); //
    if(newNode == NULL)
    {
        cout << "No New Memory left" << endl;
    }
    else
    {
        newNode -> data = data;
        newNode -> fLink = ptr -> fLink;
        ptr -> fLink = newNode;
    }
}
