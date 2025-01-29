// given 1D code
void smooth (double *v_new, double *v, int n, double c) {
    int i;
    for (i=1; i<n-1; i++)
    v_new[i] = v[i] + c*(v[i-1]-2*v[i]+v[i+1]);
    v_new[0] = v[0];
    v_new[n-1] = v[n-1];
}


/*
Assuming that the 2D array is stored using double pointer
*/
void smooth(double **v_new, double **v, int rows, int cols, double c) {
    int i, j;
    for (i = 1; i < rows - 1; i++) {
        for (j = 1; j < cols - 1; j++) {
            v_new[i][j] = v[i][j] + c * (v[i-1][j] + v[i][j-1] - 4*v[i][j] + v[i][j+1] + v[i+1][j]);
        }
    }
}
