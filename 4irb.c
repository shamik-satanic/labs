#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int search(int array[]){
    int max = 0, min = 10001;
    int inmax, inmin;
    for(int i = 0; i < 5; i++){
        if(array[i] > max){
            max = array[i];
            inmax = i;
        }else if(array[i] < min){
            min = array[i];
            inmin = i;
        }
    }printf("max = %d, index = %d\n", max, inmax);
    printf("min = %d, index = %d", min, inmin);

}

int main(){
    srand(time(NULL));
    int arr[5];
    for(int i = 0; i < 5; i++){
        arr[i] = -10000 + rand() % 20000;
    }
    search(arr);
    return 0;
}
