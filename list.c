# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "list.h"

struct song_node * find_random(struct song_node * nod){
  struct song_node * copy = nod;
  int len = 0;
  while (nod){
    nod = nod -> next;
    len++;
  }
  int randNum = rand() % len;
  while (randNum--){
    copy = copy -> next;
  }
  return copy;
}

struct song_node * find_artist( struct song_node * nod ,char* art){
  while (nod){
    if (!strcmp(nod -> artist, art)){
      return nod;
    }
    nod = nod -> next;
  }
  return NULL;
}

struct song_node * insert(struct song_node * nod, char * art, char * song){
  return NULL;
}

struct song_node * find(struct song_node * nod, char * art, char* song){
  while (nod){
    if ( (!strcmp(nod -> artist, art)) && (!strcmp(nod -> name, song )) ){
      return nod;
    }
    nod = nod -> next;
  }
  return NULL;
}

void remove_node(struct song_node * current, struct song_node * gone){
  struct song_node * previous = current;
  if (&current == &gone){
    free(current);
  }
  current = current -> next;
  while (current){
    printf("while works");
    if (&current == &gone){
      (previous -> next) = (current -> next);
      printf("REMOVED");
      free(current);
    }
    previous = previous -> next;
    current = current -> next;
    if (current && &current == &gone){
      free(current);
    }
  }
}

void print_list(struct song_node * nod){
  while(nod){
    printf("%p: %s | %s\n", nod, nod->name, nod->artist);
    nod = nod->next;
  }
}

struct song_node * insert_front(struct song_node * head, char * newArtist, char * newName){
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
