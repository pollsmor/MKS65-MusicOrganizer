#include <stdio.h>
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
