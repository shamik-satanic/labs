#include <stdio.h>

int transposed(int matrix[3][3])
{
    int row = 3;
    int col = 3;
    int i, j, ptr;
    ptr = 0;
    int transpose[3][3];
    printf("Transpose matrix:\n");

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
            printf("%-3d ", matrix[j][i]);
            ptr++;
            if (ptr % col == 0) {
                printf("\n");
            }
        }
    }
    printf("\n");
    return 0;
}

int main() {
    int matrix[3][3] ={
            {57, 105, 206},
            {73, 88, 19},
            {190, 151, 12}
    };
    transposed(matrix);

    return 0;
}