#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;
typedef struct node node;
void createnode(int n);
void deleteBeg();
void deleteMid();
void DeleteEnd();
void display();

int main()
{
    int n;
    printf("Enter Number Of Node : ");
    scanf("%d", &n);

    createnode(n);
    display();
    deleteBeg();
    display();
    deleteMid();
    display();
    DeleteEnd();
    display();

    return 0;
}
void createnode(int n)
{
    node *temp,*newnode;

    head=(node*) malloc(sizeof(node));
    printf("Enter Data Of Node 1 : ");
    scanf("%d", &head->data);
    head->next=NULL;
    temp=head;

    for(int i=2; i<=n; i++)
    {
        newnode=(node*) malloc(sizeof(node));
        printf("Enter Data Of Node %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}

void deleteBeg()
{
    node *temp,*newnode;
    temp=head;
    head=temp->next;
    printf("After Deleting Beginning Node : \n");
    free(temp);
}

void deleteMid()
{
    node *temp,*prev,*current;
    int pos,i;
    printf("Position In Mid :");
    scanf("%d",&pos);
    temp=head;

    for(i=1; i<pos; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    free(current);
}

void DeleteEnd()
{
    node *temp,*newnode,*prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;
}

void display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
