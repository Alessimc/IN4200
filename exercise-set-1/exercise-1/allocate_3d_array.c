#include <stdio.h>
#include <stdlib.h>

int main() {
    int nx, ny, nz;         // Dimensions of the 3D array
    float *storage;         // Pointer for contiguous memory storage
    float ***array_3d;      // Triple pointer for simulating a 3D array

    // Get dimensions from the user
    printf("Enter dimensions nx, ny, nz: ");
    scanf("%d %d %d", &nx, &ny, &nz);

    // Step 1: Allocate contiguous memory for the entire 3D array
    // Allocate space for nx * ny * nz elements in a single block of memory.
    storage = (float *)malloc(nx * ny * nz * sizeof(float));
    if (storage == NULL) {
        printf("Error! Memory not allocated for storage.\n");
        return -1; // Exit program if allocation fails
    }

    // Step 2: Allocate memory for the top-level pointer array (nx pointers)
    // This array will hold pointers to each 2D "slice" of the 3D array.
    array_3d = (float ***)malloc(nx * sizeof(float **));
    if (array_3d == NULL) {
        printf("Error! Memory not allocated for 3D pointer array.\n");
        free(storage); // Free the contiguous memory block to avoid memory leaks
        return -1;      // Exit program if allocation fails
    }

    // Step 3: For each "slice" in the x-dimension, allocate pointers for rows (ny)
    for (int i = 0; i < nx; i++) {
        // Allocate memory for ny pointers, each pointing to a row within this slice.
        array_3d[i] = (float **)malloc(ny * sizeof(float *));
        if (array_3d[i] == NULL) {
            printf("Error! Memory not allocated for array_3d[%d].\n", i);

            // Free previously allocated memory to avoid leaks
            free(storage);
            for (int j = 0; j < i; j++) free(array_3d[j]); // Free earlier slices
            free(array_3d);
            return -1; // Exit program if allocation fails
        }

        // Step 4: Point each row in this slice to the correct part of the contiguous storage
        for (int j = 0; j < ny; j++) {
            // Compute the starting address of row `j` in slice `i` in the contiguous 1D storage:
            // The formula is: base + i * ny * nz + j * nz
            array_3d[i][j] = &(storage[i * ny * nz + j * nz]);
        }
    }

    // Step 5: Assign values to the 3D array
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                // Assign a unique value based on i, j, and k
                array_3d[i][j][k] = i * ny * nz + j * nz + k;
            }
        }
    }

    // Step 6: Print the values to verify correctness
    printf("3D Array values:\n");
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                printf("array_3d[%d][%d][%d] = %.1f\n", i, j, k, array_3d[i][j][k]);
            }
        }
    }

    // Step 7: Free allocated memory
    free(storage);          // Free the contiguous storage block
    for (int i = 0; i < nx; i++) {
        free(array_3d[i]);  // Free each 2D slice pointer array
    }
    free(array_3d);         // Free the top-level pointer array

    printf("Memory deallocated successfully.\n");

    return 0;
}
