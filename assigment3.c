#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* addTwoNumbers(Node* list1, Node* list2) {
    Node *result = NULL, *tail = NULL;
    int carry = 0;
    while (list1 || list2 || carry) {
        int sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        carry = sum / 10;
        Node* newNode = createNode(sum % 10);
        if (!result) result = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }
    return result;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *list1 = createNode(1), *list2 = createNode(2);
    list1->next = createNode(4); list1->next->next = createNode(8);
    list2->next = createNode(7); list2->next->next = createNode(0);

    Node* sumList = addTwoNumbers(list1, list2);
    printf("Sum stored in a doubly linked list: ");
    printList(sumList);

    return 0;
}
