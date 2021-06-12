#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *link;
};

void pushStack(node *header , char data);
void printList(node *header);
char popStack(node *header);
int evalution(char num1 , char num2 , char ch);

int main()
{
    char str[100];
    cout << "Enter Equation : " << endl;
    cin >> str;
    node *header;
    header = (node * ) malloc(sizeof(node)); //

    if(header == NULL)
    {
        cout << "Memory not available" << endl;
        return 0;
    }

    header ->data = 0;
    header ->link = header;

    for(int i = 0 ; i< strlen(str) ; i++)
    {
        if(str[i] == ')')
        {
            char num2 = popStack(header);
            char ch = popStack(header);
            char num1 = popStack(header);
            char dummyBracket = popStack(header);
            int res = evalution(num1 , num2 , ch);
            char res2 = res+48;
            //cout << num1 << " " << num2 << " " << ch << " " << dummyBracket << endl;
            pushStack(header , res2);
        }
        else
        {
            //cout << str[i] << endl;
            pushStack(header , str[i]);
        }
    }
    printList(header);
    //char res = popStack(header);
    cout << header -> link -> data << endl;
}

void pushStack(node *header , char data)
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


char popStack(node *header)
{
    if(header -> link == header)
    {
        cout << "The Stack Is Underflow" << endl;
        return '$';
    }
    else
    {
        node *ptr = header;
        while(ptr ->link -> link !=header)
        {
            ptr = ptr->link;
        }
        char data = ptr->link->data;
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

int evalution(char num1 , char num2 , char ch)
{
    if(ch == '+')
    {
        return (num1-48) + (num2-48);
    }
    else if(ch == '-')
    {
        return (num1-48) - (num2-48);
    }
    else if(ch == '*')
    {
        return (num1-48) * (num2-48);
    }
    else
    {
        return (int) (num1-48) / (num2-48);
    }
}
