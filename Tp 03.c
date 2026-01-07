#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

Node* createEmptyList() {
    return NULL;
}

int isEmpty(Node *head) {
    return head == NULL;
}

Node* createNode(Product p) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->Prod = p;
    n->next = NULL;
    return n;
}

Node* insertAtBeginning(Node *head, Product p) {
    Node *n = createNode(p);
    if (head == NULL) {
        n->next = n;
        return n;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    n->next = head;
    temp->next = n;
    return n;
}

Node* insertAtEnd(Node *head, Product p) {
    Node *n = createNode(p);
    if (head == NULL) {
        n->next = n;
        return n;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
    return head;
}

void displayProducts(Node *head) {
    if (head == NULL)
        return;
    Node *temp = head;
    do {
        printf("ID: %d | Name: %s | Price: %d\n",
               temp->Prod.ID,
               temp->Prod.Name,
               temp->Prod.Price);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node *head = createEmptyList();

    Product p1 = {10, "Laptop", 180};
    Product p2 = {20, "Mouse", 45};
    Product p3 = {30, "Keyboard", 95};
    Product p4 = {40, "screen", 370};

    head = insertAtEnd(head, p3);
    head = insertAtBeginning(head, p2);
    head = insertAtEnd(head, p4);
    head = insertAtBeginning(head, p1);

    displayProducts(head);

    return 0;
}
