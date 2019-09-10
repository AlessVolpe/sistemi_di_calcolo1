#ifndef __E2__
#define __E2__
    
#pragma pack(1)
typedef struct header_t {
    unsigned size;
    struct header_t* next;
} header_t;

void* mymalloc(size_t m);
void myfree(void* p);

#endif
