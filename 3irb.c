#include <stdio.h>
#include <string.h>

int reverse(int * num1, int * num2){
    int n = *num1;
    *num1 = *num2;
    *num2 = n;
}

int main(){
    int num1 = 13, num2 = 26, a;
    reverse(&num1, &num2);
    printf("%d %d", num1, num2);
    return 0;
}