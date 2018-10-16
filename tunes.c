# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "tunes.h"
# include "list.h"

int find_index(char * art){
  int i = 0;
  while (strncasecmp(art, alphabet[i], 1) && i < 27){
    i++;
  }
  return i;
}

void print_library(){
  int i;;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    print_list(table[i]);
  }
}

struct song_node * clear_library(){
  int i;;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    free_list(table[i]);
  }
}

void print_letter(char * letter){
  int i = find_index(letter);
  //printf("%d: ", i);
  print_list(table[i]);
  
}

void delete_song(char* art, char* name){
  int i = find_index(art);
  remove_node(table[i], find(table[i], art, name));
}

struct song_node * find_library(char * art, char * name){
  int i = find_index(art);
  return find(table[i], art, name);
}

struct song_node * find_library_art(char * art){
  int i = find_index(art);
  return find_artist(table[i], art);
}

struct song_node * add( char * art, char * name){
  int i = find_index(art);
  return insert(table[i], art, name);
}

/*
int main(){
  clear_library();
}

*/
