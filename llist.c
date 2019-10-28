#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void print_list(struct Node *llist) {
  if (llist == NULL) { //empty list
    printf("[ ]");
    return;
  }

  struct Node *current = llist;
  while (current != NULL) {
    printf("%d ", current -> i);
    current = current -> next;
  }

  printf(" |");
}

struct Node * insert_front(struct Node *llist, int i) {
  struct Node *front = malloc(sizeof(struct Node));
  front -> i = i;
  front -> next = llist;

  return llist;
}

struct Node *remove_node(struct Node *llist, int data) {
  struct Node *prev = NULL;
  struct Node *current = llist;
  while (current != NULL) {
    if (current -> i == data) {
      if (prev == NULL) { //case where the first element is removed - start of list is now the next struct
        printf("Data found; freeing the first node and setting the front to the next node. \n");
        struct Node *next = current -> next;
        free(current);
        return next;
      }

      printf("[%d] Data found; the node containing this data will now be freed. \n", current -> i);
      prev -> next = current -> next;
      free(current);
      return llist;
    }

    prev = current;
    current = current -> next;
  }

  //Couldn't find the data
  printf("Data not found; nothing has been changed. \n");
  return llist;
}
