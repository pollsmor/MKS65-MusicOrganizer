struct song_node {
  char const *name;
  char const *artist;
  struct song_node *next;
};

void print_list(struct song_node *llist);

struct song_node * insert_front(struct song_node *llist, char const *name, char const *artist);

struct song_node *remove_song(struct song_node *llist, int data);

struct song_node * free_list(struct song_node *llist);
