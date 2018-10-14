# include <stdio.h>
# include <stdlib.h>
# include "list.h"

int main(){
  struct song_node * a = insert_front(NULL,"alex", "hi");
  struct song_node * b = insert_front(a,"karen", "hello");
  struct song_node * c = insert_front(b,"amy", "santiago");
  struct song_node * d = insert_front(c,"jake", "peralta");
  printf("=====Printing list=====\n");
  print_list(d);
  printf("=====Finished printing list=====\n\n");
  
  free_list(d);
  printf("=====Printing freed list=====\n");
  print_list(d);
  return 0;
  
}
