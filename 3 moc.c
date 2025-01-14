#include <stdio.h>
int main()
{
    unsigned int a;
    int k;
    scanf("%u", &a);
    scanf("%d", &k);
    a |= (1 << k);
    printf("%u\n", a);
    return 0;
}
