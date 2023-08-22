//zahed01x
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;
node* head;

node* Create(int data) {
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void display() {
    node* temp = head;
    do {
        printf("Data for node: %d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void insert_beg(int data) {
    node* newNode = Create(data);
    newNode->next = head;
    
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    
    head = newNode;
}

void insert_end(int data) {
    node* newNode = Create(data);
    
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    
    newNode->next = head;
}

int main() {
    node* node2, *node3;
    head = Create(1);
    node2 = Create(2);
    node3 = Create(3);
    
    head->next = node2;
    node2->next = node3;
    node3->next = head;
    
    printf("Original circular linked list:\n");
    display();
    
    insert_beg(0);
    printf("\nCircular linked list after inserting at beginning:\n");
    display();
    
    insert_end(4);
    printf("\nCircular linked list after inserting at end:\n");
    display();

    return 0;
}