#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

// Function that inserts a new node at the end of the dll
void insert_at_the_end(struct Node **list_tail, struct Node **list_head, int new_element){
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node)); 
    
    new_node->element = new_element;
    new_node->next = NULL;

    if ((*list_head) == NULL){ 
        (*list_head) = new_node; 
        (*list_tail) = new_node; 
        (*list_head)->previous = NULL; 
        return; 
    }

    new_node->previous = (*list_tail);

    if((*list_tail) != NULL){
        (*list_tail)->next = new_node;
    }
  
    (*list_tail) = new_node;
  
    return; 
} 

// Function that inserts a new node at the front of the dll
void insert_at_the_beginning(struct Node **list_head, struct Node **list_tail, int new_element){
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    new_node->element = new_element;
    new_node->previous = NULL;

    if ((*list_tail) == NULL){ 
        (*list_head) = new_node; 
        (*list_tail) = new_node; 
        (*list_head)->previous = NULL; 
        return; 
    }

    new_node->next = (*list_head);

    if ((*list_head) != NULL){
        (*list_head)->previous = new_node; 
    }
  
    (*list_head) = new_node; 

    return;
} 

// Function that prints out the dll
void print_list(struct Node *node){
    struct Node *current; 

    printf("\nThe doubly linked list has these elements:\n"); 
    while (node != NULL){ 
        printf(" %d ", node->element); 
        current = node; 
        node = node->next; 
    } 
    printf("\n");
}

// Function that prints out the dll from behind
void print_list_from_behind(struct Node *node){
    struct Node *current; 

    printf("\nThe doubly linked list has these element in reverse order:\n"); 
    while (node != NULL){ 
        printf(" %d ", node->element); 
        current = node; 
        node = node->previous; 
    } 
    printf("\n");
}

// Function that deletes the smallest node in the dll
void delete_the_smallest_node(struct Node **list_head){
    if (*list_head == NULL){
        return;
    }

    struct Node *current = *list_head;

    int min, position;
    min = (*list_head)->element;
    position = 1;

    for (int i = 1; current != NULL; ++i){
        if (min > current->element){
            min = current->element;
            position = i;
        } 
        current = current->next;  
    }
 
    struct Node *del = *list_head;

    for (int i = 1; del != NULL && i < position; ++i){
        del = del->next;
    }
 
    if (del == NULL){
        return;
    }
    
    // if we are deleting the head node, then head starts pointing to the next node
    if (*list_head == del){
        *list_head = del->next;
    }

    // We have to change the next pointer only if we are not deleting the last node
    if (del->next != NULL){
        del->next->previous = del->previous;
    }
    
 
    // We have to change the previous pointer only if we are not deleting the first node
    if (del->previous != NULL){
        del->previous->next = del->next;
    }
 
    free(del);

    return;
}

// Function that destroys all of the dll
void destroy_list(struct Node *list_head){

    if(list_head == NULL){
        return;
    }

    destroy_list(list_head->next);
    free(list_head);

    return;
}