#include <stdio.h>
#include <stdint.h>
uint64_t rol(uint64_t x, unsigned int n, unsigned int p) {
    return ((x << n) | (x >> (BITS(p) - n))) & MASK(p);
}
uint64_t ror(uint64_t x, unsigned int n, unsigned int p) {
    return ((x >> n) | (x << (BITS(p) - n))) & MASK(p);
}
#define BITS(p) (1ULL << (p))
#define MASK(p) (BITS(p) - 1)
