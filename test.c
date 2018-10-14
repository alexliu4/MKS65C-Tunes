# include <stdio.h>
# include <stdlib.h>
# include "list.h"

int main(){
  struct node * a = insert_front(NULL,3);
  struct node * b = insert_front(a,6);
  struct node * c = insert_front(b,9);
  struct node * d = insert_front(c,12);
  printf("=====Printing list=====\n");
  print_list(d);
  printf("=====Finished printing list=====\n\n");
  
  free_list(d);
  printf("=====Printing freed list=====\n");
  print_list(d);
  return 0;
  
}
