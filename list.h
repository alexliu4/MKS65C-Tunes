#ifndef INCL_LIST
#define INCL_LIST

struct song_node{
  char name[100];
  char artist[100];
  struct song_node * next;
};

void print_node(struct song_node *); //done
void print_list(struct song_node *); //done
struct song_node * insert_front(struct song_node *, char *, char * ); //done
struct song_node * find(struct song_node *, char *, char*); //done
struct song_node * find_artist(struct song_node *, char*);//done
struct song_node * insert(struct song_node *, char *, char * ); //done
struct song_node * remove_node(struct song_node *, char*, char *);//done
struct song_node * find_random(struct song_node * );//done
struct song_node * free_list(struct song_node *);//done


#endif
