/*********************************************************
 *           Created by manparvesh on 2/6/18.
 *********************************************************/

#include <stdio.h>
#include <assert.h>
#include "linked_list/singly_linked_list.h"

void test_simple() {
    struct linked_list *list;
    list = create_new_list();

    assert(0 == get_length(list));

    append_to_list(&list, 1);
    assert(1 == get_length(list));
    print_list(list);

    append_to_list(&list, 2);
    assert(2 == get_length(list));
    print_list(list);

    prepend_to_list(&list, 3);
    assert(3 == get_length(list));
    assert(3 == get_value_at_position(list, 0));
    assert(1 == get_value_at_position(list, 1));
    assert(2 == get_value_at_position(list, 2));
    assert(-1 == get_value_at_position(list, 3));
    print_list(list);

    free(list);
}

void test_with_unitialized_list() {
    struct linked_list *list = NULL;
    assert(0 == get_length(list));
    assert(-1 == get_value_at_position(list, 1));

    // since our linked list is not initialized,
    // our method will automatically initialize it
    // and then append
    append_to_list(&list, 1);
    assert(1 == get_length(list));
    assert(1 == get_value_at_position(list, 0));
    print_list(list);

    delete_at_position(&list, 0);
    assert(0 == get_length(list));
    // append_to_list(&list, 1);
    // append_to_list(&list, 2);
    // append_to_list(&list, 3);
    // delete_at_position(&list, 1);
    // assert(3 == get_length(list));
    // print_list(list);

    free(list);
}

int main() {
    // test_simple();
    test_with_unitialized_list();
}