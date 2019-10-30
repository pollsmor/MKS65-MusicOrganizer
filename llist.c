#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct song_node * insert_front(struct song_node *llist, char name[], char artist[]) {
  struct song_node *front = malloc(sizeof(struct song_node));
  strncpy(front -> name, name, 100);
  strncpy(front -> artist, artist, 100);
  front -> next = llist;

  return front;
}

//Alphabetical first by artist then by song
struct song_node * insert_in_order(struct song_node *llist, char name[], char artist[]) {
  //Fill node with appropriate data, besides what the  next node is
  struct song_node *node = malloc(sizeof(struct song_node));
  strncpy(node -> name, name, 100);
  strncpy(node -> artist, artist, 100);

  struct song_node *current = llist;

  if (current == NULL) { //case where list is empty
    current = node;
    current -> next = NULL;
    return current; //return front of list
  }

  while (current != NULL) {
    struct song_node *next = current -> next;


    current = next;
  }

  //Case where a song is at the end of the list
  current -> next = node;
  return llist; //return front of list
}

int lenOfList(struct song_node *llist) {
  struct song_node *current = llist;
  int i = 0; //for counting the songs in the list
  while (current != NULL) {
    i++;
    current = current -> next;
  }

  return i;
}

struct song_node *random_song(struct song_node *llist) {
  int len = lenOfList(llist);
  int randIdx = rand() % len;
  int i = 0;

  struct song_node *current = llist;
  while (i++ != randIdx) {
    current = current -> next;
  }

  return current;
}

void print_node(struct song_node *node) {
  if (node == NULL) { //empty node
    printf("[ ]");
    return;
  }

  printf("\"%s\" by %s \n", node -> name, node -> artist);
}

struct song_node *remove_song(struct song_node *llist, char name[], char artist[]) {
  struct song_node *prev = NULL;
  struct song_node *current = llist;

  while (current != NULL) {
    if (strcmp(artist, current -> artist) == 0) {
      while (strcmp(artist, current -> artist) == 0) {
        if (strcmp(name, current -> name) == 0) {
          printf("Removing \"%s\" by %s \n", current -> name, current -> artist);

          if (prev == NULL) { //case where song is at the start of the list
            struct song_node *next = current -> next;
            free(current);
            return next;
          }

          prev -> next = current -> next;
          free(current);
          return llist;
        }

        prev = current;
        current = current -> next;
      }

    //Couldn't find the song
    printf("Song not found; nothing has been removed. \n");
    return llist;
  }

    prev = current;
    current = current -> next;
  }

  //Couldn't find the artist
  printf("Artist not found; nothing has been removed. \n");
  return llist;
}

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
