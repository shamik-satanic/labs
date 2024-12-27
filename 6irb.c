#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gauss(double **matrix, int a, int b){
    double res = 1.0;
    if(a == b){
        for(int n = 0; n < a; n ++){
            double del = matrix[n][n];

            res = res * del;
            for(int m = 0; m < b; m++){
                matrix[n][m] = matrix[n][m] / del;
            }
            for(int c = n + 1; c < a; c++){
                del = matrix[c][n];

                res = res * del;
                matrix[c][n] = matrix[c][n] / del;
            }
            for(int i = n + 1; i < a; i++){
                for(int j = 0; j < b; j++){
                    matrix[i][j] = matrix[i][j] - matrix[n][j];

                }
            }
        }
    }
    res = res * (matrix[a - 1][b - 1]);
    printf("%lf\n", res);

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    double **matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc((n + 1) * sizeof(double));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    gauss(matrix, n, m);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}