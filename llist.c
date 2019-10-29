#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void print_list(struct song_node *llist) {
  if (llist == NULL) { //empty list
    printf("[ ]");
    return;
  }

  struct song_node *current = llist;
  int i = 0; //for counting the songs in the list
  while (current != NULL) {
    printf("%d. \"%s\" by %s \n", i++, current -> name, current -> artist);
    current = current -> next;
  }
}

struct song_node * insert_front(struct song_node *llist, char const *name, char const *artist){
  struct song_node *front = malloc(sizeof(struct song_node));
  front -> name = name;
  front -> artist = artist;
  front -> next = llist;

  return front;
}

/*
struct song_node *remove_song_node(struct song_node *llist, int data) {
  struct song_node *prev = NULL;
  struct song_node *current = llist;
  while (current != NULL) {
    if (current -> i == data) {
      if (prev == NULL) { //case where the first element is removed - start of list is now the next struct
        printf("Data found; freeing the first song_node and setting the front to the next song_node. \n");
        struct song_node *next = current -> next;
        free(current);
        return next;
      }

      printf("[%d] Data found; the song_node containing this data will now be freed. \n", current -> i);
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
*/

struct song_node * free_list(struct song_node *llist) {
  struct song_node *current = llist;
  while (current != NULL) {
    struct song_node *next = current -> next;
    printf("Freeing node containing song: \"%s\" by %s \n", current -> name, current -> artist);
    free(current);
    current = next;
  }

  llist = NULL;

  return llist;
}
