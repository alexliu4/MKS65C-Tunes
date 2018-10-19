# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "tunes.h"
# include "list.h"

char* alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int find_index(char * art){
  int i = 0;
  while (strncasecmp(art, alphabet[i], 1) && i < 26){
    i++;
  }
  //printf("i: %d\n", i);
  return i;
}

struct library * new_lib(){
  struct library * lib = (struct library *) malloc(sizeof(struct library));
  return lib;
}

void print_library(struct library * lib){
  int i;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    print_list(lib -> table[i]);
  }
}

struct song_node * add(struct library * lib, char * art, char * name){
  //printf("inside add function\n");
  int i = find_index(art);
  //printf("%d\n", i);

  lib -> table[i] = insert(lib -> table[i], art, name);

  return lib -> table[i];
}

void print_letter(struct library * lib, char * letter){
  int i = find_index(letter);
  //printf("%d: ", i);
  print_list(lib -> table[i]);

}

struct song_node * library_find(struct library * lib, char * art, char * name){
  int i = find_index(art);
  return find(lib->table[i], art, name);
}

struct song_node * library_artist(struct library * lib, char * art){
  int i = find_index(art);
  return find_artist(lib->table[i], art);
}

void print_artist(struct library * lib, char* art){
  struct song_node * temp = library_artist(lib, art);
  while (temp && strcmp(temp -> artist, art) == 0){
    print_node(temp);
    temp = temp -> next;
  }
}

struct library *  clear_library(struct library * lib){
  int i;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    lib->table[i] = free_list(lib -> table[i]);
  }
}

void shuffle (struct library * lib, int i){
  struct song_node * random = lib->table[(int)rand()%27];
  while (!random){
    random = lib->table[(int)rand()%27];
  }
  while(i--){
    print_node(find_random(random));
  }
}

void delete_song(struct library * lib, char* art, char* name){
  int i = find_index(art);
  remove_node(lib -> table[i], art, name);
}



