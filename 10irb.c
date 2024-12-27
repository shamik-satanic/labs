#include <stdio.h>
#include <stdlib.h>

void multiplication_matrix(double **matrix1, int n, int m, double **matrix2, int a, int b, double **result) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < m; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &a, &b);


    if (m != a) {
        printf("Умножение матриц невозможно.\n");
        return 1;
    }


    double **matrix1 = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix1[i] = malloc(m * sizeof(double));
    }

    double **matrix2 = malloc(a * sizeof(double*));
    for (int i = 0; i < a; i++) {
        matrix2[i] = malloc(b * sizeof(double));
    }

    double **result = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = malloc(b * sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }


    multiplication_matrix(matrix1, n, m, matrix2, a, b, result);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < a; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}