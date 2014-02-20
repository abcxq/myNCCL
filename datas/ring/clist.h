struct tagnode
{
    void *data;
    struct tagnode *next;
};

typedef struct tagnode *link;
typedef struct tagnode node;

link make_node(void *data);
int *make_data(int data);

void print_int_data(void *data);

link clist_new(void);
void clist_print(link cur, void (*pf)(void *));
link clist_insert_after(link cur, link item);
link clist_delete(link cur, link item);
int clist_length(link cur);
