struct Node {
  int i;
  struct Node *next;
};

void print_list(struct Node *llist);

struct Node * insert_front(struct Node *llist, int i);

struct Node *remove_node(struct Node *llist, int data);

struct Node * free_list(struct Node *llist);
