#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "queue"
#define maxNameSize 10


using namespace std;

struct node
{
    int index, data;
    char name[maxNameSize];
    struct node *leftChild, *rightChild;
};

typedef struct node node;
node *root;
int height = 0;
int nodeIndexNum=0;

void createTree();
void traverseInOrder(node *root);
void traverseInLevelOrder(node *root);
void traversePreOrder(node *root , int tab);

int main()
{
    //freopen("binaryTreeInput.txt", "r", stdin);

    createTree();

    printf("\n\n");
    cout << "IN ORDER DISPLAY : ";
    traverseInOrder(root);

    printf("\n\n");
    cout << "LEVEL ORDER DISPLAY : ";
    traverseInLevelOrder(root);
    cout << endl;
    cout << height << endl;

    printf("\n\n");
    cout << "PRE ORDER DISPLAY : \n";
    traversePreOrder(root , 1);
    return 0;
}

void createTree()
{
    printf("Entry for tree root:\n");

    root = (node *)malloc(sizeof(node));
    root->index=nodeIndexNum++;
    //printf("Enter root name: ");
    //gets(root->name);
    printf("Enter root value: ");
    scanf("%d",&root->data);
    root->leftChild=NULL;
    root->rightChild=NULL;


    printf("Enter nodes: \n");

    int tempData;
    node *currentNode, *parentNode;
    while(1)
    {
        //printf("Enter node value: (Enter %d to finish entry)\n",root->data);
        scanf("%d", &tempData);
        if(tempData==root->data)
        {
            break;
        }

        currentNode = (node*)malloc(sizeof(node));
        currentNode->data=tempData;
        currentNode->index=nodeIndexNum++;
        currentNode->leftChild=NULL;
        currentNode->rightChild=NULL;

        parentNode = root;
        //cout << tempData << "\t";
        while(1)
        {
            if(currentNode->data < parentNode->data)
            {
                if(parentNode->leftChild == NULL)
                {
                    parentNode->leftChild = currentNode;
                    break;
                }
                else
                {
                    parentNode = parentNode->leftChild;
                }
            }
            else
            {
                if(parentNode->rightChild == NULL)
                {
                    parentNode->rightChild = currentNode;
                    break;
                }
                else
                {
                    parentNode = parentNode->rightChild;
                }
            }
        }

    }
}

void traverseInOrder(node *root)
{
    if(root != NULL)
    {
        traverseInOrder(root ->leftChild);
        cout << root->data << " ";
        traverseInOrder(root ->rightChild);
    }
}

void traversePreOrder(node *root , int tab)
{
    if(root != NULL)
    {
        int tab2 = 1;
        for(int i = 0 ; i < tab ; i++)
        {
            if(i!=0)
            cout << "\t";
            tab2++;
        }
        cout << root->data << endl;

        traversePreOrder(root ->leftChild , tab2);
        traversePreOrder(root ->rightChild , tab2);
    }
}

void traverseInLevelOrder(node *root)
{
    queue <node*> q;

    q.push(root);
    height++;
    while(!q.empty())
    {

        node *temp = q.front();
        q.pop();
        if(temp != NULL)
        {
            //height++;
            cout << temp->data << " ";
            q.push(temp->leftChild);
            q.push(temp->rightChild);
        }
    }


}
