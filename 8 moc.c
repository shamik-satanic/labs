#include <stdio.h>
int maxPowerOfTwo(int n) {
    if (n == 0) return 0;
    n = (n < 0) ? -n : n;
    return n & (-n);
}

int main() {
    int num;
    scanf("%d", &num);
    int result = maxPowerOfTwo(num);
    printf("%d\n", result);
    return 0;
}