struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

void add_song(struct song_node * table[27], char name[], char artist[]);

void print_library(struct song_node * table[27]);

void print_letter(struct song_node * table[27], char letter);

struct song_node * find_song_in_lib(struct song_node * table[27], char name[], char artist[]);

struct song_node * find_artist_in_lib(struct song_node * table[27], char artist[]);

void shuffle_songs(struct song_node * table[27]);

void remove_song_in_lib(struct song_node * table[27], char name[], char artist[]);

void clear_library(struct song_node * table[27]);
