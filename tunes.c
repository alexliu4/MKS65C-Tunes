# include <stdio.h>
# include <stdlib.h>
# include "list.h"

void print_list(struct node * nod){
  while(nod){
    printf("%p: %d\n", nod, nod->i);
    nod = nod->next;
  }
}

struct node * insert_front(struct node * nod, int i){
  struct node * newNode;
  newNode = (struct node *) malloc(sizeof(struct node));
  newNode -> next = nod;
  newNode -> i = i;
  return newNode;
}

struct node * free_list(struct node * nod){
  struct node * start = nod;
  struct node * temp; 
  while(nod){
    temp = nod -> next;
    //printf("%p: %d\n", nod, nod->i);
    nod -> i = 0;
    nod -> next = NULL;
    free(nod);
    //printf("%p: %d\n", nod, nod->i);
    nod = temp;
  }
  return start;
}



