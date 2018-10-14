# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "tunes.h"

struct song_node * insert(struct song_node * nod, char * f_artist, char * f_song){
  return NULL;
}

struct song_node * find(char * f_artist, char* f_song){
  return NULL;
}

void print_list(struct song_node * nod){
  while(nod){
    printf("%p: %s | %s\n", nod, nod->name, nod->artist);
    nod = nod->next;
  }
}

struct song_node * insert_front(struct song_node * head, char * newName, char * newArtist){
  struct song_node * new;
  new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new -> name, newName);
  strcpy(new -> artist, newArtist);
  new -> next = head;
  return new;
}

struct song_node * free_list(struct song_node * nod){
  struct song_node * start = nod;
  struct song_node * temp; 
  while(nod){
    temp = nod -> next;
    //printf("%p: %d\n", nod, nod->i);
    strcpy(nod -> name, "");
    strcpy(nod -> artist, "");
    nod -> next = NULL;
    free(nod);
    //printf("%p: %d\n", nod, nod->i);
    nod = temp;
  }
  return start;
}



