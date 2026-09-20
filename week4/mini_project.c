#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

void addEmployee()
{
    FILE *fp;
    struct Employee e;

    fp = fopen("employees.dat", "ab");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(e), 1, fp);

    fclose(fp);

    printf("Employee added successfully.\n");
}

void displayEmployees()
{
    FILE *fp;
    struct Employee e;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\n--- Employee Details ---\n");

    while (fread(&e, sizeof(e), 1, fp))
    {
        printf("\nEmployee ID: %d", e.id);
        printf("\nName: %s", e.name);
        printf("\nSalary: %.2f\n", e.salary);
    }

    fclose(fp);
}

void searchEmployee()
{
    FILE *fp;
    struct Employee e;
    int id;
    int found = 0;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp))
    {
        if (e.id == id)
        {
            printf("\nEmployee Found!\n");
            printf("Employee ID: %d\n", e.id);
            printf("Name: %s\n", e.name);
            printf("Salary: %.2f\n", e.salary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n==============================");
        printf("\n EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
