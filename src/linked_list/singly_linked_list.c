/*********************************************************
 *           Created by manparvesh on 2/6/18.
 *********************************************************/

#include "singly_linked_list.h"

// remove the comment below to enable debug mode
// #define DEBUG
#include "../util/logger.c"

/*********************************************************
 *                  private methods
 *********************************************************/

/**
 * creates and returns a new node with the given value
 * */
struct Node *get_new_node(int value) {
    struct Node *node;
    node = (struct Node *) malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = value;
    return node;
}

/*********************************************************
 *            public method implementations
 *********************************************************/

/**
 * returns a new linked list
 * */
struct linked_list *create_new_list() {
    struct linked_list *new_linked_list;
    new_linked_list = malloc(sizeof(struct linked_list));
    new_linked_list->head = NULL;
    return new_linked_list;
}

/**
 * adds an element to the end of list
 * */
void append_to_list(struct linked_list **list, int value) {
    if (*list == NULL) {
        LOG(WARN, __FILE__, __FUNCTION__, "The list is not initialized");
        *list = create_new_list();
    }
    struct Node *head = (*list)->head;
    struct Node *node_to_be_added = get_new_node(value);
    if (head == NULL) {
        head = node_to_be_added;
    } else {
        head->next = node_to_be_added;
    }
    (*list)->head = head;
}

/**
 * adds an element to the beginning of list
 * */
void prepend_to_list(struct linked_list **list, int value) {
    if (*list == NULL) {
        LOG(WARN, __FILE__, __FUNCTION__, "The list is not initialized");
        *list = create_new_list();
    }
    struct Node *head = (*list)->head;
    struct Node *node_to_be_added = get_new_node(value);
    node_to_be_added->next = head;
    (*list)->head = node_to_be_added;
}

/**
 * get length of the list
 * */
int get_length(struct linked_list *list) {
    if (list == NULL) {
        LOG(WARN, __FILE__, __FUNCTION__, "The list is not initialized");
        return 0;
    }
    struct Node *head = list->head;
    struct Node *current_node = head;
    int length = 0;
    while (current_node != NULL) {
        length++;
        current_node = current_node->next;
    }
    return length;
}

/**
 * print contents of list
 * */
void print_list(struct linked_list *list) {
    struct Node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

/**
 * delete the complete list
 * */
void delete_list(struct linked_list **list) {
    // todo
}

/**
 * delete a node at a given position
 * */
void delete_at_position(struct linked_list **list, int position) {
    if (list == NULL){
        LOG(WARN, __FILE__, __FUNCTION__, "The list is not initialized");
        return;
    }
    struct Node *head = (*list)->head;
    struct Node *current_node = head;
    if(current_node == NULL){
        return;
    }
    if (position == 0){
        (*list)->head = (*list)->head->next;
        return;
    }
    int pos = 0;
    while (current_node->next != NULL && pos < position){
        current_node->next = current_node->next->next;
        pos++;
    }
    if (pos  == position && current_node->next != NULL) {
        current_node = current_node->next->next;
    }
    // todo this implementation is incomplete
    (*list)->head = head;
}

int get_value_at_position(struct linked_list *list, int position) {
    if (list == NULL){
        LOG(WARN, __FILE__, __FUNCTION__, "The list is not initialized");
        return -1;
    }
    struct Node *current_node = list->head;
    while (position--){
        if (current_node == NULL){
            return -1;
        }
        current_node = current_node->next;
    }
    if (current_node == NULL || position > -1){
        return -1;
    }
    return current_node->data;
}
