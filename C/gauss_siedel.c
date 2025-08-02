double* gauss_seidel(double** A, double* b, int n, double tol, int max_iter) {
    double* x = (double*) malloc(n * sizeof(double));
    double* x_new = (double*) malloc(n * sizeof(double));
    double sum;
    int i, j, k;
    for (i = 0; i < n; i++) {
        x[i] = 0;
    }
    for (k = 0; k < max_iter; k++) {
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }
        if (norm(x_new, x, n) < tol) {
            free(x);
            return x_new;
        }
        for (i = 0; i < n; i++) {
            x[i] = x_new[i];
        }
    }
    free(x);
    return NULL;
}
int main() {
    double** A = (double**) malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        A[i] = (double*) malloc(3 * sizeof(double));
    }
    A[0][0] = 4;
    A[0][1] = 1;
    A[0][2] = 2;
    A[1][0] = 3;
    A[1][1] = 5;
    A[1][2] = 1;
    A[2][0] = 1;
    A[2][1] = 2;
    A[2][2] = 4;
    double b[3] = {4, 7, 3};
    double tol = 1e-6;
    int max_iter = 1000;
    double* x = gauss_seidel(A, b, 3, tol, max_iter);
    if (x != NULL) {
        for (int i = 0; i < 3; i++) {
            printf("%f\n", x[i]);
        }
        free(x);
    }
    for (int i = 0; i < 3; i++) {
        free(A[i]);
    }
    free(A);
    return 0;
}