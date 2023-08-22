//zahed01x
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void createNode(int n);
void insertBeginning();
void displayList();

int main() {
    int n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    createNode(n);
    insertBeginning();
    displayList();
    
    return 0;
}

void createNode(int n) {
    Node *newNode, *temp;
    
    head = (Node *)malloc(sizeof(Node));
    
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    
    for (int i = 2; i <= n; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = temp->next;
    }
}

void insertBeginning() {
    Node *newNode;
    
    newNode = (Node *)malloc(sizeof(Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    printf("Enter data for the new node at the beginning: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void displayList() {
    //Node *temp = head;
    
    printf("Linked List: ");
    
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    
    printf("NULL\n");
}
