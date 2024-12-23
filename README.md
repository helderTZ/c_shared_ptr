# shared_ptr in C

A barebones, stb style, non thread-safe implemetation of shared_ptr in C. Just to see if I could.

⚠ WARNING:  Not production ready.

Usage:
```c++
#define SHARED_PTR_IMPL
#include "shared_ptr.h"

...

// create shared_ptr
shared_ptr sptr = make_shared(sizeof(int));

// make a copy of shared_ptr
shared_ptr sptr2 = shared_ptr_copy(sptr);

// modify the pointed-by data
*(int*)shared_ptr_get(sptr) = 10;

// free the shared_ptr
// will decrement the reference counter,
// will only free if no more shared_ptrs to the same data
shared_ptr_free(sptr);
```
