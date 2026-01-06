#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct SNode {
    char data;
    struct SNode *next;
} SNode;

typedef struct QNode {
    char data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

SNode* push(SNode *top, char ch) {
    SNode *n = malloc(sizeof(SNode));
    n->data = ch;
    n->next = top;
    return n;
}

SNode* pop(SNode *top, char *ch) {
    if (!top) return NULL;
    *ch = top->data;
    SNode *tmp = top;
    top = top->next;
    free(tmp);
    return top;
}

void enqueue(Queue *q, char ch) {
    QNode *n = malloc(sizeof(QNode));
    n->data = ch;
    n->next = NULL;
    if (!q->rear) {
        q->front = q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
}

void dequeue(Queue *q, char *ch) {
    if (!q->front) return;
    QNode *tmp = q->front;
    *ch = tmp->data;
    q->front = tmp->next;
    if (!q->front) q->rear = NULL;
    free(tmp);
}

int main() {
    char text[200];
    SNode *top = NULL;
    Queue q;
    q.front = q.rear = NULL;

    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char c = toupper(text[i]);
            top = push(top, c);
            enqueue(&q, c);
        }
    }

    char s, qu;
    int ok = 1;

    while (top && q.front) {
        top = pop(top, &s);
        dequeue(&q, &qu);
        if (s != qu) {
            ok = 0;
            break;
        }
    }

    if (ok)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
