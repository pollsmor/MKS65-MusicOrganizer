#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llist.h"
#include "library.h"

int main() {
  srand(time(NULL));

  printf("LINKED LIST TESTS \n");
  printf("==================================== \n\n");
  struct song_node *list = NULL;
  printf("Testing print_list on empty list: ");
  print_list(list);
  printf("\n");

  printf("Adding some Disney songs and their artists in order and testing print_list: \n");
  list = insert_in_order(list, "I See The Light", "Mandy Moore"); //and Zachary Levi
  list = insert_in_order(list, "Let it Go", "Idina Menzel");
  list = insert_in_order(list, "Reflection", "Lea Salonga");
  list = insert_in_order(list, "For the First Time In Forever", "Kristen Bell"); //and Idina Menzel
  list = insert_in_order(list, "Do You Want to Build a Snowman?", "Kristen Bell"); //and Idina Menzel
  list = insert_in_order(list, "A Place Called Slaughter Race", "Sarah Silverman");
  list = insert_in_order(list, "When Will My Life Begin", "Mandy Moore");
  list = insert_in_order(list, "A Whole New World", "Lea Salonga"); //and Brad Kane
  print_list(list);

  printf("==================================== \n\n");
  printf("Testing find_song (with the help of print_node): \n");
  printf("Looking for \'Go the Distance\' by Michael Bolton: ");
  print_node(find_song(list, "Go the Distance", "Michael Bolton"));
  printf("\n");
  printf("Looking for \'Let it Go\' by Idina Menzel: ");
  print_node(find_song(list, "Let it Go", "Idina Menzel"));
  printf("\n");
  printf("Looking for \'When Will My Life Begin\' by Kanye West: ");
  print_node(find_song(list, "When Will My Life Begin", "Kanye West"));
  printf("\n");
  printf("Looking for \'Let it Go\' by Mandy Moore: ");
  print_node(find_song(list, "Let it Go", "Mandy Moore"));

  printf("==================================== \n\n");
  printf("Testing find_artist (with the help of print_list): \n");
  printf("Looking for the first song by Michael Bolton: \n");
  print_list(find_artist(list, "Michael Bolton"));
  printf("\n");
  printf("Looking for the first song by Kristen Bell: \n");
  print_list(find_artist(list, "Kristen Bell"));
  printf("\n");
  printf("Looking for the first song by Idina Menzel: \n");
  print_list(find_artist(list, "Idina Menzel"));
  printf("\n");
  printf("Looking for the first song by Kanye West: \n");
  print_list(find_artist(list, "Kanye West"));
  printf("\n");
  printf("Looking for the first song by Mandy Moore: \n");
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
  printf("Printing the list again, for convenience: \n");
  print_list(list);
  printf("\n");

  list = remove_song(list, "Reflection", "Lea Salonga");
  print_list(list);
  printf("\n");
  list = remove_song(list, "I See The Light", "Kanye West");
  print_list(list);
  printf("\n");
  list = remove_song(list, "A Whole New World", "Lea Salonga");
  print_list(list);

  printf("==================================== \n\n");
  printf("Testing free_list \n");
  list = free_list(list);
  printf("List after free_list: ");
  print_list(list);
  printf("\n");

  printf("==================================== \n\n");
  printf("MUSIC LIBRARY TESTS \n\n");
  printf("==================================== \n\n");


  printf("Testing print_library \n");
  struct song_node * table[27];
  for (int i = 0; i < 27; i++) {
    table[i] = NULL;
  }

  add_song(table, "Let it Go", "Idina Menzel");
  add_song(table, "I See The Light", "Mandy Moore"); //and Zachary Levi
  add_song(table, "Reflection", "Lea Salonga");
  add_song(table, "For the First Time In Forever", "Kristen Bell"); //and Idina Menzel
  add_song(table, "Do You Want to Build a Snowman?", "Kristen Bell"); //and Idina Menzel
  add_song(table, "A Place Called Slaughter Race", "Sarah Silverman");
  add_song(table, "When Will My Life Begin", "Mandy Moore");
  add_song(table, "A Whole New World", "Lea Salonga"); //and Brad Kane
  add_song(table, "Test song", "#TeamTrees");
  add_song(table, "I Give Up On Thinking Of Songs", "Someone StartingWithS");
  print_library(table);

  printf("==================================== \n\n");
  printf("Testing print_letter: \n");
  print_letter(table, 'S');
  print_letter(table, 'K');
  print_letter(table, 'Z');
  printf("\n");

  printf("==================================== \n\n");
  printf("Testing find_song_in_lib: \n");
  print_node(find_song_in_lib(table, "Go the Distance", "Michael Bolton"));
  printf("\n");
  print_node(find_song_in_lib(table, "Let it Go", "Idina Menzel"));
  printf("\n");
  print_node(find_song_in_lib(table, "When Will My Life Begin", "Kanye West"));
  printf("\n");
  print_node(find_song_in_lib(table, "Let it Go", "Mandy Moore"));

  printf("==================================== \n\n");
  printf("Testing find_artist_in_lib: \n");
  print_list(find_artist_in_lib(table, "Michael Bolton"));
  printf("\n");
  print_list(find_artist_in_lib(table, "Kristen Bell"));
  printf("\n");
  print_list(find_artist_in_lib(table, "Idina Menzel"));
  printf("\n");
  print_list(find_artist_in_lib(table, "Kanye West"));
  printf("\n");
  print_list(find_artist_in_lib(table, "Mandy Moore"));
  printf("\n");
  print_list(find_artist_in_lib(table, "Sarah Silverman"));

  printf("==================================== \n\n");
  printf("Testing shuffle_songs: \n");
  shuffle_songs(table);
  printf("\n");

  printf("==================================== \n\n");
  printf("Testing remove_song_in_lib: \n");
  printf("Printing the library again, for convenience: \n");
  print_library(table);
  printf("\n");

  remove_song_in_lib(table, "Reflection", "Lea Salonga");
  print_library(table);
  printf("\n");
  remove_song_in_lib(table, "I See The Light", "Kanye West");
  print_library(table);
  printf("\n");
  remove_song_in_lib(table, "A Whole New World", "Lea Salonga");
  print_library(table);

  printf("==================================== \n\n");
  printf("Testing clear_library \n");
  clear_library(table);
  printf("List after clear_library: ");
  print_library(table);
  printf("\n");

  return 0;
}
