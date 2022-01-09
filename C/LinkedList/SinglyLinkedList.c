#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*nnode=NULL,*temp=NULL;
int counter=0, data=0;

void createNode()
{
    nnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter data for node: ");
    scanf("%d",&data);

    nnode->data=data;
    nnode->next=NULL;
    counter++;
}
void createList()
{
    nnode=NULL,temp=NULL;
    data=0;
    int n;
    if(head!=NULL)
    {
        printf("List is already created\n");
        return;
    }
    printf("Enter the number of nodes: ");
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
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("Length: %d\n",counter);
}
void insertNode()
{
    nnode=NULL,temp=head;
    int position=0;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter position for insertion of new node: ");
    scanf("%d",&position);
    for(int i=2;i<=position;i++)
    {
        temp=temp->next;
        if(temp==NULL)
            break;
    }
    
    if(temp!=NULL)
    {
        createNode();
        if(position==0)
        {
            head=nnode;
            head->next=temp;
        }
        else 
        {
            nnode->next=temp->next;
            temp->next=nnode;           
        }
    }
    
    else    
        printf("Cannot insert data at given position\n"); 
    
}

void deleteNode()
{
    struct node *toDelete=head,*prevNode=head;
    int key;
    if(head==NULL)
    {
        printf("List is already empty\n");
        return;
    }
    printf("Enter index of element to be deleted: ");
    scanf("%d",&key);
    for(int i=0;i<key;i++)
    {        
        prevNode=toDelete;
        toDelete=toDelete->next;
        if(toDelete==NULL)
            break;
    }
    if(toDelete!=NULL)
    {
        if(toDelete==head)
        {
            if(head->next==NULL)
                head=NULL;
            else
                head=head->next;
        }
        else
            prevNode->next=toDelete->next;
         
        toDelete->next=NULL;
        counter--; 
        printf("Successfully deleted %d from list.\n",toDelete->data);
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
        printf("\n--- Singly Linked List ---\n");
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