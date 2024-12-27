#include <stdio.h>
#include <stdlib.h>

int copy(int arr[]){
    int *arr2 = (int *)malloc(sizeof(arr));
    int i = 0;
    int j = 0;
    while(arr[i] != '\0'){
        if(arr[i] % 2 == 0 ){
            arr2[j] = arr[i];
            j++;
            i++;
        }
        else{
            i++;
        }
    }
    arr2[j] = '\0';
    int a = 0;
    while(arr2[a] != '\0') {
        printf("%d", arr2[a]);
        a++;

    }
    free(arr2);
    return 0;
}

int main(){
    int arr[] = {1, 2 ,3, 4, 5, 6};
    copy(arr);
    return 0;
}
