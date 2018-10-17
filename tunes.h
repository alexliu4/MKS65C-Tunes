#ifndef INCL_TUNES
#define INCL_TUNES
struct song_node * table[27];
char* alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

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
