#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

void construct_list(struct LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

struct Node *construct_node(int key) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->next = NULL;
    return node;
}

void print_list(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node->next != list->tail) {
        printf("%d->", node->key);
        node = node->next;
    }
    printf("%d->", node->key);
    node = node->next;
    printf("%d\n", node->key);
}

void insert_tail(struct LinkedList *list, int key) {
    struct Node *node = construct_node(key);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = list->tail->next;
    }
}

void delete_tail(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node->next != list->tail)
        node = node->next;
    list->tail = node;
    list->tail->next = NULL;
}

// position is a key of node after which we are going to insert
void insert(struct LinkedList *list, int position, int key) {
    if (list->head == NULL || list->head->next == NULL)
        insert_tail(list, key);
    else {
        struct Node *node = list->head;
        while (node->key != position)
            node = node->next;
        struct Node *new_node = construct_node(key);
        struct Node *tmp = node->next;
        node->next = new_node;
        new_node->next = tmp;
    }
}

void delete(struct LinkedList *list, int position) {
    if (list->head->next == NULL)
        delete_tail(list);
    else {
        struct Node *node = list->head;
        while(node->next->key != position)
            node = node->next;
        node->next = node->next->next;
    }
}

int main() {
    struct LinkedList *list = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    construct_list(list);
    insert_tail(list, 0);
    insert_tail(list, 1);
    insert_tail(list, 2);
    insert_tail(list, 3);
    insert(list, 2, 5);
    delete_tail(list);
    delete(list, 1);
    print_list(list);
}
