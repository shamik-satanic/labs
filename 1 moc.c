#include <stdio.h>

int main(){
    int g1, s1, k1, g2, s2, k2;
    int g, s, k, ss, gs;
    scanf("%d%d%d", g1, s1, k1);
    scanf("%d%d%d", g2, s2, k2);
    ss = (k1 + k2) / 29;
    k = (k1 + k2) % 29;
    gs = (s1 + s2 + ss) / 17;
    s = (s1 + s2 + ss) % 17;
    g = g1 + g2 + gs;
    printf("%d %d %d", g, s, k);
    return 0;
}