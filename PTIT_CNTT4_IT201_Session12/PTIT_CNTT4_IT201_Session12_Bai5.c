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

int length(Node* head) {
    int count = 0;
    if (head == NULL) {
        return 0;
    }
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

Node* deleteNodeValue(Node* head, int value) {
   Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        if (current->data == value) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }else {
               current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            current = current->next;
            free(temp);
        }else {
            current = current->next;
        }
    }

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
    Node* node2 = createNode(5);
    node1->next = node2;
    node2->prev = node1;
    Node* node3 = createNode(5);
    node2->next = node3;
    node3->prev = node2;
    print(head);
    int value;
    scanf("%d", &value);
    head = deleteNodeValue(head, value);
    print(head);
    return 0;
}