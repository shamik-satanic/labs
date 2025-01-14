#include <stdio.h>

#pragma warning(disable: 4996)

int main() {
    unsigned int n, first_b, last_b, gb, mb;
    int len, i;
    scanf("%u", &n);
    scanf("%d", &len);
    scanf("%d", &i);
    first_b = (n >> (len - i)) & ((1 << i) - 1);
    last_b = n & ((1 << i) - 1);
    gb = (first_b << i) | last_b;
    mb = (n >> i) & ((1 << (len - 2 * i)) - 1);
    printf("\n%u", gb);
    printf("\n%u\n", mb);

    return 0;
}