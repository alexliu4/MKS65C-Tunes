#ifndef INCL_TUNES
#define INCL_TUNES
struct library {struct song_node * table[27];};

int find_index(char *);
struct library * new_lib();
void print_library(struct library *);
void print_letter(struct library *, char*);
struct song_node * find_library(struct library *, char *, char*);
struct song_node * find_library_art(struct library *, char *);
struct song_node * add(struct library *, char *, char * );
void print_artist(struct library *, char*);
void shuffle(struct library *, int );
void delete_song(struct library *, char*, char*);
struct song_node * clear_library(struct library *);

#endif
