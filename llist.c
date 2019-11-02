#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"
#include "library.h"

//Helper function
int songcmp(struct song_node *song1, struct song_node *song2) {
  if (strcmp(song1 -> artist, song2 -> artist) == 0) {
    return strcmp(song1 -> name, song2 -> name);
  }

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
  struct song_node *current = llist;
  struct song_node *prev = NULL;

  //Fill node with appropriate data, besides what the  next node is
  struct song_node *node = malloc(sizeof(struct song_node));
  strncpy(node -> name, name, 100);
  strncpy(node -> artist, artist, 100);

  if (current == NULL) { //case where list is empty
    node -> next = llist;
    return node;
  }

  if (songcmp(node, current) < 0) { //case where it should be inserted in front of the 1st element
    node -> next = llist;
    return node;
  }

  while (current != NULL) {
    if (songcmp(node, current) < 0) { //wait until the song is actually "smaller" than the current song
      prev -> next = node;
      node -> next = current;
      return llist;
    }

    prev = current;
    current = current -> next;
  }

  //Coudln't find a song "larger" than the song to be inserted, put it at the end
  prev -> next = node; //can't do current -> next since current has been set to NULL by this point
  node -> next = NULL;
  return llist; //return front of list
}

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

void print_node(struct song_node *node) {
  if (node == NULL) { //empty node
    printf("[ ] \n");
    return;
  }

  printf("\"%s\" by %s \n", node -> name, node -> artist);
}

struct song_node *find_song(struct song_node *llist, char name[], char artist[]) {
  struct song_node *current = llist;

  while (current != NULL) {
    if (strcmp(current -> artist, artist) == 0) {
      if (strcmp(current -> name, name) == 0) {
        return current;
      }
    }

    current = current -> next;
  }

  return NULL;
}

struct song_node *find_artist(struct song_node *llist, char artist[]) {
  struct song_node *current = llist;

  while (current != NULL) {
    if (strcmp(current -> artist, artist) == 0) {
      return current;
    }

    current = current -> next;
  }

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

  if (current -> next == NULL) { //case where the list is only 1 song long
    if (strcmp(current -> artist, artist) == 0) {
      if (strcmp(current -> name, name) == 0) {
        printf("Removing \"%s\" by %s \n", current -> name, current -> artist);
        free(current);
        return NULL;
      }
    }

    //Couldn't find the song
    printf("\"%s\" by %s not found; nothing has been removed. \n", name, artist);
    return llist;
  }

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
