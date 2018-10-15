# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "list.h"
//test

int main(){
  srand(time(NULL));
  struct song_node * a = insert_front(NULL,"zoe", "bye");
  struct song_node * b = insert_front(a,"karen", "hello");
  struct song_node * c = insert_front(b,"jake", "peralta");
  struct song_node * d = insert_front(c,"amy", "santiago");
  struct song_node * e = insert_front(d,"alex", "first");
  printf("=====Printing list=====\n");
  print_list(e);
  printf("=====Finished printing list=====\n\n");

  printf("Finding Random: %p\n\n",(find_random(e)) );
  printf("Finding Artist: %p\n\n",(find_artist(e, "karen")) );
  printf("Finding Specfic: %p\n\n",(find(e, "amy", "santiago")) );

  //removes d
  remove_node(e, e);
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
  free_list(e);
  printf("=====Printing freed list=====\n");
  print_list(e);
  return 0;

}
