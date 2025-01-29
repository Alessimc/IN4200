/*
The order of nested loops in C matters in terms of
memory access patterns. This can impact performance
due to cache locality/efficiency
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10000  // Number of rows
#define N 10000  // Number of columns

int main() {
    // Allocate a 2D matrix on the heap
    double** matrix = (double**) malloc(M * sizeof(double*));
    for (int i = 0; i < M; i++) {
        matrix[i] = (double*) malloc(N * sizeof(double));
    }

    // Measure time for row-major access (outer loop: rows, inner loop: columns)
    clock_t start_row_major = clock();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;  // Row-major access
        }
    }
    clock_t end_row_major = clock();

    // Measure time for column-major access (outer loop: columns, inner loop: rows)
    clock_t start_col_major = clock();
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            matrix[i][j] = i + j;  // Column-major access
        }
    }
    clock_t end_col_major = clock();

    // Calculate elapsed times
    double time_row_major = (double)(end_row_major - start_row_major) / CLOCKS_PER_SEC;
    double time_col_major = (double)(end_col_major - start_col_major) / CLOCKS_PER_SEC;

    // Print results
    printf("Time for row-major access: %.6f seconds\n", time_row_major);
    printf("Time for column-major access: %.6f seconds\n", time_col_major);

    // Free allocated memory
    for (int i = 0; i < M; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

/*
Time for row-major access: 0.353265 seconds
Time for column-major access: 0.438237 seconds

Accessing elements in row-major aligns with how the data is stored.
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
would be stored as {1, 2, 3, 4, 5, 6, 7, 8, 9} in memory.
*/