#include <stdio.h>
#include <stdlib.h>

void copy(const double arr[], int sizearr) {
    double *arr2 = (double *)malloc(sizearr * sizeof(double));
    int unique_count = 0;
    for (int i = 0; i < sizearr; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (arr[i] == arr2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            arr2[unique_count++] = arr[i];
        }
    }
    for (int i = 0; i < unique_count; i++) {
        printf("%lf ", arr2[i]);
    }
    printf("\n");
    free(arr2);
}

int main() {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 2.0, 1.0};
    int sizearr = sizeof(arr) / sizeof(arr[0]);
    copy(arr, sizearr);
    return 0;
}