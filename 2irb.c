#include <stdio.h>
#include <string.h>

char reverse(char * str){
    int c = strlen(str);
    char str2[c];
    int i = 0;
    while(i != c){
        str2[i] = str[c - 1 - i];
        i++;
    }
    printf("%s", str2);
}

int main(){
    char str[] = {"cxz"};
    reverse(str);
    return 0;
}