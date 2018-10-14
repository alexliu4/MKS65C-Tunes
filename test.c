# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "list.h"

int main(){
  srand(time(NULL));
  struct song_node * a = insert_front(NULL,"alex", "hi");
  struct song_node * b = insert_front(a,"karen", "hello");
  struct song_node * c = insert_front(b,"amy", "santiago");
  struct song_node * d = insert_front(c,"jake", "peralta");
  printf("=====Printing list=====\n");
  print_list(d);
  printf("=====Finished printing list=====\n\n");

  printf("Finding Random: %p\n\n",(find_random(d)) );
  printf("Finding Artist: %p\n\n",(find_artist(d, "karen")) );
  printf("Finding Specfic: %p\n\n",(find(d, "amy", "santiago")) );

  //removes d
  remove_node(d, d);
  printf("=====Removing first element=====\n");
  print_list(c);
  printf("=====Finished Printing New List=====\n\n");

  //removes b
  remove_node(c, b);
  printf("=====Removing middle element=====\n");
  print_list(c);
  printf("=====Finished Printing New List=====\n\n");

  //removes a
  remove_node(c, a);
  printf("=====Removing end element=====\n");
  print_list(c);
  printf("=====Finished Printing New List=====\n\n");

  //frees entire list
  free_list(d);
  printf("=====Printing freed list=====\n");
  print_list(d);
  return 0;

}
