/*********************************************************
 *           Created by manparvesh on 2/6/18.
 *********************************************************/

#ifndef CSTLMP_SINGLY_LINKED_LIST_H
#define CSTLMP_SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct linked_list {
    struct Node *head;
};

/**
 * returns a new linked list
 * */
struct linked_list *create_new_list();

/**
 * adds an element to the end of list
 * */
void append_to_list(struct linked_list **list, int value);

/**
 * adds an element to the beginning of list
 * */
void prepend_to_list(struct linked_list **list, int value);

/**
 * get length of the list
 * */
int get_length(struct linked_list *list);

/**
 * print contents of list
 * */
void print_list(struct linked_list *list);

/**
 * delete the complete list
 * */
void delete_list(struct linked_list **list);

/**
 * delete a node at a given position
 * */
void delete_at_position(struct linked_list **list, int position);

int get_value_at_position(struct linked_list *list, int position);

#endif //CSTLMP_SINGLY_LINKED_LIST_H
