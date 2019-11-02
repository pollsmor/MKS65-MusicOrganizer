#include "library.h"
#include "llist.h"

void add_song(struct song_node * table[27], char name[], char artist[]) {
  char letter = name[0];
  table[letter - 'A'] = insert_in_order(table[letter - 'A'], name, artist);
}
