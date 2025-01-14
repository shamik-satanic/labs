#include <stdio.h>
int main()
{
    int a;
    int k;
    int res;
    scanf("%d, \n", &a);
    scanf("%d, \n", &k);
    res = a & (1 << k);
    printf("%d", res);
    return 0;
}