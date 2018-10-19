# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "list.h"


struct song_node * insert_front(struct song_node * head, char * art, char * song){
  struct song_node * new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new -> artist, art);
  strcpy(new -> name, song);
  new -> next = head;
  return new;
}

void print_node(struct song_node * nod){
  if (nod){
    printf("%p: %s | %s\n", nod, nod->artist, nod->name);
  }
  else{
    printf("NULL\n");
  }
}

void print_list(struct song_node * nod){
  //printf("=============PRINTING LIST============\n");
  while (nod){
    print_node(nod);
    nod = nod->next;
  }
  //printf("=======FINISHED PRINTING LIST=========\n");
}



struct song_node * find(struct song_node * nod, char * art, char* song){
  //iterates through until it finds the matching artist and song in the linked list
  while (nod){
    if ((!strcmp(nod -> artist, art)) && (!strcmp(nod -> name, song ))){
      return nod;
    }
    nod = nod -> next;
  }
  return NULL;
}

struct song_node * find_artist( struct song_node * nod ,char* art){
  //iterates through until it finds the matching artist in the linked list
  while (nod){
    //printf("artist: %s\n", nod -> artist);
    if (!strcmp(nod -> artist, art)){
      return nod;
    }
    nod = nod -> next;
  }
  return NULL;
}

struct song_node * new_node(char * newArt, char * newName){
  struct song_node * new;
  new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new -> name, newName);
  strcpy(new -> artist, newArt);
  return new;
}

struct song_node * insert(struct song_node * current, char * newArt, char * newName){
  struct song_node * head = current;
  struct song_node * previous = current;
  struct song_node * new;

  //if nod belongs first alphabetically
  if ( !current || strcmp(current -> artist, newArt) > 0 ){
    new = insert_front(current, newArt, newName);
    return new;
  }
  //else iterate through the linked list to find place for nod
  new = new_node(newArt, newName);
  current = current -> next;
  while (current ){
    if ( strcmp(current -> artist, newArt) > 0){
      previous -> next = new;
      new -> next = current;
      return head;
    }
    else if ( strcmp(current -> artist, newArt) == 0){
      if ( strcmp(current -> name, newName) > 0){
	previous -> next = new;
	new -> next = current;
	return head;
      }
    }
    previous = previous -> next;
    current = current -> next;
  }
  previous -> next = new;
  return head;
}

struct song_node * remove_node(struct song_node * current, char * art, char * name){
  struct song_node * previous = current;
  struct song_node * head = current;
  if (current && !strcmp(current->artist, art) && !strcmp(current->name, name)){
    //printf("%s: %s\n", current-> artist, current->name);
    head = head -> next;
    free(current);
    return head;
  }
  current = current -> next;
  while(current){
    if (!strcmp(current->artist, art) && !strcmp(current->name, name)){
      //printf("%s: %s\n", current-> artist, current->name);
      (previous -> next) = (current -> next);
      free(current);
      return head;
    }
    previous = previous -> next;
    current = current -> next;   
  }
  return head;
}

struct song_node * free_list(struct song_node * nod){
  struct song_node * start = nod;
  struct song_node * temp;
  //iterates through freeing each element
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
  return NULL;
}

struct song_node * find_random(struct song_node * nod){
  struct song_node * copy = nod;
  int len = 0;
  //find length first
  while (nod){
    nod = nod -> next;
    len++;
  }
  //sets random number, n, from range of len
  int randNum = rand() % len;
  //finds the nth node
  while (randNum--){
    copy = copy -> next;
  }
  return copy;
}

