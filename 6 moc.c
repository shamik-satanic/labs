#include <stdio.h>

int main()
{
    unsigned int n;
    int k;
    scanf("%u", &n);
    scanf("%d", &k);
    unsigned int mask = ~((1U << k) - 1);
    n &= mask;
    printf("%u\n", n);
    return 0;
}