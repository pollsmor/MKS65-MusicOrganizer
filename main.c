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
  printf("\n");

  printf("Adding some Disney songs and their artists in order and testing print_list: \n");
  list = insert_front(list, "I See The Light", "Mandy Moore"); //and Zachary Levi
  list = insert_front(list, "Reflection", "Lea Salonga");
  list = insert_front(list, "Let it Go", "Idina Menzel");
  list = insert_front(list, "For the First Time In Forever", "Kristen Bell"); //and Idina Menzel
  list = insert_front(list, "Do You Want to Build a Snowman?", "Kristen Bell"); //and Idina Menzel
  list = insert_front(list, "A Place Called Slaughter Race", "Sarah Silverman");
  list = insert_front(list, "When Will My Life Begin", "Mandy Moore");
  list = insert_front(list, "A Whole New World", "Brad Kane & Lea Salonga");
  print_list(list);

  printf("==================================== \n\n");
  printf("Testing find_song (with the help of print_node): \n");
  print_node(find_song(list, "Go the Distance", "Michael Bolton"));
  printf("\n");
  print_node(find_song(list, "Let it Go", "Idina Menzel"));
  printf("\n");
  print_node(find_song(list, "When Will My Life Begin", "Kanye West"));
  printf("\n");
  print_node(find_song(list, "Let it Go", "Mandy Moore"));

  printf("==================================== \n\n");
  printf("Testing find_artist (with the help of print_list): \n");
  print_list(find_artist(list, "Michael Bolton"));
  printf("\n");
  print_list(find_artist(list, "Kristen Bell"));
  printf("\n");
  print_list(find_artist(list, "Idina Menzel"));
  printf("\n");
  print_list(find_artist(list, "Kanye West"));
  printf("\n");
  print_list(find_artist(list, "Mandy Moore"));

  printf("==================================== \n\n");
  printf("Testing random (with the help of print_node): \n");
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

  printf("==================================== \n\n");
  printf("Testing free_list \n");
  list = free_list(list);
  printf("List after free_list: ");
  print_list(list);
  printf("\n\n");

  return 0;
}
