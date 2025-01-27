#include <stdio.h>
#include <math.h>

double calculate_term(int n) {
    // calculate even powers of 2 (2^(2n)) with alternating signs
    double term = pow(-1, n) * (1 / pow(2, 2 * n));
    printf("%.15f\n", pow(-1, n-1));
    return term;
}

double calculate_series_sum(int terms) {
    double sum = 0.0;
    for (int n = 0; n < terms; n++) {
        sum += calculate_term(n);
    }
    return sum;
}

int main() {
    int terms = 20;
    double calculated_sum = calculate_series_sum(terms);
    double expected_sum = 4.0 / 5.0; // The know limit

    printf("Calculating the sum using %d terms: %.15f\n", terms, calculated_sum);
    printf("Expected sum: %.15f\n", expected_sum);

    // checking convergence
    if (fabs(calculated_sum - expected_sum) < 1e-10) {
        printf("The series converges to the expected sum of 4/5.\n");
    } else {
        printf("The series does not converge to the expected sum of 4/5.\n");
    }
}