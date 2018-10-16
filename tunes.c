# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "tunes.h"
# include "list.c"

void print_library(){
  int i;;
  for (i=0; i < 27; i++){
    //printf("%d: ", i);
    print_list(table[i]);
  }
}

void print_letter(char letter[]){
  int i = 0;
  while (strncasecmp(letter, alphabet[i], 1) && i < 27){
    i++;
  }
  //printf("%d: ", i);
  print_list(table[i]);
  
}

/*
int main(){
  print_letter("z");
}
*/
