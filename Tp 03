#include <stdio.h>
#include <stdlib.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node* next;
} Node;

Node* createEmptyList() {
    return NULL;
}

int isEmpty(Node* head) {
    return (head == NULL);
}

Node* insertAtBeginning(Node* head, Product p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    if (head == NULL) { 
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {  
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, Product p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

void displayProducts(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("ID: %d | Name: %s | Price: %d\n",
               temp->Prod.ID,
               temp->Prod.Name,
               temp->Prod.Price);
        temp = temp->next;
    } while (temp != head);
}
