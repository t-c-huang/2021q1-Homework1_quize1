#include<stdio.h>
#include<stdlib.h>



void msws(uint64_t *w_rand_ptr, uint64_t *w_ptr)
{
    uint64_t w_seed = 0xb5ad4eceda1ce2a9;
    *w_rand_ptr *= *w_rand_ptr;
    *w_rand_ptr += (*w_ptr += w_seed);
    *w_rand_ptr = ((*w_rand_ptr << 8) >> 32) << 8 | (*w_rand_ptr << 32) >> 48;
}
