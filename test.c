#define SHARED_PTR_IMPL
#include "shared_ptr.h"

#include <stdio.h>

int main() {
    shared_ptr sptr = make_shared(sizeof(int));
    shared_ptr sptr2 = shared_ptr_copy(sptr);
    
    *(int*)shared_ptr_get(sptr) = 10;
    printf("Value via sptr: %d\n", *(int*)shared_ptr_get(sptr));
    printf("Value via sptr2: %d\n", *(int*)shared_ptr_get(sptr2));

    shared_ptr_free(sptr);
    printf("Value via sptr2 after freeing sptr: %d\n", *(int*)shared_ptr_get(sptr2));

    shared_ptr_free(sptr2);

    return 0;
}
