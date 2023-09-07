/*
* inline expansions
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdatomic.h>

/*

#include <smrproxy.h>


void smracquire(smrproxy_ref_t *ref)
{
    smrproxy_ref_acquire(ref);
}

void smrrelease(smrproxy_ref_t *ref)
{
    smrproxy_ref_release(ref);
}
*/

__int128_t mov16(volatile __int128_t x)
{
    return x;
}

_Atomic uint64_t incr64(_Atomic uint64_t *x)
{
    return atomic_fetch_add(x, 1);
}

bool xxxx(__int128_t *x, __int128_t *y)
{
   return __atomic_compare_exchange_16(x, y, 0, false, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
} 

bool xxxx2(__int128_t *x, __int128_t y)
{
   return __sync_bool_compare_and_swap(x, y, 0, false, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
} 

int main(int argc, char **argv)
{
   _Alignas(16) _Atomic __int128_t xx = 0;
   _Alignas(16) __int128_t xx1 = 0;
   _Alignas(16) _Atomic  __int128_t xx2 = 1;

    atomic_uint_least64_t yy;


    char *b = atomic_is_lock_free(&xx) ? "true" : "false";
    char *b2 = __atomic_is_lock_free(16, 0) ? "true" : "false";

    fprintf(stdout, "__int128 is lock free - %s\n", b);
    fprintf(stdout, "__int128 is lock free  (2) - %s\n", b2);

    atomic_compare_exchange_strong(&xx, &xx1, xx2);


    return 0;
}