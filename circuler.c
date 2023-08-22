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
void displayList();

int main() {
    int n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    createNode(n);
    displayList();
    
    return 0;
}

void createNode(int n) {
    Node *newNode, *temp;
    
    head = (Node *)malloc(sizeof(Node));
    
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
    // Make the last node point back to the head to form a circular linked list
    temp->next = head;
}

void displayList() {
    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
