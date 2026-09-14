#include <stdio.h>

float average(int marks[], int n) {
    int i, sum = 0;

    for(i = 0; i < n; i++)
        sum = sum + marks[i];

    return (float)sum / n;
}

int main() {
    int marks[5], i;
    float avg;

    printf("Enter marks of 5 subjects:\n");

    for(i = 0; i < 5; i++)
        scanf("%d", &marks[i]);

    avg = average(marks, 5);

    printf("Student Average = %.2f", avg);

    return 0;
}