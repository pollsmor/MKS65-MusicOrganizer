struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *llist, char name[], char artist[]);

struct song_node * insert_in_order(struct song_node *llist, char name[], char artist[]);

void print_list(struct song_node *llist);

void print_node(struct song_node *node);

struct song_node *find_song(struct song_node *llist, char name[], char artist[]);

struct song_node *random_song(struct song_node *llist);

struct song_node *remove_song(struct song_node *llist, char name[], char artist[]);

struct song_node * free_list(struct song_node *llist);
