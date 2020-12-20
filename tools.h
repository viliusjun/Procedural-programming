#ifndef __TOOLS_H_
#define __TOOLS_H_

struct Node { 
    int element; 
    struct Node *next; 
    struct Node *previous;
};

void insert_at_the_end(struct Node **list_tail, struct Node **list_head, int new_element);
void insert_at_the_beginning(struct Node **list_head, struct Node **list_tail, int new_element);
void print_list(struct Node *node);
void print_list_from_behind(struct Node *node);
void destroy_list(struct Node *list_head);

#endif