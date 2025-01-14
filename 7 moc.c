#include <stdio.h>

unsigned int swapBytes(unsigned int num, int pos1, int pos2) {
    pos1 %= 4;
    pos2 %= 4;
    unsigned char byte1 = (num >> (pos1 * 8)) & 0xFF;
    unsigned char byte2 = (num >> (pos2 * 8)) & 0xFF;
    num &= ~(0xFF << (pos1 * 8));
    num &= ~(0xFF << (pos2 * 8));
    num |= (unsigned int)byte1 << (pos2 * 8);
    num |= (unsigned int)byte2 << (pos1 * 8);
    return num;
}

int main() {
    unsigned int num;
    int pos1, pos2;
    scanf("%x", &num);
    scanf("%d %d", &pos1, &pos2);
    unsigned int result = swapBytes(num, pos1, pos2);
    printf("%08d\n", num);
    printf("%08d\n", result);
    return 0;
}