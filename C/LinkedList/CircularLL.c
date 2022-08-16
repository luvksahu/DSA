#include <stdio.h>
#include <stdlib.h>

struct Node
{
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
    nnode->data=data;
    nnode->next=head;
    counter++;
}
void createList()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    if(n<1)
    {
        printf("Invalid input\n");
        return;
    }
    if(head!=NULL)
    {
        printf("List is already created\n");
        return;
    }
    createNode();
    head=nnode;
    // head->next=head;
    temp=head;
    while(counter<n)
    {
        createNode();
        temp->next=nnode;
        temp=temp->next;
    }
}
void traverseList()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("%d ",head->data);
    if(head->next!=NULL)
        temp=head->next;
    while(temp!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("Length: %d\n",counter);
}
void insertNode()
{
    temp=head;
    int t,key;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter index for insertion of new node: ");
    scanf("%d",&key); 
    if(key>counter)
    {
        printf("Cannot insert data at given position\n");
        return;
    }
    for(int i=2;i<=key;i++)
        temp=temp->next;
    createNode();
    nnode->next=temp->next;
    temp->next=nnode;
    if(key==0)
    {
        t=nnode->data;
        nnode->data=head->data;
        head->data=t;
    }  
}
void deleteHead()
{
    struct Node *prev=head,*toDelete=head->next;
    while(toDelete!=head)
    {
        prev=toDelete;
        toDelete=toDelete->next;
    }
    prev->next=toDelete->next;
    head=head->next;
    toDelete->next=NULL;
    if(toDelete==head)
        head=NULL;
    printf("Succesfully deleted %d from list\n",toDelete->data);
    free(toDelete);
    counter--;
}
void deleteNode()
{
    struct Node *prev=NULL,*toDelete=head;
    int key;
    if(head==NULL)
    {
        printf("List is already empty\n");
        return;
    }
    printf("Enter index for deletion of node: ");
    scanf("%d",&key);
    if(key>=counter)
    {
        printf("Invalid position\n");
        return;
    }
    if(key==0)
    {
        deleteHead();
        return;
    }
    for(int i=1;i<=key;i++)
    {
        prev=toDelete;
        toDelete=toDelete->next;
    }
    prev->next=toDelete->next;
    toDelete->next=NULL;
    printf("Succesfully deleted %d from list\n",toDelete->data);
    free(toDelete);
    counter--;
}
int main()
{
    int check=0;
    do
    {
        printf("\n--- Circular Linked List ---\n");
        printf("Press 1 to create List\n");
        printf("Press 2 to display List\n");       
        printf("Press 3 for Insertion\n");
        printf("Press 4 for Deletion\n");
        printf("Press 5 to exit\n");
        printf("Enter your Choice : ");
        scanf("%d",&check);
        switch (check)
        {
        case 1: createList();
            break;
        case 2: traverseList();
            break;
        case 3: insertNode();
            break;
        case 4: deleteNode();
            break;
        case 5: break;
        default: printf("Invalid input");
            break;
        }
    }while(check!=5);
    return 0;
}