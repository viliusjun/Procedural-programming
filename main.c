// Vilius Junevičius, group 4, software engineering
// viliusjunevicius@mif.stud.vu.lt

// Create a doubly linked list. Write a function that deletes the smallest value node.

/*
2020-12-15
coding standard should not have bad examples
There should also be a pointer list_tail for inserting at the end of the list
The function that deletes the smallest node should be only one function, not multiple functions
The function that deletes the smallest node should not be in the header file
*/

/*
2020-12-22
If there are multiple values of the smallest values, then remove all of them, not only the first smallest value in the dll
*/


#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void delete_the_smallest_node(struct Node **list_head, struct Node **list_tail);

int main(){
    struct Node *list_head = NULL; // we inicialize the doubly linked list's head
    struct Node *list_tail = NULL; // we inicialiaze the doubly linked list's tail
    int value;
    int flag = 0;

    while (flag != 3){
        printf("Enter 1 for inserting a value at the end of the doubly linked list\n");
        printf("Enter 2 for inserting a value at the beginning of the doubly linked list\n");
        printf("Enter 3 for the finished linked list\n");
        scanf("%d", &flag);
        if (flag == 1){
            printf("Input the value you want to insert into the the end of the dll\n");
            scanf("%d", &value);
            insert_at_the_end(&list_tail, &list_head, value);
        }
        if (flag == 2){
            printf("Input the value you want to insert into the the beginning of the dll\n");
            scanf("%d", &value);
            insert_at_the_beginning(&list_head, &list_tail, value);
        }
    }
    print_list(list_head);
    print_list_from_behind(list_tail);

    printf("\nAfter removing the smallest element from the dll,");
    delete_the_smallest_node(&list_head, &list_tail);
    print_list(list_head);

    destroy_list(list_head);

    return 0;
}