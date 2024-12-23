#ifndef SHARED_PTR
#define SHARED_PTR

typedef struct shared_ptr_metadata  {
    int ref_count;
} shared_ptr_metadata;

typedef struct shared_ptr  {
    shared_ptr_metadata* meta;
    void* data;
} shared_ptr;

shared_ptr make_shared(int size);
shared_ptr shared_ptr_copy(shared_ptr sptr);
void* shared_ptr_get(shared_ptr);
void shared_ptr_free(shared_ptr ptr);

#endif  // SHARED_PTR

#ifdef SHARED_PTR_IMPL

#include <stdlib.h>

shared_ptr make_shared(int size) {
    shared_ptr_metadata* metadata = (shared_ptr_metadata*)malloc(sizeof(shared_ptr_metadata));
    metadata->ref_count = 1;
    shared_ptr ptr;
    ptr.meta = metadata;
    ptr.data = malloc(size);
    return ptr;
}

void shared_ptr_free(shared_ptr sptr) {
    sptr.meta->ref_count--;
    if (sptr.meta->ref_count == 0) {
        free(sptr.meta);
        free(sptr.data);
    }
}

shared_ptr shared_ptr_copy(shared_ptr sptr) {
    sptr.meta->ref_count++;
    return (shared_ptr) {sptr.meta, sptr.data};
}

void* shared_ptr_get(shared_ptr sptr) {
    return sptr.data;
}

#endif  // SHARED_PTR_IMPL
