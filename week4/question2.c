#include <stdio.h>

struct Student
{
    char name[50];
    int age;
    float marks;
};

int main()
{
    struct Student s, temp;
    FILE *fp;

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Write data to file
    fp = fopen("student.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.marks);

    fclose(fp);

    // Read data from file
    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    fscanf(fp, "%s %d %f",
           temp.name, &temp.age, &temp.marks);

    fclose(fp);

    printf("\n--- Data Read From File ---\n");
    printf("Name: %s\n", temp.name);
    printf("Age: %d\n", temp.age);
    printf("Marks: %.2f\n", temp.marks);

    return 0;
}
