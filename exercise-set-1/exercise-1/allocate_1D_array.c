# include <stdlib.h>
# include <stdio.h>

int main() {
    int n, *array_ptr, max_val, min_val;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    array_ptr = (int*) malloc(n * sizeof(int)); 
    if (array_ptr == NULL) {
        printf("Error! Memory not allocated.\n");
        exit(-1);
    }

    // Seed the random number generator
    srand(42);

    // Assign random values to the array
    for (int i = 0; i < n; i++) {
        array_ptr[i] = rand();
    }

    // init max and min with first val in array
    max_val = array_ptr[0];
    min_val = array_ptr[0];

    // loop though to find actual max and min
    for ( int i = 1; i<n; i++) {
        if (array_ptr[i] > max_val) {
            max_val = array_ptr[i];
        }
        if (array_ptr[i] < min_val) {
            min_val = array_ptr[i];
        }
    }

    // Print the max and min values
    printf("Max value: %d\n", max_val);
    printf("Min value: %d\n", min_val);

    // Free the memory
    free(array_ptr);

    return 0;

}