#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;

}*head,*temp;

typedef struct node node;
/*void display();
void createnode(int n);
void deleteBeg();
void deleteMid();
void deleteEnd();*/
int main()
{
    int n;
    printf("Enter Number A Node : ");
    scanf("%d", &n);

    createnode(n);
    display();
    deleteBeg();
    display();
    deleteMid();
    display();
    deleteEnd();
    display();

    return 0;
}

void createnode(n)
{
    node *newnode;
    head=(node*) malloc (sizeof(node));
    printf("Enter Node 1 : ");
    scanf("%d", &head->data);
    head->prev=NULL;
    head->next=NULL;
    temp=head;

    for(int i=2; i<=n; i++)
    {
        newnode=(node*) malloc (sizeof(node));
        printf("Enter Node %d : ", i);
        scanf("%d", &newnode->data);
        newnode->prev=temp;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}


void deleteBeg()
{
    temp=head;
    head=temp->next;
    free(temp);
}

void deleteMid()
{
    node *prev,*current,*newnode;
    int pos;
    printf("Enter Position : ");
    scanf("%d", &pos);
    temp=head;
    for(int i=1; i<pos; i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    free(current);
}

void deleteEnd()
{
    node *prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);

}
void display()
{
    node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
