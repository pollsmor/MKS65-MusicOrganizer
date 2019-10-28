struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *llist);

struct song_node * insert_front(struct song_node *llist, int i);

struct song_node *remove_song(struct song_node *llist, int data);

struct song_node * free_list(struct song_node *llist);
