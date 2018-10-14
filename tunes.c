# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "tunes.h"

void print_list(struct node * nod){
  while(nod){
    printf("%p: %s\n", nod, nod->value);
    nod = nod->next;
  }
}

struct node * insert_front(struct node * head, char * adding){
  struct node * new;
  new = (struct node *) malloc(sizeof(struct node));
  strcpy(new -> value, adding);
  new -> next = head;
  return new;
}

struct node * free_list(struct node * nod){
  struct node * start = nod;
  struct node * temp; 
  while(nod){
    temp = nod -> next;
    //printf("%p: %d\n", nod, nod->i);
    strcpy(nod -> value, "");
    nod -> next = NULL;
    free(nod);
    //printf("%p: %d\n", nod, nod->i);
    nod = temp;
  }
  return start;
}



