//
// Created by Admin on 07/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void print(Node* head) {
    if (head == NULL) {
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node = createNode(2);
    head->next = node;
    node->prev = head;
    Node* node1 = createNode(3);
    node->next = node1;
    node1->prev = node;
    Node* node2 = createNode(4);
    node1->next = node2;
    node2->prev = node1;
    Node* node3 = createNode(5);
    node2->next = node3;
    node3->prev = node2;
    print(head);
    deleteAtEnd(head);
    print(head);
    return 0;
}