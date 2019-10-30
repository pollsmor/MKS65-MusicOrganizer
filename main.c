#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llist.h"

int main() {
  srand(time(NULL));

  printf("LINKED LIST TESTS \n");
  printf("==================================== \n\n");
  struct song_node *list = NULL;
  printf("Testing print_list on empty list: ");
  print_list(list);
  printf("\n\n");

  printf("Adding 3 Disney songs and their artists in order and testing print_list: \n");
  list = insert_front(list, "I See The Light", "Mandy Moore & Zachary Levi");
  list = insert_front(list, "Reflection", "Lea Salonga");
  list = insert_front(list, "Let it Go", "Idina Menzel");
  list = insert_front(list, "A Whole New World", "Brad Kane & Lea Salonga");
  print_list(list);

  printf("==================================== \n\n");
  printf("Testing random: \n");
  print_node(random_song(list));
  print_node(random_song(list));
  print_node(random_song(list));
  print_node(random_song(list));
  print_node(random_song(list));

  printf("==================================== \n\n");
  printf("Testing remove_song: \n");
  list = remove_song(list, "Reflection", "Lea Salonga");
  print_list(list);
  printf("\n");
  list = remove_song(list, "I See The Light", "Mandy Moore & Zachary Levi");
  print_list(list);
  printf("\n");
  list = remove_song(list, "A Whole New World", "Brad Kane & Lea Salonga");
  print_list(list);
  printf("\n");

  printf("==================================== \n\n");
  printf("Testing free_list \n");
  list = free_list(list);
  printf("List after free_list: ");
  print_list(list);
  printf("\n\n");

  return 0;
}
