/*
Read in the file tryvannshøgda_air_temp_26012025.csv

Find out the highest and lowest temperatures and when they occurred.
Compute also the average temperature and the associated standard
deviation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define MAX_ENTRIES 100

int main() {
    FILE *file;
    char time[6];
    double temperature, sum = 0.0, sum_sq = 0.0;
    double max_temp = -100.0, min_temp = 100.0;
    char max_time[6], min_time[6];
    int count = 0;

    double avg_temperature, var, std_dev;
    
    // Open file for reading
    file = fopen("tryvannshøgda_air_temp_26012025.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fscanf(file, "%s %lf", time, &temperature) == 2) {
        if (count >= MAX_ENTRIES) {
            printf("Max entries reached... reading interupted.\n");
            break;
        }
        // store sum and sum of squares for mean and std
        sum += temperature;
        sum_sq += temperature * temperature;
        count++;

        // check if current temperature is new max
        if (temperature > max_temp) {
            max_temp = temperature;
            snprintf(max_time, sizeof(max_time), "%s", time);
        }

        // check if current temperature is new min
        if (temperature < min_temp) {
            min_temp = temperature;
            snprintf(min_time, sizeof(min_time), "%s", time);    
        }
    }

    fclose(file);
    
    if (count == 0) {
        printf("No data found in file.\n");
        return -1;
    }

    // Compute average temperature
    avg_temperature = sum / count;

    // Compute var and std
    var = (sum_sq - sum * sum / count) / count;
    std_dev = sqrt(var);

    // Output
    printf("Max temperature: %.2f at %s\n", max_temp, max_time);
    printf("Min temperature: %.2f at %s\n", min_temp, min_time);
    printf("Average temperature: %.2f\n", avg_temperature);
    printf("Standard deviation: %.2f\n", std_dev);

    return 0;
}