void swap(int *a, int *b) {
    int t=*a; *a=*b; *b=t;
}

// Original quicksort algorithm
void sort(int arr[], int beg, int end) {
    if (end > beg + 1) {
        int piv = arr[beg], l = beg + 1, r = end;
        while (l < r) {
            if (arr[l] <= piv)
                l++;
            else
                swap(&arr[l], &arr[--r]);
        }
        swap(&arr[--l], &arr[beg]);
        sort(arr, beg, l);
        sort(arr, r, end);
    }
}

// Modified quicksort algorithm, with permutation vectior
void sort_perm(int arr[], int perm[], int beg, int end) {
    if (end > beg + 1) {
        int piv = arr[perm[beg]], l = beg + 1, r = end;
        while (l < r) {
            if (arr[perm[l]] <= piv)
                l++;
            else
                swap(&perm[l], &perm[--r]);
        }
        swap(&perm[--l], &perm[beg]);
        sort_perm(arr, perm, beg, l);
        sort_perm(arr, perm, r, end);
    }
}