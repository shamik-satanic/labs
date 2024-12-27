#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bi_search(int array[], int size, int target){
    int first = 0, last = size - 1;
    int mid = (first + last) / 2;
    while(array[mid] != target){
        if(target <= array[mid]){
            last = mid - 1;
            mid = first + (last - first) / 2;
        }else{
            first = mid + 1;
            mid = first + (last - first) / 2;
        }
    }printf("%d", mid);
}

int main(){
    int target, size, el;
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &el);
        array[i] = el;
    }
    scanf("%d", &target);
    bi_search(array, size, target);
    return 0;
}