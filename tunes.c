# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "tunes.h"
# include "list.h"

char* alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

struct library * new_lib(){
  struct library * lib = (struct library *) malloc(sizeof(struct library));
  int i = 0;
  while (i<27){
    lib -> table[i] = malloc(sizeof(struct song_node));
    lib -> table[i] = NULL;
    i++;
  }
  return lib;
}

int find_index(char * art){
  int i = 0;
  while (strncasecmp(art, alphabet[i], 1) && i < 27){
    i++;
  }
  //printf("i: %d\n", i);
  return i;
}

void print_library(struct library * lib){
  int i;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    print_list(lib -> table[i]);
  }
}

void clear_library(struct library * lib){
  int i;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    free_list(lib -> table[i]);
  }
}

void print_letter(struct library * lib, char * letter){
  int i = find_index(letter);
  //printf("%d: ", i);
  print_list(lib -> table[i]);

}

void delete_song(struct library * lib, char* art, char* name){
  int i = find_index(art);
  remove_node(lib -> table[i], find(lib->table[i], art, name));
}

struct song_node * find_library(struct library * lib, char * art, char * name){
  int i = find_index(art);
  return find(lib->table[i], art, name);
}

struct song_node * find_library_art(struct library * lib, char * art){
  int i = find_index(art);
  return find_artist(lib->table[i], art);
}

struct song_node * add(struct library * lib, char * art, char * name){
  //printf("inside add function\n");
  int i = find_index(art);
  //printf("%d\n", i);
  return insert(lib -> table[i], art, name);
}

void shuffle (struct library * lib, int i){
  while(i--){
    print_node(find_random(lib->table[rand()%27]));
  }
}

void print_artist(struct library * lib, char* art){

}
