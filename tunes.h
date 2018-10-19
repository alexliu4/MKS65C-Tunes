#ifndef INCL_TUNES
#define INCL_TUNES
struct library {struct song_node * table[27];};

int find_index(char *); //done
struct library * new_lib(); //done
void print_library(struct library *);//done
void print_letter(struct library *, char*);//done
struct song_node * library_find(struct library *, char *, char*);//done
struct song_node * library_artist(struct library *, char *);//done
struct song_node * add(struct library *, char *, char * );//done
void print_artist(struct library *, char*);//done
void shuffle(struct library *, int );//done
void delete_song(struct library *, char*, char*);
struct library * clear_library(struct library *);//done

#endif
