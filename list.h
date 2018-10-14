struct song_node{
  char name[20];
  char artist[100];
  struct song_node * next;
};


void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char *, char * );
struct song_node * insert(struct song_node *, char *, char * );
struct song_node * find(char *, char*);
struct song_node * find_artist( char*);
struct song_node * find_random( char*);
struct song_node * free_list(struct song_node *);
void remove_node(struct song_node *);
