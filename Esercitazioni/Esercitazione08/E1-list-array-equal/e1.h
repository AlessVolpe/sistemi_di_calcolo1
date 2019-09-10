#ifndef __NODE_T__
#define __NODE_T__

typedef struct node_t {
    short elem;
    struct node_t *next;
} node_t;

void list_new(node_t **l);
int  list_new_from_buffer(node_t **l, short* buf, int n);
void list_delete(node_t **l);
int  list_add_first(node_t **l, short elem);
int  list_delete_first(node_t **l, short *elem);
int  list_equal_array(const node_t *p, short *buf, int n);

#endif
