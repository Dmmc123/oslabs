#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
} node_t;

void print_list(node_t *);
void insert_node(node_t *, int);
void delete_node(node_t **, int);

int main(){
    node_t * head = (node_t *)malloc(sizeof(node_t));
    head->value = 1;
    insert_node(head, 2);
    insert_node(head, 3);
    insert_node(head, 4);
    print_list(head);
    delete_node(&head, 1); //should remove 2
    print_list(head); // 1 3 4
    delete_node(&head, 2); //should remove 4
    print_list(head); // 1 3
    delete_node(&head, 0); // should remove 1
    print_list(head); //  3
    return 0;
}

void print_list(node_t * head) {
    node_t * iterator = head;
    do printf("%d ", iterator->value);
    while ((iterator = iterator->next) != NULL);
    printf("\n");
}
void insert_node(node_t * head, int value) {
    node_t * temp = (node_t *)malloc(sizeof(node_t));
    temp->value = value;
    node_t * iterator = head;
    while (iterator->next != NULL) iterator = iterator->next;
    iterator->next = temp;
}
void delete_node(node_t ** head, int pos) {
    pos = (pos < 0) ? 0 : pos;
    if (pos == 0) {
        node_t * next = NULL;
        next = (*head)->next;
        free(*head);
        *head = next;
    }
    else {
        node_t * iterator = * head;
        node_t * temp = NULL;
        while(--pos > 0 && (iterator = iterator->next) != NULL);
        temp = iterator->next;
        iterator->next = temp->next;
        free(temp);
    }
}
