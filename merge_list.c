#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* merge(Node* list1, Node* list2) {
    Node dummy, *tail = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        tail->next = (list1->data <= list2->data) ? list1 : list2;
        if (list1->data <= list2->data) list1 = list1->next;
        else list2 = list2->next;
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* createList(int* arr, int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }
    return head;
}

int main() {
    int arr1[] = {1, 3, 5, 7}, arr2[] = {2, 4, 6, 8};
    Node* mergedList = merge(createList(arr1, 4), createList(arr2, 4));
    printf("Merged List: \n");
    printList(mergedList);
    return 0;
}
