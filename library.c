#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "llist.h"

void add_song(struct song_node * table[27], char name[], char artist[]) {
  char letter = artist[0];

  if (letter - 'A' >= 26 || letter - 'A' < 0) { //special character
    table[26] = insert_in_order(table[26], name, artist);
    return;
  }

  table[letter - 'A'] = insert_in_order(table[letter - 'A'], name, artist);
}

void print_library(struct song_node * table[27]) {
  int i;
  for (i = 0; i < 26; i++) {
    if (table[i] != NULL) {
      printf("[%c] list: \n", 'A' + i);
      print_list(table[i]);
    }
  }

  if (table[26] != NULL) { //handle those with special characters
    printf("[SPECIAL] list: \n");
    print_list(table[26]);
  }
}

void print_letter(struct song_node * table[27], char letter) {
  printf("[%c] list: \n", letter);
  print_list(table[letter - 'A']);
}

struct song_node * find_song_in_lib(struct song_node * table[27], char name[], char artist[]) {
  printf("Looking for \'%s\' by %s: \n", name, artist);

  int i;
  for (i = 0; i < 26; i++) {
    if (table[i] != NULL) {
      if (find_song(table[i], name, artist) != NULL) {
        printf("Song found! >> ");
        return table[i];
      }
    }
  }

  return NULL;
}

struct song_node * find_artist_in_lib(struct song_node * table[27], char artist[]) {
  printf("Looking for the first song by %s: \n", artist);
  char letter = artist[0];

  struct song_node * output = find_artist(table[letter - 'A'], artist);
  if (output != NULL) {
    printf("Artist found! \n");
    return output;
  }

  return NULL;
}

void shuffle_songs(struct song_node * table[27]) {
  printf("Shuffling and retrieving 5 random songs from the library: \n");
  for (int i = 0; i < 5; ++i) {
    struct song_node * chosen = NULL;
    while (chosen == NULL) {
      int idx = rand() % 27;
      chosen = random_song(table[idx]);
    }

    print_node(chosen);
  }
}

void remove_song_in_lib(struct song_node * table[27], char name[], char artist[]) {
  char letter = artist[0];

  table[letter - 'A'] = remove_song(table[letter - 'A'], name, artist);
}

void clear_library(struct song_node * table[27]) {
  int i;
  for (i = 0; i < 27; i++) {
    if (table[i] != NULL) {
      table[i] = free_list(table[i]);
    }
  }
}
