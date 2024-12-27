#include <stdio.h>

void search(int array[], int size, int *max, int *min, int *inmax, int *inmin) {
    *max = array[0];
    *min = array[0];
    *inmax = 0;
    *inmin = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] > *max) {
            *max = array[i];
            *inmax = i;
        } else if (array[i] < *min) {
            *min = array[i];
            *inmin = i;
        }
    }
}

int main() {
    int array[] = {-3, 15, 7, -9, 20};
    int size = sizeof(array) / sizeof(array[0]);

    int max, min, inmax, inmin;
    search(array, size, &max, &min, &inmax, &inmin);

    printf("Максимальный элемент: %d, индекс: %d\n", max, inmax);
    printf("Минимальный элемент: %d, индекс: %d\n", min, inmin);

    return 0;
}