#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

//Helper function
int songcmp(struct song_node *song1, struct song_node *song2) {
  printf("Comparing \"%s\" by %s to \"%s\" by %s \n", song1 -> name, song1 -> artist, song2 -> name, song2 -> artist);

  if (strcmp(song1 -> artist, song2 -> artist) == 0) {
    printf("%d \n", strcmp(song1 -> name, song2 -> name));
    return strcmp(song1 -> name, song2 -> name);
  }

  printf("%d \n", strcmp(song1 -> artist, song2 -> artist));
  return strcmp(song1 -> artist, song2 -> artist);
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

  if (llist == NULL) { //case where list is empty
    llist = node;
    llist -> next = NULL;
    return llist; //return front of list
  }

  struct song_node *current = llist;
  struct song_node *next = NULL;

  while (songcmp(node, current) < 0) {
    next = current -> next;

    if (next == NULL) { //reached end of list
      if (current == llist) { //case where there is only 1 element
        node -> next = current;
        return node;
      }

      current -> next = node;
      node -> next = NULL;
      return llist;
    }

    current = next;
  }

  //Location of song found
  printf("%s \n", name);
  next = current -> next;
  current -> next = node;
  node -> next = next;
  return llist; //return front of list
}

void print_list(struct song_node *llist) {
  if (llist == NULL) { //empty list
    printf("[ ] \n");
    return;
  }

  struct song_node *current = llist;
  int i = 0; //for counting the songs in the list
  while (current != NULL) {
    printf("%d. \"%s\" by %s \n", i++, current -> name, current -> artist);
    current = current -> next;
  }
}

void print_node(struct song_node *node) {
  if (node == NULL) { //empty node
    printf("[ ] \n");
    return;
  }

  printf("\"%s\" by %s \n", node -> name, node -> artist);
}

struct song_node *find_song(struct song_node *llist, char name[], char artist[]) {
  printf("Looking for \"%s\" by %s: \n", name, artist);
  struct song_node *current = llist;

  while (current != NULL) {
    if (strcmp(current -> artist, artist) == 0) {
      if (strcmp(current -> name, name) == 0) {
        printf(" >> Song found: ");
        return current;
      }
    }

    current = current -> next;
  }

  printf(" >> Song not found: ");
  return NULL;
}

struct song_node *find_artist(struct song_node *llist, char artist[]) {
  printf("Looking for the first song by %s: \n", artist);
  struct song_node *current = llist;

  while (current != NULL) {
    if (strcmp(current -> artist, artist) == 0) {
      printf(" >> Artist found! \n");
      return current;
    }

    current = current -> next;
  }

  printf(" >> Artist not found: ");
  return NULL;
}

int lenOfList(struct song_node *llist) { //helper function for random_song
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

struct song_node *remove_song(struct song_node *llist, char name[], char artist[]) {
  struct song_node *prev = NULL;
  struct song_node *current = llist;

  while (current != NULL) {
    if (strcmp(current -> artist, artist) == 0) {
      if (strcmp(current -> name, name) == 0) {
        printf("Removing \"%s\" by %s \n", current -> name, current -> artist);

        if (prev == NULL) { //case where the song is at the start of the list
          struct song_node *next = current -> next;
          free(current);
          return next;
        }

        prev -> next = current -> next;
        free(current);
        return llist;
      }
    }

    prev = current;
    current = current -> next;
  }

  //Couldn't find the song
  printf("\"%s\" by %s not found; nothing has been removed. \n", name, artist);
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
