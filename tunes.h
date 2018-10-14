struct node{
  char value[20];
  struct node * next;
};

void print_list(struct node *);
struct node * insert_front(struct node *, char * );
struct node * free_list(struct node *);
