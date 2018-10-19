# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "list.h"
# include "tunes.h"

int main(){
  srand(time(NULL));
  struct library * lib = new_lib();
  add(lib, "a1", "s1");
  add(lib, "a1", "s3");
  add(lib, "a5", "s2");
  add(lib, "a0", "s2");
  add(lib, "b1", "s1");
  add(lib, "b5", "s2");
  add(lib, "b4", "s0");
  add(lib, "b5", "s2");
  add(lib, "b0", "s2");
  printf("\n============\nprinting letter a\n");
  print_letter(lib, "a");
  printf("\n============\nprinting library\n");
  print_library(lib);
  printf("\n============\ndeleting b4 s0\n");
  delete_song(lib, "b4", "s0");
  printf("\n============\nprinting library\n");
  print_library(lib);
  printf("\n============\nfinding a1 s1\n");
  print_node(library_find(lib, "a1", "s1"));
  printf("\n============\nfinding artist b5\n");
  print_node(library_artist(lib, "b5"));
  printf("\n============\nprint artist b5\n");
  print_artist(lib, "b5");
  printf("\n============\nshuffle 3 songs\n");
  //print_node(find_random(lib->table[1]));
  shuffle(lib, 3);
  printf("\n============\nclearing library\n");
  clear_library(lib);
  printf("\n============\nprinting library\n");
  print_library(lib);
  return 0;
}
