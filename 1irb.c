#include <stdio.h>
#include <string.h>

int puzyrok(int array[]){
    int j, i = 0, c = 0;
    while(array[i] != '\0'){
        c++;
        i++;
    }
    i = 0;
    while(i != c){
        if(array[i + 1] < array[i]){
            j = array[i];
            array[i] = array[i + 1];
            array[i + 1] = j;
            i = 0;
        }else{
            i++;
        }
    }
}
int main() {
    int array[] = {4, 3, 6, 7, 8,2, 1, 5, 9, 0};
    int i, c = 0;
    while(array[i] != '\0'){
        c++;
        i++;
    }
    puzyrok(array);
    for(int i = 1; i < c + 1; i++){
        printf("%d", array[i]);
    }
    return 0;
}

