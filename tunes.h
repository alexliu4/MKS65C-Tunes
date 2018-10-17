#ifndef INCL_TUNES
#define INCL_TUNES
struct song_node * table[27];

int find_index(char *);
void print_library();
void print_letter(char*);
struct song_node * find_library(char *, char*);
struct song_node * find_library_art(char *);
struct song_node * add( char *, char * );
void print_artist(char*);
void shuffle();
void delete_song(char*, char*);
struct song_node * clear_library();

#endif
