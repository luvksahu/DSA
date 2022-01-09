#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head,*nnode,*temp;
int counter=0,data=0;

void createNode()
{
    nnode=(struct Node*)malloc(sizeof(struct Node));

    printf("Enter data for node: ");
    scanf("%d",&data);
    nnode->prev=NULL;
    nnode->data=data;
    nnode->next=NULL;
    counter++;
}
void createList()
{
    int n=0;
    if(head!=NULL)
    {
        printf("List is already created\n");
        return;
    }
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    if(n<1)
    {
        printf("Invalid input\n");
        return;
    }
    createNode();
    head=nnode;
    temp=head;
    while(counter<n)
    {
        createNode();
        nnode->prev=temp;
        temp->next=nnode;
        temp=temp->next;
    }
}
void traverseFromHead()
{
    temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("Length: %d\n",counter);
}
void traverseFromTail()
{
    temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("Length: %d\n",counter);
}
void insertNode()
{
    temp=head;
    int key=0;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter index for new node: ");
    scanf("%d",&key);
    for(int i=2;i<=key;i++)
    {
        temp=temp->next;
        if(temp==NULL)
            break;
    }
    if(temp!=NULL)
    {
        createNode();
        if(key==0)
        {
            head=nnode;
            head->next=temp;
            temp->prev=head;
        }
        else
        {
            nnode->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=nnode;
            nnode->prev=temp;
            temp->next=nnode;
        }
    }
    else
        printf("Cannot insert node at given position\n");
}
void deleteNode()
{
    struct Node *toDelete=head;
    int key=0;
    if(head==NULL)
    {
        printf("List is already empty\n");
        return;
    }
    printf("Enter index of node to be deleted: ");
    scanf("%d",&key);
    for(int i=1;i<=key;i++)
    {
        toDelete=toDelete->next;
        if(toDelete==NULL)
            break;
    }
    if(toDelete!=NULL)
    {
        if(toDelete==head)
        {   if(head->next==NULL)
                head=NULL;
            else
            {
                head->next->prev=NULL;
                head=head->next;
                toDelete->next=NULL;
            }                                  
        }
        else
        {
            toDelete->prev->next=toDelete->next;
            if(toDelete->next!=NULL)
                toDelete->next->prev=toDelete->prev;
            toDelete->prev=NULL;
            toDelete->next=NULL;
        }
        counter--;
        printf("Successfully deleted %d from list\n",toDelete->data);
        free(toDelete);
    }
    else
        printf("Invalid input\n");
}
int main()
{   
    int check=0;
    do
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("Press 1 to create List\n");
        printf("Press 2 to display List in forward direction\n");       
        printf("Press 3 to display List in backward direction\n");       
        printf("Press 4 for Insertion\n");
        printf("Press 5 for Deletion\n");
        printf("Press 6 to exit\n");
        printf("Enter your Choice : ");
        scanf("%d",&check);
        switch (check)
        {
        case 1: createList();
            break;
        case 2: traverseFromHead();
            break;
        case 3: traverseFromTail();
            break;
        case 4: insertNode();
            break;
        case 5: deleteNode();
            break;
        case 6: break;
        default: printf("Invalid input");
            break;
        }
    }while(check!=6);
    return 0;
}
