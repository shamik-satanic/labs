#include <stdio.h>
int main() {
    unsigned int a;
    int i;
    int j;
    scanf("%u", &a);
    scanf("%d", &i);
    scanf("%d", &j);
    unsigned int bit_i = (a >> i) & 1;
    unsigned int bit_j = (a >> j) & 1;
    a ^= (1U << i);
    a ^= (1U << j);
    if (bit_i) a |= (1U << j);
    if (bit_j) a |= (1U << i);
    printf("%u\n", a);
    return 0;
}
